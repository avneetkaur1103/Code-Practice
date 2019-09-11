#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b){
	return (a>b)?a : b;
}

int lcs(char *X,char *Y, int m, int n){
	int L[m+1][n+1];
	int i,j;
	
	for (i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if (i==0 || j==0)
				L[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] +1;
			else
				L[i][j] = max(L[i][j-1], L[i-1][j]);
		}
	}
	return L[m][n];
}

int main() {
	char arr1[] = "AGGTAB";
	char arr2[] = "GXTXAYB";
	int m = strlen(arr1);
	int n = strlen(arr2);
	cout<<lcs(arr1,arr2,m,n);
	return 0;
}

//Complexity: O(mn)