#include <iostream>
#include <climits>
using namespace std;

int min_number_of_coin_change(int coin[], int m, int V){
	int dp[V+1];

	dp[0] = 0;
	for (int i=1;i<V+1;i++)
		dp[i] = INT_MAX;
		
	for (int i=0;i<V+1;i++){
		for (int j=0;j<m;j++){
			if(coin[j] <= i ){
				int subsol = 1+dp[i-coin[j]];
				if(subsol != INT_MAX && subsol<dp[i] )
					dp[i] = subsol;
			}
		}
	}
	return dp[V];
}

int main() {
	int coin[] =  {9, 6, 5, 1}; 
    int m = sizeof(coin)/sizeof(coin[0]); 
    int V = 11; 
    cout << "Minimum coins required is "<<min_number_of_coin_change(coin, m,V);
	return 0;
}

//Complexity: O(m*V)