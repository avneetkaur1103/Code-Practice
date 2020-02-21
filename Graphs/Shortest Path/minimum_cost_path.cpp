#include <iostream>
#include <set>

#define ROW 5
#define COL 5

using namespace std;



struct cell{
    int x;
    int y;
    int w;
    cell(int u, int v,int d){
        x = u;
        y = v;
        w = d;
    }
};

bool operator<(const cell &a, const cell &b){
    if(a.w == b.w){
        if(a.x != b.x)
            return (a.x<b.x);
        else
            return (a.y<b.y);
    }
    return (a.w < b.w);
}

bool isSafe(int x, int y){
    return (x>=0 && x < COL && y >=0 && y< ROW);
}

int shortest(int grid[][COL], int row, int col){
    int distance[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            distance[i][j]=INT_MAX;
    }

    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};

    set<cell> s;
    s.insert(cell(0,0,0));
    distance[0][0] = grid[0][0];

    while(!s.empty()){
        cell k = *s.begin();
        s.erase(s.begin());

        for(int i=0;i<4;i++){
                int x = k.x + dx[i];
                int y = k.y + dy[i];

                if (!isSafe(x,y))
                    continue;

                if(distance[x][y] > distance[k.x][k.y] + grid[x][y]){
                    if(distance[x][y] != INT_MAX)
                        s.erase(s.find(cell(x,y,distance[x][y])));

                    distance[x][y] = distance[k.x][k.y] + grid[x][y];
                    s.insert(cell(x,y,distance[x][y]));
                }
        }
        
    }
    return distance[row-1][col-1];

}


int main() 
{ 
    int grid[ROW][COL] = 
    { 
        31, 100, 65, 12, 18, 
        10, 13, 47, 157, 6, 
        100, 113, 174, 11, 33, 
        88, 124, 41, 20, 140, 
        99, 32, 111, 41, 20 
    }; 
  
    cout << shortest(grid, ROW, COL) << endl; 
    return 0; 
} 