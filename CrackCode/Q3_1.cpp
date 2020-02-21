#include <iostream>
using namespace std;

class ThreeStacks{
	int n;
	int *arr;
	int *next;
	int *top;
	int free;
public:
	ThreeStacks(int num);
	void push(int item, int sn);
	int pop(int sn);
	bool isEmpty(int sn) {return (top[sn] == -1);}
	bool isFull() {return (free == -1);}
};

ThreeStacks::ThreeStacks(int num){
	n = num;
	arr = new int[n];

	next = new int[n];
	for(int i=0;i<n;i++)
		next[i] = i+1;
	next[n-1] = -1;
	
	top = new int[3];
	for(int i=0;i<3;i++)
		top[i] = -1;

	free = 0;
}

void ThreeStacks::push(int item, int sn){
	if(isFull()){
		cout<<"Full"<<endl;
		return;
	}

	int i= free;
	free = next[i];

	next[i] = top[sn];
	top[sn] = i;
	arr[i] = item;
}

int ThreeStacks::pop(int sn){
	if(isEmpty(sn)){
		cout<<"Stack is Empty"<<endl;
		return INT_MAX;
	}

	int i = top[sn];
	int item = arr[i];
	top[sn] = next[i];
	next[i] = free;
	free = i;
	return item;
}

int main(){
	int n = 10;
	ThreeStacks ks(n);

	ks.push(15, 2); 
    ks.push(45, 2); 

    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0);

    cout<<ks.pop(1)<<endl;
    cout<<ks.pop(2)<<endl;
    cout<<ks.pop(0)<<endl;
    return 0;
}

//complexity: O(1) for push() & pop()