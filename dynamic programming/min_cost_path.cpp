#include <iostream>
#include <algorithm>
using namespace std;
#define R 3
#define C 3

int min(int x, int y, int z){
	return min(min(x,y),z);
}

int mincodepath(int cost[R][C], int r, int c){
	int res[R][C];
	res[0][0] = cost[0][0];
	int i, j;
	
	for (int i=1; i<=r; i++)
		res[i][0] = res[i-1][0] + cost[i][0];
	
	for (int j=1; j<=c; j++)
		res[0][j] = res[0][j-1] + cost[0][j];
	
	for (i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			res[i][j] = cost[i][j] + min(res[i-1][j], res[i][j-1], res[i-1][j-1]);
		}
	}
	
	return res[r][c];
}

int main() {
	int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };
    cout<<mincodepath(cost,2,2);
	return 0;
}

//Complexity: O(r.c)