#include <iostream>
using namespace std;

char S[10000];
char result[10000];
bool adj[10][10];

bool findthepath(char S[], int v){
	result[0] = v + '0';

	for (int i = 1; S[i]; i++)
	{
		if(adj[v][S[i]-'A'] || adj[S[i]-'A'][v])
			v = S[i]-'A';
		else if (adj[v][S[i]-'A'+ 5] || adj[S[i]-'A'+5][v])
			v = S[i]-'A'+5;
		else
			return false;

		result[i]=v+'0';
	}
	return true;
}

int main() 
{  
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] =  
    adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] = 
    adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] = 
    adj[9][6] = adj[6][8] = adj[8][5] = true; 

    char S[] = "ABB"; 
      
    if (findthepath(S, S[0] - 'A') ||  
        findthepath(S, S[0] - 'A' + 5)) { 
        cout << result; 
    } else { 
        cout << "-1"; 
    } 
    return 0; 
}