#include <iostream>
#include <set>
using namespace std;


void pairs(int arr[], int n, int k){
	int smallest = INT_MAX, count = 0;
	set<int> s;
	s.insert(arr[0]);
	for(int i=1;i<n;i++){
		int upper = *upper_bound(s.begin(),s.end(), k - arr[i]);
		int lower = *lower_bound(s.begin(),s.end(), k - arr[i]);

		int curr_min = min(abs(upper+arr[i] -k), abs(lower+arr[i]-k));
		if(curr_min < smallest){
			smallest = curr_min;
			count = 1;
		}
		else if(curr_min == smallest)
			count++;

		s.insert(arr[i]);
	}
	cout<<"Smallest: "<<smallest<<endl;
	cout<<"Count: "<<count<<endl;
}

int main(){ 
    int arr[] = {3, 5, 7, 5, 1, 9, 9}; 
    int k = 12; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    pairs(arr, n, k); 
    return 0; 
} 