#include <iostream>
using namespace std;

#define ROW 5
#define COL 5

bool isSafe(int M[][COL],int i,int j, int visited[][COL]){
	return (i>=0 && j>=0 && i<ROW && j<COL && M[i][j] && !visited[i][j]);
}

void DFS(int M[][COL], int i, int j, int visited[][COL]){
	int dx[] = {0,1,0,-1,1,-1,1,-1};
	int dy[] = {1,0,-1,0,1,-1,-1,1};
	visited[i][j] = 1;

	for(int k=0;k<8;k++){
		if(isSafe(M,i+dx[k], j+dy[k],visited))
			DFS(M,i+dx[k], j+dy[k],visited);
	}
}

int countIslands(int M[][COL]){
	int visited[ROW][COL];
	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){
			visited[i][j] = 0;
		}
	}

	int count = 0;

	for(int i=0;i<ROW;i++){
		for(int j=0;j<COL;j++){

			if(M[i][j] && !visited[i][j]){
				DFS(M,i,j,visited);
				count++;
			}
		}
	}

	return count;
}

int main(){
	int M[][COL] = { { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } }; 
  
    cout << "Number of islands is: " << countIslands(M); 
  
    return 0; 
}

//Complexity:O(ROW*COL)