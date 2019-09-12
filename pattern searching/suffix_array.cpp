#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct suffix{
	int index;
	char *suff;
};

int cmp(struct suffix a, struct suffix b){
	return ((strcmp(a.suff,b.suff) < 0)?1:0);
}

int* build_suffix_array(char *txt, int n){
	struct suffix s[n];
	int i;

	for(i=0;i<n;i++){
		s[i].index = i;
		s[i].suff = txt+i;
	} 
	sort(s,s+n,cmp);

	int *suffArr = new int[n];

	for(i=0;i<n;i++)
		suffArr[i] = s[i].index;

	return suffArr;
}

void PrintArr(int arr[], int n){
	for (int i = 0;i<n;i++)
		cout<<arr[i]<<"\t";

	cout<<endl;
}

void pattern_search(char *txt,char *pat,int n, int suffArr[]){
	int m = strlen(pat);
	int l=0, r=n-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		int res = strncmp(pat, txt+suffArr[mid],m);
		if(res ==0){
			cout<<"Pattern found at index: "<<suffArr[mid]<<endl;
			return;
		}
		else if (res<0)
			r = mid -1;
		else
			l= mid+1;
	}
	cout<<"Pattern not found"<<endl;
	
}

int main(){
	char txt[]="banana";
	int n = strlen(txt);
	int *suffArr = build_suffix_array(txt,n);
	PrintArr(suffArr,n);
	char pat[]="nan";
	pattern_search(txt,pat,n,suffArr);
	return 0;
}