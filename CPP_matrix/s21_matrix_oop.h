#include <math.h>

#include <iostream>
using namespace std;

// incorrect matrix
// error calculation

class S21Matrix {
 private:
  double **matrix_;
  int rows_;
  int cols_;

 public:
  //методы

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  //операции над матрицами
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  //операции с детерминантом
  void copy_matrix(S21Matrix *res, int index);
  void gaussan_method(double *result);

  //операции с минором и алг дополнениями
  double minor_r(int get_i, int get_j);
  void copy_matrix_ordinary(S21Matrix *res);
  int det_zero();

  //вспомогтельные метды
  void PrintMatrix();
  void delete_matrix();
  void filling_matrix();
  void filling_matrix_3();

  // assesor //getter
  int get_rows() const;
  int get_cols() const;
  // mutator
  void SetCols(int NewCols);
  void SetRows(int NewCols);
  // helper для оператора ()
  double Matrix_El(int i, int j);

  //операторы
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(double num);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double num);
  double &operator()(int i, int j);
};