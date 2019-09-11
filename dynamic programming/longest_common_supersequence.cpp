#include <iostream>
#include <string.h>
using namespace std;

int longest_common_superseq(char str1[],char str2[], int m, int n){
	int i,j;
	int dp[m+1][n+1];
	for (i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			if(!i)
				dp[i][j] = j;
			else if(!j)
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main() {
	char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB";
    cout<<"Length of longest common supersequence is: "<<longest_common_superseq(X,Y, strlen(X), strlen(Y));
	return 0;
}

//Complexity: O(m*n)