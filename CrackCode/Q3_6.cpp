#include <iostream>
#include <queue>

using namespace std;

class animalShelter{
	bool type; //0-Dog, 1-Cat
	queue< pair<bool, int> > q0, q1;
public:
	static int seq;
	void enQueue(bool type);
	int deQueueAny();
	int deQueueDog();
	int deQueueCat();
};

int animalShelter::seq = 0;

void animalShelter::enQueue(bool type){
	seq++;
	if(type == 0)
		q0.push(pair<bool, int> (0,this->seq));
	else
		q1.push(pair<bool, int> (1,this->seq));
}

int animalShelter::deQueueCat(){
	if (q1.empty()){
		cout<<"No cats to pop!!"<<endl;
		return INT_MIN;
	}

	int item = q1.front().second;
	q1.pop();
	return item;
}

int animalShelter::deQueueDog(){
	if (q0.empty()){
		cout<<"No Dogs to pop!!"<<endl;
		return INT_MIN;
	}

	int item = q0.front().second;
	q0.pop();
	return item;
}

int animalShelter::deQueueAny(){
	if (q1.empty() && q0.empty()){
		cout<<"No cats or Dogs to pop!!"<<endl;
		return INT_MIN;
	}

	if(q0.empty()){
		int item = q1.front().second;
		q1.pop();
		return item;
	}

	if(q1.empty()){
		int item = q0.front().second;
		q0.pop();
		return item;
	}

	int item0 = q0.front().second;
	int item1 = q1.front().second;
	if (item0<item1){
		q0.pop();
		return item0;
	}
	else{
		q1.pop();
		return item1;
	}
}
int main(){
	animalShelter as;
	as.enQueue(1);
	as.enQueue(1);
	as.enQueue(1);
	cout<<as.deQueueCat()<<endl;
	//cout<<as.deQueueCat()<<endl;
	cout<<as.deQueueCat()<<endl;
	as.enQueue(0);
	as.enQueue(0);
	cout<<as.deQueueDog()<<endl;
	cout<<as.deQueueAny()<<endl;
	return 0;
}