#include "s21_matrix_oop.h"

//-------------очищение матрицы для деструктора и оператора-------------//
void S21Matrix::delete_matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}

// //-------------печать матрицы-------------//
// void S21Matrix::PrintMatrix() {
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       cout << matrix_[i][j] << "\t";
//     }
//     cout << "\n";
//   }
//   for (int a = 0; a < 25; a++) {
//     cout << "-*-";
//   }
//   cout << "\n";
// }

//-------------заполнение матрицы по порядку-------------//
void S21Matrix::filling_matrix() {
  int a = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      a++;
      matrix_[i][j] = a;
    }
  }
}

//-------------assesor-------------//
int S21Matrix::get_rows() const { return rows_; }
int S21Matrix::get_cols() const { return cols_; }

//-------------mutator-------------//
void S21Matrix::SetCols(int NewCols) {
  if (NewCols <= 0) throw invalid_argument("less than one");
  S21Matrix buff(rows_, NewCols);
  if (NewCols > 0) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < NewCols; j++) {
        if (j < cols_) buff.matrix_[i][j] = (*this)(i, j);
      }
    }
  }
  *this = buff;
}

void S21Matrix::SetRows(int NewRows) {
  if (NewRows <= 0) throw invalid_argument("less than one");
  S21Matrix buff(NewRows, cols_);
  if (NewRows != rows_) {
    for (int i = 0; i < NewRows; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i < rows_) buff.matrix_[i][j] = (*this)(i, j);
      }
    }
  }
  *this = buff;
}

//-------------копирование для гаусса-------------//
void S21Matrix::copy_matrix(S21Matrix *res, int index) {
  for (int j = 0; j < cols_; j++) {
    res->matrix_[0][j] = matrix_[index - 1][j];
  }
}
//-------------нулевой детерминант для инверсии-------------//
int S21Matrix::det_zero() {
  int code = 0;
  double det = 0;
  det = this->Determinant();
  if (det == 0.0000000) throw std::invalid_argument("det is equal to 0");
  ;
  return code;
}

//-------------копирование матрицы-------------//
void S21Matrix::copy_matrix_ordinary(S21Matrix *res) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res->matrix_[i][j] = matrix_[i][j];
    }
  }
}
