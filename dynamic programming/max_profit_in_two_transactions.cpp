#include <iostream>
using namespace std;

int maxProfit(int price[], int n){
	int profit[n];
	int i;
	for (i=0;i<n;i++)
		profit[i] = 0;
		
	int max_price, min_price;
	
	max_price = price[n-1];
	for (i=n-2;i>=0;i--){
		if (price[i] > max_price)
			max_price = price[i];
			
		profit[i] = max(profit[i+1], max_price - price[i]);
	}
	
	min_price = price[0];
	for (i=1;i<n;i++){
		if(price[i] < min_price)
			min_price = price[i];
			
		profit[i] = max(profit[i-1], profit[i] + (price[i] - min_price));
	}
	
	return profit[n-1];
}

int main() {
	int price[] = {2, 30, 15, 10, 8, 25, 80}; 
    int n = sizeof(price)/sizeof(price[0]); 
    cout << "Maximum Profit = " << maxProfit(price, n); 
	return 0;
}

//Complexity:O(n)