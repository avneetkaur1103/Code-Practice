#include <iostream>
using namespace std;
#define R 4
#define C 3

int get_count(char keypad[4][3], int n){
	
	if (keypad == NULL || n<=0)
		return 0;
	if(n==1)
		return 10;
		
	int count[10][n+1];
	int i,j,k,move;
	
	for (i=0;i<10;i++){
		count[i][0] = 0;
		count[i][1] = 1;
	}
	
	int row[]={0,0,-1,0,1};
	int col[]={0,-1,0,1,0};
	
	
	int ro=0,co=0;
	int num, next_num, total;
	num = next_num = total =0;
	
	for(k=2;k<=n;k++){
		for(i=0;i<4;i++){
			for(j=0;j<3;j++){
				if(keypad[i][j] != '*' && keypad[i][j] != '#'){
					num = keypad[i][j] - '0';
					count[num][k] = 0;
				
					for (move = 0;move<5;move++){
						ro = i+row[move];
						co = j+col[move];
						if(ro>=0 && ro<4 && co>=0 && co<3 && (keypad[ro][co] != '*' && keypad[ro][co] != '#')){
							next_num = keypad[ro][co] - '0';
							count[num][k] += count[next_num][k-1];
						}
					}
				}
			}
		}
	}
	for (i=0;i<10;i++)
		total += count[i][n];
		
	return total;
}



int main() {
	 char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 
   printf("Count for numbers of length %d: %d\n", 1, get_count(keypad, 1)); 
   printf("Count for numbers of length %d: %d\n", 2, get_count(keypad, 2)); 
   printf("Count for numbers of length %d: %d\n", 3, get_count(keypad, 3)); 
   printf("Count for numbers of length %d: %d\n", 4, get_count(keypad, 4)); 
   printf("Count for numbers of length %d: %d\n", 5, get_count(keypad, 5)); 
  
   return 0;
}

//Complexity:O(i*j*n)