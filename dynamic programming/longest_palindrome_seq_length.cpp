#include <iostream>
#include <string.h>
using namespace std;

int max(int a, int b){
	return (a>b)?a:b;
}

int longest_palindrome(char *str){
	int n= strlen(str);
	int i,j,l;
	
	int lp[n][n];
	
	for (i=0;i<=n;i++){
		lp[i][i]= 1;
	}
	
	for (l=2;l<=n;l++){
		for(i=0;i<=n-l+1;i++){
			j=i+l-1;
			if(str[i] == str[j] && l==2)
				lp[i][j] = 2;
			else if (str[i] == str[j])
				lp[i][j] = lp[i+1][j-1] + 2;
			else
				lp[i][j] = max(lp[i][j-1], lp[i+1][j]);
		}
	}
	return lp[0][n-1];
}

int main() {
	char seq[] = "GEEKS FOR GEEKS";
	int n = strlen(seq);
	cout<<"The length of longest palindrome sequence is: "<<longest_palindrome(seq);
	return 0;
}

//Complexity:O(n^2)