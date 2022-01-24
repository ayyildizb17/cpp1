//Buse AYYILDIZ
//150170099


#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;

struct vehicles{
    int vehicle_id;
    string veh_location;
    double veh_distance;
    double speed;
    double time;

};

void swap(vehicles *a, vehicles *b){ //to swap 2 vehicles locations on the vector
    vehicles temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

void decreaseTime(vector<vehicles> &hT,int i, int newVal) //decrease key function
{
    hT[i].time = newVal;
    while (i != 0 && hT[(i-1)/2].time > hT[i].time)
    {
        swap(hT[i], hT[(i-1)/2]);
        i = (i-1)/2;
    }
}

void min_heapify(vector<vehicles> &hT, int i,int n) { // to heapify the tree


    int smallest = i;
    int l = 1 + 2*i; //left cihld
    int r = 2 + 2*i; // right child


    if (l < n && hT[l].time< hT[smallest].time){ //when left child < vector size, if left child's key < smallest's key
        smallest = l; //smallest = left child
    }
    if (r < n && hT[r].time< hT[smallest].time){ //when right child < vector size, if right child's key < smallest's key
        smallest = r;   //smallest = right child
    }
    if (smallest != i) {
        swap(hT[i], hT[smallest]);
        min_heapify(hT, smallest,n);
    }
}

void insert(vector<vehicles> &hT, vehicles newVehicles,int n) {
    int i = n;
    hT.push_back(newVehicles); //push the new vehicle to the back of hT
        while (i != 0 && hT[(i-1)/2].time > hT[i].time) // to control min heap
        {
           swap(&hT[i], &hT[(i-1)/2]);
           i = (i-1)/2; //parent
        }
}

vehicles extractMin(vector<vehicles> &hT, int n)
{

    vehicles result = hT[0]; //the element which is extracted
    hT[0] = hT.back();
    hT.pop_back();
    min_heapify(hT,0,hT.size());
    return result;
}

void buildHeap(vector<vehicles> &hT){ //to build a min heap from a vector
    for(int i=hT.size()-1; i>=0; i--){
        min_heapify(hT,i,hT.size());
    }
}



int main(int argc, char **argv) {


    int N; //size of the requests
    vector<vehicles> hT; //heap tree vector
    string a = argv[1];
    N = stoi(a);
    ifstream vehicles_file;
    vehicles_file.open("vehicles.txt");

    string line;

    int id; //vehicle id
    string location; //vehicle location
    double distance,speed; //vehicle speed

    vehicles_file >> line >> line >> line >> line;      //to pass the first line

    while(vehicles_file >> id >> location >> distance >> speed){
        vehicles vehicle;                                        //vehicle object
        vehicle.vehicle_id = id;
        vehicle.veh_location = location;
        vehicle.veh_distance = distance;
        vehicle.speed = speed;
        vehicle.time = distance/speed;
        hT.push_back(vehicle); // push back vehicle in hT
    }
    vehicles_file.close();
    buildHeap(hT);

    int i=0;
    ifstream request_file;
    request_file.open("requests.txt");
    request_file >> line >> line >> line;
    vector<int> callHist; //call History vector

    clock_t t_start = clock();
    while(i<N) {

        string loc; //customer location
        double dist; //customer distance
        int luckyNum; //customer's lucky number


        request_file>>loc>>dist>>luckyNum;
        if(luckyNum!=0){ //if customer have a lucky number, we have to extract hT[luckyNum]
            decreaseTime(hT,luckyNum,0); //because of this, we decrease the key of hT[luckyNum]
            i++;
        }
        vehicles vec1 = extractMin(hT, hT.size()); //to extract min
        i++;
        vec1.veh_location = loc;
        vec1.veh_distance = dist;
        vec1.time =dist/vec1.speed;
        insert(hT,vec1,hT.size());
        i++;
        callHist.push_back(vec1.vehicle_id); //push the vehicle id to call history vector

    }
    clock_t t_end = clock();
    request_file.close();


    ofstream call_history;
    call_history.open("call_history.txt");
    
    for(int i=0; i<callHist.size(); i++){
        call_history<<callHist[i]<<endl; //to write the file
    }

    cout<<"Running in "<<100*((double(t_end-t_start))/CLOCKS_PER_SEC)<<" milisecond"<<endl;
    return 0;
}

