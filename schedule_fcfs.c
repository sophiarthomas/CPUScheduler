/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>
#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"


//Your code and design here
void schedule_fcfs() {
    struct node *current= task_list; 
    while(current != NULL) {
        run(current -> task, current -> task -> burst);
        current = current -> next;
    };
}