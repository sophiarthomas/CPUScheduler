/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.c"

//Your code and design here
void schedule_fcfs() {
    struct node *current_task = task_list; 
    while(current_task != NULL) {
        Task *task = current_task -> task; 
        run(task, task -> burst);
        current_task = current_task -> next ;

    };
}
