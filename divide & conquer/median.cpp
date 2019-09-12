#include <iostream>
using namespace std;

int median(int arr[], int n){
		if(n%2 == 0)
			return (arr[n/2] + arr[n/2-1])/2;
		else
			return arr[n/2];
}

int getMedian(int a[], int b[], int n){
	if(n <= 0)
		return -1;

	if (n == 1)
		return (a[0] + b[0])/2 ;

	if(n == 2)
		return (max(a[0],b[0]) + min(a[1], b[1]))/2;

	int m1 = median(a,n);
	int m2 = median(b,n);

	if(m1 == m2)
		return m1;

	else if(m1 > m2){
		if(n%2 == 0)
			return getMedian(a,b+n/2-1,n-n/2+1);
		return getMedian(a,b+n/2,n-n/2);
	}
	else{
		if(n%2 == 0)
			return getMedian(a+n/2-1,b,n-n/2+1);
		return getMedian(a+n/2,b,n-n/2);
	}
}

int main(){
	int arr1[] = {1, 2, 3, 6}; 
    int arr2[] = {4, 6, 8, 10}; 

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    if(n1 == n2)
    	cout<<"Median: "<<getMedian(arr1, arr2, n1)<<endl;
    else
    	cout<<"Cannot get median for unequal sized array"<<endl;

    return 0;
}

//Complexity: O(logn)