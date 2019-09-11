#include <iostream>
using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int binom_coeff(int n, int k){
	int c[n+1][k+1];
	
	int i,j;
	for(int i=0;i<n+1;i++){
		for(j=0; j<= min(i,k); j++){
			if(j==0 || j==i)
				c[i][j] = 1;
			else
				c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	return c[n][k];
}

int main() {
	int n = 5, k=2;
	cout<<"Binnomial coefficient: "<< binom_coeff(n,k);
	return 0;
}

//complexity: O(n*k)