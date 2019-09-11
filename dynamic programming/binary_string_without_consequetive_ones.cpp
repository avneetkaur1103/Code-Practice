#include <iostream>
using namespace std;

int count_of_strings(int n){
	int a[n], b[n];
	a[0] = b[0] = 1;
	for (int i=1;i<n;i++){
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return a[n-1] + b[n-1];
}

int main() {
	int n = 3;
	cout<<" Number of binary string without consequetive one's : "<< count_of_strings(n);
	return 0;
}

//Complexity: O(n)