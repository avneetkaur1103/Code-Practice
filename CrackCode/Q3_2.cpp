#include <iostream>
#include <vector>
#define MAXX 1000

using namespace std;

class MinStack{
	int minn;
	int size;
	
public:
	MinStack(){
		minn = INT_MAX;
		size = -1;
	}

	vector< pair<int, int> > ms;
	void push(int element);
	void pop();
	int top();
	int getMin();
};

void MinStack::push(int element){

	if(size > MAXX){
		cout<<"stack overflow";
		return;
	}

	if(element<minn)
		minn = element;

	ms.push_back(pair<int, int> (element,minn));
	size++;
}

int MinStack::top(){
	if (size == -1){
		cout<<"empty stack"<<endl;
		return INT_MAX;
	}
	return ms[size].first;
}

void MinStack::pop(){
	if(size == -1){
		cout<<"empty stack"<<endl;
		return;
	}

	if(size > 0 && ms[size-1].second > ms[size].second){
		minn = ms[size-1].second;
		ms.pop_back();
		size--;
	}
}

int MinStack::getMin(){
	if(size == -1){
		cout<<"empty stack"<<endl;
		return INT_MIN;
	}
	return ms[size].second;
}

int  main()
{
	MinStack s;
	s.push(5);
	s.push(7);
	s.push(3);
	cout<<s.top()<<endl;
	s.pop();
	s.push(2);
	s.push(0);
	s.push(9);
	cout<<s.getMin();
	return 0;
}