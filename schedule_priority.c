/*
 * Priority scheduling
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

void schedule_pri() {
    struct node *current = task_list;

    while (current != NULL) {
        struct node *highest_priority = current;
        struct node *temp = current->next;

        // Find the task with the highest priority
        while (temp != NULL) {
            if (temp->task->priority < highest_priority->task->priority) {
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