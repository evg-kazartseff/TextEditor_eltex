//
// Created by evgenii on 01.11.17.
//

#ifndef GRAPHIC_MAIN_H
#define GRAPHIC_MAIN_H

#include <ncurses.h>

WINDOW* main_window(WINDOW* win);
WINDOW* bottom_panel(WINDOW *win);
WINDOW* init_graphic();
int finalize_graphic();


#endif //GRAPHIC_MAIN_H
