#include <iostream>
#include <vector>
#include <math.h>
#define m 5
#define n 5

using namespace std;

bool isPossible(int k, int r, vector<int> X, vector<int> Y){
	int rect[m][n]={0};

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int h=0;h<k;h++){
				if(sqrt(pow((X[h]-i-1),2) + pow((Y[h]-j-1),2)) <= r)
					rect[i][j] = -1;
			}
		}
	}

	if(rect[0][0] == -1)
		return false;

	vector<pair<int, int> > q;
	rect[0][0] = 1;	
	q.push_back(make_pair(0,0));

	while(!q.empty()){

		pair<int, int> p = q.front();
		q.erase(q.begin());
		int elex = p.first;
		int eley = p.second;

		//Check elements in all 8 directions
		if(elex > 0 && eley > 0 && rect[elex-1][eley-1] == 0 ){
			rect[elex-1][eley-1] = 1;
			q.push_back(make_pair(elex-1,eley-1));
		}

		if(elex > 0 && rect[elex-1][eley] == 0){
			rect[elex-1][eley] = 1;
			q.push_back(make_pair(elex-1,eley));
		}

		if(elex > 0 && eley < n-1 && rect[elex-1][eley+1] == 0 ){
			rect[elex-1][eley+1] = 1;
			q.push_back(make_pair(elex-1,eley+1));
		}

		if(eley > 0 && rect[elex][eley-1] == 0 ){
			rect[elex][eley-1] = 1;
			q.push_back(make_pair(elex,eley-1));
		}

		if(eley < n-1 && rect[elex][eley+1] == 0 ){
			rect[elex][eley+1] = 1;
			q.push_back(make_pair(elex,eley+1));
		}

		if(elex < m-1 && eley > 0 && rect[elex+1][eley-1] == 0 ){
			rect[elex+1][eley-1] = 1;
			q.push_back(make_pair(elex+1,eley-1));
		}

		if(elex < m-1 && rect[elex+1][eley] == 0 ){
			rect[elex+1][eley] = 1;
			q.push_back(make_pair(elex+1,eley));
		}

		if(elex < m-1 && eley < n-1 && rect[elex+1][eley+1] == 0 ){
			rect[elex+1][eley+1] = 1;
			q.push_back(make_pair(elex+1,eley+1));
		}
	}

	return (rect[m-1][n-1] == 1);
}

int main(){
	int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
	vector<int> X1;
	X1.push_back(1);
	X1.push_back(3);
	vector<int> Y1;
	Y1.push_back(3);
	Y1.push_back(3);

	if (isPossible(k1, r1, X1, Y1)) 
    	cout << "Possible" << endl;
    else
    	cout << "Not Possible" << endl; 

    cout<<endl;

    int m2 = 5, n2 = 5, k2 = 2, r2 = 1;
	vector<int> X2;
	X2.push_back(1);
	X2.push_back(1);
	vector<int> Y2;
	Y2.push_back(2);
	Y2.push_back(3);

	if (isPossible(k2, r2, X2, Y2)) 
    	cout << "Possible" << endl;
    else
    	cout << "Not Possible" << endl; 
    return 0;
}

//Complexity: O(m*n*k)