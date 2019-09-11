#include <iostream>
#include <algorithm>
using namespace std;

struct job{
	char job_id;
	int deadline;
	int pri;
};

int comp(job a, job b){
	return a.pri > b.pri;	
}

void print_scheduling(job arr[], int n){
	sort(arr, arr+n,comp);
	int result[n];
	bool slot[n];
	
	for (int i = 0;i<n; i++)
		slot[i] = false;
		
	for (int i = 0; i<n; i++){
		for(int j=min(n,arr[i].deadline)-1;j>=0;j--){
			if(slot[j] == false){
				result[j] = i;
				slot[j]= true;
				break;
			}
		}
	}
	for (int k=0;k<n;k++){
		if(slot[k])
			cout<<arr[result[k]].job_id<<"\t";
	}
}

int main() {
	job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    print_scheduling(arr,n);
	return 0;
}

//complexity: O(n^2)