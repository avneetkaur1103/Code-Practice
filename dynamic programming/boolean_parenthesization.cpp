#include <iostream>	
#include <string.h>
using namespace std;

int count_bool_parenthesization(char symb[], char opr[], int n){
	int T[n][n];
	int F[n][n];
	
	int i,j,k,gap, g;
	
	
	for (i=0;i<n;i++){
		T[i][i] = (symb[i] == 'T')?1:0;
		F[i][i] = (symb[i] == 'F')?1:0;
	}	
	
	for (gap = 1; gap <n; gap++){
		for (i=0, j=gap; i<n,j<n; i++,j++){
			T[i][j] = F[i][j] = 0;
			for (g= 0;g<gap;g++){
				k = i+g;
					
				int total_ik = T[i][k] + F[i][k];
				int total_kj = T[k+1][j] + F[k+1][j];
					
				if (opr[k] == '&'){
					T[i][j] += T[i][k] * T[k+1][j];
					F[i][j] += total_ik * total_kj - T[i][k] * T[k+1][j];
				}
				
				if (opr[k] == '|'){
					F[i][j] += F[i][k] * F[k+1][j];
					T[i][j] += total_ik * total_kj - F[i][k] * F[k+1][j];
				}
					
				if (opr[k] == '^'){
					T[i][j] += T[i][k] * F[k+1][j] + F[i][k] * T[k+1][j];
					F[i][j] += T[i][k] * T[k+1][j] + F[i][k] * F[k+1][j];
				}
			}
		}
	}
	return T[0][n-1];
}

int main() {
	char symb[] = "TTFT";
	char opr[] = "|&^";
	int n = strlen(symb);
	
	cout<<"Number of ways to parenthesize boolean expr: " << count_bool_parenthesization(symb, opr, n);
	return 0;
}

//complexity: O(n^3)