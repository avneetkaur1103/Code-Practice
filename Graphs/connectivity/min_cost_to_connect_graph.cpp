#include <iostream>
using namespace std;

int minimum_cost(int a[], int n){
	int min_elem = a[0];
	int sum = a[0];

	for(int i=1;i<n;i++){
		if(a[i] < min_elem)
			min_elem = a[i];

		sum += a[i];
	}
	return min_elem * (sum-min_elem);
}

int main() 
{ 
    int a[] = { 4, 3, 2, 5 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << minimum_cost(a, n) << endl; 
    return 0; 
}

//Complexity: O(n)