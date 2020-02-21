/*We can do this by inserting elements in AVL trees. Complexity: O(nlogn) = O(n) - traversal & insertion in AVL - O(logn)*/
/*The method below uses STL. Worst Case Complexity: O(n^2)*/
#include <iostream>
#include <set>
using namespace std;

struct Node{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int data){
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data = data;
	n->left = n->right = NULL;
	return n;
}

int getInvCount(int arr[], int n){
	 	multiset<int> s;
	 	s.insert(arr[0]);
	 	int invCount = 0;

	 	for(int i=1;i<n;i++){
	 		s.insert(arr[i]);
	 		multiset<int>::iterator it;
	 		it = s.upper_bound(arr[i]);
	 		invCount += distance(it, s.end());
	 	}
	 	return invCount;
}

int main(){
	int arr[] = {8, 4, 2, 1}; 
    int n = sizeof(arr)/sizeof(int); 
    cout << "Number of inversions count are : "
         << getInvCount(arr,n); 
    return 0; 
}