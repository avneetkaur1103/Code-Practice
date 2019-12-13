#include <iostream>
#include <cstring>
using namespace std;

void mergeArrays(int A[], int B[], int a, int b){
	int t = a+b-1;
	int i,j,k;
	int arr[t];
	memset(arr,0,sizeof(arr));

	while(i<a && j<b){
		if(A[i] < B[j]){
			cout<<A[i]<<endl;
			arr[k] = A[i];
			i++;
		}
		else{
			cout<<B[j]<<endl;
			arr[k] = B[j];
			j++;
		}
		k++;
	}

	while(i<a){
		cout<<"Last while:"<<A[i]<<endl;
		arr[k] = A[i];
		i++;
		k++;
	}

	while(j<b){
		cout<<"Last While:"<<B[j]<<endl;
		arr[k] = B[j];
		j++;
		k++;
	}
	
	/*for(int k=0;k<a;k++)
		cout<<arr[k]<<" ";*/
}

int main(){
	int A[15] = {1,3,7,8,9,15,32};
	int B[5] = {2,10,13,20,35};
	int a = sizeof(A)/sizeof(A[0]);
	int b = sizeof(B)/sizeof(B[0]);
	
	mergeArrays(A,B,a,b);
	
	return 0;
}