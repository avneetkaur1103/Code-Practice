#include <iostream>
#include <climits>
using namespace std;

bool isSameBSTUtil(int a[], int b[], int n, int i1, int i2, int min, int max){
	int i,j;

	for(i = i1;i<n; i++){
		if(a[i] > min && a[i] < max)
			break;
	}

	for(j=i2;j<n;j++){
		if(b[j] > min && b[j] < max)
			break;
	}

	if(i==n && j==n)
		return true;

	if(i==n || j==n || a[i] != b[j])
		return false;

	return (isSameBSTUtil(a,b,n,i+1,j+1,min,a[i]) && isSameBSTUtil(a,b,n,i+1,j+1,a[i], max));
}

bool isSameBST(int a[], int b[], int n){
	return isSameBSTUtil(a,b,n,0,0,INT_MAX, INT_MIN);
}

int main()  
{  
    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};  
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};  
    int n=sizeof(a)/sizeof(a[0]);  
    if(isSameBST(a, b, n)) 
    { 
        cout << "BSTs are same"; 
    } 
    else
    { 
        cout << "BSTs not same"; 
    } 
    return 0;  
}

//Complexity: O(n)