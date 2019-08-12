#include <iostream>
#include <climits>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[],int l, int r){
	int pivot = arr[r];
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

int random_partition(int arr[], int l, int r){
	int n = r-l+1;
	int pivot = rand()%n;
	swap(&arr[1+pivot], &arr[r]);
	return partition(arr,l,r);
}

int KthSmallest_Linear_Time(int arr[], int l , int r, int k){
	
	if(k>0 && k<=r-l+1){
		
		int pos = random_partition(arr,l,r);
		
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


//complexity: Best & avg: O(n), worst: o(n^2)