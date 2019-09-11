#include <iostream>
#include <string.h>
#include <climits>
using namespace std;
#define R 5
#define C 4

int get_max_traversal_util(int arr[R][C], int dp[R][C][C], int x, int y1, int y2){
	if (x<0 || x>= R || y1 <0 || y1 >=C || y2<0 || y2 >=C)
		return INT_MIN;
		
	if (x == R-1 && y1 == 0 && y2 == C-1)
		return (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2];
	
	if (x == R-1)
		return INT_MIN;
		
	if (dp[x][y1][y2] != -1)
		return dp[x][y1][y2];
	
	int ans = INT_MIN;
	int temp = (y1 == y2)? arr[x][y1]: arr[x][y1]+arr[x][y2];
	
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1,y2-1));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1,y2));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1,y2+1));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1-1,y2-1));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1-1,y2));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1-1,y2+1));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1+1,y2-1));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1+1,y2));
	ans = max(ans, temp + get_max_traversal_util(arr,dp,x+1,y1+1,y2+1));
	
	return (dp[x][y1][y2] = ans);
}

int get_max_traversal(int arr[R][C]){
	int dp[R][C][C];
	memset(dp,-1, sizeof(dp));
	
	return get_max_traversal_util(arr,dp,0,0,C-1);
}

int main() {
	int arr[R][C] = {{3, 6, 8, 2}, 
                     {5, 2, 4, 3}, 
                     {1, 1, 20, 10}, 
                     {1, 1, 20, 10}, 
                     {1, 1, 20, 10}, 
                    }; 
                    
    cout<<" The maximum points in traversal: "<< get_max_traversal(arr);
	return 0;
}

//Complexity: