#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

string sortString(string s){
	sort(s.begin(),s.end());
	return s;
}

void groupAnagrams(string arr[], int n){
	multimap<string, string> m;
	for(int i=0;i<n;i++){
		string p = arr[i];
		m.insert(pair<string, string> (sortString(p), arr[i]));
	}

	map<string, string>::iterator it;
	for(it = m.begin();it!=m.end();it++)
		cout<<it->first<<" "<<it->second<<endl;;
}

int main(){
	string arr[] = {"acre" , "abcd", "race", "care", "cadb"};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	groupAnagrams(arr,n);
	return 0;
}
