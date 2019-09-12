#include <iostream>

using namespace std;

void permutation(string str, int l, int r){
	if(l==r)
		cout<<str<<endl;

	else{

		for(int i=l;i<=r;i++){
			swap(str[l],str[i]);
			permutation(str,l+1,r);
			swap(str[l],str[i]);
		}
	}
}

int main(){
	string str = "ABC";
	int len = str.size();
	permutation(str,0,len-1);
	return 0;
}

//Complexity:O(n * n!)