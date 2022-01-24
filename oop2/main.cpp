#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;


struct resistor{
    char group;
    double value;
    int quantity;
    resistor *next;
};
struct circuit{
    resistor *head;
    void create();
    void add_resistor(char, double);
    void remove_resistor(char, double);
    void delete_resistor(char);
    void circuit_info();
    void clear();
};
struct resistor_value{
	double value;
	int quantity;
	resistor_value *next;
};
struct circuit_info{
resistor_value *head;
void create();
void add_resistor_value(double);
void remove_resistor_value(double);
void delete_resistor_value(double);
void info();
void clear();
};
void circuit_info::create(){
    head = NULL;
}
void circuit_info::add_resistor_value(double value){
    if(head==NULL){
        resistor_value *resist;
        resist=new resistor_value();
        resist->value=value;
        resist->quantity=1;
        resist->next=NULL;
        head=resist;
        return;

    }
    if(value<head->value){
        resistor_value *resist;
        resist=new resistor_value();
        resist->value=value;
        resist->quantity=1;
        resist->next=head;
        head=resist;
        return;
    }
    if(head->value==value){
        head->quantity=head->quantity+1;
        return;
    }

    resistor_value *temp;
    temp=head;
    resistor_value *iter;
    while(temp->next!=NULL){
        iter=temp;
        temp=temp->next;
        if(temp->value==value){
            temp->quantity=temp->quantity+1;
            return;
        }
        if(value<temp->value){
            resistor_value *resist;
            resist=new resistor_value();
            resist->value=value;
            resist->quantity=1;
     		resist->next = temp;
    		iter->next = resist;
            return;
        }
    }
    resistor_value *resist;
    resist = new resistor_value();  
	resist->value = value;
    resist->quantity = 1;
    resist->next = NULL;
	temp->next = resist;
	return;
}
void circuit_info::remove_resistor_value(double value){
    if(head==NULL){
        return;
    }
    if(head->value==value){
        head->quantity=head->quantity-1;
        return;
    }
    resistor_value *temp;
    temp=head;
    while(temp->value!=value){
        temp =temp->next;
        if(temp==NULL){
            return;
        }
    }
    if(temp->value==value){
        if(temp->quantity>1){
            temp->quantity=temp->quantity-1;
            return;
        }
        else{
            delete_resistor_value(value);
        }
    }
}

void circuit_info::delete_resistor_value(double value){
    resistor_value *temp;
    temp=head;
    if(head->value==value){
        head=head->next;
        delete temp;
        return;
    }
    resistor_value *iter;
    while(temp->value!=value){
        iter=temp;
        temp=temp->next;

    }
    iter->next=temp->next;
    delete temp;

}
void circuit_info::info(){
    resistor_value *resist;
    resist=head;
    while(resist!=NULL){
        cout<<resist->value<<":"<<resist->quantity<<endl;
        resist=resist->next;
    }

}
void circuit_info::clear(){
    resistor_value *temp;
    temp=head;
    while(head->next!=NULL){
        head = head->next;
        delete temp;
        temp=head;
    }
    delete head;
}

void circuit::create(){
    head = NULL;
}

void circuit::add_resistor(char resistor_name, double resistor_value){
    if(head == NULL){
        resistor *resist;
        resist=new resistor();
        resist->group=resistor_name;
        resist->value=resistor_value;
        resist->quantity=1;
        resist->next= NULL;
        head=resist;
        return;
    }
    
    if(head->group==resistor_name){
        head->quantity=head->quantity+1;
        return;
    }
    resistor *temp;
    temp=head;
    resistor *iter;
    while(temp->next== NULL){
        iter=temp;
        temp=temp->next;
        if(temp->group==resistor_name){
            temp->quantity=temp->quantity+1;
            return;
        }
    
        if(temp->group>resistor_name){
            resistor *resist;
            resist=new resistor();
            resist->group=resistor_name;
            resist->value=resistor_value;
            resist->quantity=1;
            resist->next=temp;
            iter->next=resist;
            return;
        }
    }
    resistor *resist;
    resist=new resistor();
    resist->group=resistor_name;
    resist->value=resistor_value;
    resist->quantity=1;
    resist->next=NULL;
    return;
}
void circuit::remove_resistor(char resistor_name, double resistor_value){

    if(head==NULL){
        cout<<"NO_RESISTOR"<<endl;
        return;
    }
    resistor *temp;
    temp=head;
    while(temp->group != resistor_name){
        temp=temp->next;
        if(temp==NULL){
            cout<<"NO_RESISTOR"<<endl;
            return;
        }
    }
    if(temp->quantity>1){
        temp->quantity=temp->quantity-1;
        return;
    }
    delete_resistor(resistor_name);    
     
    }

void circuit::delete_resistor(char resistor_name){
    resistor *temp;
    temp=head;
    if(head->group==resistor_name){
        head=head->next;
        delete temp;
        return;
    }
    resistor *iter;
    while(temp->group!=resistor_name){
        iter=temp;
        temp=temp->next;

    }
    iter->next=temp->next;
    delete temp;
    
}

void circuit::circuit_info(){
    double total_resistance=0;
    resistor *resist;
    resist=head;
    while(resist!=NULL){
        total_resistance=total_resistance+(resist->value/resist->quantity);
        resist=resist->next;
    }
    cout<<"Total resistance="<<total_resistance<<" ohm"<<endl;
}

void circuit::clear(){
    resistor *temp;
    temp=head;
    while(head->next!=NULL){
        head = head->next;
        delete temp;
        temp=head;
    }
    delete head;
}


int main(){
    circuit Circuit;
	Circuit.create();
	circuit_info Info;
	Info.create();
	const char *filename;
    FILE *input_file;
    char gr;
    double val;
    filename="input.txt";
    input_file=fopen(filename,"r");
    fseek(input_file,0,SEEK_SET);
    while(!feof(input_file)){
        fscanf(input_file,"%c %lf",&gr,&val);
        if(gr==' ' || gr=='\n')continue;
    
        if(gr=='A' && val== 0){
            Info.info();
            Circuit.circuit_info();
    }
        else if(val>0){
            Circuit.add_resistor(gr,val);
            Info.add_resistor_value(val);
    }
        else if(val<0){
            val=val*(-1);
            Circuit.remove_resistor(gr,val);
            Info.remove_resistor_value(val);
    }
    }

Circuit.clear();
Info.clear();
return 0;
}
