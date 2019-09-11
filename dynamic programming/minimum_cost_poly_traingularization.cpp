#include <iostream>
#include <climits>
#include <cmath>
#define MAX 1000000.0
using namespace std;

struct Point{
	int x;
	int y;
};

double min(double x,double y){
	return (x<=y)?x:y;
}

double distance(Point p1, Point p2){
	return sqrt(((p1.x - p2.x )*(p1.x - p2.x )) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

double cost(Point points[], int i,int j, int k){
	Point p1 = points[i];
	Point p2 = points[j];
	Point p3 = points[k];
	return (distance(p1,p2) + distance(p2,p3) + distance(p3,p1));
}

double min_cost_polygon_triangulation(Point points[], int n){
	int i,j,k;
	double table[n][n];
	int gap;
	
	if (n<3)
		return 0;
	
	for (gap=0; gap<n;gap++){
		for (i=0,j=gap;i<n,j<n;i++,j++){
			if (j<i+2)
				table[i][j] = 0.0;
			else{
				table[i][j] = MAX;
				for (k=i+1;k<j;k++){
				double val = table[i][k] + table[k][j] + cost(points,i,j,k);
				if(val < table[i][j])
					table[i][j] = val;
				}
			}
		}
	}
	return table[0][n-1];
}

int main() {
	Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}}; 
	int n = sizeof(points)/sizeof(points[0]);
	cout<<"Minimum cost of polygon traingularization: "<<min_cost_polygon_triangulation(points,n);
	return 0;
}

//Complexity: O(n^3)