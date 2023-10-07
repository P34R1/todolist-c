#ifndef TASK_H
#define TASK_H

#include <stdbool.h>

#define MAX_TASKS 100
#define TASK_LENGTH 30

#define COLOUR_CHARS 15

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

struct Task {
    char description[TASK_LENGTH];
    bool completed;
};

extern struct Task todoList[MAX_TASKS];
extern int totalTasks;

void viewTasks();
void addTask(const char* description);
void deleteTask(int taskIndex);
void toggleCompletionStatus(struct Task* task);

#endif  // TASK_H
