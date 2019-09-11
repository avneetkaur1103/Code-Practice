#include <iostream>
#include <climits>
using namespace std;

int egg_drop(int n, int k){
	int ed[n+1][k+1];
	int i,j,x,min;
	
	for (i=1;i<=n;i++){
		ed[i][0] = 0;
		ed[i][1] = 1;
	}
	
	for (j=1;j<=k;j++)
		ed[1][j] = j;
		
	for(i=2;i<=n;i++){
		for(j=2;j<=k;j++){
			ed[i][j] = INT_MAX;
			for (x=1;x<=j;x++){
				min = 1+max(ed[i-1][x-1], ed[i][j-x]);
				if (min < ed[i][j])
					ed[i][j] = min;
			}
		}
	}
	return ed[n][k];
}
int main() {
	int n=2, k=36;
	cout<<"Min no. of trials: "<<egg_drop(n,k);
	return 0;
}

//complexity:O(n*k)