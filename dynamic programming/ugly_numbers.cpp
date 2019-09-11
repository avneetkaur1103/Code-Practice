#include <iostream>
using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int Nth_Ugly_number(int n){
	int ugly[n];
	ugly[0] = 1;
	int i2=0,i3=0,i5=0;
	int next_ugly_num = 1;
	int multipleof_2 = 2, multipleof_3 = 3, multipleof_5 = 5;
	
	for (int i=1;i<n;i++){
		next_ugly_num  = min(multipleof_2, min(multipleof_3, multipleof_5));
		ugly[i] = next_ugly_num;
		if (next_ugly_num == multipleof_2){
			i2 = i2 + 1;
			multipleof_2 = ugly[i2]*2;
		}
		if (next_ugly_num == multipleof_3){
			i3 = i3 + 1;
			multipleof_3 = ugly[i3]*3;
		}
		if (next_ugly_num == multipleof_5){
			i5 = i5 + 1;
			multipleof_5 = ugly[i5]*5;
		}
	}
	return ugly[n-1];
}
int main() {
	int n = 150;
	cout<<n<<"th ugly number: "<<Nth_Ugly_number(n);
	return 0;
}

//Complexity: O(n)