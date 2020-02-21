#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool oneAway(string s1, string s2){
	int l1 = s1.length();
	int l2 = s2.length();

	int dp[l1+1][l2+1];

	for(int i=0;i<=l1;i++){
		for(int j=0;j<=l2;j++){
			if(i==0)
				dp[i][j] = j;
			else if(j==0)
				dp[i][j] = i;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));
		}
	}
	if(dp[l1][l2] > 1)
		return false;
	
	return true;
}

int main(){
	string s1 = "pale";
	string s2 = "bake";
	oneAway(s1,s2)?cout<<"Yes":cout<<"No";
	cout<<endl;
	return 0;
}