#include <iostream>
#define N 8
using namespace std;

bool isSafeMove(int X,int Y, int sol[][N]){
	if(X>=0 && X<N && Y>=0 && Y<N && sol[X][Y] == -1)
		return true;
	return false;
}

void printsol(int sol[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<sol[i][j]<<"\t";
		cout<<endl;
	}
}

bool solveKtUtil(int sol[N][N], int X, int Y, int movei, int moveX[], int moveY[]){
	if(movei == N * N)
		return true;

	for(int k=0;k<N;k++){
		int nextX = X + moveX[k];
		int nextY = Y + moveY[k];
		
		if (isSafeMove(nextX, nextY, sol)){
				sol[nextX][nextY] = movei;
				if(solveKtUtil(sol,nextX,nextY,movei+1,moveX,moveY) == true)
					return true;

				else
					sol[nextX][nextY] = -1;
		}
	}
	return false;
}

void solve_knight_tracking(){
	int sol[N][N];
	int i,j;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			sol[i][j] = -1;
	} 

	sol[0][0] = 0;

	int moveX[8] = {2,1,-1,-2,2,1,-2,-1};
	int moveY[8] = {1,2,2,1,-1,-2,-1,-2};

	if ( solveKtUtil(sol,0,0,1,moveX,moveY) == false)
		cout<<"Solution does not exist";
	else
		printsol(sol);
}


int main(){
	solve_knight_tracking();
	return 0;
}

//Complexity:O(n*n) ?