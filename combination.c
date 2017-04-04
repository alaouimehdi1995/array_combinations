#include <stdio.h>
#include <stdlib.h>


int length(int* T);
int* _switch(int* T,int i,int j);
void print_array(int* T,int n);
void combination(int* T,int n,int i);

// The function below switch elements i and j from the array T given
int* _switch(int* T,int i,int j){
	
	int Temp=T[i];
	T[i]=T[j];
	T[j]=Temp;
	return T;

}
// The function below prints the array given as parameter

void print_array(int* T,int len_T){
	int i;
	for(i=0;i<len_T;i++)
		printf("%d ", T[i]);
	
	printf("\n");
}


/*
	This function is recursive. it returns all combinations except T itself
	The pivot is the first element which will be switched with all elements after
	example: for T={0,1,2,3} with 1 as pivot, means that 1 will be switched with 2 and 3 (as result: {0,2,1,3} and {0,3,2,1} )
	the function calls itself with the same array, and the pivot moved to the right.
	for a fixed pivot, we switch it with all elements after (as shown in the ex. before), and for every switch,
	then the function call itself with the pivot moved to the right.
	
	*/


void combination(int* T,int len_T,int pivot){
	
	if(pivot==0)
		print_array(T,len_T);
	
	if(pivot<len_T-1){

		combination(T,len_T,pivot+1);
		int j;
		
		for(j=pivot+1;j<len_T;j++){

			T=_switch(T,pivot,j);
			print_array(T,len_T);
			combination(T,len_T,pivot+1);
			T=_switch(T,j,pivot);

		}

	}

}




int main(){
	int START_PIVOT=0;
	int T[]={1,2,3,4,5}; // The array that we would find all combinations
	int n=5; // The array length
	combination(T,n,START_PIVOT);
	return 0;
}