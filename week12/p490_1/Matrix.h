#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
	int rows, cols;
	int** mat;
public:
	Matrix(int r = 0, int c = 0) : rows(r), cols(c), mat(nullptr) {
		mat = new int*[rows];
		for (int i = 0; i < rows; i++)
			mat[i] = new int[cols];
	}
	~Matrix() {
		for (int i = 0; i < rows; i++) delete[] mat[i];
		delete[] mat;
	}
	int& elem(int x, int y) { return mat[y][x]; }
	int Rows() { return rows; }
	int Cols() { return cols; }
	int** Data() { return mat; };
};

#endif
