#include <ncurses.h>
#include "screen.h"

void data_labels (WINDOW *window) {
    mvwprintw(window, 0, 7, "DATA");
    mvwprintw(window, 1, 1, "0");
    mvwprintw(window, 2, 1, "4");
    mvwprintw(window, 3, 1, "8");
    mvwprintw(window, 4, 1, "C");
    mvwprintw(window, 5, 1, "10");
    mvwprintw(window, 6, 1, "14");
    mvwprintw(window, 7, 1, "18");
    mvwprintw(window, 8, 1, "1C");
    mvwprintw(window, 9, 1, "20");
    mvwprintw(window, 10, 1, "24");
    mvwprintw(window, 11, 1, "28");
    mvwprintw(window, 12, 1, "2C");
    mvwprintw(window, 13, 1, "30");
    mvwprintw(window, 14, 1, "34");
    mvwprintw(window, 15, 1, "38");
    mvwprintw(window, 16, 1, "3C");
    mvwprintw(window, 17, 1, "40");
    mvwprintw(window, 18, 1, "44");
    mvwprintw(window, 19, 1, "48");
    mvwprintw(window, 20, 1, "4C");
    mvwprintw(window, 21, 1, "50");
    mvwprintw(window, 22, 1, "54");
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
    mvwprintw(window, 17, 10, "%8X", values[16]);
    mvwprintw(window, 18, 10, "%8X", values[17]);
    mvwprintw(window, 19, 10, "%8X", values[18]);
    mvwprintw(window, 20, 10, "%8X", values[19]);
    mvwprintw(window, 21, 10, "%8X", values[20]);
    mvwprintw(window, 22, 10, "%8X", values[21]);
}

void mode_label (WINDOW *window) {
    mvwprintw(window, 0, 11, "%s", "MODE");
}

void mode_value (WINDOW *window, unsigned int value) {
    mvwprintw(window, 1, 10, "%s", "default");
}

void pc_label (WINDOW *window) {
    mvwprintw(window, 0, 12, "%s", "PC");
}

void pc_value (WINDOW *window, unsigned int value) {
    mvwprintw(window, 1, 10, "%8X", value);
}

void ram_labels (WINDOW *window) {
    mvwprintw(window, 0, 8, "RAM");
    mvwprintw(window, 1, 1, "0");
    mvwprintw(window, 2, 1, "4");
    mvwprintw(window, 3, 1, "8");
    mvwprintw(window, 4, 1, "C");
    mvwprintw(window, 5, 1, "10");
    mvwprintw(window, 6, 1, "14");
    mvwprintw(window, 7, 1, "18");
    mvwprintw(window, 8, 1, "1C");
    mvwprintw(window, 9, 1, "20");
    mvwprintw(window, 10, 1, "24");
    mvwprintw(window, 11, 1, "28");
    mvwprintw(window, 12, 1, "2C");
    mvwprintw(window, 13, 1, "30");
    mvwprintw(window, 14, 1, "34");
    mvwprintw(window, 15, 1, "38");
    mvwprintw(window, 16, 1, "3C");
    mvwprintw(window, 17, 1, "40");
    mvwprintw(window, 18, 1, "44");
    mvwprintw(window, 19, 1, "48");
    mvwprintw(window, 20, 1, "4C");
    mvwprintw(window, 21, 1, "50");
    mvwprintw(window, 22, 1, "54");
}

void ram_values (WINDOW *window, unsigned int *values) {
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
    mvwprintw(window, 17, 10, "%8X", values[16]);
    mvwprintw(window, 18, 10, "%8X", values[17]);
    mvwprintw(window, 19, 10, "%8X", values[18]);
    mvwprintw(window, 20, 10, "%8X", values[19]);
    mvwprintw(window, 21, 10, "%8X", values[20]);
    mvwprintw(window, 22, 10, "%8X", values[21]);
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
    mvwprintw(window, 0, 7, "TEXT");
    mvwprintw(window, 1, 1, "0");
    mvwprintw(window, 2, 1, "4");
    mvwprintw(window, 3, 1, "8");
    mvwprintw(window, 4, 1, "C");
    mvwprintw(window, 5, 1, "10");
    mvwprintw(window, 6, 1, "14");
    mvwprintw(window, 7, 1, "18");
    mvwprintw(window, 8, 1, "1C");
    mvwprintw(window, 9, 1, "20");
    mvwprintw(window, 10, 1, "24");
    mvwprintw(window, 11, 1, "28");
    mvwprintw(window, 12, 1, "2C");
    mvwprintw(window, 13, 1, "30");
    mvwprintw(window, 14, 1, "34");
    mvwprintw(window, 15, 1, "38");
    mvwprintw(window, 16, 1, "3C");
    mvwprintw(window, 17, 1, "40");
    mvwprintw(window, 18, 1, "44");
    mvwprintw(window, 19, 1, "48");
    mvwprintw(window, 20, 1, "4C");
    mvwprintw(window, 21, 1, "50");
    mvwprintw(window, 22, 1, "54");
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
    mvwprintw(window, 17, 10, "%8X", values[16]);
    mvwprintw(window, 18, 10, "%8X", values[17]);
    mvwprintw(window, 19, 10, "%8X", values[18]);
    mvwprintw(window, 20, 10, "%8X", values[19]);
    mvwprintw(window, 21, 10, "%8X", values[20]);
    mvwprintw(window, 22, 10, "%8X", values[21]);
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
