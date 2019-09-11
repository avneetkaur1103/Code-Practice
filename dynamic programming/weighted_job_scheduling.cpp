#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct Job{
	int start, finish, profit;
};

/*int max(int a, int b){
	return (a>b)?a:b;
}*/

bool jobcomp(struct Job s1, struct Job s2){
	return (s1.finish < s2.finish);
}

int latestnonconflictingjob(struct Job arr[], int i){
	for (int j=i-1;j>=0;j--){
		if(arr[i].start>=arr[j].finish)
			return j;
	}	
	return -1;
}

int weighted_job_scheduling(struct Job  arr[], int n){
	sort(arr, arr+n,jobcomp);
	int prof[n];
	memset(prof,0,sizeof(prof));
	
	//int *prof = new int[n];
	prof[0] = arr[0].profit;
	for (int i=1;i<n;i++){
		int incl = arr[i].profit;
		int l = latestnonconflictingjob(arr,i);
		if(l != -1)
			incl += prof[l];
		
		prof[i] = max(incl,prof[i-1]);
	}
	int res = prof[n-1];
	//delete[] prof;
	return res;
}

int main() {
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The maximum optimal profit is : "<< weighted_job_scheduling(arr, n);
	return 0;
}

//Complexity: O(n^2)