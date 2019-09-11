#include <iostream>
#include <string.h>
using namespace std;

int longest_substring(char *str){
	int n = strlen(str);
	int i,j,k,l,maxlen = 0;
	
	int len[n][n];
	
	for (i=0;i<n;i++)
		len[i][i] = str[i] - '0';
		
	for(l = 2;l<=n;l++){
		for(i=0;i<n-l+1;i++){
			j= i+l-1;
			k=l/2;
			len[i][j] = len[i][j-k] + len[j-k+1][j];
			
			if(l%2 == 0 && len[i][j-k] == len[j-k+1][j] && maxlen < l)
				maxlen = l;
		}
	}
	return maxlen;
}

int main() {
	char str[] = "153803";
    cout << "Length of the substring is " <<longest_substring(str);
	return 0;
}

//Complexity: O(n^2)