#include <iostream>
#include <string.h>
using namespace std;

void naive_pattern_search(char *str,char *pat){
	int m = strlen(str);
	int n = strlen(pat);
	
	for (int i=0;i<m-n;i++){
		int j;
		for (j=0;j<n;j++)
			if(str[i+j] != pat[j])
				break;
			
			if(j==n)
				cout<<"Pattern found at index: "<<i<<endl;
	}
}

int main(){
	char str[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA";
    naive_pattern_search(str,pat);
	return 0;
}

//Complexity: BestCase: O(n) | Worstcase: O(n* (m-n+1))