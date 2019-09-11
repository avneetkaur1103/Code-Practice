#include <iostream>
#include <algorithm>
using namespace std;

int no_of_platforms(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep,dep+n);
	
	int result = 1, plat_req=1;
	int i=1, j=0;
	while(i<n && j<n){
		if(arr[i]<=dep[j]){
			plat_req++;
			i++;
			
			if(result<plat_req)
				result = plat_req;
		}
		else{
			plat_req--;
			j++;
		}
	}
	return result;
}

int main() {
	int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<no_of_platforms(arr,dep,n);
	return 0;
}

//Complexity:O(nlogn)