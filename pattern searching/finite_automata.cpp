#include <iostream>
#include <string.h>
using namespace std;
#define NO_OF_CHARS 256


int calculate_state(char *pat,int m, int state, int x){
	if(pat[state] == x && state<m)
		return state+1;

		int ns, i;
		for (ns=state;ns >0;ns--){
			if(pat[ns-1] == x){
				for(i=0;i<ns-1;i++){
					if(pat[i] != pat[state - ns +1 +i])
						break;
				}

					if(i == ns-1)
						return ns;
				
			}
		}
	return 0;	
}

void calculate_FA(char *pat,int m, int FA[][NO_OF_CHARS]){
	int state, x;

	for (state=0;state<m+1;state++){
		for(x=0;x<NO_OF_CHARS;x++){
			FA[state][x] = calculate_state(pat,m,state,x);
		}
	}
}

void search(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);

	int FA[m+1][NO_OF_CHARS];

	calculate_FA(pat,m,FA);

	int state=0;
	for(int i=0;i<n;i++){
		state = FA[state][txt[i]];
		if (state == m)
			cout<<"Pattern found at "<<i-m+1<<endl;
	}
}

int main(){
	char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA";
    search(txt,pat);
    return 0;
}