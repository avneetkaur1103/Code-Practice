#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define prime 101

int calc_hash(char str[], int len){
	int i, h=0;
	for(i=0;i<=len;i++){
		h += (str[i] * pow(prime,i));
	}	
	return h;
}

bool checkequal(char *txt, int start1, int end1, char *pat, int start2, int end2){
	if(end1-start1 != end2-start2)
		return false;

	while(start1<=end1 && start2<=end2){
		if(txt[start1] != pat[start2])
			return false;

		start1++;
		start2++;
	}
	return true;
}

int recalculatehash(int prevhash,int oldstart, int newstart, char *txt,int len){
	int newhash = prevhash - txt[oldstart];
	newhash = newhash/prime;
	newhash = newhash + txt[newstart]* pow(prime,len-1);
	return newhash;
}

void rabin_karp_search(char *txt,char *pat){
	int m = strlen(pat);
	int n = strlen(txt);

	int p=0,t=0;
	int i;
	p = calc_hash(pat,m-1);
	t = calc_hash(txt,m-1);

	for(i=1;i<n-m+1;i++){
		if(p==t && checkequal(txt,i-1,i-1+m-1,pat,0,m-1))
			cout<<"Pattern found at index: "<<i-1<<endl;
	
	if(i<n-m+1)
		t = recalculatehash(t,i-1,i+m-1,txt,m);
	}
	//cout<<"Pattern not found"<<endl;
}

int main(){
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "FOR";
	rabin_karp_search(txt,pat);
	//cout<<"Pattern found at index: "<<idx;
	return 0;
}

//Complexity:O(m*n)