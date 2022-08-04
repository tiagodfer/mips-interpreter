/*
 * 1  - Run the specified program = 5% DONE
 * 2  - Convert MIPS Assembly to machine code = 10% DONE
 * 3  - RAM as a vector of integers and copy program to RAM = 5% DONE
 * 4  - Instruction validation in RAM = 10% DONE
 * 5  - Directly mapped cache, 4 sets, 1 word per block = 5%
 * 6  - Two way associative chace, 4, sets, 1 word per block = 10%
 * 7  - Modify item 6 to support 4 words per block = 10%
 * 8  - Modify item 6 to support user inputted set number = 10%
 * 9  - RAM + Cache = 10%
 * 10 - Run the specified program with RAM + Cache = 10%
 * 11 - UI = 5% DONE
 * 12 - Run the specified benchmarks = 10%
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "mips.h"
#include "file.h"
#include "screen.h"
#include "constants.h"

int main () {
    unsigned int counter = 0;
    FILE *file = NULL;
    char assy[LENGHT] = "\0";
    int input;
    int locked = 0;
    unsigned int cycle_count = 0x0;
    unsigned int mc = 0x0;
    unsigned int op = 0x0;
    unsigned int rs = 0x0;
    unsigned int rt = 0x0;
    unsigned int rd = 0x0;
    unsigned int target = 0x0;
    int immediate = 0x0;
    unsigned int shamt = 0x0;
    unsigned int funct = 0x0;
    int offset = 0x0;
    unsigned int data[DATA_SIZE] = {0x0};
    unsigned int data_info[DATA_SIZE] = {0x0};
    unsigned int mode = 0;
    unsigned int pc = 0x0;
    unsigned int ram[RAM_SIZE] = {0x0};
    unsigned int ram_info[RAM_SIZE] = {0x0};
    unsigned int registers[32] = {0x0};
    unsigned int text[TEXT_SIZE] = {0x0};
    unsigned int text_info[TEXT_SIZE] = {0x0};
    unsigned int scroll = 0x0;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();
    curs_set(0);
    WINDOW *cycle_window = newwin(3, 12, 1, 13);
    WINDOW *data_window = newwin(18, 19, 1, 44);
    WINDOW *mode_window = newwin(3, 25, 22, 0);
    WINDOW *pc_window = newwin(3, 12, 1, 0);
    WINDOW *ram_window = newwin(24, 19, 1, 63);
    WINDOW *registers_window = newwin(18, 25, 4, 0);
    WINDOW *text_window = newwin(18, 19, 1, 25);
    refresh();
    mvprintw(0, 10, "%s", "(M)ODE - (L)OAD - (R)UN - (S)TEP - RESE(T) - (E)XIT");
    refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
    while (input != 'e') {
        if (kbhit()) {
            input = getch();
            switch (input) {
                case 'l':
                    file = file_read();
                    if (file) {
                        locked = 0;
                        pc = 0;
                        counter = 0;
                        while (fscanf(file, " %[^\n]", assy) != EOF) {
                            if (!strcmp(assy, ".TEXT")) {
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".DATA")) {
                                    mc = assembler(assy);
                                    ram[counter] = mc;
                                    ram_info[counter] = 0x1100 + counter;
                                    counter++;
                                }
                            }
                            if (!strcmp(assy, ".DATA")) {
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".TEXT")) {
                                    ram[counter] = strtol(assy, NULL, 10);
                                    ram_info[counter] = 0x2100 + counter;
                                    counter++;
                                }
                            }
                        }
                    }
                    switch (mode) {
                        case 0:
                            break;
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                    }
                    refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                    break;
                case 'r':
                    break;
                case 's':
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
                        locked = step(&cycle_count, &pc, &op, &rs, &rt, &rd, &target, &immediate, &shamt, &funct, &offset, data, registers, text);
                    }
                    refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                    break;
                case 't':
                    locked = 0;
                    pc = 0;
                    for (int i = 0; i < 32; i++) {
                        registers[i] = 0x0;
                    }
                    for (int i = 0; i < RAM_SIZE; i++) {
                        ram[i] = 0x0;
                    }
                    for (int i = 0; i < DATA_SIZE; i++) {
                        data[i] = 0x0;
                    }
                    for (int i = 0; i < TEXT_SIZE; i++) {
                        text[i] = 0x0;
                    }
                    refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                    break;
                case 'm':
                    mode += 1;
                    if (mode >= 5) {
                        mode = 0;
                    }
                    refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                case KEY_UP:
                    if (scroll > 0) {
                        scroll -= 4;
                        refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                    }
                    break;
                case KEY_DOWN:
                    if (scroll < (RAM_SIZE - 0x54)) {
                        scroll += 4;
                        refresh_windows(cycle_window, cycle_count, data_window, data, mode_window, mode, pc_window, pc, ram_window, ram, scroll, registers_window, registers, text_window, text);
                    }
                    break;
            }
        }
    }
    endwin();
}
