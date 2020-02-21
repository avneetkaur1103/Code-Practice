#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class setOfStack{
	int capacity;
	vector<stack<int> > ss;

	int getLastStack();
	bool isFull(int sn) {return (ss[sn].size() == capacity);}
	bool isEmpty(int sn) {return (ss[sn].size() == 0);}
public:
	setOfStack(int c):capacity(c){}
	int size(){ return ss.size(); }
	void push(int item);
	int pop();
	int popAt(int sn);
};

int setOfStack::getLastStack(){
	if(ss.size() == 0)
		return INT_MIN;
	else
		return (ss.size() - 1);
}


void setOfStack::push(int item){
	int sn = getLastStack();
	if(sn == INT_MIN || isFull(sn)){
		stack<int> st;
		st.push(item);
		ss.push_back(st);
	}
	else
		ss[sn].push(item);
}

int setOfStack::pop(){
	int sn = getLastStack();
	if(sn == INT_MIN)
		cout<<"No Element to pop"<<endl;
	int item = ss[sn].top();
	ss[sn].pop();
	if(isEmpty(sn)){
		ss.pop_back();
	}

	return item;
}

int setOfStack::popAt(int sn){
	if(sn > ss.size() -1){
		cout<<"No such stack"<<endl;
		return INT_MIN;
	}

	int item = ss[sn].top();
	ss[sn].pop();
	if(isEmpty(sn)){
		ss.pop_back();
	}
	return item;
}

int main(){
	setOfStack sos(5);
	sos.push(4);
	sos.push(1);
	sos.push(0);
	sos.push(56);
	sos.push(43);
	sos.push(32);
	//cout<<sos.size()<<endl;
	//cout<<sos.pop()<<endl;
	//cout<<sos.size()<<endl;
	cout<<sos.popAt(0)<<endl;
}