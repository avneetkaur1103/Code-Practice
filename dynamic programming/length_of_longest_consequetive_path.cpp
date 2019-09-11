#include <iostream>
#include <string.h>
using namespace std;
#define R 3
#define C 3

int dp[R][C];

int ro[] = {0,1,0,-1,-1,-1,1,1};
int co[] = {1,0,-1,0,-1,1,-1,1};
//int ro[] = {0, 1, 1, -1, 1, 0, -1, -1}; 
//int co[] = {1, 0, 1, 1, -1, -1, 0, -1};

bool isvalid(int i, int j){
	if (i>=0 && j>=0 && i<R && j<C)
		return true;
	else
		return false;
}

bool isneighbour(char next, char prev){
	if ((next - prev) != 1)
		return false;
	return true;
}

int get_len_util(char arr[][C], int i, int j, char prev){
	int k;
	if (!isvalid(i,j) || !isneighbour(arr[i][j], prev))
		return 0;
	
	if (dp[i][j] != -1)
		return dp[i][j];
		
	int ans = 0;
	
	for (k=0;k<8;k++){
		ans = max(ans, 1+get_len_util(arr, i+ro[k], j+co[k], arr[i][j]));
	}
	
	return dp[i][j] =  ans;
}

int get_len(char arr[][C], char s){
	memset(dp,-1,sizeof(dp));
	int i,j,k;
	int ans = 0;
	
	for(i=0;i<R;i++){
		for(j=0;j<C;j++){
			if(arr[i][j] == s)
			for (k=0;k<8;k++){
				ans = max(ans, 1+get_len_util(arr,i+ro[k],j+co[k],s));
			}
		}
	}
	return ans;
}
int main() {
	char mat[R][C] = { {'a','c','d'}, 
                     { 'h','b','a'}, 
                     { 'i','g','f'}}; 
                     
    cout<<"Length of longest consequetive path from a: "<<get_len(mat, 'a')<<endl;
	return 0;
}

//Complexity:O(R*C)