#include <iostream>
using namespace std;

long multiplyBy7(long n){
	return ((n<<3) - n);
}

int main(){
	int num = 5;
	cout<<multiplyBy7(num)<<endl;
}

//complexity: O(1)