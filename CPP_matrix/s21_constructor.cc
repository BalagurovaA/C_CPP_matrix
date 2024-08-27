#include "s21_matrix_oop.h"

//-------------базовый контсруктор-------------//
S21Matrix::S21Matrix() {
  rows_ = 2;
  cols_ = 2;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

//-------------параметризированный конструктор-------------//
S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1 || cols < 1) throw std ::invalid_argument("incorrect matrix");
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

//-------------конструктор копирования-------------//
S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

//-------------конструктор переноса-------------//
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

//-------------деструктор-------------//
S21Matrix::~S21Matrix() { delete_matrix(); }
