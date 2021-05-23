/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedulers.h"


#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char str[60];

    char *name;
    int priority;
    int burst;

    in = fopen("rr-schedule.txt","r");

    if(in == NULL) {
      perror("Error opening file");
      return(-1);
   }

    while (fgets(task,SIZE,in) != NULL) {

        temp = strdup(task);
        name = strtok_r(temp,",",&temp);
        priority = atoi(strtok_r(temp,",",&temp));
        burst = atoi(strtok_r(temp,",",&temp));

        //printf("%s",name);
        //printf("%d",priority);
        //printf("%d",burst);

        // add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);
   // traverse(inicioNodo);

    // invoke the scheduler
    schedule();

    return 0;
}
