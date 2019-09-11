#include <iostream>
#include <string.h>
using namespace std;

int lookup[101][501];
long count(int n, int sum){
	if (n==0)
		return sum == 0;

		
	if (lookup[n][sum] != -1)
		return lookup[n][sum];
	long ans;
	int i;
	
	for (i=0;i<10;i++){
		if((sum-i)>=0)
			ans += count(n-1,sum-i);
	}
	
	return lookup[n][sum] = ans;
}

long final_count(int n, int sum){
	long ans;
	int i;
	memset(lookup, -1, sizeof(lookup));
	for (i=1;i<10;i++){
		if(sum-i >=0)
			ans += count(n-1,sum-i);
	}
	return ans;
}

int main() {
	int n=3, sum=5;
	cout<<final_count(n,sum);
	return 0;
}

//complexity:O()