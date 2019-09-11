#include <iostream>
using namespace std;

int count_ways_to_construct_building(int N){
	int result[N], countB[N], countS[N];
	countB[0] = countS[0] = 0;
	countB[1] = countS[1] = 1;
	
	for (int i=0;i<N;i++)
		result[i] = 0;
		
	if(N==0)
		return (result[0] = 0);
	if(N==1)
		return (result[1] = 4);
		
	
	
	for (int i=2;i<=N;i++){
		
		countS[i] = countB[i-1] + countS[i-1];
		countB[i] = countS[i-1];
		result[i] = countB[i] + countS[i];
	}
	
	return (result[N] * result[N]);
}

int main() {
	int N = 3;
	cout<<"Number of ways in which we can construct building is: "<<count_ways_to_construct_building(N);
	return 0;
}

//Complexity: O(n)