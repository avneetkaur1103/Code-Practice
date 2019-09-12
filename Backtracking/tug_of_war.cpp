#include <iostream>
#include <climits>
using namespace std;

void tugOfWarUtil(int arr[], int n, bool curr_ele[], int num_of_curr_ele, int sum,bool sol[], int *min_diff, int current_sum, int curr_pos){
	if(curr_pos == n)
			return;

	if((n/2 -  num_of_curr_ele) > (n - curr_pos))
		return;

	tugOfWarUtil(arr,n,curr_ele,num_of_curr_ele,sum,sol,min_diff,current_sum,curr_pos+1);
	num_of_curr_ele++;
	current_sum = current_sum + arr[curr_pos];
	curr_ele[curr_pos] = true;

	if(num_of_curr_ele == n/2){
		if(abs(sum/2 - current_sum) < *min_diff){
			*min_diff = abs(sum/2 - current_sum);
			for(int i=0;i<n;i++)
					sol[i] = curr_ele[i];
		}
	}
	else{

		tugOfWarUtil(arr,n,curr_ele,num_of_curr_ele,sum,sol,min_diff,current_sum,curr_pos+1);
	}
	curr_ele[curr_pos] = false;
}

void tugOfWar(int arr[], int n){
	bool *curr_ele = new bool[n];
	bool *sol = new bool[n];

	int min_diff = INT_MAX;	
	int sum=0;

	for(int i=0;i<n;i++){
		sum += arr[i];
		curr_ele[i] = sol[i] = false;
	}

	tugOfWarUtil(arr,n,curr_ele,0,sum,sol,&min_diff,0,0);

	cout<<"First half is: ";
	for(int i=0;i<n;i++){
		if(sol[i] == true)
			cout<<arr[i]<<"\t";
	}
	cout<<endl;

	cout<<"Second half is: ";
	for(int i=0;i<n;i++){
		if(sol[i] == false)
			cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	tugOfWar(arr,size);
	return 0;
}