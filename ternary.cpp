#include <iostream>
using namespace std;

int ternary_search(int arr[], int l, int h, int x){
	if (h>=l){
		int mida = l+(h-1)/3;
		int midb = mida+(h-1)/3;
		
		if (arr[mida] == x)
			return mida;
		if(arr[midb] == x)
			return midb;
		
		if (arr[mida] > x)
			return ternary_search(arr,l,mida-1,x);
		if (arr[midb] < x)
			return ternary_search(arr,midb+1,h,x);
		else
			return ternary_search(arr,mida+1,midb-1,x);
	}	
	return -1;
}

int main() {
	int arr[]={0,11,22,33,44,55,66,77};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 44;
	cout<<ternary_search(arr,0,n-1,x);
	return 0;
}