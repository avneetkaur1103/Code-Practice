#include <iostream>
using namespace std;

bool isSafe(int m, int n, int i, int j){
	if(i>=0 && i<m && j>=0 && j<n)
		return true;

	return false;
}

double findProbability(int m, int n, int i, int j, int N){
	if(!isSafe(m,n,i,j))
		return 0.0;

	if(N==0)
		return 1.0;

	double prob = 0.0;

	prob += findProbability(m,n,i+1,j,N-1)*.25;
	prob += findProbability(m,n,i-1,j,N-1)*.25;
	prob += findProbability(m,n,i,j+1,N-1)*.25;
	prob += findProbability(m,n,i,j-1,N-1)*.25;

	return prob;

}

int main() 
{
    int m = 5, n = 5;
    int i = 1, j = 1;
    int N = 2; 
  
    cout << "Probability is "
        << findProbability(m, n, i, j, N); 
    return 0; 
}