#include <ncurses.h>
#include "screen.h"
#include "constants.h"

void cycle_label (WINDOW *window) {
    mvwprintw(window, 0, 3, "%s", "CYCLES");
}

void cycle_value (WINDOW *window, unsigned int value) {
    mvwprintw(window, 1, 2, "%8X", value);
}

void data_labels (WINDOW *window) {
    mvwprintw(window, 0, 7, ".DATA");
    mvwprintw(window, 1, 1, "%-8s", "0");
    mvwprintw(window, 2, 1, "%-8s", "4");
    mvwprintw(window, 3, 1, "%-8s", "8");
    mvwprintw(window, 4, 1, "%-8s", "C");
    mvwprintw(window, 5, 1, "%-8s", "10");
    mvwprintw(window, 6, 1, "%-8s", "14");
    mvwprintw(window, 7, 1, "%-8s", "18");
    mvwprintw(window, 8, 1, "%-8s", "1C");
    mvwprintw(window, 9, 1, "%-8s", "20");
    mvwprintw(window, 10, 1, "%-8s", "24");
    mvwprintw(window, 11, 1, "%-8s", "28");
    mvwprintw(window, 12, 1, "%-8s", "2C");
    mvwprintw(window, 13, 1, "%-8s", "30");
    mvwprintw(window, 14, 1, "%-8s", "34");
    mvwprintw(window, 15, 1, "%-8s", "38");
    mvwprintw(window, 16, 1, "%-8s", "3C");
    /*
    mvwprintw(window, 17, 1, "%-8s", "40");
    mvwprintw(window, 18, 1, "%-8s", "44");
    mvwprintw(window, 19, 1, "%-8s", "48");
    mvwprintw(window, 20, 1, "%-8s", "4C");
    mvwprintw(window, 21, 1, "%-8s", "50");
    mvwprintw(window, 22, 1, "%-8s", "54");
    */
}

void data_values (WINDOW *window, unsigned int *values) {
    mvwprintw(window, 1, 10, "%8X", values[0]);
    mvwprintw(window, 2, 10, "%8X", values[1]);
    mvwprintw(window, 3, 10, "%8X", values[2]);
    mvwprintw(window, 4, 10, "%8X", values[3]);
    mvwprintw(window, 5, 10, "%8X", values[4]);
    mvwprintw(window, 6, 10, "%8X", values[5]);
    mvwprintw(window, 7, 10, "%8X", values[6]);
    mvwprintw(window, 8, 10, "%8X", values[7]);
    mvwprintw(window, 9, 10, "%8X", values[8]);
    mvwprintw(window, 10, 10, "%8X", values[9]);
    mvwprintw(window, 11, 10, "%8X", values[10]);
    mvwprintw(window, 12, 10, "%8X", values[11]);
    mvwprintw(window, 13, 10, "%8X", values[12]);
    mvwprintw(window, 14, 10, "%8X", values[13]);
    mvwprintw(window, 15, 10, "%8X", values[14]);
    mvwprintw(window, 16, 10, "%8X", values[15]);
    /*
    mvwprintw(window, 17, 10, "%8X", values[16]);
    mvwprintw(window, 18, 10, "%8X", values[17]);
    mvwprintw(window, 19, 10, "%8X", values[18]);
    mvwprintw(window, 20, 10, "%8X", values[19]);
    mvwprintw(window, 21, 10, "%8X", values[20]);
    mvwprintw(window, 22, 10, "%8X", values[21]);
    */
}

void mode_label (WINDOW *window) {
    mvwprintw(window, 0, 11, "%s", "MODE");
}

void mode_value (WINDOW *window, unsigned int value) {
    switch (value) {
        case 0:
            mvwprintw(window, 1, 1, "%23s", "      DIRECT-4B1W      ");
            break;
        case 1:
            mvwprintw(window, 1, 1, "%23s", "  2W-ASSOCIATIVE-4B1W  ");
            break;
        case 2:
            mvwprintw(window, 1, 1, "%23s", "  2W-ASSOCIATIVE-4B4W  ");
            break;
        case 3:
            mvwprintw(window, 1, 1, "%23s", "  2W-ASSOCIATIVE-2B4W  ");
            break;
        case 4:
            mvwprintw(window, 1, 1, "%23s", "  2W-ASSOCIATIVE-1B4W  ");
            break;
    }
}

void pc_label (WINDOW *window) {
    mvwprintw(window, 0, 5, "%s", "PC");
}

void pc_value (WINDOW *window, unsigned int value) {
    mvwprintw(window, 1, 2, "%8X", value);
}

void ram_labels (WINDOW *window, unsigned int scroll) {
    mvwprintw(window, 0, 8, "RAM");
    if (scroll) {
        mvwprintw(window, 0, 5, "/\\");
    }
    if (scroll < (RAM_SIZE - 0x54)) {
        mvwprintw(window, 0, 12, "\\/");
    }
    mvwprintw(window, 1, 1, "%-8X", scroll);
    mvwprintw(window, 2, 1, "%-8X", scroll + 0x4);
    mvwprintw(window, 3, 1, "%-8X", scroll + 0x8);
    mvwprintw(window, 4, 1, "%-8X", scroll + 0xC);
    mvwprintw(window, 5, 1, "%-8X", scroll + 0x10);
    mvwprintw(window, 6, 1, "%-8X", scroll + 0x14);
    mvwprintw(window, 7, 1, "%-8X", scroll + 0x18);
    mvwprintw(window, 8, 1, "%-8X", scroll + 0x1C);
    mvwprintw(window, 9, 1, "%-8X", scroll + 0x20);
    mvwprintw(window, 10, 1, "%-8X", scroll + 0x24);
    mvwprintw(window, 11, 1, "%-8X", scroll + 0x28);
    mvwprintw(window, 12, 1, "%-8X", scroll + 0x2C);
    mvwprintw(window, 13, 1, "%-8X", scroll + 0x30);
    mvwprintw(window, 14, 1, "%-8X", scroll + 0x34);
    mvwprintw(window, 15, 1, "%-8X", scroll + 0x38);
    mvwprintw(window, 16, 1, "%-8X", scroll + 0x3C);
    mvwprintw(window, 17, 1, "%-8X", scroll + 0x40);
    mvwprintw(window, 18, 1, "%-8X", scroll + 0x44);
    mvwprintw(window, 19, 1, "%-8X", scroll + 0x48);
    mvwprintw(window, 20, 1, "%-8X", scroll + 0x4C);
    mvwprintw(window, 21, 1, "%-8X", scroll + 0x50);
    mvwprintw(window, 22, 1, "%-8X", scroll + 0x54);
}

void ram_values (WINDOW *window, unsigned int *values, unsigned int scroll) {
    mvwprintw(window, 1, 10, "%8X", values[scroll + 0]);
    mvwprintw(window, 2, 10, "%8X", values[scroll + 1]);
    mvwprintw(window, 3, 10, "%8X", values[scroll + 2]);
    mvwprintw(window, 4, 10, "%8X", values[scroll + 3]);
    mvwprintw(window, 5, 10, "%8X", values[scroll + 4]);
    mvwprintw(window, 6, 10, "%8X", values[scroll + 5]);
    mvwprintw(window, 7, 10, "%8X", values[scroll + 6]);
    mvwprintw(window, 8, 10, "%8X", values[scroll + 7]);
    mvwprintw(window, 9, 10, "%8X", values[scroll + 8]);
    mvwprintw(window, 10, 10, "%8X", values[scroll + 9]);
    mvwprintw(window, 11, 10, "%8X", values[scroll + 10]);
    mvwprintw(window, 12, 10, "%8X", values[scroll + 11]);
    mvwprintw(window, 13, 10, "%8X", values[scroll + 12]);
    mvwprintw(window, 14, 10, "%8X", values[scroll + 13]);
    mvwprintw(window, 15, 10, "%8X", values[scroll + 14]);
    mvwprintw(window, 16, 10, "%8X", values[scroll + 15]);
    mvwprintw(window, 17, 10, "%8X", values[scroll + 16]);
    mvwprintw(window, 18, 10, "%8X", values[scroll + 17]);
    mvwprintw(window, 19, 10, "%8X", values[scroll + 18]);
    mvwprintw(window, 20, 10, "%8X", values[scroll + 19]);
    mvwprintw(window, 21, 10, "%8X", values[scroll + 20]);
    mvwprintw(window, 22, 10, "%8X", values[scroll + 21]);
}

void registers_labels (WINDOW *window) {
    mvwprintw(window, 0, 9, "REGISTERS");
    mvwprintw(window, 1, 1, "%s", "R0");
    mvwprintw(window, 2, 1, "%s", "AT");
    mvwprintw(window, 3, 1, "%s", "V0");
    mvwprintw(window, 4, 1, "%s", "V1");
    mvwprintw(window, 5, 1, "%s", "A0");
    mvwprintw(window, 6, 1, "%s", "A1");
    mvwprintw(window, 7, 1, "%s", "A2");
    mvwprintw(window, 8, 1, "%s", "A3");
    mvwprintw(window, 9, 1, "%s", "T0");
    mvwprintw(window, 10, 1, "%s", "T1");
    mvwprintw(window, 11, 1, "%s", "T2");
    mvwprintw(window, 12, 1, "%s", "T3");
    mvwprintw(window, 13, 1, "%s", "T4");
    mvwprintw(window, 14, 1, "%s", "T5");
    mvwprintw(window, 15, 1, "%s", "T6");
    mvwprintw(window, 16, 1, "%s", "T7");
    mvwprintw(window, 1, 13, "%s", "S0");
    mvwprintw(window, 2, 13, "%s", "S1");
    mvwprintw(window, 3, 13, "%s", "S2");
    mvwprintw(window, 4, 13, "%s", "S3");
    mvwprintw(window, 5, 13, "%s", "S4");
    mvwprintw(window, 6, 13, "%s", "S5");
    mvwprintw(window, 7, 13, "%s", "S6");
    mvwprintw(window, 8, 13, "%s", "S7");
    mvwprintw(window, 9, 13, "%s", "T8");
    mvwprintw(window, 10, 13, "%s", "T9");
    mvwprintw(window, 11, 13, "%s", "K0");
    mvwprintw(window, 12, 13, "%s", "K1");
    mvwprintw(window, 13, 13, "%s", "GP");
    mvwprintw(window, 14, 13, "%s", "SP");
    mvwprintw(window, 15, 13, "%s", "FP");
    mvwprintw(window, 16, 13, "%s", "RA");
}

void registers_values (WINDOW *window, unsigned int *values) {
    mvwprintw(window, 1, 4, "%8X", values[0]);
    mvwprintw(window, 2, 4, "%8X", values[1]);
    mvwprintw(window, 3, 4, "%8X", values[2]);
    mvwprintw(window, 4, 4, "%8X", values[3]);
    mvwprintw(window, 5, 4, "%8X", values[4]);
    mvwprintw(window, 6, 4, "%8X", values[5]);
    mvwprintw(window, 7, 4, "%8X", values[6]);
    mvwprintw(window, 8, 4, "%8X", values[7]);
    mvwprintw(window, 9, 4, "%8X", values[8]);
    mvwprintw(window, 10, 4, "%8X", values[9]);
    mvwprintw(window, 11, 4, "%8X", values[10]);
    mvwprintw(window, 12, 4, "%8X", values[11]);
    mvwprintw(window, 13, 4, "%8X", values[12]);
    mvwprintw(window, 14, 4, "%8X", values[13]);
    mvwprintw(window, 15, 4, "%8X", values[14]);
    mvwprintw(window, 16, 4, "%8X", values[15]);
    mvwprintw(window, 1, 16, "%8X", values[16]);
    mvwprintw(window, 2, 16, "%8X", values[17]);
    mvwprintw(window, 3, 16, "%8X", values[18]);
    mvwprintw(window, 4, 16, "%8X", values[19]);
    mvwprintw(window, 5, 16, "%8X", values[13]);
    mvwprintw(window, 6, 16, "%8X", values[21]);
    mvwprintw(window, 7, 16, "%8X", values[22]);
    mvwprintw(window, 8, 16, "%8X", values[23]);
    mvwprintw(window, 9, 16, "%8X", values[24]);
    mvwprintw(window, 10, 16, "%8X", values[25]);
    mvwprintw(window, 11, 16, "%8X", values[26]);
    mvwprintw(window, 12, 16, "%8X", values[27]);
    mvwprintw(window, 13, 16, "%8X", values[28]);
    mvwprintw(window, 14, 16, "%8X", values[29]);
    mvwprintw(window, 15, 16, "%8X", values[30]);
    mvwprintw(window, 16, 16, "%8X", values[31]);
}

void text_labels (WINDOW *window) {
    mvwprintw(window, 0, 7, ".TEXT");
    mvwprintw(window, 1, 1, "%-8s", "0");
    mvwprintw(window, 2, 1, "%-8s", "4");
    mvwprintw(window, 3, 1, "%-8s", "8");
    mvwprintw(window, 4, 1, "%-8s", "C");
    mvwprintw(window, 5, 1, "%-8s", "10");
    mvwprintw(window, 6, 1, "%-8s", "14");
    mvwprintw(window, 7, 1, "%-8s", "18");
    mvwprintw(window, 8, 1, "%-8s", "1C");
    mvwprintw(window, 9, 1, "%-8s", "20");
    mvwprintw(window, 10, 1, "%-8s", "24");
    mvwprintw(window, 11, 1, "%-8s", "28");
    mvwprintw(window, 12, 1, "%-8s", "2C");
    mvwprintw(window, 13, 1, "%-8s", "30");
    mvwprintw(window, 14, 1, "%-8s", "34");
    mvwprintw(window, 15, 1, "%-8s", "38");
    mvwprintw(window, 16, 1, "%-8s", "3C");
    /*
    mvwprintw(window, 17, 1, "%-8s", "40");
    mvwprintw(window, 18, 1, "%-8s", "44");
    mvwprintw(window, 19, 1, "%-8s", "48");
    mvwprintw(window, 20, 1, "%-8s", "4C");
    mvwprintw(window, 21, 1, "%-8s", "50");
    mvwprintw(window, 22, 1, "%-8s", "54");
    */
}

void text_values (WINDOW *window, unsigned int *values) {
    mvwprintw(window, 1, 10, "%8X", values[0]);
    mvwprintw(window, 2, 10, "%8X", values[1]);
    mvwprintw(window, 3, 10, "%8X", values[2]);
    mvwprintw(window, 4, 10, "%8X", values[3]);
    mvwprintw(window, 5, 10, "%8X", values[4]);
    mvwprintw(window, 6, 10, "%8X", values[5]);
    mvwprintw(window, 7, 10, "%8X", values[6]);
    mvwprintw(window, 8, 10, "%8X", values[7]);
    mvwprintw(window, 9, 10, "%8X", values[8]);
    mvwprintw(window, 10, 10, "%8X", values[9]);
    mvwprintw(window, 11, 10, "%8X", values[10]);
    mvwprintw(window, 12, 10, "%8X", values[11]);
    mvwprintw(window, 13, 10, "%8X", values[12]);
    mvwprintw(window, 14, 10, "%8X", values[13]);
    mvwprintw(window, 15, 10, "%8X", values[14]);
    mvwprintw(window, 16, 10, "%8X", values[15]);
    /*
    mvwprintw(window, 17, 10, "%8X", values[16]);
    mvwprintw(window, 18, 10, "%8X", values[17]);
    mvwprintw(window, 19, 10, "%8X", values[18]);
    mvwprintw(window, 20, 10, "%8X", values[19]);
    mvwprintw(window, 21, 10, "%8X", values[20]);
    mvwprintw(window, 22, 10, "%8X", values[21]);
    */
}

void miss_labels(WINDOW *window){
    mvwprintw(window, 0, 17, "MISS");
}

void miss_value (WINDOW *window, unsigned int value) {
    mvwprintw(window, 1, 2, "%8X", value);
}

int kbhit () {
    int ch;
    int r;
    nodelay(stdscr, TRUE);
    ch = getch();
    if (ch == ERR) {
        r = 0;
    } else {
        r = 1;
        ungetch(ch);
    }
    nodelay(stdscr, FALSE);
    return r;
}

void refresh_windows (WINDOW *cycle_window, unsigned int cycle_count, WINDOW *data_window, unsigned int *data, WINDOW *mode_window, unsigned int mode, WINDOW *pc_window, unsigned int pc, WINDOW *ram_window, unsigned int *ram, unsigned int scroll, WINDOW *registers_window, unsigned int *registers, WINDOW *text_window, unsigned int *text, WINDOW *miss_window, unsigned int *miss) {
    box(cycle_window, 0, 0);
    box(data_window, 0, 0);
    box(mode_window, 0, 0);
    box(pc_window, 0, 0);
    box(ram_window, 0, 0);
    box(registers_window, 0, 0);
    box(text_window, 0, 0);
    box(miss_window, 0, 0);
    cycle_label(cycle_window);
    cycle_value(cycle_window, cycle_count);
    data_labels(data_window);
    data_values(data_window, data);
    mode_label(mode_window);
    mode_value(mode_window, mode);
    pc_label(pc_window);
    pc_value(pc_window, pc);
    ram_labels(ram_window, scroll);
    ram_values(ram_window, ram, scroll);
    registers_labels(registers_window);
    registers_values(registers_window, registers);
    text_labels(text_window);
    text_values(text_window, text);
    miss_labels(miss_window);
    miss_value(miss_window, miss);
    wrefresh(cycle_window);
    wrefresh(data_window);
    wrefresh(mode_window);
    wrefresh(pc_window);
    wrefresh(ram_window);
    wrefresh(registers_window);
    wrefresh(text_window);
    wrefresh(miss_window);
}
