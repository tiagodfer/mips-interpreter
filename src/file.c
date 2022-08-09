#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "file.h"
#include "constants.h"


FILE *file_read () {
    FILE *file;
    char file_name[LENGHT];
    WINDOW *load_window = newwin(5, 35, 10, 25);
    refresh();
    box(load_window, 0, 0);
    mvwprintw(load_window, 1, 1, "Which file to load?");
    wrefresh(load_window);
    echo();
    curs_set(1);
    mvwscanw(load_window, 2, 1, " %[^\n]", file_name);
    file = fopen(file_name, "r");
    noecho();
    if (file) {
        mvwprintw(load_window, 3, 1, "Loaded succesfully!");
    } else {
        mvwprintw(load_window, 3, 1, "Couldn't load!");
        file = NULL;
    }
    wgetch(load_window);
    curs_set(0);
    wclear(load_window);
    wrefresh(load_window);
    delwin(load_window);
    return file;
}
