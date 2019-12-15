#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

#define max 80000
//Can change max later

int MissingInt(int arr[], int n){
	//int max = max_element(0,n-1);
	bitset<max> bv;

	for(int i=0;i<n;i++){
		bv[arr[i]] =true;
	}

	for(auto i=0;i<max;i++){
		if(!bv[i])
			return i;
	}
	return -1;
}

void Duplicate(int arr[], int n){
	//int max = max_element(0,n-1);
	bitset<max> bv;

	for(int i=0;i<n;i++){
		if(!bv[arr[i]] )
			bv[arr[i]] =true;
		else
			cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[] = {1,7,90,46,83,86,23,45,62,99,100,0,56,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Missing number: "<<MissingInt(arr,n);

	cout<<endl;

	int arr1[] = {1,7,90,46,83,86,23,45,1,62,99,100,0,56,99,2};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout<<"Duplicate numbers: ";
	Duplicate(arr1,n1);
	return 0;
}