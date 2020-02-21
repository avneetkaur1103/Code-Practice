#include<iostream>
#include <stack>
using namespace std;

class MyQueue{
	stack<int> s1,s2;
public:
	void enqueue(int item);
	int dequeue();
};

void MyQueue::enqueue(int item){
	if(s1.empty()){
		s1.push(item);
		return;
	}

	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();
	}

	s1.push(item);
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

int MyQueue::dequeue(){
	if(s1.empty()){
		cout<<"Queue is empty"<<endl;
		return INT_MIN;
	}

	int x = s1.top();
	s1.pop();
	return x;
}

int main(){
	MyQueue q;
	q.enqueue(8);
	q.enqueue(7);
	q.enqueue(12);

	cout<<q.dequeue()<<endl;
	return 0;
}