#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int> list[], int node, int parent){
	cout<<node<<" ";

	for(int i=0;i<list[node].size();i++){
		if(list[node][i] != parent)
			dfs(list,list[node][i], node);
	}
}

int main(){
	int V=5;
	vector<int> list[10000];

	list[1].push_back(2); 
    list[2].push_back(1); 
  
    list[1].push_back(3); 
    list[3].push_back(1); 
  
    list[2].push_back(4); 
    list[4].push_back(2); 
  
    list[3].push_back(5); 
    list[5].push_back(3);

    dfs(list,1,0);
    return 0;
}

//Avoid extra space used by visited nodes