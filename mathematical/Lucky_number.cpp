#include <iostream>
using namespace std;

int luckyNumber(int n){
	static int counter = 2;
	if (counter > n)
		return 1;
	if (n%counter == 0)
		return 0;

	n -= n/counter;
	counter++;
	return luckyNumber(n);
}

int main(){
	int num = 19;
	if(luckyNumber(num))
		cout<<num<<" is a lucky number";
	else
		cout<<num<<" is NOT a lucky number";
	return 0;
}