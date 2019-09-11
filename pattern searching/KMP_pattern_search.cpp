#include <iostream>
#include <string.h>
using namespace std;


void calculate_lps(char *pat, int m, int* lps){
	int i = 1, j=0;
	lps[0] = 0;
	while(i<m){
	if(pat[i] == pat[j]){
		j++;
		lps[i] = j;
		i++;
	}
	else{
		if(j != 0)
			j = lps[j-1];
		else
			lps[i] = 0;
			i++;
	}
}
}

void match_pattern(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);
	int lps[m];
	calculate_lps(pat,m,lps);
	int i=0,j=0;
	while(i<n){
	if(pat[j] == txt[i]){
		i++;
		j++;
		if(j==m){
			cout<<"Pattern found at: "<<i-m<<endl;
			j= lps[j-1];	
		}
	}
	else{
		if(j!=0)
			j=lps[j-1];
		else
			i++;
	}
}
}


int main() {
	char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB"; 
	match_pattern(txt,pat);
	return 0;
}

//Complexity: O(n)