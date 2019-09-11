#include <iostream>
using namespace std;
#define N 4

bool isSafe(int X,int Y, int maze[N][N]){
	if(X>=0 && X<N && Y>=0 && Y<N && maze[X][Y] == 1)
		return true;
	return false;
}

bool solveMazeUtil(int sol[][N], int x, int y, int maze[][N]){
	if (x== N-1 && y == N-1){
		sol[x][y] = 1;
		return true;
	}
	if(isSafe(x,y,maze)){
		sol[x][y] = 1;

		if(solveMazeUtil(sol,x+1,y,maze) == true)
				return true;

		if(solveMazeUtil(sol,x,y+1,maze) == true)
				return true;

		sol[x][y] = 0;
		return false;
	}

	return false;
}

void printsol(int sol[][N]){
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++)
			cout<<sol[i][j]<<"\t";

		cout<<"\n";
	}
}

bool solveMaze(int maze[N][N]){
	int sol[N][N];
	int i,j;
	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			sol[i][j] = 0;
	}

	if (solveMazeUtil(sol,0,0, maze) == false){
		cout<<"Solution does not exist"<<endl;
		return false;
	}

	printsol(sol);
	return true;
}

int main(){
	int maze[N][N]= { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

    solveMaze(maze);
   
    return 0;
}
