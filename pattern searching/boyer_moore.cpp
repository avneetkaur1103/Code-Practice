#include <iostream>
#include <string.h>
using namespace std;
#define NO_OF_CHARS 256


void bad_char_heuristic(char *pat, int m, int badchar[NO_OF_CHARS]){
	int i;
	for(i=0;i<NO_OF_CHARS;i++)
		badchar[i] = -1;

	for(i=0;i<m;i++)
		badchar[(int)pat[i]] = i;
}

void search(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);

	int badchar[NO_OF_CHARS];

	bad_char_heuristic(pat,m,badchar);

	int s=0;

	while(s<=n-m){
		int j = m-1;

		while (j>=0  && pat[j] == txt[s+j])
			j--;

		if(j < 0){
			cout<<"Pattern occurs at: " << s<<endl;
			s += (s+m < n)? m - badchar[txt[s+m]] : 1; // case where pattern is matched and we need to slide to find next occurrance.
		}
		
		else
			s += max(j-badchar[txt[s+j]], 1); // case where mismatch occurs and we slide pattern to match that particluar char in txt to pattern.

	}
}

int main(){
	char txt[] = "ABAAABCD";
	char pat[] = "ABC";
	search(txt,pat);
	return 0;
}

//Complexity: O(n/m)