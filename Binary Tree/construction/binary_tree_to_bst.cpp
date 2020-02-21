#include <iostream>
#include <vector>

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

void inOrder(int a[], vector<int> &v, int n, int i){
	if(i>=n)
		return;

	inOrder(a,v,n,2*i+1);
	v.push_back(a[i]);
	inOrder(a,v,n,2*i+2);
}

int minSwaps(vector<int> v){
	vector<pair<int, int> > t(v.size());
	int res=0;
	//cout<<v.size()<<endl;
	for(int i=0;i<v.size(); i++){
		//t.push_back(pair<int, int> (v[i], i));
		t[i].first = v[i];
		t[i].second = i;
	}

	//cout<<t.size()<<endl;
	sort(t.begin(), t.end());

	for(int i=0;i<t.size(); i++){
		if(t[i].second == i)
			continue;
		else{
			swap(t[i].first, t[t[i].second].first);
			swap(t[i].second, t[t[i].second].second);
		}
			if(i != t[i].second)
				i--;
			res++;
		
	}
	return res;
}

int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a)/sizeof(a[0]);
	vector<int> v;
	inOrder(a,v,n,0);
	int sw = minSwaps(v);
	cout<<"Minimum Swaps: "<<sw;
	return 0;
}

//Complexity: O(nlogn)