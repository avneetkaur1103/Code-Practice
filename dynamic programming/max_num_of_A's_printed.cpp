#include <iostream>
using namespace std;

int max_A_print(int N){
	int out[N];
	if (N<=6)
		return N;
		
	for(int i=0;i<=6;i++)
		out[i-1] = i;
		
	for(int i=7;i<=N;i++){
		out[i-1] = 0;
		for(int b = i-3;b>=1;b--){
			int curr = (i-b-1)*out[b-1];
			if (curr > out[i-1])
				out[i-1] = curr;
		}
	}
	
	return out[N-1];
}

int main() {
	int N=7;
	cout<<"Maximum number of A's printed with "<<N<<" keypresses: "<<max_A_print(N);
	return 0;
}

//Complexity: O(n)