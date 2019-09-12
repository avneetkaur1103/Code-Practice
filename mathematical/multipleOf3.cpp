#include <iostream>
#include <cmath>
using namespace std;

int isMultipleOf3(int n){
	if(n<0)
		n = -n;

	if (n == 0)
		return 1;

	if (n == 1)
		return 0;

	int odd,even;

	while(n){
		if(n&1)
			odd++;
		if(n&2)
			even++;

		n = n>>2;
	}
		return isMultipleOf3(abs(odd-even));
}

int main(){
	int num = 24;
	if(isMultipleOf3(num) == 1)
		cout<<num<<" is a multiple of 3"<<endl;
	else
		cout<<num<<" is NOT a multiple of 3"<<endl;
	return 0;
}

//complexity:O(logn)