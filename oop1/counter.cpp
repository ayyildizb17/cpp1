/*
YOU HAVE TO WRITE THE REQUIRED  FUNCTIONS. YOU CAN ADD NEW FUNCTIONS IF YOU NEED.
*/
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;

	
int Counter::findindex(Token *arr,char elem[]){
	int i;
	for(i=0;i<100;i++){
		if(arr[i].token[0]==elem[0] && arr[i].token[1]==elem[1]){

			return i;
		}
	}
	return -1;
	
	
	

	
} 

bool Counter::contains(char *token, char target){
	int i;
	
	for(i=0;i<2 ;i++){
		if(token[i]==target){
			return true;
		}
				
	}
	return false;
			
}
	
	



void Counter::read_and_count(){
	
	char k[102];
	int i,temp_count;
	int j=0;
	filename="pi_approximate";
	pi_file=fopen(filename,"r");
	fseek(pi_file,0,SEEK_SET);
	char temp[2];
	
	while(!feof(pi_file)){
		fread(&k,sizeof(k),1,pi_file);
		if(feof(pi_file)) break;
	}
	

	
	for(i=0;i<102;i++){
		
		temp[0]=k[i];
		temp[1]=k[i+1];
		if(contains(temp,'.'))continue;
		if(temp[0]=='\0' || temp[1]=='\0')continue;
		
		token_array[j].token[0]=temp[0];
		token_array[j].token[1]=temp[1];
		j++;
		
	}
	token_count=j;
	for(i=0;i<token_count;i++){
		temp[0]=token_array[i].token[0];
		temp[1]=token_array[i].token[1];
		temp_count=0;
		for(j=0;j<token_count;j++){
			if(token_array[j].token[0]==temp[0]&& token_array[j].token[1]==temp[1])temp_count++;
		}
		token_array[i].count=temp_count;
	}
		
}





Token *Counter::get_most_common_three(){
    int i,j;
    Token temp;
    Token *token_list = new Token[3];

    for(i=0;i<100;i++){
        for(j=0;j<99;j++){
            if(token_array[i].count>token_array[j].count){
                temp=token_array[j];
                token_array[j]=token_array[i];
                token_array[i]=temp;
            }
        }
    }
    token_list[0]=token_array[0];
    for(i=0;i<100;i++){
        if(token_list[0].token[0]!=token_array[i].token[0] && token_list[0].token[1]!=token_array[i].token[1]){
            token_list[1]=token_array[i];
            break;
        }
    }
    for(j=i;j<100;j++){
        if(token_list[1].token[0]!=token_array[j].token[0] && token_list[1].token[1]!=token_array[j].token[1]){
            token_list[2]=token_array[j];
            break;
        }
    }

    return token_list;

}

