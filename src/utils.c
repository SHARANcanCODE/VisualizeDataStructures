#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause(void) {
    printf("\nPress ENTER to continue...");
    while (getchar() != '\n');
}

void print_red(const char* text) {
    printf("\033[31m%s\033[0m", text);
}

void print_green(const char* text) {
    printf("\033[32m%s\033[0m", text);
}

void print_blue(const char* text) {
    printf("\033[34m%s\033[0m", text);
}
