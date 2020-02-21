#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string text, string pattern){
	int m = text.length();
	int n = pattern.length();

	for(int i=0;i<m-n;i++){
		int j;
		for(j=0;j<n;j++){
			if(text[i+j] != pattern[j])
				break;
		}

		if(j==n)
			return true;
	}
	return false;
}

bool isRotation(string s1, string s2){
	string s3 = s2 + s2;
	//cout<<s3<<endl;
	return isSubstring(s3,s1);
}

int main(){
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	isRotation(s1,s2)?cout<<"Yes":cout<<"No";
	return 0;
}