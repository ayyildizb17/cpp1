//Buse AYYILDIZ 150170099

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include<bits/stdc++.h>
using namespace std;

struct tweet{
    string tweet_id;
    string tweet_datetime;
    string tweet_unixtime;
    string artist_name;
    string track_title;
    string country;
};

void swap_func(tweet *a, tweet *b){  //swap function to swapping two values
    tweet temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
int partition(vector<tweet>& arr, int low, int high)
{
    int pivot,index;


    pivot = high;
    index = low;

    for(int i=low; i<high; i++){
        string str1 = arr[i].country;  //this part provides to convert all strings to uppercase
        string str2 = arr[pivot].country;
        string str3 = arr[i].artist_name;
        string str4 = arr[pivot].artist_name;
        string str5 = arr[i].tweet_unixtime;
        string str6 = arr[pivot].tweet_unixtime;
        transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        transform(str3.begin(), str3.end(), str3.begin(), ::toupper);
        transform(str4.begin(), str4.end(), str4.begin(), ::toupper);
        transform(str5.begin(), str5.end(), str5.begin(), ::toupper);
        transform(str6.begin(), str6.end(), str6.begin(), ::toupper);


        if(str1 < str2){        //if arr[i].country<arr[pivot].country, swap them and increment index
            swap_func(&arr[i],&arr[index]);
            index++;

        }
        else if(str1 == str2){ //if arr[i].country=arr[pivot].country, check their artist name
            if(str3 < str4){ // if arr[i].artist_name<arr[pivot].artist_name, swap them and increment index
                swap_func(&arr[i],&arr[index]);
                index++;
            }
            else if(str3 == str4){ //if arr[i].artist_name=arr[pivot].artist_name too, swap them according to their tweet_unixtime
                if(str5 < str6){
                    swap_func(&arr[i],&arr[index]);
                    index++;
                }
            }
        }
    }
    swap_func(&arr[pivot],&arr[index]);
    return index;
}
int randomPivot(vector<tweet>& arr, int low, int high){ //this part used to randomized quicksort
    int pvt,n;
    n = rand();
    //to obtain a random number between low and high
    pvt = low + n%(high-low+1);
    swap_func(&arr[high], &arr[pvt]);

    return partition(arr,low,high);
}

void QuickSort(vector<tweet>& arr, int low, int high,string algorithm_name){ //low -> starting index, high -> ending index
    int p;

    if(algorithm_name == "randomized"){
        if(low<high){
            p = randomPivot(arr,low, high);
            QuickSort(arr,low,p-1,algorithm_name); //sort elements before partition
            QuickSort(arr,p+1,high,algorithm_name); //sort elements after parititon
        }

    }
    else{
        if(low<high){
            p = partition(arr,low,high);
            QuickSort(arr,low,p-1,algorithm_name);
            QuickSort(arr,p+1,high,algorithm_name);
        }
    }

}


int main(int argc, char **argv) {
    int n;
    clock_t t_start = clock();

    string  a;
    fstream file;
    string line, data, filename,output,algorithm_name;
    vector <tweet> arr;

    a = argv[1]; //number of the tweets to be sorted
    algorithm_name = argv[2]; //name of the algorithm (randomized or deterministic)
    filename = argv[3];     //name of the input file
    output = argv[4]; //name of the output file
    n = stoi(a); //converting string to integer

    // opening file
    file.open(filename);

    int count=0;
    int i = 0;
    while (getline(file,line,'\n')&& count!=n*6) { //splitting file line by line
        i++;
        stringstream str(line);
        while(getline(str, data, '\t')) {   //splitting lines word by word
            count++; //counter shows us number of word
            if(count<=(n+1)*7 && count>=6) {
                arr.push_back(tweet());

                if (count % 7 == 1) { //because of '\n' on the end of the line, there are 7 string for each line
                    if(data!="tweet_id"){
                        arr[i - 1].tweet_id = data;
                    }
                } else if (count % 7 == 2) {
                    if(data!="tweet_datetime"){
                        arr[i - 1].tweet_datetime = data;
                    }
                } else if (count % 7 == 3) {
                    if(data!="tweet_unixtime"){
                        arr[i - 1].tweet_unixtime = data;
                    }
                } else if (count % 7 == 4) {
                    if(data!="artist_name"){
                        arr[i - 1].artist_name = data;
                    }
                } else if (count % 7 == 5) {
                    if(data!="track_title"){
                        arr[i - 1].track_title = data;
                    }
                } else if (count % 7 == 6) {
                    if(data!="country") {
                        arr[i - 1].country = data;
                    }
                }
            }
        }if(count>(n+1)*7){

            break;

        }
        count++;


    }

    QuickSort(arr,0,n-1,algorithm_name);
    clock_t t_end = clock();

    //sorted data is kept in that file
    ofstream outputFile(output);
    outputFile << "tweet_id" << '\t'<< "tweet_datetime" <<'\t'<< "tweet_unixtime" <<'\t'<< "artist_name"<<'\t'<<"track_title"<<'\t'<<"country";
    for(i=0; i<n; i++){
        outputFile<<arr[i].tweet_id<<'\t'<<arr[i].tweet_datetime<<'\t'<<arr[i].tweet_unixtime<<'\t'<<arr[i].artist_name<<'\t'<<arr[i].track_title<<'\t'<<arr[i].country<<endl;
    }
    outputFile.close();

    cout<<"Sorted in "<<100*((double(t_end-t_start))/CLOCKS_PER_SEC)<<" milisecond by using "<<algorithm_name<<" pivot selection."<<endl;

    return 0;
}
