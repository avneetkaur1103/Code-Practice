#include <iostream>
using namespace std;

int power(int x, unsigned int y){
	if (y==0)
		return 1;
	else if(y%2 == 0)
		return power(x,y/2) * power(x, y/2);
	else
		return x * power(x,y/2) * power(x, y/2);
}

int main(){
	int x = 2, y = 3;
	cout<<power(x,y);
	return 0;
}

//complexity: O(n)