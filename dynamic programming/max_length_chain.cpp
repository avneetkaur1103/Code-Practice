#include <iostream>
using namespace std;

class Pair{
	public:
			int a;
			int b;
};

int max_length_chain(Pair arr[], int n){
	int *mlc = new int[sizeof(int) * n]; // we can take int mlc[n] too
	int i,j;
	int max = 0;
	
	for(i=0;i<n;i++)
		mlc[i] = 1;
		
		
	for (i=1;i<n;i++){
		for (j=0;j<i;j++){
			if(arr[i].a > arr[j].b && mlc[i] < mlc[j] + 1)
				mlc[i] = mlc[j] + 1;
		}
	}
	
	for (i=0;i<n;i++){
		if (max < mlc[i])
			max = mlc[i];
	}
	return max;
}

int main() {
	Pair arr[] = { {5, 24}, {15, 25},  {27, 40}, {50, 60} };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"length of max length chain is : " <<max_length_chain(arr, n);
	return 0;
}

//Complexity: O(n^2)