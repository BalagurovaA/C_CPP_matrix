#include <gtest/gtest.h>

#include "s21_matrix_oop.h"
#define EPS 1e-6
using namespace std;
/***********************************/
/************ COMPARISON ***********/
/***********************************/
TEST(EQTest, EqTest_1) {
  S21Matrix A;
  S21Matrix B;

  A.filling_matrix();
  B.filling_matrix();

  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(EQTest, EqTest_2) {
  S21Matrix A(2, 2);
  S21Matrix B(1, 2);

  A.filling_matrix();
  B.filling_matrix();

  ASSERT_TRUE(A.EqMatrix(B) == false);
}

TEST(EQTest, EqTest_3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);

  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(EQTest, EqTest_4) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 12;
  A(0, 1) = 85;
  A(1, 0) = 21;
  A(1, 1) = 1;

  B(0, 0) = 12;
  B(0, 1) = 85;
  B(1, 0) = 21;
  B(1, 1) = 1;

  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(EQTest, EqTest_5) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 12;
  B(0, 0) = 10;

  ASSERT_TRUE(A.EqMatrix(B) == false);
}

TEST(EQTest, EqTest_6) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A(0, 0) = 0.00001;
  B(0, 0) = 0.00001;

  ASSERT_TRUE(A.EqMatrix(B) == true);
}

/***********************************/
/*************** SUM ***************/
/***********************************/
TEST(SUTest, SuTest_1) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 12;
  A(0, 1) = 78;
  A(1, 0) = 45;
  A(1, 1) = 55;

  B(0, 0) = 78;
  B(0, 1) = 54;
  B(1, 0) = 111;
  B(1, 1) = 71.3;
  S21Matrix C;
  C(0, 0) = 90;
  C(0, 1) = 132;
  C(1, 0) = 156;
  C(1, 1) = 126.3;
  A += B;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}
TEST(SUTest, SuTest_2) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 12;
  A(0, 1) = 78;
  A(1, 0) = 45;
  A(1, 1) = 55;

  B(0, 0) = 78;
  B(0, 1) = 54;
  B(1, 0) = 111;
  B(1, 1) = 71.3;
  S21Matrix D;
  S21Matrix C;
  C(0, 0) = 90;
  C(0, 1) = 132;
  C(1, 0) = 156;
  C(1, 1) = 126.3;
  D = A + B;
  ASSERT_TRUE(D.EqMatrix(C) == true);
}

TEST(SUTest, SuTest_3) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 0.56;
  A(0, 1) = 21.311;
  A(1, 0) = 45.66;
  A(1, 1) = 45.889;

  B(0, 0) = 32.54;
  B(0, 1) = 112.32;
  B(1, 0) = 78.96;
  B(1, 1) = 15.389;
  S21Matrix C;
  C(0, 0) = 33.1;
  C(0, 1) = 133.631;
  C(1, 0) = 124.62;
  C(1, 1) = 61.278;
  A += B;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(SUTest, SuTest_4) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 0.56;
  A(0, 1) = 21.311;
  A(1, 0) = 45.66;
  A(1, 1) = 45.889;

  B(0, 0) = 32.54;
  B(0, 1) = 112.32;
  B(1, 0) = 78.96;
  B(1, 1) = 15.389;
  S21Matrix C;
  C(0, 0) = 33.1;
  C(0, 1) = 133.631;
  C(1, 0) = 124.62;
  C(1, 1) = 61.278;
  A += B;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(SUTest, SuTest_5) {
  S21Matrix A(2, 2);
  S21Matrix B(1, 1);
  EXPECT_THROW(A.SumMatrix(B), std::invalid_argument);
}

/***********************************/
/*************** SUB ***************/
/***********************************/
TEST(SBTest, SBTest_1) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 12;
  A(0, 1) = 78;
  A(1, 0) = 45;
  A(1, 1) = 55;

  B(0, 0) = 78;
  B(0, 1) = 54;
  B(1, 0) = 111;
  B(1, 1) = 71;

  S21Matrix C;
  C(0, 0) = -66;
  C(0, 1) = 24;
  C(1, 0) = -66;
  C(1, 1) = -16;
  A -= B;

  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(SBTest, SBTest_2) {
  S21Matrix A;
  S21Matrix B;
  S21Matrix D;
  A(0, 0) = 26.36;
  A(0, 1) = 48.9;
  A(1, 0) = 64.1;
  A(1, 1) = 7458.123;

  B(0, 0) = 4566.88;
  B(0, 1) = 460.21;
  B(1, 0) = 345.65;
  B(1, 1) = 78.54;

  S21Matrix C;
  C(0, 0) = -4540.52;
  C(0, 1) = -411.31;
  C(1, 0) = -281.55;
  C(1, 1) = 7379.583;
  D = A - B;
  ASSERT_TRUE(D.EqMatrix(C) == true);
}

TEST(SBTest, SBTest_3) {
  S21Matrix A(3, 5);
  S21Matrix B(3, 5);
  S21Matrix C(3, 5);
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(SBTest, SBTest_4) {
  S21Matrix A;
  S21Matrix B;
  A(0, 0) = 26.36;
  A(0, 1) = 48.9;
  A(1, 0) = 64.1;
  A(1, 1) = 7458.123;

  B(0, 0) = 4566.88;
  B(0, 1) = 460.21;
  B(1, 0) = 345.65;
  B(1, 1) = 78.54;

  S21Matrix C;
  C(0, 0) = -4540.52;
  C(0, 1) = -411.31;
  C(1, 0) = -281.55;
  C(1, 1) = 7379.583;
  A -= B;

  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(SBTest, SBTest_5) {
  S21Matrix A(3, 5);
  S21Matrix B(34, 5);
  EXPECT_THROW(A.SubMatrix(B), std::invalid_argument);
}

/***********************************/
/************* MUL NUM *************/
/***********************************/
TEST(MNTest, MNTest_1) {
  S21Matrix A;

  A(0, 0) = 25;
  A(0, 1) = 75;
  A(1, 0) = 85;
  A(1, 1) = 105;

  S21Matrix C;
  C(0, 0) = 1962.5;
  C(0, 1) = 5887.5;
  C(1, 0) = 6672.5;
  C(1, 1) = 8242.5;
  A *= 78.5;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(MNTest, MNTest_2) {
  S21Matrix A(3, 2);

  A(0, 0) = 25;
  A(0, 1) = 75;
  A(1, 0) = 33;
  A(1, 1) = 85;
  A(2, 0) = 105;
  A(2, 1) = 75;

  S21Matrix C(3, 2);
  C(0, 0) = -550;
  C(0, 1) = -1650;
  C(1, 0) = -726;
  C(1, 1) = -1870;
  C(2, 0) = -2310;
  C(2, 1) = -1650;
  A *= -22;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

TEST(MNTest, MNTest_22) {
  S21Matrix A(3, 2);
  S21Matrix B(3, 2);
  A(0, 0) = 10;
  A(0, 1) = 10;
  A(1, 0) = 10;
  A(1, 1) = 10;
  A(2, 0) = 10;
  A(2, 1) = 10;

  S21Matrix C(3, 2);
  C(0, 0) = 220;
  C(0, 1) = 220;
  C(1, 0) = 220;
  C(1, 1) = 220;
  C(2, 0) = 220;
  C(2, 1) = 220;
  B = A * 22;
  ASSERT_TRUE(B == C);
}

TEST(MNTest, MNTest_3) {
  S21Matrix A(3, 3);

  A(0, 0) = 39;
  A(0, 1) = 15;
  A(0, 2) = 564;
  A(1, 0) = 33;
  A(1, 1) = 78;
  A(1, 2) = 270;
  A(2, 0) = 105;
  A(2, 1) = 71;
  A(2, 2) = 1600;

  S21Matrix C(3, 3);
  C(0, 0) = -858;
  C(0, 1) = -330;
  C(0, 2) = -12408;
  C(1, 0) = -726;
  C(1, 1) = -1716;
  C(1, 2) = -5940;
  C(2, 0) = -2310;
  C(2, 1) = -1562;
  C(2, 2) = -35200;
  A *= -22;
  ASSERT_TRUE(A.EqMatrix(C) == true);
}

/***********************************/
/*********** MULT MATRIX ***********/
/***********************************/

TEST(MMTest, MMTest_1) {
  S21Matrix A;
  S21Matrix C;
  S21Matrix B;
  A(0, 0) = 39;
  A(0, 1) = 15;
  A(1, 0) = 33;
  A(1, 1) = 78;

  C(0, 0) = -8;
  C(0, 1) = -4;
  C(1, 0) = 3;
  C(1, 1) = 28;

  B(0, 0) = -267;
  B(0, 1) = 264;
  B(1, 0) = -30;
  B(1, 1) = 2052;
  A *= C;
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(MMTest, MMTest_22) {
  S21Matrix A;
  S21Matrix C;
  S21Matrix B;
  S21Matrix D;
  A(0, 0) = 11;
  A(0, 1) = 22;
  A(1, 0) = 33;
  A(1, 1) = 44;

  C(0, 0) = 10;
  C(0, 1) = 21;
  C(1, 0) = 31;
  C(1, 1) = 41;

  B(0, 0) = 792;
  B(0, 1) = 1133;
  B(1, 0) = 1694;
  B(1, 1) = 2497;

  D = A * C;
  ASSERT_TRUE(D.EqMatrix(B) == true);
}

TEST(MMTest, MMTest_2) {
  S21Matrix A(2, 2);
  S21Matrix C(1, 2);

  EXPECT_THROW(A.MulMatrix(C), std::invalid_argument);
}

// /***********************************/
// /************ TRANSPOSE ************/
// /***********************************/

TEST(TRTest, TRTest_1) {
  S21Matrix A(6, 2);
  S21Matrix B(2, 6);
  A = A.Transpose();
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(TRTest, TRTest_2) {
  S21Matrix A(1, 3);
  S21Matrix B(3, 1);
  A(0, 0) = 39;
  A(0, 1) = 15;
  A(0, 2) = 33;

  B(0, 0) = 39;
  B(1, 0) = 15;
  B(2, 0) = 33;
  A = A.Transpose();

  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(TRTest, TRTest_3) {
  S21Matrix A(2, 2);
  S21Matrix B(2, 2);
  A.filling_matrix();
  A = A.Transpose();
  B(0, 0) = 1;
  B(0, 1) = 3;
  B(1, 0) = 2;
  B(1, 1) = 4;
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

/***********************************/
/*********** DETERMINANT ***********/
/***********************************/

TEST(DTTest, DTTest_1) {
  S21Matrix A(2, 2);
  A.filling_matrix();
  double my_res = A.Determinant();
  ASSERT_EQ(-2, my_res);
}

TEST(DTTest, DTTest_2) {
  S21Matrix A(3, 3);

  A(0, 0) = 39;
  A(0, 1) = 15;
  A(0, 2) = 564;
  A(1, 0) = 33;
  A(1, 1) = 78;
  A(1, 2) = 270;
  A(2, 0) = 105;
  A(2, 1) = 71;
  A(2, 2) = 1600;
  double my_res = A.Determinant();
  ASSERT_NEAR(my_res, 455112, EPS);
}

TEST(DTTest, DTTest_33) {
  S21Matrix A(3, 3);

  A(0, 0) = 0;
  A(0, 1) = 5;
  A(0, 2) = 5;
  A(1, 0) = 5;
  A(1, 1) = 5;
  A(1, 2) = 5;
  A(2, 0) = 0;
  A(2, 1) = 5;
  A(2, 2) = 0;
  double my_res = A.Determinant();
  ASSERT_NEAR(my_res, 125, EPS);
}

TEST(DTTest, DTTest_3) {
  S21Matrix A;
  A(0, 0) = 0.27;
  A(0, 1) = 1.45;
  A(1, 0) = -64.1;
  A(1, 1) = -96.5;
  double my_res = A.Determinant();
  ASSERT_NEAR(my_res, 66.89, EPS);
}

TEST(DTTest, DTTest_4) {
  S21Matrix A(1, 1);
  A(0, 0) = 0.27;
  double my_res = A.Determinant();
  ASSERT_NEAR(my_res, 0.27, EPS);
}

TEST(DTTest, DTTest_5) {
  S21Matrix A(1, 8);
  EXPECT_THROW(A.Determinant(), std::invalid_argument);
}
/***********************************/
/********* CALC COMPLEMENTS ********/
/***********************************/

TEST(CCTest, CCTest_1) {
  S21Matrix A(3, 3);
  A(0, 0) = 3;
  A(0, 1) = 1;
  A(0, 2) = 5;
  A(1, 0) = 3;
  A(1, 1) = 7;
  A(1, 2) = 2;
  A(2, 0) = 1;
  A(2, 1) = 7;
  A(2, 2) = 6;

  S21Matrix B(3, 3);
  B(0, 0) = 28;
  B(0, 1) = -16;
  B(0, 2) = 14;
  B(1, 0) = 29;
  B(1, 1) = 13;
  B(1, 2) = -20;
  B(2, 0) = -33;
  B(2, 1) = 9;
  B(2, 2) = 18;
  A = A.CalcComplements();
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(CCTest, CCTest_2) {
  S21Matrix A(3, 4);
  EXPECT_THROW(A.CalcComplements(), std::invalid_argument);
}
/***********************************/
/************* INVERSE *************/
/***********************************/
TEST(INTest, INTest_1) {
  S21Matrix A;
  A(0, 0) = 2;
  A(0, 1) = 6;
  A(1, 0) = 8;
  A(1, 1) = 4;

  S21Matrix B;
  B(0, 0) = -0.1;
  B(0, 1) = 0.15;
  B(1, 0) = 0.2;
  B(1, 1) = -0.05;

  A = A.InverseMatrix();
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(INTest, INTest_2) {
  S21Matrix A(1, 1);
  A(0, 0) = 4;
  S21Matrix B(1, 1);
  B(0, 0) = 0.25;
  A = A.InverseMatrix();
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(INTest, INTest_3) {
  S21Matrix A(12, 9);
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}
/***********************************/
/************ NEW ROWS *************/
/***********************************/

TEST(NRTest, NRTest_1) {
  S21Matrix A(1, 1);
  S21Matrix B(4, 1);
  A.SetRows(4);
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(NRTest, NRTest_2) {
  S21Matrix A;
  A(0, 0) = 2;
  A(0, 1) = 6;
  A(1, 0) = 8;
  A(1, 1) = 4;
  A.SetRows(1);

  S21Matrix B(1, 2);
  B(0, 0) = 2;
  B(0, 1) = 6;
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

/***********************************/
/************ NEW COLS *************/
/***********************************/

TEST(NCTest, NCTest_1) {
  S21Matrix A;
  A(0, 0) = 2;
  A(0, 1) = 6;
  A(1, 0) = 8;
  A(1, 1) = 4;
  A.SetCols(1);

  S21Matrix B(2, 1);
  B(0, 0) = 2;
  B(1, 0) = 8;
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

TEST(NCTest, NCTest_2) {
  S21Matrix A(1, 1);
  S21Matrix B(1, 4);
  A.SetCols(4);
  ASSERT_TRUE(A.EqMatrix(B) == true);
}

/***********************************/
/************ CONSTRUCTOR **********/
/***********************************/
TEST(COPYTest, COPYTest_1) {
  S21Matrix A;
  A(0, 0) = 2;
  A(0, 1) = 6;
  A(1, 0) = 8;
  A(1, 1) = 4;
  S21Matrix copy(A);

  ASSERT_TRUE(A.EqMatrix(copy) == true);
}

TEST(MOVEYTest, MOVETest_1) {
  S21Matrix A(3, 3);
  S21Matrix B(move(A));
  EXPECT_EQ(3, B.get_rows());
  EXPECT_EQ(3, B.get_cols());
  EXPECT_EQ(0, A.get_rows());
  EXPECT_EQ(0, A.get_cols());
}

TEST(OPERATORTest, OPERATORTest_0) {
  S21Matrix A;

  EXPECT_THROW(A(45, 4) = 2, std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}