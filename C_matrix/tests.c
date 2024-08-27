#include <check.h>

#include "s21_matrix.h"

/***********************************/
/************** CREATE *************/
/***********************************/
START_TEST(test_create) {
  matrix_t A;
  int code = s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_create_1) {
  matrix_t A;
  int code = s21_create_matrix(0, 2, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_2) {
  matrix_t A;
  int code = s21_create_matrix(2, 0, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_3) {
  matrix_t A;
  int code = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_4) {
  matrix_t A;
  int code = s21_create_matrix(10000, 10000, &A);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_create_5) {
  matrix_t A;
  int code = s21_create_matrix(-1, 1000, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_6) {
  matrix_t A;
  int code = s21_create_matrix(1000, -1, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_7) {
  matrix_t A;
  int code = s21_create_matrix(-1, -1, &A);
  ck_assert_int_eq(1, code);
}
END_TEST;

START_TEST(test_create_8) {
  matrix_t A;
  int code = s21_create_matrix(10, 5, &A);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_create_9) {
  matrix_t A;
  int code = s21_create_matrix(5, 10, &A);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST;

Suite *s21_test_create() {
  Suite *result;
  TCase *tc_create;

  result = suite_create("s21_create_matrix");
  tc_create = tcase_create("s21_create");

  tcase_add_test(tc_create, test_create);
  tcase_add_test(tc_create, test_create_1);
  tcase_add_test(tc_create, test_create_2);
  tcase_add_test(tc_create, test_create_3);
  tcase_add_test(tc_create, test_create_4);
  tcase_add_test(tc_create, test_create_5);
  tcase_add_test(tc_create, test_create_6);
  tcase_add_test(tc_create, test_create_7);
  tcase_add_test(tc_create, test_create_8);
  tcase_add_test(tc_create, test_create_9);
  suite_add_tcase(result, tc_create);
  return result;
}

/***********************************/
/************ COMPARISON ***********/
/***********************************/
START_TEST(test_comparison) {
  matrix_t A;
  matrix_t B;

  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(1, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_2) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_3) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[2][2] = 10;
  B.matrix[2][2] = 10;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_4) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[2][2] = 1;
  B.matrix[2][2] = 10;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_5) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  A.matrix[2][2] = 0.00001;
  B.matrix[2][2] = 0.00001;
  int code = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(1, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_comparison_6) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  int code = s21_eq_matrix(&A, NULL);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
}
END_TEST;

Suite *s21_test_comparison() {
  Suite *result;
  TCase *tc_comparison;

  result = suite_create("s21_comparison_matrix");
  tc_comparison = tcase_create("s21_comparison");

  tcase_add_test(tc_comparison, test_comparison);
  tcase_add_test(tc_comparison, test_comparison_1);
  tcase_add_test(tc_comparison, test_comparison_2);
  tcase_add_test(tc_comparison, test_comparison_3);
  tcase_add_test(tc_comparison, test_comparison_4);
  tcase_add_test(tc_comparison, test_comparison_5);
  tcase_add_test(tc_comparison, test_comparison_6);
  suite_add_tcase(result, tc_comparison);
  return result;
}

/***********************************/
/*************** SUM ***************/
/***********************************/
START_TEST(test_sum) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_sum_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(1, 1, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sum_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sum_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_sum_4) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(6, 6, &B);

  int code = s21_sum_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sum_6) {
  matrix_t res;
  int code = s21_sum_matrix(NULL, NULL, &res);
  ck_assert_int_eq(1, code);
}
END_TEST;

Suite *s21_test_sum() {
  Suite *result;
  TCase *tc_sum;

  result = suite_create("s21_sum_matrix");
  tc_sum = tcase_create("s21_sum");

  tcase_add_test(tc_sum, test_sum);
  tcase_add_test(tc_sum, test_sum_1);
  tcase_add_test(tc_sum, test_sum_2);
  tcase_add_test(tc_sum, test_sum_3);
  tcase_add_test(tc_sum, test_sum_4);
  tcase_add_test(tc_sum, test_sum_6);
  suite_add_tcase(result, tc_sum);
  return result;
}

/***********************************/
/*************** SUB ***************/
/***********************************/
START_TEST(test_sub) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 0;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_sub_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 1, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sub_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sub_3) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_sub_4) {
  matrix_t A;
  matrix_t B;
  matrix_t res = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(6, 6, &B);

  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sub_5) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(9, 8, &A);
  s21_create_matrix(1, 5, &B);
  int code = s21_sub_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_sub_6) {
  matrix_t res;

  int code = s21_sub_matrix(NULL, NULL, &res);
  ck_assert_int_eq(1, code);
}
END_TEST;

Suite *s21_test_sub() {
  Suite *result;
  TCase *tc_sub;

  result = suite_create("s21_sub_matrix");
  tc_sub = tcase_create("s21_sub");

  tcase_add_test(tc_sub, test_sub);
  tcase_add_test(tc_sub, test_sub_1);
  tcase_add_test(tc_sub, test_sub_2);
  tcase_add_test(tc_sub, test_sub_3);
  tcase_add_test(tc_sub, test_sub_4);
  tcase_add_test(tc_sub, test_sub_5);
  tcase_add_test(tc_sub, test_sub_6);
  suite_add_tcase(result, tc_sub);
  return result;
}

/***********************************/
/*************** MULT **************/
/***********************************/

START_TEST(test_mult) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 25;
  A.matrix[0][1] = 14;
  A.matrix[1][0] = 101;
  A.matrix[1][1] = 9;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 5;
  B.matrix[1][1] = 8;

  int code = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_mult_1) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(1, 2, &B);

  int code = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_mult_2) {
  matrix_t A;
  matrix_t B;
  matrix_t res;
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(8, 3, &B);
  int code = s21_mult_matrix(&A, &B, &res);
  ck_assert_int_eq(2, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_mult_5) {
  matrix_t res;
  int code = s21_mult_matrix(NULL, NULL, &res);
  ck_assert_int_eq(1, code);
}
END_TEST;

Suite *s21_test_mult() {
  Suite *result;
  TCase *tc_mult;

  result = suite_create("s21_mult_matrix");
  tc_mult = tcase_create("s21_mult");

  tcase_add_test(tc_mult, test_mult);
  tcase_add_test(tc_mult, test_mult_1);
  tcase_add_test(tc_mult, test_mult_2);
  tcase_add_test(tc_mult, test_mult_5);

  suite_add_tcase(result, tc_mult);
  return result;
}

/***********************************/
/*********** MULT NUMBER ***********/
/***********************************/

START_TEST(test_mult_number) {
  matrix_t A;
  matrix_t res;
  double result = 4;
  s21_create_matrix(2, 2, &A);
  int code = s21_mult_number(&A, result, &res);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST;

START_TEST(test_mult_number_1) {
  double result = 4;
  matrix_t res;
  int code = s21_mult_number(NULL, result, &res);
  ck_assert_int_eq(1, code);
}
END_TEST;

Suite *s21_test_mult_number() {
  Suite *result;
  TCase *tc_test_mult_number;

  result = suite_create("s21_test_mult_number_matrix");
  tc_test_mult_number = tcase_create("s21_test_mult_number");

  tcase_add_test(tc_test_mult_number, test_mult_number);
  tcase_add_test(tc_test_mult_number, test_mult_number_1);
  suite_add_tcase(result, tc_test_mult_number);
  return result;
}

/***********************************/
/************ TRANSPOSE ************/
/***********************************/
START_TEST(test_transpose) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 2, &A);

  int code = s21_transpose(&A, &B);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_transpose_1) {
  matrix_t B;
  int code = s21_transpose(NULL, &B);
  ck_assert_int_eq(1, code);
}
END_TEST;

Suite *s21_test_transpose() {
  Suite *result;
  TCase *tc_test_transpose;

  result = suite_create("s21_test_transpose");
  tc_test_transpose = tcase_create("s21_test_transpose");

  tcase_add_test(tc_test_transpose, test_transpose);
  tcase_add_test(tc_test_transpose, test_transpose_1);

  suite_add_tcase(result, tc_test_transpose);
  return result;
}

/***********************************/
/*********** DETERMINANT ***********/
/***********************************/
START_TEST(test_determinant) {
  matrix_t A;
  double result = 0;
  double res = -24;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;

  s21_determinant(&A, &result);
  ck_assert_int_eq(res, result);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_determinant_1) {
  matrix_t A;
  double result = 0;
  double res = 2;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;
  s21_determinant(&A, &result);
  ck_assert_int_eq(res, result);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_determinant_2) {
  matrix_t A;
  double result;
  double res = -1;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_determinant(&A, &result);
  ck_assert_double_eq_tol(res, result, 10e-7);
  s21_remove_matrix(&A);
}
END_TEST;

START_TEST(test_determinant_3) {
  matrix_t A;
  double result;
  double res = -2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_determinant(&A, &result);
  ck_assert_double_eq_tol(res, result, 10e-7);
  s21_remove_matrix(&A);
}
END_TEST;

Suite *s21_test_determinant() {
  Suite *result;
  TCase *tc_test_determinant;

  result = suite_create("s21_test_determinant");
  tc_test_determinant = tcase_create("s21_test_determinant");

  tcase_add_test(tc_test_determinant, test_determinant);
  tcase_add_test(tc_test_determinant, test_determinant_1);
  tcase_add_test(tc_test_determinant, test_determinant_2);
  tcase_add_test(tc_test_determinant, test_determinant_3);

  suite_add_tcase(result, tc_test_determinant);
  return result;
}

/***********************************/
/********* CALC COMPLEMENTS ********/
/***********************************/

START_TEST(test_c_compl) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;
  int code = s21_calc_complements(&A, &B);
  ck_assert_int_eq(0, code);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_c_compl_1) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int code = s21_calc_complements(&A, &B);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

START_TEST(test_c_compl_2) {
  matrix_t A;
  matrix_t res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;

  int code = s21_calc_complements(&A, &res);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST;

Suite *s21_test_c_compl() {
  Suite *result;
  TCase *tc_test_c_compl;

  result = suite_create("s21_test_c_compl");
  tc_test_c_compl = tcase_create("s21_test_test_c_compl");

  tcase_add_test(tc_test_c_compl, test_c_compl);
  tcase_add_test(tc_test_c_compl, test_c_compl_1);
  tcase_add_test(tc_test_c_compl, test_c_compl_2);

  suite_add_tcase(result, tc_test_c_compl);
  return result;
}

/***********************************/
/************* INVERSE *************/
/***********************************/

START_TEST(test_inverse) {
  matrix_t A;
  matrix_t B;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int code = s21_inverse_matrix(&A, &B);
  ck_assert_int_eq(0, code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST;

Suite *s21_test_inverse() {
  Suite *result;
  TCase *tc_inverse;

  result = suite_create("s21_inverse");
  tc_inverse = tcase_create("s21_test_inverse");

  tcase_add_test(tc_inverse, test_inverse);
  suite_add_tcase(result, tc_inverse);
  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = s21_test_create();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_comparison();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_sum();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_sub();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_mult();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_mult_number();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_transpose();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_determinant();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_c_compl();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_inverse();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}