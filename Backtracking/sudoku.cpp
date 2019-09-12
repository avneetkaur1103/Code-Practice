#include <iostream>
using namespace std;
#define N 9

bool isUnassigned(int &i, int &j, int grid[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(grid[i][j] == 0)
				return true;
		}
	}
	return false;
}

bool usedInRow(int grid[N][N],int row,int num){
	for(int j=0;j<N;j++){
		if(grid[row][j] == num)
			return true;
	}
	return false;
}

bool usedInCol(int grid[N][N], int col, int num){
	for(int i=0;i<N;i++){
		if(grid[i][col] == num)
			return true;
	}
	return false;
}

bool usedInGrid(int grid[N][N], int row, int col, int num){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i+row][j+col] == num)
				return true;
		}
	}
	return false;
}

bool isSafe(int row, int col, int grid[N][N], int num){
		if (!usedInRow(grid,row,num) && !usedInCol(grid,col,num) && !usedInGrid(grid,row - row % 3,col - col % 3,num) && grid[row][col] == 0)
			return true;
	
		return false;
}

void printGrid(int grid[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool solveSudoku(int grid[N][N]){
	int row, col;
	if(!isUnassigned(row,col,grid))
		return true;

	for(int k=1;k<=9;k++){
		if(isSafe(row,col,grid,k)){
			grid[row][col] = k;
			if(solveSudoku(grid) == true)
				return true;

			grid[row][col] = 0;
		}
	}
	return false;
}

int main(){
	
	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}}; 

	if(solveSudoku(grid) == true)
		printGrid(grid);
	else
		cout<<"Solution does not exist"<<endl;
	return 0;
}                       