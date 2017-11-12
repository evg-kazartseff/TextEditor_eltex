//
// Created by evgenii on 01.11.17.
//

#include "graphic.h"

WINDOW* init_graphic() {
    WINDOW* main = initscr();
    start_color();
    init_pair(1,COLOR_BLACK, COLOR_CYAN);
    wbkgd(main, COLOR_PAIR(1));
    return main;
}

int finalize_graphic() {
    return endwin();
}

WINDOW *bottom_window() {
    short height = 3;
    WINDOW* panel = subwin(stdscr, height, stdscr->_maxx, stdscr->_maxy - height +1, 0);
    box(panel, ACS_VLINE, ACS_HLINE);
    move(panel->_begy + 1, stdscr->_begx + stdscr->_maxx / 4 - 8);
    printw("[f1 - open file]");
    move(panel->_begy + 1, stdscr->_begx + stdscr->_maxx / 4 * 2 - 8);
    printw("[f2 - save file]");
    move(panel->_begy + 1, stdscr->_begx + stdscr->_maxx / 4 * 3 - 11/2);
    printw("[f3 - exit]");
    wrefresh(panel);
    return panel;
}

void print_name_file(WINDOW* win, const char *name) {
    size_t lenght = strlen(name);
    if(lenght < win->_maxx - 4) {
        move(0, win->_maxx / 2 - (int) lenght / 2);
        printw(" ");
        printw(name);
        printw(" ");
    }
}

WINDOW *text_window(WINDOW* BottomP) {
    WINDOW* text = subwin(stdscr, stdscr->_maxy - BottomP->_maxy, stdscr->_maxx, 0, 0);
    box(text, ACS_VLINE, ACS_HLINE);
    wrefresh(text);
    return text;
}

WINDOW* edit_window(WINDOW* TextWindow) {
    return subwin(TextWindow, TextWindow->_maxy - 1, TextWindow->_maxx - 1,
                  TextWindow->_begy + 1, TextWindow->_begx + 1);
}

WINDOW* open_file_window(WINDOW* TextWindow) {
    int k = 2;
    int j = 3;
    WINDOW* win = subwin(TextWindow, TextWindow->_maxy / k,
                         TextWindow->_maxx / j,
                         TextWindow->_maxy / 2 - TextWindow->_maxy / (2 * k),
                         TextWindow->_maxx / 2 - TextWindow->_maxx / (2 * j));
    box(win, ACS_VLINE, ACS_HLINE);
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    wbkgd(win, COLOR_PAIR(2));
    return win;
}

PANEL* open_file_panel(WINDOW* OpenFileWindow) {
    return new_panel(OpenFileWindow);
}
