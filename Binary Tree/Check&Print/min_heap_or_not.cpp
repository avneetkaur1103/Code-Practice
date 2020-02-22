#include <iostream>
using namespace std;

bool isMinHeap(int level[], int n){
	int r = n/2 - 1;

	for(int i=r;i>=0;i--){
		if (level[i] > level[2*i+1])
			return false;

		if(n > 2*i+2){
			if(level[i] > level[2*i+2])
				return false;
		}
	}
	return true;
}


int main(){
	int level[] = {10, 15, 14, 25, 30};
	int n = sizeof(level)/sizeof(level[0]);
	if(isMinHeap(level,n))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}

//Complexity: O(n)
