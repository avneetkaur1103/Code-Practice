#include <iostream>
#include <string>

#define CHARS 256
using namespace std;

bool permutation(string s, string t){
	if(s.length() != t.length())
		return false;

	int s_array[CHARS];
	memset(s_array,0,CHARS);

	for(int i=0;i<s.length();i++)
		s_array[s[i]]++;

	for(int j=0;j<t.length();j++)
		s_array[t[j]]--;

	for(int i=0;i<sizeof(s_array);i++)
		if(s_array[i]<0){
			
			return false;
		}

	return true;
}

int main(){
	string s = "abcd";
	string t = "bcad";
	permutation(s,t)?cout<<"Yes":cout<<"No";
	cout<<endl;
	return 0;
}