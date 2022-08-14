#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "mips.h"
#include "file.h"
#include "screen.h"
#include "constants.h"

int main () {
    unsigned int ram_count = 0;
    FILE *file = NULL;
    char assy[LENGHT] = "\0";
    int input = '\0';
    int locked = 0;
    unsigned int counters[3] = {0x0}; // [0] = cycle, [1] miss, [2] reads
    unsigned int mc = 0x0;
    unsigned int data[DATA_SIZE] = {0x0};
    unsigned int data_info[DATA_SIZE] = {0x0};
    unsigned int mode = 0;
    unsigned int pc = 0x0;
    unsigned int ram[RAM_SIZE] = {0x0};
    unsigned int ram_info[RAM_SIZE] = {0x0};
    unsigned int ram_start = 0x0;
    unsigned int registers[32] = {0x0};
    unsigned int text[TEXT_SIZE] = {0x0};
    unsigned int text_info[TEXT_SIZE] = {0x0};
    unsigned int scroll = 0x0;
    initscr(); // initializes a screen on terminal & sets up memory and clears the screen 
    keypad(stdscr, TRUE); // up and down arrow to roll RAM window
    noecho(); 
    cbreak();
    curs_set(0);
    WINDOW *cycle_window = newwin(3, 12, 1, 13); // newwin(height, widgth, start_y, start_x);
    WINDOW *data_window = newwin(18, 19, 1, 44);
    WINDOW *mode_window = newwin(3, 25, 22, 0);
    WINDOW *pc_window = newwin(3, 12, 1, 0);
    WINDOW *ram_window = newwin(24, 19, 1, 63);
    WINDOW *registers_window = newwin(18, 25, 4, 0);
    WINDOW *text_window = newwin(18, 19, 1, 25);
    WINDOW *miss_window = newwin(6, 38, 19, 25);
    refresh(); // refreshes screen to match whats in memory
    mvprintw(0, 10, "%s", "(M)ODE - (L)OAD - (R)UN - (S)TEP - RESE(T) - (E)XIT"); //prints a string to a window: mvprintw( Line,  Column, Format, [Content ...])
    refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
    while (input != 'e') {
        if (kbhit()) {
            input = getch(); //whats for user input, returns char value of that key
            switch (input) {
                // load
                case 'l':
                    file = file_read();
                    if (file) {
                        locked = 0;
                        pc = 0;
                        ram_count = 0;
                        while (fscanf(file, " %[^\n]", assy) != EOF) {
                            if (!strcmp(assy, ".TEXT")) {
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".DATA")) {
                                    mc = assembler(assy);
                                    ram[ram_count] = mc;
                                    ram_info[ram_count] = 0x10000000;
                                    ram_count++;
                                }
                            }
                            if (!strcmp(assy, ".DATA")) {
                                if (ram_count % 4) {
                                    ram_count += 4 - ram_count % 4;
                                }
                                ram_start = ram_count;
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".TEXT")) {
                                    ram[ram_count] = strtol(assy, NULL, 10);
                                    ram_info[ram_count] = 0x20000000;
                                    ram_count++;
                                }
                            }
                        }
                    }
                    refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    break;
                // run
                case 'r':
                    while (!locked) {
                        if (locked) {
                            WINDOW *error_window = newwin(5, 35, 10, 25);
                            refresh();
                            box(error_window, 0, 0);
                            mvwprintw(error_window, 2, 10, "Reset first!");
                            wrefresh(error_window);
                            wgetch(error_window);
                            wclear(error_window);
                            wrefresh(error_window);
                            delwin(error_window);
                        } else {
                            fetch(counters, &pc, mode, ram, ram_info, data, data_info, text, text_info);
                            locked = decode_execute(mode, counters, &pc, registers, text, text_info, data, data_info, ram, ram_info, ram_start);
                        }
                        refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    }
                    break;
                // step
                case 's':
                    if (locked) {
                        WINDOW *error_window = newwin(5, 35, 10, 25);
                        refresh();
                        box(error_window, 0, 0);
                        mvwprintw(error_window, 2, 10, "Reset first!");
                        wrefresh(error_window); // refresh just a window
                        wgetch(error_window);
                        wclear(error_window);
                        wrefresh(error_window);
                        delwin(error_window);
                    } else {
                        fetch(counters, &pc, mode, ram, ram_info, data, data_info, text, text_info);
                        locked = decode_execute(mode, counters, &pc, registers, text, text_info, data, data_info, ram, ram_info, ram_start);
                    }
                    refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    break;
                // reset
                case 't':
                    locked = 0;
                    pc = 0;
                    counters[0] = 0;
                    counters[1] = 0;
                    counters[2] = 0;
                    for (int i = 0; i < 32; i++) {
                        registers[i] = 0x0;
                    }
                    for (int i = 0; i < RAM_SIZE; i++) {
                        ram[i] = 0x0;
                        ram_info[i] = 0x0;
                    }
                    for (int i = 0; i < DATA_SIZE; i++) {
                        data[i] = 0x0;
                        data_info[i] = 0x0;
                    }
                    for (int i = 0; i < TEXT_SIZE; i++) {
                        text[i] = 0x0;
                        text_info[i] = 0x0;
                    }
                    refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    break;
                // mode
                case 'm':
                    mode += 1;
                    if (mode >= 2) {
                        mode = 0;
                    }
                    refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                // up
                case KEY_UP:
                    if (scroll > 0) {
                        scroll -= 4;
                        refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    }
                    break;
                // down
                case KEY_DOWN:
                    if (scroll < (RAM_SIZE - 0x54)) {
                        scroll += 4;
                        refresh_windows(cycle_window, counters, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text, miss_window);
                    }
                    break;
            }
        }
    }
    endwin(); // deallocates memory and ends ncurses
}
