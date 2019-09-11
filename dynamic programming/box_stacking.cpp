#include <iostream>
using namespace std;
struct Box{
	int h,w,d;
};

int min(int a, int b){
	return (a<b)?a:b;
}

int max(int a , int b){
	return (a>b)?a:b;
}

int compare(const void* a, const void* b){
	return (((*(Box*)b).w * (*(Box*)b).d) - 
		((*(Box*)a).w * (*(Box*)a).d));
}

int box_stack(struct Box arr[], int n){
	int i,j;
	struct Box rot_arr[3*n];
	int idx = 0;
	for(i=0;i<n;i++){
		rot_arr[idx].h = arr[i].h;
		rot_arr[idx].w = min(arr[i].w,arr[i].d);
		rot_arr[idx].d = max(arr[i].w,arr[i].d);
		idx++;
		
		rot_arr[idx].h = arr[i].w;
		rot_arr[idx].w = min(arr[i].h,arr[i].d);
		rot_arr[idx].d = max(arr[i].h,arr[i].d);
		idx++;
		
		rot_arr[idx].h = arr[i].d;
		rot_arr[idx].w = min(arr[i].h,arr[i].w);
		rot_arr[idx].d = max(arr[i].h,arr[i].w);
		idx++;
	}
	
	n = 3*n;
	qsort(rot_arr,n,sizeof(rot_arr[0]),compare);
	

	
	int lis[n];
	int res[n];
	
	for (i=0;i<n;i++)
		lis[i] = rot_arr[i].h;
	
	for (i=1;i<n;i++){
		for (j=0;j<i;j++){
			if((rot_arr[i].w < rot_arr[j].w ) && (rot_arr[i].d < rot_arr[j].d) &&
			(lis[i] <lis[j]+rot_arr[i].h))
				
				lis[i] = lis[j]+rot_arr[i].h;
		}
	}
	int max_ht = -1;
	for (i=0;i<n;i++){
		if(max_ht<lis[i])
			max_ht = lis[i];
	}
	return max_ht;
}
int main() {
	struct Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"The max height is: "<<box_stack(arr,n);
	return 0;
}

//Complexity: O(n^2)