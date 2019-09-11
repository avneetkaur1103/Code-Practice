#include <iostream>
#include <climits>
using namespace std;

struct Adjnode{
	int wt;
	int dest;
	struct Adjnode* next;
};

struct Adjlist{
	struct Adjnode *head;
};

struct Graph{
	int V;
	struct Adjlist *array;
};

struct Adjnode* create_adjnode(int wt, int dest){
	struct Adjnode* new_node = (struct Adjnode*)malloc(sizeof(struct Adjnode));
	new_node->wt = wt;
	new_node->dest = dest;
	new_node->next = NULL;
	return new_node;
}

struct Graph* create_graph(int V){
	struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
	g->V = V;
	g->array = (struct Adjlist*) malloc(V * sizeof(struct Adjlist));
	
	for (int i = 0;i<V; i++)
		g->array[i].head = NULL;
	
	return g;
}

void addEdge(struct Graph* g, int src, int dest, int wt){
	struct Adjnode* n = create_adjnode(wt,dest);
	n-> next = g->array[src].head;
	g->array[src].head = n;
	
	n = create_adjnode(wt,src);
	n-> next = g->array[dest].head;
	g->array[dest].head = n;
}

struct minheapnode{
	int v;
	int dist;
};

struct minheap{
	int size, cap, *pos;
	struct minheapnode **array;
};

struct minheapnode* create_minheapnode(int v, int dist){
	struct minheapnode* n = (struct minheapnode*)malloc(sizeof(struct minheapnode));
	n->v = v;
	n->dist = dist;
	return n;
}

struct minheap* create_minheap(int cap){
	struct minheap* mn = (struct minheap*) malloc(sizeof(struct minheap));
	mn->size = 0;
	mn->cap = cap;
	mn->pos = (int*)malloc(cap * sizeof(int));
	mn->array = (struct minheapnode**)malloc(cap * sizeof(struct minheapnode*));
	return mn;
}

void swap(struct minheapnode **a, struct minheapnode **b){
	struct minheapnode *temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(struct minheap* mn, int i){
	int smallest = i;
	int l = i*2 +1;	
	int r = i*2+2;
	
	if (l<mn->size && mn->array[l]->dist < mn->array[smallest]->dist)
		smallest = l;
	if (r<mn->size && mn->array[r]->dist < mn->array[smallest]->dist)
		smallest = r;
		
		if(smallest != i){
			struct minheapnode *smallestnode = mn->array[smallest];
			struct minheapnode *inode = mn->array[i];
			
			mn->pos[smallestnode->v] = i;
			mn->pos[inode->v] = smallest;
			
			swap(&mn->array[smallest], &mn->array[i]);
			heapify(mn, smallest);
		}
}

bool isempty(struct minheap* mn){
	return (mn->size == 0);
}

struct minheapnode* extractmin(struct minheap* mn){
	if(isempty(mn))
		return NULL;
	struct minheapnode* root = mn->array[0];
	struct minheapnode* lastnode = mn->array[mn->size-1];
	mn->array[0] = lastnode;
	mn->pos[mn->array[0]->v] = mn->size -1;
	mn->pos[lastnode->v] = 0;
	--mn->size;
	heapify(mn,0);
	return root;
}

bool isinminheap(struct minheap* mn, int v){
	if(mn->pos[v] < mn->size)
		return true;
		
	return false;
}

void decreasekey(struct minheap* mn, int v, int dist){
	int i = mn->pos[v];
	mn->array[i]->dist = dist;
	
	while (i && mn->array[(i-1)/2]->dist > mn->array[i]->dist){
		mn->pos[mn->array[(i-1)/2]->v] = i;
		mn->pos[mn->array[i]->v] = (i-1)/2;
		swap(&mn->array[(i-1)/2], &mn->array[i]);
		i = (i-1)/2;
	}
}

void printarr(int dist[], int V){
	for (int i = 0; i<V; i++){
		cout<<i <<" --  "<<dist[i]<<endl;
	}
}
void Dijkstra(struct Graph *g){
	int V = g->V;
	int dist[V];
	
	struct minheap* mn = create_minheap(V);
	
	for (int i=0; i<V; i++){
		dist[i] = INT_MAX;
		mn->array[i] = create_minheapnode(i, dist[i]);
		mn->pos[i] = i;
	}
	
	dist[0] = 0;
	mn->array[0] = create_minheapnode(0, dist[0]);
	mn->pos[0]=0;
	
	mn->size = V;
	
	while(!isempty(mn)){
		struct minheapnode* min_node = extractmin(mn);
		int u = min_node->v;
		
		struct Adjnode* a = g->array[u].head;
		while (a != NULL){
			int k = a->dest;
			if(isinminheap(mn, k) && dist[u] != INT_MAX && dist[k] > dist[u] + a->wt){
				dist[k] = dist[u] + a->wt;
				decreasekey(mn, k, dist[k]);
			}
			a = a->next;
		}
	}
	printarr(dist, V);
}

int main() {
	int V= 9;
	struct Graph *graph = create_graph(V);
	addEdge(graph, 0, 1, 4); 
    addEdge(graph, 0, 7, 8); 
    addEdge(graph, 1, 2, 8); 
    addEdge(graph, 1, 7, 11); 
    addEdge(graph, 2, 3, 7); 
    addEdge(graph, 2, 8, 2); 
    addEdge(graph, 2, 5, 4); 
    addEdge(graph, 3, 4, 9); 
    addEdge(graph, 3, 5, 14); 
    addEdge(graph, 4, 5, 10); 
    addEdge(graph, 5, 6, 2); 
    addEdge(graph, 6, 7, 1); 
    addEdge(graph, 6, 8, 6); 
    addEdge(graph, 7, 8, 7); 
	
	Dijkstra(graph);
	return 0;
}

//complexity:   O(ElogV)
// can be reduced to O(E+VlogV) using fibonacci heap