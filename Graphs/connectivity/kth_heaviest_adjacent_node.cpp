#include <iostream>
#include <vector>

using namespace std;

void KthHeaviestNode(vector<pair<int, int> > adj[], int k, int n, int wt[]){
	for(int i=0;i<n;i++){
		sort(adj[i].begin(), adj[i].end());
		if(adj[i].size() >= k)
			cout<<adj[i][adj[i].size() - k].second<< " ";
		else 
			cout<<"-1"<<" ";
	}
}

int main(){
	int n = 3, k = 2; 
    int wt[] = { 2, 4, 3 };
    vector<pair<int, int> > adj[n];

    adj[0].push_back(make_pair(wt[2], 2));
    adj[2].push_back(make_pair(wt[0], 0)); 
  
    adj[0].push_back(make_pair(wt[1], 1)); 
    adj[1].push_back(make_pair(wt[0], 0)); 
  
    adj[1].push_back(make_pair(wt[2], 2)); 
    adj[2].push_back(make_pair(wt[1], 1)); 

    KthHeaviestNode(adj,k,n,wt);
    return 0;
}