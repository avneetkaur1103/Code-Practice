#include <iostream>
#include<climits>
using namespace std;

class MinHeap{
	public:
		int *arr;
		int capacity;
		int size;
		
	
		MinHeap(int c);
		int parent(int i){ return (i-1)/2; }
		void insert(int k);
		
		int left(int i) { return (i*2+1); }
		int right(int i) { return (i*2+2); }
		int getmin(){return arr[0];}
		
		int extractmin();
		int deletekey(int i);
		void decreasekey(int i,int new_val);
		void heapify(int );
		void printarr(int *);
};

MinHeap::MinHeap(int c){
	capacity = c;
	size = 0;
	arr = new int[capacity];
}

void swap (int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void MinHeap::insert(int k){
	if (size == capacity)
		return;
	
	size++;
	int i = size-1;
	arr[i] = k;
	
	while (i != 0 && arr[parent(i)] > arr[i]){
		swap(&arr[i], &arr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decreasekey(int i,int new_val){
	arr[i] = new_val;
	
	while (i!= 0 && arr[parent(i)] >arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void MinHeap::heapify(int i){
	int l = left(i);
	int r = right(i);
	int small = i;
	if (l < size && arr[l]<arr[i])
		small = l;
	if (r < size && arr[r] < arr[small])
		small = r;
	if (i != small)	{
		swap(&arr[i], &arr[small]);
		heapify(small);
	}
}

int MinHeap::extractmin(){
	if (size <= 0)
		return 0;
	
	if (size == 1){
		size--;
		return arr[0];
	}
	
	int ret = arr[0];
	arr[0] = arr[size -1];
	size--;
	heapify(0);
	
	return ret;
}

int MinHeap::deletekey(int i){
	decreasekey(i,INT_MIN);
	extractmin();
}

void MinHeap::printarr(int *arr){
	for (int i = 0; i <size ; i++)
		cout << arr[i] << "\t";
}

int main() {
	MinHeap h(10);
	h.insert(22);
	h.insert(5);
	h.insert(12);
	h.insert(7);
	
	h.printarr(h.arr);
	cout<<endl;
	cout<< h.getmin()<<endl;
	cout<<h.extractmin()<<endl;
	h.printarr(h.arr);
	cout<<endl;
	h.insert(9);
	h.insert(2);
	h.printarr(h.arr);
	cout<<endl;
	h.decreasekey(2,3);
	cout<< h.deletekey(2)<<endl;
	h.printarr(h.arr);
	cout<<endl;
	return 0;
}