#include <iostream>
#include <string>

using namespace std;

char* URLify(string str){
	int no_of_spaces=0;
	//cout<<str.length()<<endl;
	for(int i=0;i<str.length();i++)
		if(str[i] == ' ')
			no_of_spaces++;

	int new_len = str.length() + no_of_spaces*2;
	//cout<<new_len<<endl;
	//string *new_str = new string[new_len];
	char *new_str = new char[new_len];
	for(int i=str.length() - 1;i>=0;i--){
		if(str[i] == ' '){
			new_str[new_len-1] = '0';
			new_str[new_len-2] = '2';
			new_str[new_len-3] = '%';
			new_len = new_len-3;
		}
		else{
			new_str[new_len - 1] = str[i];
			new_len--;
		}
	}
	return new_str;
}

int main(){
	string str = "Mr John Smith";
	cout<<URLify(str);
	
	return 0;
}