#include <iostream>
#include <string.h>
#include <climits>
using namespace std;

int minimum(int a, int b){
	return (a<b)?a:b;
}

int palin_partition(char* str){
	int n = strlen(str);
	int i,j,k,L;
	int C[n][n];
	bool P[n][n];
	
	for (i=0;i<n;i++){
		C[i][i] = 0;
		P[i][i] = true;
	}
	
	for (L=2; L<=n; L++){
		for (i=0;i<n-L+1;i++){
			j= i+L-1;
			
			if(L==2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i+1][j-1];
				
			if(P[i][j] == true)
				C[i][j] = 0;
			else{
					C[i][j] = INT_MAX;
					for(k=i; k<=j-1; k++){
						C[i][j] = min(C[i][j], 1+C[i][k]+C[k+1][j]);
					}
				}
		}
	}
	return C[0][n-1];
}

int main(){
	char str[] = "ababbbabbababa";
	cout<<palin_partition(str);
	return 0;
}

//Complexity: O(n^3)