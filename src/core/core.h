//
// Created by evgenii on 10.11.17.
//

#ifndef TEXT_EDITOR_CORE_H
#define TEXT_EDITOR_CORE_H

#include "../graphic/graphic.h"
#include "IOfile.h"
#include <zconf.h>
#include <stdbool.h>


int core_te(int argc, char **argv);
void handler(WINDOW* EditWindow, const char* file, char* text);
void move_up(WINDOW* Win, volatile const int *x, volatile int *y);
void move_down(WINDOW* Win, volatile const int *x, volatile int *y);
void move_left(WINDOW* Win, volatile int* x, volatile const int* y);
void move_rigt(WINDOW* Win, volatile int* x, volatile const int* y);
void move_new_line(WINDOW* Win, volatile int* x, volatile int* y);
bool print_symbol(int key);

#endif //TEXT_EDITOR_CORE_H
