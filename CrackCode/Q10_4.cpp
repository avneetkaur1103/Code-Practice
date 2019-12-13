#include <iostream>
#include <list>
using namespace std;

int elementAt(int idx, list<int> l){
	list<int>::iterator it = l.begin();
	if(idx>0)
		it = next(it,idx-1);
	return *it;
}

int binary_search(list<int> l, int p, int q, int x){
	if(q>=p){
		int m = p + (q-p)/2;
		if(elementAt(m,l) == x)
			return m;
		else if (elementAt(m,l) > x)
			return binary_search(l,p,m-1,x);
		else
			return binary_search(l,m+1,q,x);
	}
	return -1;
}

int exp_search(list<int> l, int x){
	if(elementAt(0,l) == x)
		return 0;

	int i=1;
	while(elementAt(i,l) != -1 && elementAt(i,l) <=x)
		i = i*2;
	
	return binary_search(l,i/2,i,x);
}


int main(){
	list<int> l;
	l.push_back(2);
	l.push_back(5);
	l.push_back(8);
	l.push_back(11);
	l.push_back(23);
	l.push_back(30);
	l.push_back(41);
	l.push_back(47);
	int x = 23;
	int pos = exp_search(l,x);
	cout<<pos<<endl;
	return 0;
}