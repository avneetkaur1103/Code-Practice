#include <iostream>
#include<climits>
#include <cmath>
#include <cfloat>

using namespace std;

struct Point{
	int x,y;
};

bool cmpX(struct Point p1, struct Point p2){
	return p1.x < p2.x;
}

bool cmpY(struct Point p1, struct Point p2){
	return p1.y < p2.y;
}

float distance(Point p1, Point p2){
	return sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));
}

float min(float a, float b){
	return (a<b ? a : b);
}

float bruteforce(Point P[], int n){
	float min = FLT_MAX;
	int i,j;
	float dis;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			dis = distance(P[i],P[j]);
			if(dis < min)
				min = dis;
		}
	}
	return min;
}

float closestPointStrip(Point strip[], float d, int n){
	int i,j;
	float min = d;
	sort(strip, strip+n,cmpY);

	for (i=0,j=i+1;i<n && j<n && strip[j].y - strip[i].y < min;i++,j++){
		if(distance(strip[i], strip[j]) < min)
			min = distance(strip[i],strip[j]);
	}
	return min;
}

float closestPointUtil(Point P[], int n){
	int i,j;

	if(n<=3)
		return bruteforce(P,n);
	//float min = FLT_MAX;

	int mid = n/2;
	Point midpoint = P[mid];

	float dl = closestPointUtil(P,mid);
	float dr = closestPointUtil(P+mid,n-mid);

	float d = min(dl,dr);

	Point strip[n];
	j=0;
	for(i=0;i<n;i++){
		if(abs(P[i].x - midpoint.x) < d){
			strip[j] = P[i];
			j++;
		}
	}
	
	return min(d, closestPointStrip(strip,d, n));
}

float closestPoint(Point P[], int n){
	sort(P, P+n, cmpX);
	return closestPointUtil(P,n);
}

int main(){
	Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(P)/sizeof(P[0]);
	cout<<"Closest distance between two points in given array is : "<< closestPoint(P,n);
	return 0;
}

//Complexity: O(n * (logn)^2)