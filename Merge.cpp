#include <iostream>
using namespace std;

void merge(int arr[],int l, int m, int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r - m;
	
	int L[n1],R[n2];
	for (i=0;i<n1;i++)
		L[i]=arr[l+i];
	for (j=0;j<n2;j++)
		R[j]= arr[m+1+j];
		
	/*for (int a=0;a<n1;a++)
		cout<<L[a]<<"\t";
	cout<<endl;
	for (int b=0;b<n2;b++)
		cout<<R[b]<<"\t";
	*/
		
	i=0;
	j=0;
	k=l;
	
	while (i<n1 && j<n2){
		if (L[i]<=R[j]){
			arr[k]=L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}
	
}

void mergesort(int arr[], int l, int r){
	if(r>l){
		int m = l + (r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
	
		merge(arr,l,m,r);
	}
}

void printarr(int arr[], int n){
	for (int  i =0; i<n; i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

int main() {	
	int arr[] = {21,12,90,56,34,45,1,88};
	int n = sizeof(arr)/sizeof(arr[0]);
	printarr(arr,n);
	mergesort(arr,0,n-1);
	printarr(arr,n);
	return 0;
}
