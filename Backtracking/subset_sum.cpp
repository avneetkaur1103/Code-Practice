#include <iostream>
#include <algorithm>
using namespace std;

static int total_nodes=0;

bool cmp(int a, int b){
	return (a<b)?true:false;
}

void printsol(int arr[], int size){
	for (int i=0;i<size;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

void subset_sum_util(int s[], int t_vector[], int s_size, int t_size, int sum, int ite, int target){
	total_nodes++;

	if(target == sum){
		printsol(t_vector, t_size);
		if(ite+1<s_size && sum - s[ite] + s[ite+1] <=target )
			subset_sum_util(s,t_vector,s_size,t_size-1,sum - s[ite],ite+1,target);

		return;
	}
	else{
		if(ite<s_size && sum +s[ite+1] <= target){

			for(int i=ite;i<=s_size;i++){
				t_vector[t_size] = s[i];
				if(sum + s[i] <= target)
					subset_sum_util(s,t_vector,s_size,t_size+1,sum+s[i],i+1,target);

			}
		}
	}
}

void subset_sum(int s[], int size, int target){
	int i, total = 0;

	sort(s, s+size, cmp);
	printsol(s, size);

	for(i=0;i<size;i++)
		total += s[i];

	int *t_vector = (int *)malloc(size * sizeof(int));

	if(s[0] <= target && total >= target){
		//cout<<"I am here "<<endl;
		subset_sum_util(s, t_vector,size,0,0,0,target);
	}

	free(t_vector);
}


int main(){
	int s[] = {15, 22, 14, 26, 32, 9, 16, 8}; 
	int target = 53;
	int size = sizeof(s)/sizeof(s[0]);
	subset_sum(s,size,target);
	return 0;
}