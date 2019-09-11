#include <iostream>
using namespace std;

int fibonacci(int n){
	int i;
	int fib[n+2];
	fib[0] = 0;
	fib[1] = 1;
	for (i=2;i<=n;i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	return fib[n];
}

int main() {
	int n=9;
	cout<<"Fibonacci result: "<<fibonacci(n);
	return 0;
}

//Complexity:O(n)