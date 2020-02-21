#include <iostream>
using namespace std;

#define M 6
#define N 6

bool dfs(bool graph[M][N], int seen[],int u, int match[]){
	for(int i=0;i<N;i++){
		if(graph[u][i] && !seen[i]){
			seen[i] = true;

			if(match[i] < 0 || dfs(graph,seen,match[i],match)) {
				match[i] = u;
				return true;
			}
		}
	}
	return false;
}

int maxBPM(bool graph[M][N]){
	int match[N];
	memset(match,-1,sizeof(match));
	int result = 0;

	for(int u=0;u<M;u++){
		int seen[N];
		memset(seen,0,sizeof(seen));

		if(dfs(graph,seen,u,match))
			result++;
	}

	for(int x =0;x<N;x++){
		if(match[x]+1 != 0)
			cout<<"Applicant "<<(match[x] + 1)<<" has job "<<x+1<<endl;
	}

	return result;
}

int main(){
	bool bpGraph[M][N] = {{0, 1, 1, 0, 0, 0}, 
                          {1, 0, 0, 1, 0, 0}, 
                          {0, 0, 1, 0, 0, 0}, 
                          {0, 0, 1, 1, 0, 0}, 
                          {0, 0, 0, 0, 0, 0}, 
                          {0, 0, 0, 0, 0, 1}}; 
  
    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph); 
}

//Same algo for channel assignment (transmitter sends packets to receivers)