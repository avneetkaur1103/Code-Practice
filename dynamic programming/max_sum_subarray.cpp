#include <iostream>
#include <climits>
#include <string.h>
using namespace std;
#define ROW 4
#define COL 5

int kadane(int temp[], int *start, int *finish, int n){
	int sum =0	, max_sum = INT_MIN,	i;
	int local_start = 0;
	*finish = -1;
	
	for (i=0;i<n;i++){
		sum += temp[i];
		
		if(sum < 0){
			sum = 0;
			local_start = i+1;
		}	
		else if(sum > max_sum){
			max_sum = sum;
			*start = local_start;
			*finish = i;
		}
	}
	
	if (*finish != -1)
		return max_sum;
	
	max_sum = temp[0];
	*start = *finish = 0;
	for (i=1;i<n;i++){
		if(temp[i] > max_sum)
			max_sum = temp[i];
			*start = *finish = i;
	}
	
	return max_sum;
	
}

void max_sum_2d_array(int arr[ROW][COL]){
	int max_sum = INT_MIN;
	int max_l,max_r,max_t,max_b;
	int sum, start, finish;
	int temp[ROW];
	int i, left,right;
	
	for (left = 0;left <COL; left++){
		memset(temp,0,sizeof(temp));
		
		for (right = left; right <= COL; right++){
			for (i = 0;i <ROW;i++)
				temp[i] += arr[i][right];
				
				sum = kadane(temp, &start, &finish, ROW);
				 if (sum > max_sum){
				 	max_sum = sum;
				 	max_l = left;
				 	max_r = right;
				 	max_t = start;
				 	max_b = finish;
				 }
		}
	}
	cout<<" Max sum is: "<<max_sum<<endl;
	cout<<" final left and right are " << max_l << " and " << max_r << " respectively."<<endl;
	cout<<" final top and bottom are " << max_t << " and " << max_b << " respectively."<<endl;
}

int main(){
	
	int M[ROW][COL] = {{1, 2, -1, -4, -20},  
                       {-8, -3, 4, 2, 1},  
                       {3, 8, 10, 1, 3},  
                       {-4, -1, 1, 7, -6}};  
                       
    max_sum_2d_array(M);
    
    return 0;
}

//Complexity: O(n^3)