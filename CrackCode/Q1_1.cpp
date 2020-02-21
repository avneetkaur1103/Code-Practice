#include <iostream>
#include <string>
#define CHARS 256
using namespace std;

bool isUnique(string str){
	int count[CHARS];
	memset(count,0,256);

	for (int i=0;i<str.length();i++)
		count[str[i]]++;

	for(int i=0;i<str.length();i++)
		if(count[str[i]] > 1)
			return false;

	return true;

}

int main(){
	string str = "Gigs";
	isUnique(str)? cout<<"Yes":cout<<"No";
	cout<<endl;
	string str1 = "Geeks";
	isUnique(str1)? cout<<"Yes":cout<<"No";
	cout<<endl;
	return 0;
}