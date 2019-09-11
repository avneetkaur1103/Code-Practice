#include <iostream>
#include <string.h>
using namespace std;

int number_of_ways_of_tiling(int m, int n){
	int count[n+1];
	memset(count,0,sizeof(count));
	int i;
	for(i=0;i<=n;i++){
		if (i<m)
			count[i] =1;
		else if(i==m)
			count[i] = 2;
		else if (i>m)
			count[i] = count[i-1] + count[i-m];
	}
	return count[n];
}

int main(){
	int n = 7, m = 4; 
	cout<<"Number of ways of tiling the floor: "<<number_of_ways_of_tiling(m,n);	
	return 0;
}

//Complexity: O(n)