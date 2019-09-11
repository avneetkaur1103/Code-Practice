#include <stdio.h>
#include<stdlib.h>
#define MAX 500

using namespace std;


class stack{
		int top;
	
	public:
		int a[MAX];
		stack(){ top = -1;}
		void push(int b);
		int pop();
		bool isempty();
};

bool stack::isempty(){
	return (top < 0);
}
void stack::push(int b){
	if (top >= MAX-1)
		printf("Stack is full\n");
	else{
		a[++top] = b;
		printf("data is pushed\n");
	}
}

int stack::pop(){
	if  (top < 0 ){
		printf("Stack is empty\n");
		return 0;
	}
	else{
		printf("Data is popped\n");
		return a[top--];
	}
}
int main() {
	stack s;
	s.push(6);
	s.push(5);
	s.push(8);
	printf("%d\n",s.pop());
	return 0;
}