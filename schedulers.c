#include "schedulers.h"


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
struct node *copia=inicioNodo;
Task *taskt;
    while(inicioNodo != NULL){

        run(inicioNodo->task,10);
        inicioNodo->task->burst-=10;

        if (inicioNodo->task->burst<=0)
            delete(&copia,inicioNodo->task);
            /*if (taskt->burst>=0)
                insert(&copia,taskt);*/

        if(inicioNodo->next==NULL){
            inicioNodo=copia;
        }else{
            inicioNodo=inicioNodo->next;
        }

    }

}
