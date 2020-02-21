#include <iostream>
#include <queue>
using namespace std;

struct cell{
	int x, y, dis;
	cell(){}
	cell(int x, int y, int dis){
		this->x=x;
		this->y=y;
		this->dis = dis;
	}
};

bool isSafe(int x, int y, int N){
	if(x>=1 && y >=1 && x<=N && y <= N)
		return true;

	return false;
}

int minStepToReachTarget(int knightPos[],int targetPos[], int N){

	bool visit[N+1][N+1];
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++)
			visit[i][j] = false;
	}

	int dis_x[] = {-1,-2,2,1,-1,-2,1,2};
	int dis_y[] = {-2,-1,1,2,2,1,-2,-1};

	struct cell t;
	int x,y;

	queue<cell> q;
	q.push(cell(knightPos[0], knightPos[1], 0));

	while(!q.empty()){
		t = q.front();
		q.pop();

		if(t.x == targetPos[0] && t.y == targetPos[1])
			return t.dis;

		for(int i=0;i<8;i++){
			x = t.x + dis_x[i];
			y = t.y + dis_y[i];

			if(isSafe(x,y,N) && !visit[x][y]){
				visit[x][y] = true;
				q.push(cell(x,y,t.dis+1));
			}
		}
	}
}

int main() 
{ 
    int N = 30; 
    int knightPos[] = {1, 1}; 
    int targetPos[] = {30, 30}; 
    cout << minStepToReachTarget(knightPos, targetPos, N); 
    return 0; 
} 

//BFS
//Complexity(Worst case): O(N^2)