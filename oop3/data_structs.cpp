/*
Buse AYYILDIZ
150170099
 */

#include <iostream>
#include "data_structs.h"

using namespace std;

void Subtask::init() {
	next = NULL;
	}

void Stack::init(){
	head = NULL;
	}
void Process::init() {
	next = NULL;
	}

void Queue::init() {
	head = NULL;
	}
	
void MultiQueue::init() {
	
	int i;
    for(i=0; i<3; i++){
        queues[i].init();
    }
}
	
bool Stack::isEmpty() {
	if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
	

bool Queue::isEmpty() {
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}

bool MultiQueue::isEmpty() {
	
	int i;
	
    for (i=0; i<3; i++){
        if(queues[i].head){
		return false;
		}
    }
    return true;
}

void Stack::push(Subtask *s) {
    if(isEmpty()){
       
	    head = s;
    }
    else{
    	
        Subtask* s2 = head;
        
        while(s2->next){
            s2 = s2->next;
        }
        
        s2->next = s;
    }
}

string Stack::pop(int& arr_time) {
    string node;
    if(!head->next){
        node = head->name;
        arr_time += head->duration;
        delete head;
        head = NULL;
    }
    else{
        Subtask* s = head;
        while(s->next){
            if(s->next->next){
                s = s->next;
            }
            else{
                break;
            }
        }
        node = s->next->name;
        arr_time += s->next->duration;
        delete s->next;
        s->next = NULL;
    }
    return node;
}


void Queue::queue(Process *p) {
    if(isEmpty()){
        head = p;
    }
    else{
        Process* p2 = head;
        while(p2->next){
            p2 = p2->next;
        }
        p2->next = p;
    }
}

Process* Queue::front() {
	return head;
	}



void MultiQueue::queue(Process *p) {
    if(queues[p->priority-1].isEmpty()){
        queues[p->priority-1].head = p;
    }
    else{
        Process* p2 = queues[p->priority-1].head;
        while(p2->next){
            p2 = p2->next;
        }
        p2->next = p;
    }
}

void MultiQueue::dequeue(int pri) {
    Process* p;
    if(!queues[pri-1].head->next){
        delete queues[pri-1].head;
        queues[pri-1].head = NULL;
    }
    else{
        p = queues[pri-1].head->next;
        delete queues[pri-1].head;
        queues[pri-1].head = p;
    }
}



