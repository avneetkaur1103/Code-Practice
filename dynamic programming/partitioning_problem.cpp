#include <iostream>
using namespace std;

bool find_partition(int arr[], int n){
	int sum = 0;
	int i,j;
	for (i=0;i<n;i++){
		sum += arr[i];
	}
	
	bool par[sum/2+1][n+1];
	
	for(i=1;i<=sum/2;i++)
		par[i][0] = false;
	
	for(j=0;j<=n;j++)
		par[0][j] = true;
		
	for(i=0;i<=sum/2;i++){
		for(j=0;j<=n;j++){
			par[i][j] = par[i][j-1];
			if(i>=arr[j-1])
				par[i][j] = par[i][j] || par[i-arr[j-1]][j-1];
				return par[sum/2][n];
		}
	}
	
}

int main() {
	int arr[] = {3, 1, 1, 2, 2, 1}; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  if (find_partition(arr, n) == true) 
     printf("Can be divided into two subsets of equal sum"); 
  else
     printf("Can not be divided into two subsets of equal sum"); 
	return 0;
}

//complexity: O(sum*n)
//We can also solve subset sum problem using same algo