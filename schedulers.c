#include "schedulers.h"
#define QUANTUM 25
struct node *inicioNodo=NULL;
int temp=0;

void add(char *name, int priority, int burst){
    Task *taskt = malloc(sizeof(Task));
    taskt->name = name;
    taskt->burst = burst;
    taskt->priority = priority;
    insert(&inicioNodo,taskt);
}

// invoke the scheduler
void schedule(){

    int currentTime = 0;
    int taskCounter = 0;
    float turnAroundSum = 0;
    float turnAroundAvg = 0;




    struct node *copia=inicioNodo;
    struct node *anterior;
    Task *taskt;
    while(inicioNodo != NULL){
        if(inicioNodo->next!=NULL){
            if(inicioNodo->task->priority==inicioNodo->next->task->priority&&inicioNodo->task->burst>0){
                anterior=inicioNodo;
                while(inicioNodo->task->burst>0){




                if(inicioNodo->task->burst < QUANTUM && inicioNodo->task->burst >0 ){

                    currentTime += inicioNodo->task->burst;
                    run(inicioNodo->task,inicioNodo->task->burst);
                    inicioNodo->task->burst -= inicioNodo->task->burst;
                    }
                else{

                    currentTime += QUANTUM;
                    run(inicioNodo->task,QUANTUM);
                    inicioNodo->task->burst-=QUANTUM;
                    }


                    if(inicioNodo->task->priority!=inicioNodo->next->task->priority){
                        inicioNodo=anterior;
                    }else{
                    inicioNodo=inicioNodo->next;
                    }
                }


            }else{
                if(inicioNodo->task->burst>0){
                 currentTime += inicioNodo->task->burst;
                run(inicioNodo->task,inicioNodo->task->burst);
            inicioNodo->task->burst-=inicioNodo->task->burst;
            }

            if (inicioNodo->task->burst<=0){
                taskCounter += 1;
                turnAroundSum += currentTime;
                //delete(&copia,inicioNodo->task);

                }

            inicioNodo=inicioNodo->next;
            }
        }else{
            if(inicioNodo->task->burst>0){
                 currentTime += inicioNodo->task->burst;
                run(inicioNodo->task,inicioNodo->task->burst);
            inicioNodo->task->burst-=inicioNodo->task->burst;
            }

            if (inicioNodo->task->burst<=0){
                taskCounter += 1;
                turnAroundSum += currentTime;
                //delete(&copia,inicioNodo->task);

                }

            inicioNodo=inicioNodo->next;
        }
    }
        turnAroundAvg = turnAroundSum/taskCounter;
    printf("\n Turn Around AVG = %f", turnAroundAvg);
}
