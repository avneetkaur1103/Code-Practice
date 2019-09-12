#include <iostream> 
using namespace std;

void optimised_naive(char *txt, char *pat){
	int n = strlen(txt);
	int m = strlen(pat);
	int i,j;

	while(i<=n-m){
		for (j=0;j<m;j++){
			if(txt[i+j] != pat[j])
				break;
		}
		if(j==m){
			cout<<"pattern found at "<<i<<endl;
			i = i+m;
		}
		else if (j==0)
			i = i+1;
		else
			i = i+j;
	}
}

int main(){
	char txt[]="ABCEABCDABCEABCD";
	char pat[] = "ABCD";
	optimised_naive(txt,pat);
	return 0;
}