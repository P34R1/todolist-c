#include <conio.h>
#include <stdio.h>
#include "task.h"

void cls() {
    // Using ANSI escape sequences to clear the terminal screen
    printf_s("\033[H\033[J");
}

char description[TASK_LENGTH];

void newTodo() {
    printf_s("Description\n> ");
    scanf_s(" %[^\n]", description, TASK_LENGTH);

    cls();
    addTask(description);
}

void removeTodo() {
    printf_s("Delete\n");
    viewTasks();

    int index = _getch() - '0';  // Parsing char as int using ASCII conversion

    cls();
    deleteTask(index);
}

void toggleCompleted() {
    printf_s("Toggle Complete\n");
    viewTasks();

    int index = _getch() - '0';  // Parsing char as int using ASCII conversion

    cls();
    toggleCompletionStatus(&todoList[index]);
}
