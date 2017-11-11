//
// Created by evgenii on 10.11.17.
//

#include "core.h"

int core_te() {
    WINDOW* MainWindow = init_graphic();
    int maxx = getmaxx(stdscr);
    int maxy = getmaxy(stdscr);
    if ((maxx < 50) || (maxy < 6)) {
        dprintf(STDERR_FILENO, "Error: Can't create window!");
        return 1;
    }
    MainWindow = main_window(MainWindow);

    WINDOW* BottomPanel = bottom_panel(MainWindow);
    refresh();
    while (1) {
        getch();
        clear();
        MainWindow = main_window(MainWindow);

        BottomPanel = bottom_panel(MainWindow);
        refresh();
    }

    finalize_graphic();
}