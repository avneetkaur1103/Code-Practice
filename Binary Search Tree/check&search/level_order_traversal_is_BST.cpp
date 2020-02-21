#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node{
	int data;
	int min,max;
};

bool levelOrderIsOfBST(int arr[], int n){
	if(n == 0)
		return true;

	queue<Node> q;
	int i=0;

	Node node;
	node.data = arr[i++];
	node.min = INT_MIN;
	node.max = INT_MAX;

	q.push(node);
	//cout<<"Pushed"<<endl;
	while(i != n && !q.empty()){
		Node temp = q.front();
		q.pop();

		if(i<n && arr[i] > temp.min && arr[i] < temp.data){
			node.data = arr[i++];
			node.min = temp.min;
			node.max = temp.data;
			q.push(node);
		}

		if(i<n && arr[i] > temp.data && arr[i] < temp.max){
			node.data = arr[i++];
			node.min = temp.data;
			node.max = temp.max;
			q.push(node);
		}
	}

	if(i == n)
		return true;

	return false;
}

int main(){
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};     
    int n = sizeof(arr) / sizeof(arr[0]);     
    if (levelOrderIsOfBST(arr, n)) 
        cout << "Yes"; 
    else
        cout << "No";         
    return 0;
}

//Complexity:O(n)