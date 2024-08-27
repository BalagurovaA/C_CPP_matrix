#include "s21_matrix_oop.h"
//-------------сравнение матриц-------------//
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool code = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;

  for (int i = 0; i < rows_ && code == true; i++) {
    for (int j = 0; j < cols_ && code == true; j++) {
      if ((fabsf((double)matrix_[i][j] - (double)other.matrix_[i][j])) > 1e-7) {
        code = false;
      }
    }
  }
  return code;
}

//-------------сумма матриц-------------//
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std ::invalid_argument("different matrix dimensions");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

//-------------разность матриц-------------//
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.get_rows() || cols_ != other.get_cols())
    throw std ::invalid_argument("different matrix dimensions");
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

//-------------умножение матриц на число -------------//
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

//-------------умножение матриц-------------//
void S21Matrix::MulMatrix(const S21Matrix& other) {
  S21Matrix res(rows_, other.cols_);
  if (cols_ != other.rows_)
    throw std ::invalid_argument(
        "the columns of the first are not equal to the rows of the second");
  for (int i = 0; i < rows_; i++) {
    for (int x = 0; x < other.cols_; x++) {
      for (int j = 0; j < cols_; j++) {
        res.matrix_[i][x] += matrix_[i][j] * other.matrix_[j][x];
      }
    }
  }
  *(this) = res;
}

//-------------транспонирование матриц-------------//
S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }
  return res;
}

//-------------детерминант-------------//
double S21Matrix::Determinant() {
  double result = 0;
  if (rows_ != cols_)
    throw std ::invalid_argument(
        "the columns of the first are not equal to the rows of the second");

  if (rows_ == 1) {
    result = matrix_[0][0];
  } else {
    gaussan_method(&result);
  }
  return result;
}

//-------------метод гаусса-------------//
void S21Matrix::gaussan_method(double* result) {
  double k = 0;
  int iteration = 0;
  for (int j = 0; j < cols_; j++) {
    for (int i = rows_ - 1; i > iteration; i--) {
      if (matrix_[i - 1][j] == 0) {
        for (int g = 0; g < cols_; g++) {
          matrix_[i - 1][g] += matrix_[i][g];
        }
      }
      S21Matrix buffer(1, cols_);
      copy_matrix(&buffer, i);
      if (matrix_[i - 1][j] != 0) {
        k = (double)-1.0 * (matrix_[i][j] / buffer.matrix_[0][j]);

        for (int z = 0; z < buffer.cols_; z++) {
          buffer.matrix_[0][z] = buffer.matrix_[0][z] * k;
          matrix_[i][z] += buffer.matrix_[0][z];
        }
      }
    }
    iteration++;
  }
  *result = 1.0;
  for (int i = 0; i < rows_; i++) {
    *result *= matrix_[i][i];
  }
}

//-------------минор для алгебраического дополнения-------------//
double S21Matrix::minor_r(int get_i, int get_j) {
  int flag = 0;
  S21Matrix buff(rows_ - 1, cols_ - 1);
  double minorr = 0;

  if (rows_ == 1) {
    minorr = matrix_[0][0];
    flag = 1;
  }
  int res_i = 0;
  int res_j = 0;
  if (!flag) {
    for (int i = 0; i < rows_; i++) {
      if (i != get_i) {
        for (int j = 0; j < cols_; j++) {
          if (j != get_j) {
            buff.matrix_[res_i][res_j] = matrix_[i][j];
            res_j++;
          }
        }
        res_j = 0;
        res_i++;
      }
    }
    minorr = buff.Determinant();
  }
  return minorr;
}

//-------------алгебраическое дополнение-------------//
S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) throw std ::invalid_argument("matrix is not square");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = minor_r(i, j);
      result.matrix_[i][j] *= pow(-1, (i + j));
    }
  }

  return result;
}

//-------------инверсия-------------//
S21Matrix S21Matrix::InverseMatrix() {
  int code = 0;
  S21Matrix result(rows_, cols_);
  S21Matrix C(rows_, cols_);
  copy_matrix_ordinary(&C);
  if (C.det_zero()) throw std ::invalid_argument("determinant is equal to 0");
  if (cols_ != rows_) throw std ::invalid_argument("matrix is not square");
  double det = 0;
  S21Matrix B(rows_, cols_);
  copy_matrix_ordinary(&B);
  det = B.Determinant();
  if (rows_ == 1) {
    result.matrix_[0][0] = 1 / B.matrix_[0][0];
  } else if (code == 0) {
    if (det != 0) {
      S21Matrix buff;
      buff = this->CalcComplements();
      S21Matrix transpose = buff.Transpose();
      transpose.MulNumber(1.0 / det);
      result = transpose;
    } else
      code = 1;
  }
  return result;
}