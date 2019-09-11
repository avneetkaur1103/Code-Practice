#include <iostream>
#include <string.h>
using namespace std;

long int non_decreasing_digits(int n){
	long int dp[10][n+1];
	memset(dp,0,sizeof(dp));
	int i,j,x;
	long int count = 0;
	
	for (i=0;i<10;i++)
		dp[i][1] = 1;
		
	for (i=0;i<10;i++){
		for(j=2;j<=n;j++){
			for(x=0;x<=i;x++){
				dp[i][j] += dp[x][j-1];
			}
		}
	}
	
	for(i=0;i<10;i++)
		count += dp[i][n];
	
	return count;
}

int main() {
	int n=3;
	cout<<"The count of non decreasing n digit number is: "<<non_decreasing_digits(n);
	return 0;
}

//Complexity: O(n)