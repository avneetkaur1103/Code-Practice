#include <iostream>
#include <stack>
using namespace std;


bool canRepresentBST(int pre[], int n){
	stack<int> s;
	int i=0;
	int root = INT_MIN;

	for(i=0;i<n;i++){
		if(pre[i] < root)
			return false;

		while(!s.empty() && pre[i] > s.top()){
			root = s.top();
			s.pop();
		}

		s.push(pre[i]);
	}
	return true;
}

int main(){

    int pre[] = {40, 30, 35, 80, 100}; 
    int n = sizeof(pre)/sizeof(pre[0]); 
    canRepresentBST(pre, n)? cout << "true": 
                              cout << "false"; 

    return 0;
}

//Complexity:O(n)