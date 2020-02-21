#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node{
	int val;
	int level;
};

int minOperations(int x, int y){
	map<int, bool> visited;
	node *n = new node();
	n->val = x;
	n->level = 0;

	queue<node*> q;
	q.push(n);

	while(!q.empty()){
		node* u = q.front();
		q.pop();

		if(u->val == y)
			return u->level;

		visited[u->val] = true;

		if(u->val * 2 == y || u->val -1 == y)
			return u->level+1;

		
		if(visited.find(u->val * 2) == visited.end()){
			n->val = u->val*2;
			n->level = u->level+1;
			q.push(n);
		}

		if(visited.find(u->val - 1) == visited.end() && u->val - 1 >=0){
			n->val = u->val-1;
			n->level = u->level+1;
			q.push(n);
		}
	}
}

int main() 
{ 
    int x = 4, y = 7; 
    cout << minOperations(x, y); 
    return 0; 
} 