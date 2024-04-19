/**
 * Round-robin scheduling
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

int TIME_QUANTUM = 10; 

void schedule_rr() {
    struct node *current = task_list;

    while (current != NULL) {
        if (current->task->burst > TIME_QUANTUM) {
            run(current->task, TIME_QUANTUM);
            current->task->burst -= TIME_QUANTUM;
        } else {
            run(current->task, current->task->burst);
            current->task->burst = 0;
        }

        if (current->task->burst > 0) {
            // Move the task to the end of the list
            delete(&task_list, current->task);
            insert(&task_list, current->task);
        }

        current = current->next;
    }
}