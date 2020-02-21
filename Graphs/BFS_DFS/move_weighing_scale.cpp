#include <iostream>
using namespace std;

bool dfs(int residue, int currStep, int wt[], int arr[], int N, int steps){
	if(currStep > steps)
		return true;

	for(int i=0;i<N;i++){
		if(residue < arr[i] && arr[i] != wt[currStep -1]){
			wt[currStep] = arr[i];

			if(dfs(wt[currStep] - residue, currStep+1,wt,arr,N,steps))
				return true;
		}
	}
	return false;
}

void printWeightsOnScale(int arr[], int N, int steps){
	int wt[steps];
	for(int i=0;i<steps;i++)
		wt[i] = 0;

	if(dfs(0,0,wt,arr,N,steps)){
		for(int i=0;i<steps;i++)
			cout<<wt[i]<<" ";
	}
	else
		cout<<"Not Possible";
}

int main(){
	int arr[] = {2, 3, 5, 6}; 
    int N = sizeof(arr) / sizeof(int); 
  
    int steps = 10; 
    printWeightsOnScale(arr, N, steps); 
    return 0; 
}