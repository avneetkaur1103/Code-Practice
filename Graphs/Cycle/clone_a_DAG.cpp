#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct GraphNode{
	int val;
	vector<GraphNode*> neighbours;
};


GraphNode* BuildGraph(){
	GraphNode* node0 = new GraphNode;
	node0->val = 0;

	GraphNode* node1 = new GraphNode;
	node1->val = 1;

	GraphNode* node2 = new GraphNode;
	node2->val = 2;

	GraphNode* node3 = new GraphNode;
	node3->val = 3;

	GraphNode* node4 = new GraphNode;
	node4->val = 4;

	node0->neighbours.push_back(node1);
	node0->neighbours.push_back(node2);

	node1->neighbours.push_back(node2);
	node1->neighbours.push_back(node3);
	node1->neighbours.push_back(node4);

	node2->neighbours.push_back(node3);

	node3->neighbours.push_back(node4);

	return node0;
}

void bfs(GraphNode* src){
	map<GraphNode*, bool> visited;
	queue<GraphNode*> q;
	q.push(src);
	visited[src] = true;

	while(!q.empty()){
		GraphNode* u = q.front();
		cout<<u->val<<" | "<<u<<", ";
		q.pop();

		vector<GraphNode*>::iterator it;
		for(it = u->neighbours.begin(); it != u->neighbours.end(); it++){
			if(!visited[*it]){
				visited[*it] = true;
				q.push(*it);
			}

		}
	}
	cout<<endl;
}

GraphNode* CloneGraph(GraphNode* oldSrc){
	map<GraphNode*, GraphNode*> clone;
	queue<GraphNode*> q;
	q.push(oldSrc);

	GraphNode* node = new GraphNode();
	node->val = oldSrc->val;
	clone[oldSrc] = node;

	while(!q.empty()){
		GraphNode* v = q.front();
		q.pop();

		vector<GraphNode*> n = v->neighbours;
		vector<GraphNode*>::iterator it;
		for(it = n.begin(); it != n.end(); it++){
			if(clone[*it] == NULL){
				node = new GraphNode();
				node->val = (*it)->val;
				clone[*it] = node;
				q.push(*it);
			}
			clone[v]->neighbours.push_back(clone[*it]);
		}

	}
	return clone[oldSrc];
}

int main(){
	GraphNode* src = BuildGraph();
	bfs(src);
	GraphNode* newSrc = CloneGraph(src);
	bfs(newSrc);
	return 0;
}

//Complexity: O(V+E)