/**
 * Round-robin scheduling
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "cpu.h"
#include "schedulers.h"

int TIME_QUANTUM = 10; 

void add(char *name, int priority,int burst) {
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

void schedule() {
    struct node *current = task_list;
    Task* temp; 
    while (task_list != NULL) {
        while (current != NULL) {
            if (current->task->burst > TIME_QUANTUM) {
                // Run the task for the TIME_QUANTUMA
                run(current->task, TIME_QUANTUM);
                // Update burst time 
                current->task->burst -= TIME_QUANTUM;
                temp = current->task;
                // Move task to the end of the list
                add(temp->name, temp->priority, temp->burst);
                delete(&task_list, current->task);
                // traverse(current);
                // traverse(task_list);
            } else {
                // Run task for the remaining burst time 
                run(current->task, current->task->burst);
                current->task->burst = 0;
                delete(&task_list, current->task); 
            }    
            current = current -> next;
        }  
        current = task_list;  
    }   
}