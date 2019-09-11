#include <iostream>
using namespace std;
#define R 3
#define C 3

int min_points_to_reach_dest(int arr[][C]){
	int m=R, n=C;
	int dp[R][C];
	int i,j, min_points_on_exit;
	
	dp[m-1][n-1] = (arr[m-1][n-1] > 0)? 1: (abs(arr[m-1][n-1])+1);
	
	for (i=m-2;i>=0;i--)
		dp[i][n-1] = max(dp[i+1][n-1] - arr[i][n-1],1);
	for (j=n-2;j>=0;j--)
		dp[m-1][j] = max(dp[m-1][j+1] - arr[m-1][j],1);
	
	for (i=m-2;i>=0;i--){
		for(j=n-2;j>=0;j--){
			min_points_on_exit = min(dp[i+1][j], dp[i][j+1]);
			dp[i][j] = max(min_points_on_exit - arr[i][j], 1);
		}
	}
	return dp[0][0];
}

int main() {
	int arr[R][C] = { {-2,-3,3}, 
                      {-5,-10,1}, 
                      {10,30,-5} 
                    }; 
    cout << "Minimum Initial Points Required: "<<min_points_to_reach_dest(arr);
	return 0;
}

//Complexity: O(m*n)