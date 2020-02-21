#include <iostream>
using namespace std;

bool hasOnlyOneChild(int pre[], int size){
	int min,max;
	if(pre[size-1] > pre[size-2]){
		min = pre[size-2];
		max = pre[size-1];
	}
	else{
		min = pre[size-1];
		max = pre[size-2];
	}

	for(int i=size-3;i>=0;i--){
		if(pre[i] < min)
			min = pre[i];
		else if(pre[i] > max)
			max = pre[i];
		else
			return false;
	}
	return true;
}

int main() 
{ 
    int pre[] = {8, 3, 5, 7, 6}; 
    int size = sizeof(pre)/sizeof(pre[0]); 
    if (hasOnlyOneChild(pre,size)) 
        printf("Yes"); 
    else
        printf("No"); 
    return 0; 
} 

//Complexity: O(n)