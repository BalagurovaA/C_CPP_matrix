#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {  // row - строка, column - столбец
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum result_code {
  OK,
  INCORRECT,  // некорректная матрица
  ERR_CALC    // ошибка вычисления
};

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

double minor_r(matrix_t *A, int get_i, int get_j);
int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);
void gaussian_method(matrix_t *A, double *result);
void copy_matrix(matrix_t *A, matrix_t *copy_res, int index);
void copy_matrix_ordinary(matrix_t *A, matrix_t *copy_res);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int det_zero(matrix_t A);
