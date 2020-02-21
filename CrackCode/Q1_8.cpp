#include <iostream>
#define M 4
#define N 4

using namespace std;

void NullifyRow(int mat[M][N], int r){
	for(int i=0;i<N;i++)
		mat[r][i] = 0;
}

void NullifyCol(int mat[M][N], int c){
	for(int i=0;i<M;i++)
		mat[i][c] = 0;
}

void zeroMatrix(int mat[][N]){
	bool firstRow = false;
	bool firstCol = false;

	for(int i=0;i<N;i++){
		if(mat[0][i] == 0){
			firstRow = true;
			break;
		}
	}

	for(int j=0;j<M;j++){
		if(mat[j][0] == 0){
			firstCol = true;
			break;
		}
	}

	for(int i=1;i<M;i++){
		for(int j=1;j<N;j++){
			if(mat[i][j] == 0){
				mat[0][j] = 0;
				mat[i][0] = 0;
			}
		}
	}

	for(int i=1;i<M;i++){
		if(mat[i][0] == 0)
			NullifyRow(mat,i);
	}


	for(int j=1;j<N;j++){
		if(mat[0][j] == 0)
			NullifyCol(mat,j);
	}

	if(firstRow)
		NullifyRow(mat,0);

	if(firstCol)
		NullifyCol(mat,0);

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cout<<mat[i][j]<<"   ";
		}
		cout<<endl;
	}	

}

int main(){
	int mat[M][N] = {{1,9,4,5},
						{3,9,8,0},
						{0,3,2,9},
						{4,0,2,0}};
	zeroMatrix(mat);
	return 0;
}