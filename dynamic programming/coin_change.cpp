#include<iostream>

using namespace std;

int coin_change(int arr[], int m, int n){
	int i,j,x,y;
	int tab[n+1][m];
	
	for (j=0;j<m;j++)
		tab[0][j] = 1;
		
	for(i=1;i<n+1;i++){
		for(j=0;j<m;j++){
			
			x = (j>=1)?tab[i][j-1]:0;
			y = (i-arr[j]>=0)?tab[i-arr[j]][j]:0;
			tab[i][j] = x+y;
		}
	}
	return tab[n][m-1];
}

int main(){
	int arr[]={1,2,3};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = 4;
	cout<<coin_change(arr,m,n);
	return 0;
}


//Complexity: O(mn)