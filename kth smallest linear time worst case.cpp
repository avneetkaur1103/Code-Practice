#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l, int r, int pivot){
	int j;
	for (j=1;j<r;j++)
		if(arr[j] == pivot)
			break;
	swap(&arr[j], &arr[r]);
	
	
	int i = l-1;
	//int i = l;
	for (int j=l;j<r-1;j++){
		if (arr[j] <= pivot){
			i++;
			swap(&arr[i],&arr[j]);
			//i++;
		}
	}
	swap(&arr[i+1], &arr[r]);
	//swap(&arr[i],&arr[r]);
	return (i+1);
	//return i;
}


int find_median(int arr[], int n){
	sort(arr,arr+n);
	return arr[n/2];
}

int KthSmallest_Linear_Time(int arr[], int l , int r, int k){
	
	if(k>0 && k<=r-l+1){
		int n = r-l+1;
		int i, median[(n+4)/5];
		for (i=0;i<n/5;i++)
			median[i]= find_median(arr+l+i*5,5);
		if(i*5<n){
			median[i] = find_median(arr+l+i*5,n%5);
			i++;
		}
		
		int medofmeds = (i==1) ? median[i-1] : KthSmallest_Linear_Time(median,0,i-1,i/2);
		int pos = partition(arr,l,r,medofmeds);
		
		if(pos-l == k-1)
			return arr[pos];
		if(k-1 < pos-l)
			return KthSmallest_Linear_Time(arr,l,pos-1,k);
		else
			return KthSmallest_Linear_Time(arr,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}
int main() {
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k=3;
	cout<<"KthSmallest_Linear_Time: "<<KthSmallest_Linear_Time(arr,0,n-1,k);
	return 0;
}

//Complexity:O(n)