#include <iostream>
#include <string>
using namespace std;

int getnum(char n){
	if(n>='0' && n<='9')
			return (n-'0');
	if (n>='A' && n<='D')
		return (n-'A'+10);

	return NULL;
}

char convertNum(int n){
	if(n>=0 && n<=9)
		return (n+'0');
	if (n>=10 && n<=14)
		return (n+'A'-10);

	return NULL;
}

char* sum(char num1[], char num2[]){
	int l1 = strlen(num1);
	//cout<<"len: "<<l1<<endl;
	int l2 = strlen(num2);

	if(l1 != l2){
		cout<<"Cannot perform such an operation."<<endl;
		assert(0);
	}

	int res1=0, n1,n2, carry=0;

	char *res = new char[(l1+1)* sizeof(char)];

	for(int i=l1-1;i>=0;i--){
		n1= getnum(num1[i]);
		n2 = getnum(num2[i]);
		res1 = n1+n2+carry;
		//cout<<"res1: "<<res1<<endl;
		if(res1>=14){
			carry = 1;
			res1 = res1-14;
		}
		else
			carry = 0;

		res[i+1] = convertNum(res1);

	}

	if(carry == 0)
		return (res+1);
	else{
		res[0] = '1';
		return res;
	}

}

int main(){
	char n1[] = "DC2";
	char n2[] = "0A3";
	cout<<"Result is "<<sum(n1,n2);
	return 0;
}
