#include "s21_matrix.h"
//-------------создание матрицы-------------//
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (result == NULL || rows <= 0 || columns <= 0) {
    return INCORRECT;
  }
  int code = OK;
  if ((result->matrix = (double **)calloc(rows, sizeof(double *)))) {
    for (int i = 0; i < rows && code == OK; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) code = INCORRECT;
    }
  } else
    code = INCORRECT;
  if (code == OK) {
    result->rows = rows;
    result->columns = columns;
  }
  return code;
}
//-------------очищение матрицы-------------//
void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->columns <= 0 || A->rows <= 0) return;
  if (A->rows != 0) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix != NULL) free(A->matrix[i]);
    }
    if (A->matrix != NULL) free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

//-------------сравнение матриц-------------//
/**
 * матрицы равны = 1
 * матрицы не равны = 0
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->rows <= 0 || A->columns <= 0 || A == NULL || B == NULL ||
      A->rows != B->rows || A->columns != B->columns)
    return FAILURE;
  int code = SUCCESS;
  for (int i = 0; i < A->rows && code == SUCCESS; i++) {
    for (int j = 0; j < A->columns && code == SUCCESS; j++) {
      if (fabsf((float)A->matrix[i][j] - (float)B->matrix[i][j]) > 1e-7) {
        code = FAILURE;
      }
    }
  }
  return code;
}

//-------------сложение матриц-------------//
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (A == NULL || B == NULL || result == NULL || A->rows <= 0 ||
      A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    return INCORRECT;
  if (A->rows != B->rows || A->columns != B->columns) return ERR_CALC;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return code;
}

//-------------вычитание матриц-------------//
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int code = OK;
  if (A == NULL || B == NULL || A->rows <= 0 || A->columns <= 0 ||
      B->rows <= 0 || B->columns <= 0)
    return INCORRECT;
  if (A->rows != B->rows || A->columns != B->columns) return ERR_CALC;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return code;
}
//-------------умножение матриц-------------//
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->rows <= 0 ||
      A->columns <= 0 || B->rows <= 0 || B->columns <= 0)
    return INCORRECT;

  int code = OK;
  if (A->columns != B->rows)
    code = ERR_CALC;
  else
    code = s21_create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < A->rows && code == OK; i++) {
    for (int x = 0; x < B->columns; x++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][x] += A->matrix[i][j] * B->matrix[j][x];
      }
    }
  }
  return code;
}

//-------------умножение матриц на число-------------//
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int code = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) return INCORRECT;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return code;
}

//-------------транспонирование матриц-------------//
int s21_transpose(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) return INCORRECT;
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return code;
}

//-------------определитель матриц-------------//
int s21_determinant(matrix_t *A, double *result) {
  int code = OK;
  // int flag = 0;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    code = INCORRECT;
    return code;
  }
  if (A->rows != A->columns) {
    code = ERR_CALC;
    return code;
  }
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else {
    gaussian_method(A, result);
  }
  return code;
}

// -------------метод Гаусса-------------//
void gaussian_method(matrix_t *A, double *result) {
  double k = 0;
  int iteration = 0;
  for (int j = 0; j < A->columns; j++) {
    for (int i = A->rows - 1; i > iteration; i--) {
      matrix_t buffer;

      if (A->matrix[i - 1][j] == 0) {
        for (int g = 0; g < A->columns; g++) {
          A->matrix[i - 1][g] += A->matrix[i][g];
        }
      }
      s21_create_matrix(1, A->columns, &buffer);
      copy_matrix(A, &buffer, i);

      if (A->matrix[i - 1][j] != 0) {
        k = (double)-1.0 * (A->matrix[i][j] / buffer.matrix[0][j]);

        for (int z = 0; z < buffer.columns; z++) {
          buffer.matrix[0][z] = buffer.matrix[0][z] * k;
          A->matrix[i][z] += buffer.matrix[0][z];
        }
      }
      s21_remove_matrix(&buffer);
    }
    iteration++;
  }
  *result = 1.0;
  for (int i = 0; i < A->rows; i++) {
    *result *= A->matrix[i][i];
  }
}
//-------------минор для алгебраического дополнения-------------//
double minor_r(matrix_t *A, int get_i, int get_j) {
  int flag = 0;
  matrix_t buff;
  buff.rows = A->rows - 1;
  buff.columns = A->columns - 1;
  s21_create_matrix(buff.rows, buff.columns, &buff);

  double minorr = 0;
  if (A->rows == 1) {
    minorr = A->matrix[0][0];
    flag = 1;
  }
  int res_i = 0;
  int res_j = 0;
  if (!flag) {
    for (int i = 0; i < A->rows; i++) {
      if (i != get_i) {
        for (int j = 0; j < A->columns; j++) {
          if (j != get_j) {
            buff.matrix[res_i][res_j] = A->matrix[i][j];
            res_j++;
          }
        }
        res_j = 0;
        res_i++;
      }
    }
    s21_determinant(&buff, &minorr);
  }
  s21_remove_matrix(&buff);
  return minorr;
}

//-------------алгебраическое дополнение-------------//
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int code = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0 || result == NULL)
    return code = INCORRECT;
  if (A->columns != A->rows) return code = ERR_CALC;
  s21_create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows && code == OK; i++) {
    for (int j = 0; j < A->columns && code == OK; j++) {
      result->matrix[i][j] = minor_r(A, i, j);
      result->matrix[i][j] *= pow(-1, (i + j));
    }
  }
  return code;
}
//-------------копирование матрицы-------------//
void copy_matrix(matrix_t *A, matrix_t *copy_res, int index) {
  for (int j = 0; j < A->columns; j++) {
    copy_res->matrix[0][j] = A->matrix[index - 1][j];
  }
}
int det_zero(matrix_t A) {
  int code = OK;
  double det = 0;
  s21_determinant(&A, &det);
  if (det == 0.0000000) code = INCORRECT;
  return code;
}

//-------------обратная матрица-------------//
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int code = OK;
  matrix_t C;
  s21_create_matrix(A->rows, A->columns, &C);
  copy_matrix_ordinary(A, &C);

  if (A == NULL || A->rows <= 0 || A->columns <= 0 || result == NULL)
    return INCORRECT;

  if (det_zero(C) || A->columns != A->rows) return ERR_CALC;
  matrix_t buff = {0};
  matrix_t B = {0};
  double det = 0;
  matrix_t transpose;

  s21_create_matrix(A->rows, A->columns, &B);
  copy_matrix_ordinary(A, &B);

  s21_determinant(&B, &det);
  if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / B.matrix[0][0];
  } else if (code == OK) {
    if (det != 0) {
      s21_calc_complements(A, &buff);

      s21_transpose(&buff, &transpose);
      s21_mult_number(&transpose, 1 / det, result);

      s21_remove_matrix(&transpose);
      s21_remove_matrix(&buff);
      s21_remove_matrix(&B);
      s21_remove_matrix(&C);
    } else
      code = INCORRECT;
  }
  return code;
}

void copy_matrix_ordinary(matrix_t *A, matrix_t *copy_res) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      copy_res->matrix[i][j] = A->matrix[i][j];
    }
  }
}