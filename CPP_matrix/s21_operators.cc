#include "s21_matrix_oop.h"
//перегрузка операторов

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (matrix_) {
    delete_matrix();
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix buff;
  buff = *this;
  buff.SumMatrix(other);
  return buff;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix buff;
  buff = *this;
  buff.SubMatrix(other);
  return buff;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix buff;
  buff = *this;
  buff.MulMatrix(other);
  return buff;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix buff;
  buff = *this;
  buff.MulNumber(num);
  return buff;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  EqMatrix(other);
  return EqMatrix(other);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

double &S21Matrix::operator()(int i, int j) {
  if (i > rows_ || i < 0 || j > cols_ || j < 0) throw invalid_argument("error");
  return matrix_[i][j];
}
