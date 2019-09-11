#include <iostream>
#include <climits>
#define INF INT_MAX
using namespace std;

int  print_sol(int p[], int n){int k;
	if(p[n] == 1)
		k =1;
	else
		k = print_sol(p,p[n]-1) + 1;
	cout<<"line no: " << k <<" from word: " <<p[n] <<" to word: "<<n <<" \n";
	return k;
		
}

void word_wrap(int l[], int n, int M){
	int extra[n+1][n+1];
	int lc[n+1][n+1];
	int c[n+1];
	int p[n+1];
	
	int i,j;
	
	for(i=1;i<=n;i++){
		extra[i][i] = M-l[i-1];
		for(j=i+1;j<=n;j++){
			extra[i][j] = extra[i][j-1]-l[j-1]-1;
		}
	}
	
	for (i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(extra[i][j] < 0)
				lc[i][j] = INF;
			else if(j==n && extra[i][j] >=0)
				lc[i][j] = 0;
			else
				lc[i][j] = extra[i][j]*extra[i][j];
		}
	}
	
	c[0] = 0;
	for(j=1;j<=n;j++){
		c[j] = INF;
		for (i= 1;i<=j;i++){
			if(c[i-1] != INF && lc[i][j] != INF && c[i-1]+lc[i][j] <c[j]){
				c[j] = c[i-1]+lc[i][j];
				p[j] = i;
			} 
		}
	}
	print_sol(p,n);
}

int main() {
	int l[] = {3, 2, 2, 5};  
    int n = sizeof(l)/sizeof(l[0]);  
    int M = 6;
    word_wrap(l,n,M);
	return 0;
}

//Complexity: O(n^2)