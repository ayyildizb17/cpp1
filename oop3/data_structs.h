/*
Buse AYYILDIZ
150170099
 */


#include <iostream>

using namespace std;

struct Subtask{
    string name;
    int duration;
    Subtask* next;
    void init();
};
struct Stack{
    Subtask* head;
    void init();
    void push(Subtask*);
    string pop(int&);
    bool isEmpty();
};
struct Process{
    string name;
    int arrival_time;
    int deadline;
    int task_count;
    int priority;
    Stack task_stack;
    Process* next;
    void init();
};
struct Queue{
    Process* head;
    void init();
    void queue(Process* in);
    bool isEmpty();
    Process* front();
};
struct MultiQueue{
    Queue queues[3];
    void init();
    void queue(Process* in);
    void dequeue(int priority);
    bool isEmpty();
};
