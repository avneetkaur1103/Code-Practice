#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int ans[], vector<int> Edges[]){
	ans[node] = 1;

	for(int i=0;i<Edges[node].size();i++){
		if(!ans[Edges[node][i]])
			dfs(Edges[node][i],ans,Edges);
	}
}

void constructBinaryPalindrome(int n, int k){
	vector<int> Edges[n];
	int ans[n];

	int arr[n];

	for(int i=0;i<n;i++){
		arr[i] = i%k;
		ans[i] = 0;
	}

	for(int i=0;i< n/2;i++){
		Edges[arr[i]].push_back(arr[n-i-1]);
		Edges[arr[n-i-1]].push_back(arr[i]);
	}

	dfs(0,ans,Edges);

	for(int i=0;i<n;i++)
		cout<<ans[arr[i]]<<" ";	
}

int main(){
	int n=10, k=4;
	constructBinaryPalindrome(n,k);
	return 0;
}

//Complexity: O(n)