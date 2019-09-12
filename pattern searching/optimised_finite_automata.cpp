#include <iostream>
#include <string.h>
using namespace std;
#define NO_OF_CHARS 256

void construct_FA(char *pat, int m, int FA[][NO_OF_CHARS]){
	int i,x,lps=0;
	for(x=0;x<NO_OF_CHARS;x++)
		FA[0][x] = 0;
	FA[0][pat[0]] = 1;

	for(i=1;i<m+1;i++){
		for(x=0;x<NO_OF_CHARS;x++)
			FA[i][x] = FA[lps][x];

		FA[i][pat[i]] = i+1;

		if(i<m)
			lps = FA[lps][pat[i]];
	}

}

void search(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);

	int FA[m+1][NO_OF_CHARS];
	construct_FA(pat,m,FA);

	int i,j=0;
	for (i=0;i<n;i++){
		j = FA[j][txt[i]];
		if(j == m)
			cout<< "Pattern found at "<<i-m+1<<endl;
	}

}

int main(){
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEKS";

	search(txt,pat);
	return 0;
}

//complexity: O(m*NO_OF_CHARS)