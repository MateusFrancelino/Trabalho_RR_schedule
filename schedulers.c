#include "schedulers.h"

#define QUANTUM 7
struct node *inicioNodo=NULL;
int temp=0;

void add(char *name, int priority, int burst){
    Task *taskt = malloc(sizeof(Task));
    taskt->name = name;
    printf("%s \n",taskt->name);
    taskt->burst = burst;
    taskt->priority = priority;
    insert(&inicioNodo,taskt);
    //traverse(inicioNodo);

}


// invoke the scheduler
void schedule(){
    int currentTime = 0;
    int taskCounter = 0;
    float turnAroundSum = 0;
    float turnAroundAvg = 0;

    struct node *copia=inicioNodo;
Task *taskt;
    while(inicioNodo != NULL){
        if(inicioNodo->task->burst < QUANTUM){
            currentTime += inicioNodo->task->burst;
            run(inicioNodo->task,inicioNodo->task->burst);
            inicioNodo->task->burst -= inicioNodo->task->burst;
        }
        else{
            currentTime += QUANTUM;
            run(inicioNodo->task,QUANTUM);
            inicioNodo->task->burst-=QUANTUM;
        }
        if (inicioNodo->task->burst<=0){
            taskCounter += 1;
            turnAroundSum += currentTime;
            delete(&copia,inicioNodo->task);
        }
        if(inicioNodo->next==NULL){
            inicioNodo=copia;
        }else{
            inicioNodo=inicioNodo->next;
        }

    }
    turnAroundAvg = turnAroundSum/taskCounter;
    printf("\n Turn Around AVG = %f", turnAroundAvg);

}
