#include <iostream>
#include <string>
using namespace std;

int stringBinarySearch(string arr[], int low, int high, string s){
	if(low > high)
		return -1;

	//int mid = (low + high)/2;
	int mid = low + (high -low)/2;
	//cout<<"Mid: "<<mid<<endl;

	if(arr[mid].compare("") == 0){
		int left = mid -1;
		int right = mid+1;

		while(true){
			if(left <low && right >high){
				cout<<"Return here"<<endl;
				return -1;
			}
			if(left >= low && !arr[left].empty() ){
				mid = left;
				break;
			}
			if(right<= high && !arr[right].empty()){
				mid = right;
				break;
			}

			left--;
			right++;
		}
	}
	
	if(arr[mid].compare(s) == 0)
		return mid;

	if(arr[mid].compare(s) < 0)
		return stringBinarySearch(arr,mid+1,high,s);

	if(arr[mid].compare(s) > 0)
		return stringBinarySearch(arr,low,mid -1,s);

	return -1;
}

int main(){
	string arr[] = {"at" , "" , "" , "" , "ball" , "", "car" , "" , "" , "dad", "" , "ear", "", ""};
	int n = sizeof(arr)/sizeof(arr[0]);
	//cout<<"n: "<<n<<endl;
	string s = "ball";
	cout<<stringBinarySearch(arr,0,n-1,s);
	return 0;
}
