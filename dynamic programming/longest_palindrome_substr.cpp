#include <iostream>
#include <string.h>
using namespace std;

int palindrome_substr(string str){
	int n = str.size();
	bool P[n][n];
	memset(P,0,sizeof(P));
	
	int i,j;
	int start = 0;
	int max_len = 1;
	
	for (i=0;i<n;i++)
		P[i][i] = true;
		
	for (i=0;i<n;i++){
		if (str[i] == str[i+1]){
			P[i][i+1] = true;
			start = i;
			max_len = 2;
		}
	}
	
	int k;
	for (k=3; k<=n; k++){
		for (i=0; i<=n-k+1;i++){
			j = i+k-1;
			
			if(P[i+1][j-1] && str[i] == str[j]){
				P[i][j] = true;
				start = i;
				if(max_len < k)
					max_len = k;
			}
		}
	}
	
	cout<<"Print Palindrome substr: ";
	for (i=start; i<=start+max_len -1; i++)
			cout<<str[i];
	cout<<endl;
	
	return max_len;
}

int main() {
	string str = "forgeeksskeegrog";
	cout<<" The max_len of palindrome substring is : " << palindrome_substr(str);
	return 0;
}

//Complexity: O(n^2)