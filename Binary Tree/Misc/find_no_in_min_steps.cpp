#include <iostream>
#include <queue>
using namespace std;

#define INF 99999

struct number{
	int val;
	int level;
	number(int n, int l){
		val = n;
		level = l;
	}
};

void findMinSteps(int n){
	queue<number> q;
	number root(0,1);
	q.push(root);

	while(!q.empty()){
		number temp = q.front();
		q.pop();

		if(temp.val >=INF || temp.val <= -INF)
			break;

		if(temp.val == n){
			cout<<"Level: "<<temp.level-1;
			break;
		}

		q.push(number(temp.val+temp.level,temp.level+1));
		q.push(number(temp.val-temp.level,temp.level+1));
	}
}

int main(){
	findMinSteps(13);
	return 0;
}