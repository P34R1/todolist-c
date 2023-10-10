#include "task.h"
#include <stdio.h>
#include <string.h>

struct Task todoList[MAX_TASKS];
int totalTasks = 0;

void viewTasks() {
    // View tasks based on the showCompleted flag
    char todosString[MAX_TASKS * (TASK_LENGTH + COLOUR_CHARS)] = "";

    for (int i = 0; i < totalTasks; i++) {
        char todoString[TASK_LENGTH + COLOUR_CHARS];

        char* description = todoList[i].description;
        char* colour = todoList[i].completed ? GREEN : RED;

        sprintf_s(todoString, TASK_LENGTH + COLOUR_CHARS, "%d: %s%s\033[0m\n",
            i, colour, description);

        if (strcat_s(todosString, sizeof(todosString), todoString) != 0) {
            printf("Error occurred during concatenation.\n");
        }
    }

    printf_s("%s", todosString);
}

void addTask(const char* description) {
    // Check if the totalTasks is not within the maximum limit
    if (totalTasks >= MAX_TASKS) {
        printf_s("Error: Maximum number of tasks reached. Task not added.\n");
        return;
    }

    if (strlen(description) == 0) {
        printf_s("Error: Task description is invalid. Task not added.\n");
        return;
    }

    char* dest = todoList[totalTasks].description;

    // Copy the task description to the todoList
    strncpy_s(dest, TASK_LENGTH, description, _TRUNCATE);
    todoList[totalTasks].completed = false;

    // Increment the totalTasks count
    totalTasks++;

    printf_s("Task added successfully: %s\n", description);
}

void deleteTask(int taskIndex) {
    if (taskIndex < 0 || taskIndex >= totalTasks) {
        printf_s("Error: Invalid task index. Task not deleted.\n");
        return;
    }

    // Shift tasks to fill the gap created by deleting the task
    for (int i = taskIndex; i < totalTasks - 1; i++) {
        char* currDesc = todoList[i].description;
        char* nextDesc = todoList[i + 1].description;

        strncpy_s(currDesc, TASK_LENGTH, nextDesc, _TRUNCATE);

        todoList[i].completed = todoList[i + 1].completed;
    }

    // Decrement the totalTasks count after deleting the task
    totalTasks--;

    printf("Task at index %d deleted successfully.\n", taskIndex);
}

void toggleCompletionStatus(struct Task* task) {
    task->completed = !task->completed;
}
