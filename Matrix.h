#pragma once
#include <iostream>
using namespace std;
class Row
{
private:
	double* row;
	int len;
public:
	Row();
	void write_st(int l, double& str);
	double& operator[](int k) const;
	virtual ~Row() { if (row != nullptr) delete[] row; }
};

class Matrix
{
private:
	Row* row;
	int size_r, size_c;
public:
	Matrix();
	~Matrix() { if ( row != nullptr) delete[] row; }
	Matrix(int r, int c);
	Matrix(const Matrix& cop)
	{
		row = nullptr;
		(*this) = cop;
	}
	Matrix& operator-();
	void matrix_enter();
	
	Row& operator[](int k) const;
	Matrix operator+(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix) const;
	friend Matrix operator*(double num, const Matrix& matrix);
	Matrix& operator=(const Matrix& matrix);
	Matrix operator*(double num) const;

	void show();
};

Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (row != nullptr) delete[] row;
	row = new Row[matrix.size_r];
	size_r = matrix.size_r;
	size_c = matrix.size_c;
	for (int i = 0; i < size_r; i++)
		for (int k = 0; k < size_c; k++)
			row[i][k] = matrix.row[i][k];
	return *this;
}

Matrix operator*(double num, const Matrix& matrix)
{
	return matrix * num;
}

Matrix& Matrix::operator-()
{
	for (int i = 0; i < size_r; i++)
		for (int k = 0; k < size_c; k++)
			row[i][k] *= -1;
	return *this;
}

Matrix Matrix::operator*(const Matrix& matrix) const
{
	if (size_c != matrix.size_r)
		throw "Size error.";
	Matrix buf(size_r, matrix.size_c);
	for (int i = 0; i < size_r; i++)
		for (int k = 0; k < matrix.size_c; k++)
			for (int p = 0; p < matrix.size_r; p++)
				buf[i][k] += (*this)[i][p] * matrix[p][k];
	return buf;
}

Matrix Matrix::operator*(double num) const
{
	Matrix buf(size_r, size_c);
	for (int i = 0; i < size_r; i++)
		for (int k = 0; k < size_c; k++)
			buf[i][k] *= num;
	return buf;
}

Matrix Matrix::operator+(const Matrix& matrix)
{
	if (size_r != matrix.size_r or size_c != matrix.size_c)
		throw "Size error.";
	Matrix buf(size_r, size_c);
	for (int i = 0; i < size_r; i++)
		for (int k = 0; k < size_c; k++)
			buf[i][k] = (*this)[i][k] + matrix[i][k];
	return buf;
}

Matrix::Matrix()
{
	size_r = size_c = 3;
	row = new Row[size_r];
}

Matrix::Matrix(int r, int c)
{
	size_r = r; size_c = c;
	double* buf;
	if (row != nullptr) 
		delete[] row;
	row = new Row[r];
	for (int i = 0; i < r; i++)
	{
		buf = new double[c];
		for (int k = 0; k < c; k++)
			buf[k] = 0;
		row[i].write_st(c, *buf);
	}
}

void Matrix::matrix_enter()
{
	double* buf;
	row = new Row[size_r];
	cout << "Enter the matrix: \n";
	for (int i = 0; i < size_r; i++)
	{
		buf = new double[size_c];
		for (int k = 0; k < size_c; k++)
			cin >> buf[k];
		row[i].write_st(size_c, *buf);
	}
}

Row::Row()
{
	len = 3;
	row = new double[len] { 0, 0, 0 };
}

void Row::write_st(int l, double& str)
{
	len = l;
	if (row != nullptr) delete[] row;
	row = &str;
}

inline double& Row::operator[](int k) const
{
	return row[k];
}

inline Row& Matrix::operator[](int k) const
{
	return row[k];
}

void Matrix::show()
{
	for (int i = 0; i < size_r; i++)
	{
		for (int k = 0; k < size_c; k++)
			cout << (*this)[i][k] << " ";
		cout << endl;
	}
		
}
