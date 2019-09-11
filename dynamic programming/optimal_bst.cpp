#include <iostream>
#include <climits>
using namespace std;

int sum(int freq[], int i, int j){
	int s=0;
	for (int k=i; k<=j; k++){
		s += freq[k];
	}
	return s;
}

int optimal_bst(int freq[], int keys[], int n){
	int i,j, L,r;
	
	int cost[n][n];
	
	for(i=0;i<n;i++)
		cost[i][i] = freq[i];
		
	for (L=2;L<=n;L++){
		for (i=0;i<n-L+1;i++){
			j = i+L-1;
			
			cost[i][j] = INT_MAX;
			for (r=i;r<=j;r++){
				int c = ((r>i)?cost[i][r-1]:0) + ((r<j)?cost[r+1][j]:0) + sum(freq,i,j);
				if (c< cost[i][j])
					cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}

int main() {
	int keys[] = {10, 12, 20};  
    int freq[] = {34, 8, 50};  
    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<"The cost of optial BST: " << optimal_bst(freq,keys,n);
	return 0;
}

//Complexity: O(n^4)