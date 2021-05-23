
#define MIN_PRIORITY 1
#define MAX_PRIORITY 10


#include "list.h"

struct node *inicioNodo=NULL;
int temp=0;

// add a task to the list
void add(char *name, int priority, int burst){

    Task *taskt = malloc(sizeof(Task));;
    printf("%d \n", taskt);
    taskt->name = name;
    printf("%s", name);
    taskt->burst = burst;
    taskt->priority = priority;
    insert(&inicioNodo,taskt);








    //printf("oi");
    //printf("%d \n", &teste);
    //printf("%d \n", &taskt);



    //printf("oi");
}


// invoke the scheduler
void schedule();
