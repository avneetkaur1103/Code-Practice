#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> g[], bool mark[], int node, vector<int> &d){
    int lastmarked = -1;
    queue<int> q;
    q.push(node);
    d[node] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(mark[u])
          lastmarked = u;

        for(int i=0;i < g[u].size();i++){
            int v = g[u][i];
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    return lastmarked;
}

int nodesKDistanceFromMarked(int edges[][2], int V, int marked[], int N, int K){
    V = V+1;
    vector<int> g[V];

    int u, v;
    bool mark[V];

   for(int i=0;i<V-1;i++){
        u = edges[i][0];
        v = edges[i][1];
        mark[i] = false;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
   for(int i=0;i<N;i++){
        mark[marked[i]] = true;
    }

    vector<int> d1(V,-1), d2(V,-1), d3(V,-1);

    int x = bfs(g,mark,0,d1);
    int y = bfs(g,mark,x,d2);
    bfs(g,mark,y,d3);

    int res = 0;
    for(int i=0;i<V;i++){
        if(d2[i] <= K && d3[i]<= K)
            res++;
    }
    return res;
}


int main() 
{ 
    int edges[][2] =  
    { 
        {1, 0}, {0, 3}, {0, 8}, {2, 3}, 
        {3, 5}, {3, 6}, {3, 7}, {4, 5}, 
        {5, 9} 
    }; 
    int V = sizeof(edges) / sizeof(edges[0]); 
      
    int marked[] = {1, 2, 4}; 
    int N = sizeof(marked) / sizeof(marked[0]); 
  
    int K = 3; 
    cout << nodesKDistanceFromMarked(edges, V, marked, N, K); 
    return 0; 
} 