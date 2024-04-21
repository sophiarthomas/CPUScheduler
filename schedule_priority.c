/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority; 
    new_task->burst = burst; 
    insert(&task_list, new_task); 
}

void schedule() {
    struct node *current = task_list;

    while (current != NULL) {
        struct node *highest_priority = current;
        struct node *temp = current->next;

        // Find the task with the highest priority
        while (temp != NULL) {
            if (temp->task->priority > highest_priority->task->priority) {
                highest_priority = temp;
            }
            temp = temp->next;
        }

        // Run the task with the highest priority
        run(highest_priority->task, highest_priority->task->burst);
        delete(&task_list, highest_priority->task);

        current = task_list;  // Start from the beginning of the list
    }
}