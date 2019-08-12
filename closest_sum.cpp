#include <iostream>
#include <climits>
using namespace std;

void print_closest(int arr1[], int arr2[], int m, int n, int x){
	int l=0, r = n-1;
	int idx1, idx2;
	int diff = INT_MAX;
	
	while(l<m && r>=0){
		if (abs(arr1[l]+arr2[r] - x) < diff){
			idx1 = l;
			idx2 = r;
			diff = abs(arr1[l]+arr2[r] - x);
		}
		else if((arr1[l]+arr2[r]) < x)
			l++;
		else
			r--;
	}
	
	cout<<"Pair is " << arr1[idx1] << " and " << arr2[idx2];
}

int main() {
	int ar1[] = {1, 4, 5, 7}; 
    int ar2[] = {10, 20, 30, 40}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]); 
    int x = 38; 
    print_closest(ar1,ar2,m,n,x);
	return 0;
}

//Complexity: O(n)