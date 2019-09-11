#include <iostream>
#include <algorithm>
using namespace std;

struct City{
	int north;
	int south;
};

bool compare(struct City a, struct City b){
	if(a.south == b.south)
		return a.north < b.north;
	else
		return a.south < b.south;
}

int build_bridges(struct City pairs[], int n){
	int lis[n];
	int i,j;
	int max=0;
	sort(pairs, pairs+n, compare);
	
	for (i=0;i<n;i++)
		lis[i] = 1;
		
	for (i=1;i<n;i++){
		for(j=0;j<i;j++){
			if(pairs[i].north >= pairs[j].north && lis[i]<lis[j]+1)
				lis[i] = lis[j]+1;
		}
	}
	
	for(i=0;i<n;i++){
		if(max < lis[i])
			max = lis[i];
	}
	return max;
}

int main() {
	struct City pairs[] = {{6, 2}, {4, 3}, {2, 6}, {1, 5}}; 
    int n = 4;
    cout<<"Max bridges built: " <<build_bridges(pairs,n);
	return 0;
}

//Complexity:O(n^2)