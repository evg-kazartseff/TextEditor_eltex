//
// Created by evgenii on 10.11.17.
//

#include "core.h"

int core_te(int argc, char **argv) {
    init_graphic();
    int maxx = getmaxx(stdscr);
    int maxy = getmaxy(stdscr);
    if ((maxx < 50) || (maxy < 6)) {
        dprintf(STDERR_FILENO, "Error: Can't create window!");
        return 1;
    }
    WINDOW* BottomPanel = bottom_window();
    WINDOW* TextWindow = text_window(BottomPanel);
    WINDOW* EditWindow = edit_window(TextWindow);
    FILE* file;
    char* text = NULL;
    if (argc == 2) {
        file = fopen(argv[1], "r");
        print_name_file(TextWindow, argv[1]);
        text = read_file(file);
        fclose(file);
        move(1, 1);
        wprintw(EditWindow, text);
    }
    refresh();
    handler(EditWindow, argv[1], text);
    finalize_graphic();
}

void handler(WINDOW* EditWindow, const char* file, char* text) {
    int key;
    noecho();
    volatile int x, y;
    keypad(stdscr, 1);
    raw();
    wmove(EditWindow, 0, 0);
    do {
        x = getcurx(EditWindow);
        y = getcury(EditWindow);
        key = getch();
        switch (key) {
            case KEY_F(1):
                if (text != NULL)
                    free(text);
                WINDOW* OpenFW = open_file_window(EditWindow);
                PANEL* OpenFP = open_file_panel(OpenFW);
                show_panel(OpenFP);
                update_panels();
                doupdate();
                getch();
                hide_panel(OpenFP);
                update_panels();
                doupdate();
                del_panel(OpenFP);
                delwin(OpenFW);
                refresh();
                break;
            case KEY_UP:
                move_up(EditWindow, &x, &y);
                break;
            case KEY_DOWN:
                move_down(EditWindow, &x, &y);
                break;
            case KEY_LEFT:
                move_left(EditWindow, &x, &y);
                break;
            case KEY_RIGHT:
                move_rigt(EditWindow, &x, &y);
                break;
            case KEY_F(2):

                break;
            case KEY_F(3):
                if (text != NULL)
                    free(text);
                break;
            case KEY_BACKSPACE:
                if (x != 0) {
                    move_left(EditWindow, &x, &y);
                    wdelch(EditWindow);
                }
                break;
            case KEY_DC:
                wdelch(EditWindow);
                break;
            case 10:
                move_new_line(EditWindow, &x, &y);
                break;
            default:
                if(print_symbol(key)) {
                    wprintw(EditWindow, "%c", key);
                    move_rigt(EditWindow, &x, &y);
                }
                break;
        }
        wmove(EditWindow, y, x);
        wrefresh(EditWindow);
    } while (key != KEY_F(3));
}

void move_up(WINDOW* Win, const volatile int* x, volatile int* y) {
    wmove(Win, (*y) -= 1, *x);
}

void move_down(WINDOW* Win, const volatile int* x, volatile int* y) {
    wmove(Win, (*y) += 1, *x);
}

void move_left(WINDOW* Win, volatile int* x, volatile const int* y) {
    *x = *x - 1;
    wmove(Win, *y, *x);
}

void move_rigt(WINDOW* Win, volatile int* x, volatile const int* y) {
    wmove(Win, *y, (*x) += 1);
}

void move_new_line(WINDOW* Win, volatile int* x, volatile int* y) {
    *x = 0;
    wmove(Win, (*y) += 1, *x);
}

bool print_symbol(int key) {
    if (key >= 32 && key <= 126)
        return true;
    return false;
}
