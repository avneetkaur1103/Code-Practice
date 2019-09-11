#include <iostream>
#include <vector>
using namespace std;

int deno[]={1,2,5,10,20,50,100,200,500,2000};
int n = sizeof(deno)/sizeof(deno[0]);

void printchange(int v){
	vector<int> result;
	
	for (int i = n-1; i>=0; i--){
		while(v>=deno[i]){
			v -= deno[i];
			result.push_back(deno[i]);
		}
	}
	
	for (int j=0;j<result.size();j++){
		cout<<result[j]<<"\t";
	}
}
int main() {
	int num = 93;
	printchange(num);
	return 0;
}

//complexity: O(n)