#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> edges[], int u, int v){
    edges[u].push_back(v);
    edges[v].push_back(u);
}

int minEdgeBFS(vector<int> edges[], int u, int v, int n){
    vector<int> distance(n,0);
    vector<bool> visited(n,false);

    queue<int> q;
    distance[u] = 0;
    visited[u] = true;
    q.push(u);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0;i<edges[x].size();i++){
            if(visited[edges[x][i]])
                continue;

            distance[edges[x][i]] = distance[x]+1;
            visited[edges[x][i]] = true;
            q.push(edges[x][i]);
        }
    }
    return distance[v];
}

int main() 
{
    int n = 9; 
    vector <int> edges[9]; 
    addEdge(edges, 0, 1); 
    addEdge(edges, 0, 7); 
    addEdge(edges, 1, 7); 
    addEdge(edges, 1, 2); 
    addEdge(edges, 2, 3); 
    addEdge(edges, 2, 5); 
    addEdge(edges, 2, 8); 
    addEdge(edges, 3, 4); 
    addEdge(edges, 3, 5); 
    addEdge(edges, 4, 5); 
    addEdge(edges, 5, 6); 
    addEdge(edges, 6, 7); 
    addEdge(edges, 7, 8); 
    int u = 0; 
    int v = 5; 
    cout << minEdgeBFS(edges, u, v, n); 
    return 0; 
} 