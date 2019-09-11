#include <iostream>
#include <algorithm>
using namespace std;

int min(int a, int b, int c){
	return min(min(a,b),c);
}

int edit_distance(string s, string t, int m, int n){
	
	int dp[m+1][n+1];
	
	for (int i =0; i<=m; i++){
		for(int j=0; j<=n; j++){
			
			if (i==0)
				dp[i][j] = j ;
			else if (j==0)
				dp[i][j] = i;
			else if (s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j] , dp[i][j-1] , dp[i-1][j-1]);
								
		}
	}
	
	return dp[m][n];
}

int main() {
	string str1 = "sunday"; 
    string str2 = "saturday"; 
    cout<<edit_distance(str1, str2, str1.length(), str2.length());
	return 0;
}

//complexity:)(m.n)