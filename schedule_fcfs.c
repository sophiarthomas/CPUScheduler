/**
 * FCFS scheduling
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

// add a task to the list 
void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task -> name = strdup(name);
    new_task -> priority = priority; 
    new_task -> burst = burst; 
    insert(&task_list, new_task); 
}


//Your code and design here
void schedule() {
    struct node *current= task_list; 
    while(current != NULL) {
        run(current -> task, current -> task -> burst);
        current = current -> next;
    };
}