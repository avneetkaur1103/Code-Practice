#include <iostream>
using namespace std;

int get_min_squares(int n){
	int dp = new int[n+1];
	memset(dp,-1,sizeof(dp));
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	int count = 0;
	
	for (int i=4;i<=n;i++){
		dp[i] = i;
		
		for (int j= 1;j<=i;j++){
			int temp = j*j;
			if(temp > i)
				break;
			
			dp[i] = min(dp[i], 1+dp[i-temp]);
		}
	}
	count = dp[n];
	delete []dp;
	
	return count;
}

int main(){
	int n = ;
	cout<<"Minimum number of squares whose sum is equal to n: " << get_min_squares(n) <<endl;
	return 0;
}

//Complexity: O(n)