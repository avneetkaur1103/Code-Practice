	#include <iostream>
	using namespace std;

	int num_of_trees(int n){
		int dp[n+1];
		memset(dp,0,sizeof(dp));

		dp[0] = dp[1] = 1;

		for(int i=2;i<=n;i++){
			for(int j=0;j<i;j++){
				dp[i] += dp[j]*dp[i-j-1];
			}
		}
		return dp[n];
	}

	int main(){
		int n = 5;
		cout<< "No of binary trees possible: "<< num_of_trees(n);
		return 0;
	}