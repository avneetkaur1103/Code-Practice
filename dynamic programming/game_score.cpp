#include <iostream>
using namespace std;

int ways_to_reach_score_in_game(int arr[],int m, int n){
	int score[n+1][m];
	int i,j,x,y;
	for (i=0;i<m;i++)
		score[0][i] = 1;
		
	for (i=1;i<n+1;i++){
		for(j=0;j<m;j++){
			x = (i - arr[j] >= 0)? score[i - arr[j]][j] : 0;
			y = (j>=1)?score[i][j-1]:0;
			score[i][j] = x+y;
		}
	}
	return score[n][m-1];
}

int main() {
	int arr[]={3,5,10};
	int m=3;
	int n=20 ;
	cout<<"Number of ways to reach a given score in a game: "<< ways_to_reach_score_in_game(arr,m,n);
	return 0;
}

//Complexity:O(m*n)