#include <iostream>
#include <queue>
#include <map>
using namespace std;

void BFS(int a, int b, int target){
	map<pair<int, int>, int> visited;
	vector<pair<int, int> > path;
	queue<pair<int, int> > q;

	bool isSolvable = false;
	q.push(make_pair(0, 0));

	while(!q.empty()){
		pair<int,int> u = q.front();
		q.pop();

		if(visited[make_pair(u.first, u.second)] == 1)
			continue;

		if(u.first > a || u.second >b || u.first <0 ||u.second <0)
			continue;

		path.push_back(make_pair(u.first, u.second));

		visited[make_pair(u.first,u.second)] = 1;

		if(u.first == target || u.second == target){
			isSolvable = true;
			if(u.first == target){
				if(u.second != target)
					path.push_back(make_pair(u.first, 0));
			}

			if(u.second == target){
				if(u.first != target)
					path.push_back(make_pair(0, u.second));
			}

			int size = path.size();
			for(int i=0;i<size;i++){
				cout<<"("<<path[i].first<<", "<<path[i].second<<")"<<endl;
			}
			break;
		}

		q.push(make_pair(u.first,b));
		q.push(make_pair(a,u.second));
		

		for(int j=0;j<max(a,b);j++){
			int c = u.first + j;
			int d = u.second - j;

			if(c == a || d==0)
				q.push(make_pair(c,d));

			c = u.first - j;
			d = u.second + j;

			if(c==0||d==b)
				q.push(make_pair(c,d));
		}

		q.push(make_pair(a,0));
		q.push(make_pair(0,b));
	}
}

int main() 
{ 
    int Jug1 = 4, Jug2 = 3, target = 2; 
    BFS(Jug1, Jug2, target); 
    return 0; 
} 