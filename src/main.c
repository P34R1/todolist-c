#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include "task.h"
#include "ui.h"

#define INSTRUCTIONS "'A'dd 'D'elete 'T'oggle complete 'Q'uit\n"

enum options {
    ADD = 'a',
    DELETE = 'd',
    TOGGLE = 't',
    QUIT = 'q',
};

int main() {
    addTask("Learn C");

    cls();
    while (true) {
        printf_s(INSTRUCTIONS);
        viewTasks();

        char ch = tolower(_getch());  // Wait for a key press

        cls();

        switch (ch) {
            case QUIT:
                return 0;
            case ADD:
                newTodo();
                break;
            case DELETE:
                removeTodo();
                break;
            case TOGGLE:
                toggleCompleted();
                break;
            default:
                printf_s("'%c' is not an option\n", ch);
                break;
        }
    }
}
