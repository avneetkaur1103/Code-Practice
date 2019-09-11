#include <iostream>
using namespace std;

int count_no_of_ways_util(int s, int m){
	int res[s];
	res[0] = 1;
	res[1] = 1;
	int i,j;
	
	for (i=2;i<s;i++){
		res[i] = 0;
		for (j=1;j<=m && j<=i; j++){
			res[i] += res[i-j];
		}
	}
	return res[s-1];
}

int count_no_of_ways(int s, int m){
	return count_no_of_ways_util(s+1,m);
}
int main() {
	int s = 4;
	int m = 2;
	cout<<" Number of ways to climb the stairs: "<<count_no_of_ways(s,m);
	return 0;
}

/Complexity:O(mn)