#include <iostream>
#include <string>

using namespace std;
#define CHARS 256


bool compare(char arr1[], char arr2[]){
	for (int i=0;i<CHARS;i++){
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

void anagram_search(char *txt, char *pat){
	int m = strlen(pat);
	int n = strlen(txt);
	int i;
	char countP[CHARS]={0};
	char countT[CHARS]={0};

	for(i=0;i<m;i++){
		countP[pat[i]]++;
		countT[txt[i]]++;
	}

	for(i=m;i<n;i++){
		if(compare(countP, countT))
			cout<<"Pattern found at index: "<<i-m<<endl;

		countT[txt[i]]++;
		countT[txt[i-m]]--;
	}

	if(compare(countP,countT))
		cout<<"Pattern found at index: "<<n-m<<endl;
}

int main(){
	char txt[] = "BACDGABCDA";
	char pat[] = "ABCD";
	anagram_search(txt,pat);
	return 0;
}


//Complexity: O(n)