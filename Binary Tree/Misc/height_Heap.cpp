#include <iostream>
#include <cmath>
using namespace std;

int heightCompleteBT(int n){
	return ceil(log2(n+1)) -1;
}

int main(){
	int n = 6;
	cout<<"Height: "<<heightCompleteBT(n);
	return 0;
}