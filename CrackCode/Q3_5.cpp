#include <iostream>
#include <stack>
using namespace std;

stack<int> stackSort(stack<int> &input){
	stack<int> aux_stack;
	while(!input.empty()){
		int x = input.top();
		input.pop();

		while(!aux_stack.empty() && x < aux_stack.top()){
			input.push(aux_stack.top());
			aux_stack.pop();
		}

		aux_stack.push(x);
	}

	return aux_stack;
}

int main(){
	stack<int> input;
	input.push(-3);
	input.push(5);
	input.push(0);
	input.push(34);
	input.push(15);
	input.push(-1);
	input.push(2);
	input.push(22);

	stack<int> s = stackSort(input);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}