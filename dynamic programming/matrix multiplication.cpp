#include <iostream>
#include <climits>
using namespace std;

int matrix_multiplication(int p[], int n){
	int i,j,k,q,L;
	
	int m[n][n];
	
	for (i=0;i<n;i++)
		m[i][i] = 0;
	
	for (L=2;L<n;L++){
		for (i=1;i<n-L+1;i++){
			j = i+L-1;
			m[i][j] = INT_MAX;
			for(k=i;k<j;k++){
				q= m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q<m[i][j])
					m[i][j] = q;
			}
		}
	}
	return m[1][n-1];
}
int main() {
	int arr[] = {1, 2, 3, 4}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Matrix multiplication: "<< matrix_multiplication(arr,n);
	return 0;
}

//Complexity: O(n^3)