#include <iostream>
class TwoDimensionMatrix {
	static const int size = 2;
	int matrix[size][size];
public:
	TwoDimensionMatrix() {}
	TwoDimensionMatrix(TwoDimensionMatrix& matrix) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
	TwoDimensionMatrix(const int tab[size][size]) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) this->matrix[i][j] = tab[i][j];
		}
	}
	int get(int i, int j) const { return this->matrix[i][j]; }
	void set(int i, int j, int x) { this->matrix[i][j] = x; }
	static constexpr int getSize() { return size; }
	TwoDimensionMatrix& operator=(const TwoDimensionMatrix& matrix);
	TwoDimensionMatrix& operator*=(int number);
	bool operator==(const TwoDimensionMatrix& matrix);
	TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
	const int * operator[](const int i){ return this->matrix[i]; }
	int* operator[](size_t i) { return this->matrix[i]; }
};
TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2);
