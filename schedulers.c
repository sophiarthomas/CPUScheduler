#include "list.h"
#include "schedulers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// add a task to the list 
void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task -> name = strdup(name);
    new_task -> priority = priority; 
    new_task -> burst = burst; 
    insert(&task_list, new_task); 
}

// invoke the scheduler
void schedule() {
}