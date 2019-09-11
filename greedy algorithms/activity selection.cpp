#include <iostream>
#include <algorithm>
using namespace std;

struct act{
	int start;
	int finish;
};

bool compare(struct act s1, struct act s2){
	return s1.finish < s2.finish;
}

void act_selection(act arr[], int n){
	sort(arr, arr+n, compare);
	int i = 0;
	cout<<"("<<arr[i].start << ", "<<arr[i].finish <<")"<<endl;
	for (int j=1;j<n;j++){
		if(arr[i].finish <= arr[j].start){
			cout<<"("<<arr[j].start << ", "<<arr[j].finish <<")"<<endl;
			i=j;
		}
	}
}
int main() {
	act arr[]={{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
	int n = sizeof(arr)/sizeof(arr[0]);
	act_selection(arr,n);
	return 0;
}

//Complexity:O(nlogn) - unsorted, O(n) - sorted