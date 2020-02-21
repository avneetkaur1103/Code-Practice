#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct Node{
	string str;
	int length;
	Node(string s, int l){
		str = s;
		length = l;
	}
};

bool isAdj(string &a, string &b){
	int len = a.length();
	int count =0;

	for(int i=0;i<len;i++){
		if(a[i] != b[i])
			count++;
		if(count>1)
			break;
	}
	return (count==1)? true:false;
}

int shortestChainLen(string &s, string &t, set<string> &D){
	queue<Node> q;
	q.push(Node(s,1));

	while(!q.empty()){
		Node curr = q.front();
		q.pop();


		set<string>::iterator it;
		for(it = D.begin(); it != D.end(); it++){
			string temp = *it;
			if(isAdj(curr.str, temp)){
				int new_len = curr.length + 1;
				q.push(Node (temp,new_len));
				D.erase(temp);
				if(t == temp)
					return new_len;
				
			}
		}
	}
	return 0;
}

int main(){
	set<string> D; 
    D.insert("poon"); 
    D.insert("plee"); 
    D.insert("same"); 
    D.insert("poie"); 
    D.insert("plie"); 
    D.insert("poin"); 
    D.insert("plea"); 
    string start = "toon"; 
    string target = "plea"; 
    cout << "Length of shortest chain is: " 
         << shortestChainLen(start, target, D);  
    return 0;  
}

//complexity: O(n^2 * m)
//		where n = no. of words in set D & m = length of string.