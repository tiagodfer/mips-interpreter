/*
 * 1  - Run the specified program = 5%
 * 2  - Convert MIPS Assembly to machine code = 10% DONE
 * 3  - RAM as a vector of integers and copy program to RAM = 5%
 * 4  - Instruction validation in RAM = 10%
 * 5  - Directly mapped cache, 4 sets, 1 word per block = 5%
 * 6  - Two way associative chace, 4, sets, 1 word per block = 10%
 * 7  - Modify item 6 to support 4 words per block = 10%
 * 8  - Modify item 6 to support user inputted set number = 10%
 * 9  - RAM + Cache = 10%
 * 10 - Run the specified program with RAM + Cache = 10%
 * 11 - UI = 5%
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
    int text_counter = 0;
    int data_counter = 0;
    FILE *file = NULL;
    char assy[LENGHT] = "\0";
    int input;
    int locked = 0;
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
    unsigned int mode = 0;
    unsigned int pc = 0x0;
    unsigned int ram[RAM_SIZE] = {0x0};
    unsigned int registers[32] = {0x0};
    unsigned int text[TEXT_SIZE] = {0x0};
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    WINDOW *data_window = newwin(24, 19, 1, 44);
    WINDOW *mode_window = newwin(3, 25, 22, 0);
    WINDOW *pc_window = newwin(3, 25, 1, 0);
    WINDOW *ram_window = newwin(24, 19, 1, 63);
    WINDOW *registers_window = newwin(18, 25, 4, 0);
    WINDOW *text_window = newwin(24, 19, 1, 25);
    refresh();
    box(data_window, 0, 0);
    box(mode_window, 0, 0);
    box(pc_window, 0, 0);
    box(ram_window, 0, 0);
    box(registers_window, 0, 0);
    box(text_window, 0, 0);
    mvprintw(0, 10, "%s", "(L)OAD - (R)UN - (S)TEP - RESE(T) - (E)XIT");
    data_labels(data_window);
    data_values(data_window, data);
    mode_label(mode_window);
    mode_value(mode_window, mode);
    pc_label(pc_window);
    pc_value(pc_window, pc);
    ram_labels(ram_window);
    ram_values(ram_window, ram);
    registers_labels(registers_window);
    registers_values(registers_window, registers);
    text_labels(text_window);
    text_values(text_window, text);
    wrefresh(data_window);
    wrefresh(mode_window);
    wrefresh(pc_window);
    wrefresh(ram_window);
    wrefresh(registers_window);
    wrefresh(text_window);
    while (input != 'e') {
        if (kbhit()) {
            input = getch();
            switch (input) {
                case 'l':
                    file = file_read();
                    if (file) {
                        locked = 0;
                        pc = 0;
                        text_counter = 0;
                        data_counter = 0;
                        while (fscanf(file, " %[^\n]", assy) != EOF) {
                            if (!strcmp(assy, ".TEXT")) {
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".DATA")) {
                                    mc = assembler(assy);
                                    text[text_counter++] = mc;
                                }
                            }
                            if (!strcmp(assy, ".DATA")) {
                                while (fscanf(file, " %[^\n]", assy) != EOF && strcmp(assy, ".TEXT")) {
                                    data[data_counter++] = strtol(assy, NULL, 10);
                                }
                            }
                        }
                    }
                    box(data_window, 0, 0);
                    box(mode_window, 0, 0);
                    box(pc_window, 0, 0);
                    box(ram_window, 0, 0);
                    box(registers_window, 0, 0);
                    box(text_window, 0, 0);
                    data_labels(data_window);
                    data_values(data_window, data);
                    mode_label(mode_window);
                    mode_value(mode_window, mode);
                    pc_label(pc_window);
                    pc_value(pc_window, pc);
                    ram_labels(ram_window);
                    ram_values(ram_window, ram);
                    registers_labels(registers_window);
                    registers_values(registers_window, registers);
                    text_labels(text_window);
                    text_values(text_window, text);
                    wrefresh(data_window);
                    wrefresh(mode_window);
                    wrefresh(pc_window);
                    wrefresh(ram_window);
                    wrefresh(registers_window);
                    wrefresh(text_window);
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
                        locked = step(&pc, &op, &rs, &rt, &rd, &target, &immediate, &shamt, &funct, &offset, data, registers, text);
                    }
                    box(data_window, 0, 0);
                    box(mode_window, 0, 0);
                    box(pc_window, 0, 0);
                    box(ram_window, 0, 0);
                    box(registers_window, 0, 0);
                    box(text_window, 0, 0);
                    data_labels(data_window);
                    data_values(data_window, data);
                    mode_label(mode_window);
                    mode_value(mode_window, mode);
                    pc_label(pc_window);
                    pc_value(pc_window, pc);
                    ram_labels(ram_window);
                    ram_values(ram_window, ram);
                    registers_labels(registers_window);
                    registers_values(registers_window, registers);
                    text_labels(text_window);
                    text_values(text_window, text);
                    wrefresh(data_window);
                    wrefresh(mode_window);
                    wrefresh(pc_window);
                    wrefresh(ram_window);
                    wrefresh(registers_window);
                    wrefresh(text_window);
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
                    box(data_window, 0, 0);
                    box(mode_window, 0, 0);
                    box(pc_window, 0, 0);
                    box(ram_window, 0, 0);
                    box(registers_window, 0, 0);
                    box(text_window, 0, 0);
                    data_labels(data_window);
                    data_values(data_window, data);
                    mode_label(mode_window);
                    mode_value(mode_window, mode);
                    pc_label(pc_window);
                    pc_value(pc_window, pc);
                    ram_labels(ram_window);
                    ram_values(ram_window, ram);
                    registers_labels(registers_window);
                    registers_values(registers_window, registers);
                    text_labels(text_window);
                    text_values(text_window, text);
                    wrefresh(data_window);
                    wrefresh(mode_window);
                    wrefresh(pc_window);
                    wrefresh(ram_window);
                    wrefresh(registers_window);
                    wrefresh(text_window);
                    break;
            }
        }
    }
    endwin();
}
