				#include <iostream>
				#include <climits>
				using namespace std;
				
				struct Adjnode{
					int wt;
					int dest;
					struct Adjnode *next;
				};
				
				struct Adjlist{
					struct Adjnode* head;
				};
				
				struct graph{
					int V;
					struct Adjlist* array;
				};
				
				struct Adjnode* createAdjnode(int wt, int dest){
					struct Adjnode* new_node = (struct Adjnode*)malloc(sizeof(struct Adjnode));
					new_node->wt = wt;
					new_node->dest = dest;
					new_node->next = NULL;
					return new_node;
				}
				
				struct graph* createGraph(int V){
					struct graph* g = (struct graph*)malloc(sizeof(struct graph));
					g->V = V;
					g->array = (struct Adjlist*)malloc(V*sizeof(struct Adjlist));
					
					for (int i=0;i<V;i++)
						g->array[i].head = NULL;
					
					return g;
					
				}
				
				void addEdge(struct graph* g, int src, int dest, int wt){
					
					struct Adjnode* n = createAdjnode(wt, dest);
					n->next = g->array[src].head;
					g->array[src].head = n;
					
					n = createAdjnode(wt, src);
					n->next = g->array[dest].head;
					g->array[dest].head = n;
				}
				
				struct minheapNode{
					int v;
					int key;
				};
				
				struct minheap{
					int cap, size, *pos;
					struct minheapNode **array;
				};
				
				struct minheapNode* create_heapnode(int v, int key){
					struct minheapNode* new_heap_node = (struct minheapNode*)malloc(sizeof(struct minheapNode));
					new_heap_node->v = v;
					new_heap_node->key = key;
					return new_heap_node;
				}
				
				struct minheap* create_minheap(int cap){
					struct minheap* new_minheap = (struct minheap*)malloc(sizeof(struct minheap));
					new_minheap->size = 0;
					new_minheap->cap = cap;
					new_minheap->pos = (int *)malloc(cap * sizeof(int));
					new_minheap->array = (struct minheapNode**)malloc(cap * sizeof(struct minheapNode*));
					return new_minheap;
				}
				
				void swap(struct minheapNode **a, struct minheapNode **b){
					struct minheapNode* temp = *a;
					*a = *b;
					*b = temp;
				}
				
				bool isemptyheap(struct minheap* minheap){
					return (minheap->size == 0);
				}
				
				void heapify(struct minheap* minheap, int idx){
					int smallest = idx;
					int l = 2*idx + 1;
					int r = 2*idx + 2;
					
					if (l<minheap->size && minheap->array[l]->key < minheap->array[smallest]->key)
						smallest = l;
					if (r<minheap->size && minheap->array[r]->key < minheap->array[smallest]->key)
						smallest = r;
						
					if (smallest != idx){
						struct minheapNode *smallestnode = minheap->array[smallest];
						struct minheapNode *idxnode = minheap->array[idx];
						minheap->pos[smallestnode->v] = idx;
						minheap->pos[idxnode->v] = smallest;
						swap(&minheap->array[smallest], &minheap->array[idx]);
						heapify(minheap, smallest);
					}
				}
				
				void decreasekey(struct minheap* minheap, int v,int key){
					int i = minheap->pos[v];
					minheap->array[i]->key = key;
					
					while(i && minheap->array[(i-1)/2]->key >  minheap->array[i]->key){
						minheap->pos[minheap->array[(i-1)/2]->v] = i;
						minheap->pos[minheap->array[i]->v] = (i-1)/2;
						swap(&minheap->array[(i-1)/2], &minheap->array[i]);
						i = (i-1)/2;
					}
				}
				
				struct minheapNode* extract_min(struct minheap *minheap){
					if (isemptyheap(minheap))
						return NULL;
						
					struct minheapNode *root = minheap->array[0];
					struct minheapNode *lastnode = minheap->array[minheap->size -1];
					minheap->pos[minheap->array[0]->v] = minheap->size-1;
					minheap->array[0] = lastnode;
					--minheap->size;
					heapify(minheap,0);
					return root;
				}
				
				bool isinheap(struct minheap* minheap, int v){
					if( minheap->pos[v] < minheap->size)
						return true;
					return false;
				}
				
				void printMST(int parent[], int V){
					for (int i=1;i<V;i++){
						cout<<parent[i]<<" -- " << i<<endl;
					}
				}
				
				void primMST(struct graph* g){
					int V = g->V;								
					int parent[V];
					int key[V];
					
					struct minheap* minheap = create_minheap(V);
					
					for (int i = 1;i <V; ++i){
						parent[i] = -1;
						key[i] = INT_MAX;
						minheap->array[i] = create_heapnode(i,key[i]);
						minheap->pos[i] = i;
					}
					
					
					key[0] = 0;
					minheap->array[0] = create_heapnode(0,key[0]);
					minheap->pos[0] = 0;
					
					minheap->size = V;
					
					while(!isemptyheap(minheap)){
						struct minheapNode* min_node = extract_min(minheap);
						int u = min_node->v;
						struct Adjnode* l = g->array[u].head; 
						while(l != NULL){
							int v = l->dest;
							if(isinheap(minheap, v) && l->wt < key[v]){
								key[v] = l->wt;
								parent[v] = u;
								decreasekey(minheap, v,key[v]);
							}	
								l =l->next;
						}
					}
					
					printMST(parent,V);
				}
				
				int main() {
					int V= 9;
					struct graph* graph = createGraph(V);
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
				    primMST(graph);
					return 0;
				}
				
				
//Complexity: O((E+V) * (logV))
			{inner loop runs V+E times & log V is for decreasekey()}