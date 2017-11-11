//
// Created by evgenii on 01.11.17.
//

#include "graphic.h"

WINDOW* main_window(WINDOW* win) {
    start_color();
    init_pair(1,COLOR_BLACK, COLOR_CYAN);
    wbkgd(win, COLOR_PAIR(1));
    box(win, ACS_VLINE, ACS_HLINE);
    return win;;
}

WINDOW* init_graphic() {
    return initscr();
}

int finalize_graphic() {
    return endwin();
}

WINDOW *bottom_panel(WINDOW *win) {
    short height = 3;
    WINDOW* panel = subwin(win, height, win->_maxx + 1, win->_maxy - height + 1, 0);
    box(panel, ACS_VLINE, ACS_HLINE);
    move(panel->_begy + 1, win->_begx + win->_maxx / 4 - 8);
    printw("[f1 - open file]");
    move(panel->_begy + 1, win->_begx + win->_maxx / 4 * 2 - 8);
    printw("[f2 - save file]");
    move(panel->_begy + 1, win->_begx + win->_maxx / 4 * 3 - 11/2);
    printw("[f3 - exit]");
    return panel;
}
