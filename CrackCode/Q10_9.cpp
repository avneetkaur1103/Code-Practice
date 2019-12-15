#include <iostream>
using namespace std;

//cols
#define M 5
//rows
#define N 4

void binarySearch(int matrix[][M], int i, int j_low, int j_high, int x){
	while(j_low <= j_high){
		int j_mid = (j_low + j_high)/2;
		if(matrix[i][j_mid] == x){
			cout<<i<<", "<<j_mid;
			return;
		}
		else if (x<matrix[i][j_mid])
			j_high = j_mid - 1;
		else if(x>matrix[i][j_mid])
			j_low = j_mid + 1;
	}
}

void sortedMatrixSearch(int matrix[][M], int x){
	if(N == 1)
		binarySearch(matrix,0,0,M-1,x);

	int i_low = 0;
	int i_high = N-1;
	int j_mid = M/2;
	int i_mid;

	while(i_low+1 < i_high){
		i_mid = (i_low + i_high)/2;
		if(matrix[i_mid][j_mid] == x)
			cout<<i_mid<<", "<<j_mid;
		else if (x<matrix[i_mid][j_mid])
			i_high = i_mid - 1;
		else if(x>matrix[i_mid][j_mid])
			i_low = i_mid + 1;
	}

	if(x == matrix[i_low][j_mid])
		cout<<i_low<<", "<<j_mid;
	else if(x == matrix[i_low+1][j_mid])
		cout<<1+i_low<<", "<<j_mid;
	else if(x<=matrix[i_low][j_mid-1])
		binarySearch(matrix,i_low,0,j_mid-1,x);
	else if(x>= matrix[i_low][j_mid+1] && x<matrix[i_low][M-1])
		binarySearch(matrix,i_low,j_mid+1,M-1,x);
	else if(x<=matrix[i_low+1][j_mid-1])
		binarySearch(matrix,i_low+1,0,j_mid-1,x);
	else
		binarySearch(matrix,i_low+1,j_mid+1,M-1,x);


}

int main(){
	int matrix[N][M] = {{0, 6, 8, 9, 11}, 
                     {20, 22, 28, 29, 31}, 
                     {36, 38, 50, 61, 63}, 
                     {64, 66, 100, 122, 128}};
	int x = 61;
	cout<<"Position of x: ";
	sortedMatrixSearch(matrix,x);
	return 0;
}

//Complexity: O(log n)