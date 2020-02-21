#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;

	public:
		Graph(int V);
		void addEdge(int v, int w);
		int BFS(int idx1, int idx2);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void findPrimeNums(vector<int> &primeSet){
	int n= 9999;
	bool isPrime[n+1];
	memset(isPrime,true,sizeof(isPrime));

	for(int p=2; p*p <=n; p++){
		if(isPrime[p] == true){
			for(int j=p*p;j<=n;j+=p)
				isPrime[j] = false;
		}
	}

	for(int i=1000;i<=n;i++){
		if(isPrime[i])
			primeSet.push_back(i);
	}
}

bool compare(int i, int j){
	string s1 = to_string(i);
	string s2 = to_string(j);

	int c=0;
	if(s1[0] != s2[0])
		c++;
	if(s1[1] != s2[1])
		c++;
	if(s1[2] != s2[2])
		c++;
	if(s1[3] != s2[3])
		c++;

	return (c==1);
}

int Graph::BFS(int idx1, int idx2){
	vector<int> visited(V,false);
	queue<int> q;
	visited[idx1] = 1;
	q.push(idx1);
	int count = 0;
	list<int>::iterator it;
	while(!q.empty()){
		int temp = q.front();
		q.pop();

		
		for(it = adj[temp].begin(); it != adj[temp].end(); it++){
			if(!visited[*it]){
				visited[*it] = visited[temp] + 1;
				q.push(*it);
				//count++;
				//cout<<count<<endl;
			}
			if(*it == idx2)
				return visited[*it] -1;
		}

	}
	return 0;
}

int shortestPath(int num1, int num2){
	vector<int> primeSet;
	findPrimeNums(primeSet);
	Graph g(primeSet.size());

	for (int i=0;i<primeSet.size();i++){
		for(int j = i+1;j<primeSet.size();j++){
			if(compare(primeSet[i],primeSet[j]))
				g.addEdge(i,j);
		}
	}

	int idx1, idx2;
	for(int i=0;i<primeSet.size();i++)
		if(primeSet[i] == num1)
			idx1 = i;

	for(int j=0;j<primeSet.size();j++)
		if(primeSet[j] == num2)
			idx2 = j;

	return g.BFS(idx1,idx2);
}

int main() 
{ 
    int num1 = 1033, num2 = 8179; 
    cout << shortestPath(num1, num2); 
    return 0; 
} 