#include <iostream>
using namespace std;
#define N 4

void printsol(int board[][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			cout<<board[i][j]<<"\t";
		cout<<endl;
	}	
}

bool isSafe(int board[][N], int row, int col){
	int i,j;
	for (i=0;i<col;i++){ // checking same row
		if(board[row][i])
			return false;
	}

	for(i=row,j=col;i>=0 && j>=0;i--,j--){ //checking upper diagnol
		if(board[i][j])
			return false;
	}

	for(i=row,j=col;i<N && j>=0;i++,j--){ //checking lower diagnol
		if(board[i][j])
			return false;
	}
	return true;
}

bool NQueenUtil(int board[][N], int col){
	if(col>=N)
		return true;

	for(int i=0;i<N;i++){
		if(isSafe(board,i,col)){
			board[i][col] = 1;
			if(NQueenUtil(board,col+1) == true)
				return true;
			board[i][col] = 0;
		}
	}
	return false;
}

bool NQueen(){
	int board[N][N];
	int i,j;

	for (i=0;i<N;i++){
		for(j=0;j<N;j++)
			board[i][j] = 0;
	}

	if(NQueenUtil(board,0) == false){
		cout<<"Solution does not exist"<<endl;
		return false;
	}

	printsol(board);
	return true;
}

int main(){
	NQueen();
	return 0;
}