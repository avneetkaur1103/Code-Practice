#include <iostream>
using namespace std;

#define TABLE_SIZE 10
#define PRIME 7

class Double_hash{
	int *htable;
	int size;
	
	public:
		int hash1(int key){
			return (key % TABLE_SIZE);
		}
		
		int hash2(int key){
			return PRIME-(key%PRIME);
		}
		
		Double_hash(){
			htable = new int[TABLE_SIZE];
			for (int i=0;i<TABLE_SIZE;i++)
				htable[i] = -1;
			size = 0;
		}
		
		void insert_in_hash(int key){
			if (size == TABLE_SIZE)
				return;
			
			int index = hash1(key);
			
			if (htable[index] != -1){
				int index2 = hash2(key);
				int i = 1;
				while(1){
					int new_index = (index+i*index2)%TABLE_SIZE;
					if(htable[new_index] == -1){
						htable[new_index] = key;
						break;
					}
					
					i++;	
				}
			}
			else
				htable[index] = key;
			
			size++;
			
		}
		
		void display(){
		
			for (int i = 0; i<TABLE_SIZE;i++){
				if (htable[i] != -1)
					cout<<i<<" - "<<htable[i]<<endl;
				else
					cout<<i<<endl;
			}
		}
};

int main() {
	int a[]={12,34,45,67,89,19};
	int n = sizeof(a)/sizeof(a[0]);
	Double_hash h;
	for (int i = 0;i<n;i++)
		h.insert_in_hash(a[i]);
	
	h.display();
	return 0;
}
