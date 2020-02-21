#include <iostream>
#include <queue>
using namespace std;

#define N 5

struct Node{
	int x, y, distance;
	Node(int u,int v, int d){
		x = u;
		y = v;
		distance = d;
	}
};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool isSafe(int x, int y){
	return (x >=0 && x<N && y>=0 && y<N);
}

bool isValid(int i, int j,char matrix[][N], int output[][N]){
	if(matrix[i][j] != 'O' || output[i][j] != -1)
		return false;

	return true;
}

void findDistance(char matrix[][N]){
	int output[N][N];
	queue<Node> q;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			output[i][j] = -1;
			if(matrix[i][j] == 'G'){
				output[i][j] = 0;
				Node n(i,j,0);
				q.push(n);
			}
		}
	}

	while(!q.empty()){
		Node n1 = q.front();

		for(int i=0;i<4;i++){
			if(isSafe(n1.x + dx[i], n1.y+dy[i]) && isValid(n1.x + dx[i], n1.y+dy[i], matrix, output)){
				output[n1.x + dx[i]][n1.y+dy[i]] = n1.distance + 1;
				Node n2(n1.x + dx[i], n1.y+dy[i], n1.distance+1);
				q.push(n2);
			}
		}
		q.pop();
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<output[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	char matrix[][N] = 
    { 
        {'O', 'O', 'O', 'O', 'G'}, 
        {'O', 'W', 'W', 'O', 'O'}, 
        {'O', 'O', 'O', 'W', 'O'}, 
        {'G', 'W', 'W', 'W', 'O'}, 
        {'O', 'O', 'O', 'O', 'G'} 
    }; 
  
    findDistance(matrix); 
  
    return 0; 
}