#include <iostream>
using namespace std;

unsigned long int binom_coeff(unsigned int n, unsigned int k){
	unsigned long int res =1;
	if(k > n-k)
		k = n-k;
		for (int i=0;i<k;i++){
			res *= (n-i);
			res /= i+1;
		}
		return res;
}

unsigned long int catalan(unsigned int n){
	unsigned long int c = binom_coeff(2*n, n);
	return c/(n+1);
}

unsigned long int num_of_valid_parenth_expr(unsigned int n){
	if (n%2 == 1)
		return 0;
	else
		return catalan(n/2);
}

int main() {
	int n = 6;
	cout<<num_of_valid_parenth_expr(n);
	return 0;
}

//complexity: O(n)