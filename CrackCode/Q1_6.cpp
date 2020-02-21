#include <iostream>
#include <string>

using namespace std;

string StringCompress(string str){
	string compStr = "";
	
	int consCount = 1;
	for(int i=0;i<str.length();i++){
		if(str[i+1] == str[i]){
			consCount++;
		}
		else{
			compStr += str[i];
			compStr += to_string(consCount);
			consCount = 1;
		}
	}
	if(str.length() <= compStr.length())
		return str;

	return compStr;
}

int main(){
	string str = "aaaabccccddde";
	cout<<StringCompress(str);
	cout<<endl;
	string str1 = "abcd";
	cout<<StringCompress(str1);
	cout<<endl;
	return 0;
}