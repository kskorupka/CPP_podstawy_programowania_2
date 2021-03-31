#include <iostream>
#include "matrix.h"
//deep copy
TwoDimensionMatrix & TwoDimensionMatrix:: operator=(const TwoDimensionMatrix& matrix) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) this->set(i, j, matrix.matrix[i][j]);
	}
	return *this;
}
//add arrays
TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
	TwoDimensionMatrix matrix;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) matrix.set(i, j, matrix1.get(i, j) + matrix2.get(i, j));
	}
	return matrix;
}
//multiply by integer
TwoDimensionMatrix& TwoDimensionMatrix:: operator*=(int number) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) this->set(i, j, get(i, j) * number);
	}
	return *this;
}
//==
bool TwoDimensionMatrix:: operator==(const TwoDimensionMatrix& matrix) {
	for (int i = 0; i < 2; i++) {
		for(int j=0;j<2;j++) if(!(this->get(i,j)==matrix.get(i,j))) return false;
	}
	return true;
}
//&&
TwoDimensionMatrix TwoDimensionMatrix:: operator&&(const TwoDimensionMatrix& matrix) const{
	TwoDimensionMatrix matrix_result;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (this->get(i, j) == matrix.get(i, j)) matrix_result.set(i, j, 1);
			else matrix_result.set(i, j, 0);
		}
	}
	return matrix_result;
}
