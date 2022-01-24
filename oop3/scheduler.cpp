/*
Buse AYYILDIZ
150170099
 */
 

#include <iostream>
#include <fstream>
#include "data_structs.h"

using namespace std;

Queue* readingdata(){
    ifstream data_file("data.txt");
    string name1; 
	int val;
    Queue* q = new Queue;
    q->init();
    int s_dur;

    if(data_file.is_open()){
        while(data_file >> name1 >> val) {
            s_dur = 0;
            Process* p = new Process;
            p->init();
            p->name = name1;
            p->priority = val;
            p->task_stack.init();
            data_file >> name1 >> val;
            p->arrival_time = stoi(name1);
            p->task_count = val;
            for (int i=0; i<p->task_count; i++){
                Subtask* s = new Subtask;
                s->init();
                data_file >> name1 >> val;
                s->name = name1;
                s->duration = val;
                s_dur = s_dur + s->duration;
                p->task_stack.push(s);
            }
            p->deadline = p->arrival_time + s_dur;
            q->queue(p);
        }
        data_file.close();
    }

    return q;
}

int main(){
    Queue* q1 = readingdata();                 
    int arr_time = 0;                               
    MultiQueue* multiq = new MultiQueue;           
    multiq->init();
    multiq->queue(q1->head);                  
    Process* p1 = q1->head->next;        
    q1->head->next = NULL;                 
    Process* p2 = p1;                       
    int cumul_lateness = 0;                           
    int s_cond = 0;                   
    while(!multiq->isEmpty()){                       
        while(p2){                             
            if(p2->arrival_time <= arr_time){
                multiq->queue(p2);
                p1 = p2->next;
                p2->next = NULL;
                p2 = p1;
            }
            else{
			break;
			}
        }
        if(!multiq->queues[0].isEmpty()){
            cout << multiq->queues[0].head->name << " ";
            cout << multiq->queues[0].front()->task_stack.pop(arr_time) << endl;
            if(multiq->queues[0].front()->task_stack.isEmpty()){
                cumul_lateness += arr_time - multiq->queues[0].front()->deadline;
                multiq->dequeue(1);
            }
        }
        else if(s_cond != 2 && !multiq->queues[1].isEmpty()){
            cout << multiq->queues[1].head->name << " ";
            cout << multiq->queues[1].front()->task_stack.pop(arr_time) << endl;
            if(multiq->queues[1].front()->task_stack.isEmpty()){
                cumul_lateness += arr_time - multiq->queues[1].front()->deadline;
                multiq->dequeue(2);
            }
            s_cond++;
        }
        else{
            cout << multiq->queues[2].head->name << " ";
            cout << multiq->queues[2].front()->task_stack.pop(arr_time) << endl;
            if(multiq->queues[2].front()->task_stack.isEmpty()){
                cumul_lateness += arr_time - multiq->queues[2].front()->deadline;
                multiq->dequeue(3);
            }
            s_cond = 0;
        }
    }
    cout << "Cumulative Lateness: " << cumul_lateness << endl;
}


