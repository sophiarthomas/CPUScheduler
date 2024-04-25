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

struct node *task_list; 

// add a task to the list 
void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));
    new_task->name = strdup(name);
    new_task->priority = priority; 
    new_task->burst = burst; 

    // If the list is empty, make the new node the head
    if (task_list == NULL) {
        insert(&task_list, new_task);
        return;
    }

    // Find the last node in the list
    struct node *current = task_list;
    while (current->next != NULL) {
        current = current->next;
    }

    // Insert the new node after the last node
    insert(&(current->next), new_task);
}


//Your code and design here
void schedule() {
    struct node *current= task_list; 
    while(current != NULL) {
        run(current -> task, current -> task -> burst);

        delete(&task_list, current->task);

        current = task_list;  // Start from the beginning of the list
    };
}