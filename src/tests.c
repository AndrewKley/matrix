// Copyright [2023] jupitere
#include "./tests.h"

int main(void) {
  SRunner *srunner = srunner_create(get_create_suite());
  int counted_errors = 0;

  srunner_add_suite(srunner, get_is_eq_matrix_suite());
  srunner_add_suite(srunner, get_sum_matrix_suite());
  srunner_add_suite(srunner, get_sub_matrix_suite());
  srunner_add_suite(srunner, get_mult_number());
  srunner_add_suite(srunner, get_mult_matrix());
  srunner_add_suite(srunner, get_transpose());
  srunner_add_suite(srunner, get_determinant());
  srunner_add_suite(srunner, get_calc_complements());
  srunner_add_suite(srunner, get_inverse());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_NORMAL);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(inverse_1_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT12);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_2_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 1, &a);
  init_matrix(&a, MAT12);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_3_test) {
  matrix_t a = {0}, result;
  int res = 0;
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_4_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT1);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_5_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT1);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_6_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT11);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_7_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT5);
  res = s21_inverse_matrix(&a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
}
END_TEST

Suite *get_inverse(void) {
  Suite *suite = suite_create("Inverse_test");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, inverse_1_test);
  tcase_add_test(tc, inverse_2_test);
  tcase_add_test(tc, inverse_3_test);
  tcase_add_test(tc, inverse_4_test);
  tcase_add_test(tc, inverse_5_test);
  tcase_add_test(tc, inverse_6_test);
  tcase_add_test(tc, inverse_7_test);

  return suite;
}

START_TEST(calc_1_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT11);
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_2_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(1, 1, &a);
  init_matrix(&a, MAT11);
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_3_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(2, 2, &a);
  init_matrix(&a, MAT1);
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_4_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(4, 2, &a);
  init_matrix(&a, MAT10);
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(calc_5_test) {
  matrix_t a = {0}, result;
  int res = 0;
  s21_create_matrix(3, 1, &a);
  init_matrix(&a, MAT2);
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(calc_6_test) {
  matrix_t a = {0}, result;
  int res = 0;
  res = s21_calc_complements(&a, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
  s21_remove_matrix(&a);
}
END_TEST

Suite *get_calc_complements(void) {
  Suite *suite = suite_create("Calc_test");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, calc_1_test);
  tcase_add_test(tc, calc_2_test);
  tcase_add_test(tc, calc_3_test);
  tcase_add_test(tc, calc_4_test);
  tcase_add_test(tc, calc_5_test);
  tcase_add_test(tc, calc_6_test);

  return suite;
}

START_TEST(determinate_1_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT10);
  ck_assert_int_eq(0, s21_determinant(&a, &det));
  ck_assert_int_eq(-87, det);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinate_2_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT1);
  ck_assert_int_eq(0, s21_determinant(&a, &det));
  ck_assert_int_eq(12, det);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinate_3_test) {
  matrix_t a = {0};
  double det = 0;
  ck_assert_int_eq(INCORRECT_MATRIX, s21_determinant(&a, &det));
}
END_TEST

START_TEST(determinate_4_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(1, 5, &a);
  init_matrix(&a, MAT1);
  ck_assert_int_eq(INCORRECT_CALCULATION, s21_determinant(&a, &det));
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinate_5_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(3, 3, &a);
  init_matrix(&a, MAT6);
  ck_assert_int_eq(0, s21_determinant(&a, &det));
  ck_assert_int_eq(32, det);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinate_6_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(1, 1, &a);
  init_matrix(&a, MAT6);
  ck_assert_int_eq(0, s21_determinant(&a, &det));
  ck_assert_int_eq(1., det);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinate_7_test) {
  matrix_t a = {0};
  double det = 0.;
  s21_create_matrix(2, 2, &a);
  init_matrix(&a, MAT6);
  ck_assert_int_eq(0, s21_determinant(&a, &det));
  ck_assert_int_eq(-2., det);
  s21_remove_matrix(&a);
}
END_TEST

Suite *get_determinant(void) {
  Suite *suite = suite_create("Determinant_test");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, determinate_1_test);
  tcase_add_test(tc, determinate_2_test);
  tcase_add_test(tc, determinate_3_test);
  tcase_add_test(tc, determinate_4_test);
  tcase_add_test(tc, determinate_5_test);
  tcase_add_test(tc, determinate_6_test);
  tcase_add_test(tc, determinate_7_test);

  return suite;
}

START_TEST(transpose_1_test) {
  matrix_t a = {0}, result;
  int m = 2, n = 2;
  int res = 0;
  ck_assert_int_eq(0, s21_create_matrix(m, n, &a));
  init_matrix(&a, MAT1);
  res = s21_transpose(&a, &result);
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_2_test) {
  matrix_t a = {0}, result;
  int m = 3, n = 2;
  int res = 0;
  ck_assert_int_eq(0, s21_create_matrix(m, n, &a));
  init_matrix(&a, MAT4);
  res = s21_transpose(&a, &result);
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_3_test) {
  matrix_t a = {0}, result;
  int res = 0;
  res = s21_transpose(&a, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
}
END_TEST

START_TEST(transpose_4_test) {
  matrix_t a = {0}, result;
  int m = 3, n = 1;
  int res = 0;
  ck_assert_int_eq(0, s21_create_matrix(m, n, &a));
  init_matrix(&a, MAT5);
  res = s21_transpose(&a, &result);
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_5_test) {
  matrix_t a = {0}, result;
  int m = 4, n = 2;
  int res = 0;
  ck_assert_int_eq(0, s21_create_matrix(m, n, &a));
  init_matrix(&a, MAT1);
  res = s21_transpose(&a, &result);
  ck_assert_int_eq(OK, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}
END_TEST

Suite *get_transpose(void) {
  Suite *suite = suite_create("Transpose_test");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, transpose_1_test);
  tcase_add_test(tc, transpose_2_test);
  tcase_add_test(tc, transpose_3_test);
  tcase_add_test(tc, transpose_4_test);
  tcase_add_test(tc, transpose_5_test);

  return suite;
}

START_TEST(mult_matrix_1_test) {
  matrix_t a = {0}, b = {0}, result;
  int m = 2, n = 2;
  int res = 0;
  s21_create_matrix(m, n, &a);
  s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT6);
  init_matrix(&b, MAT7);
  res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(2, result.rows);
  ck_assert_int_eq(2, result.columns);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_2_test) {
  matrix_t a = {0}, b = {0}, result;
  int m = 2, n = 3;
  int res = 0;
  s21_create_matrix(m, n, &a);
  s21_create_matrix(n, m, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(2, result.rows);
  ck_assert_int_eq(2, result.columns);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_3_test) {
  matrix_t a = {0}, b = {0}, result;
  int m = 2, n = 3;
  int res = 0;
  s21_create_matrix(n, m, &a);
  s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(3, result.rows);
  ck_assert_int_eq(3, result.columns);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_4_test) {
  matrix_t a = {0}, b = {0}, result;
  int m = 2, n = 3;
  int res = 0;
  s21_create_matrix(m, n, &a);
  s21_create_matrix(n, 1, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(2, result.rows);
  ck_assert_int_eq(1, result.columns);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_5_test) {
  matrix_t a = {0}, b = {0}, result;
  int m = 2, n = 3;
  int res = 0;
  s21_create_matrix(m, n, &a);
  s21_create_matrix(n, 1, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&b, &a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

START_TEST(mult_matrix_6_test) {
  matrix_t a = {0}, b = {0}, result;
  int res = 0;
  s21_create_matrix(1, 3, &a);
  s21_create_matrix(3, 1, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&a, &b, &result);
  ck_assert_int_eq(0, res);
  ck_assert_int_eq(1, result.rows);
  ck_assert_int_eq(1, result.columns);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_7_test) {
  matrix_t a = {0}, b = {0}, result;
  int res = 0;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 1, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&b, &a, &result);
  ck_assert_int_eq(INCORRECT_CALCULATION, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

START_TEST(mult_matrix_8_test) {
  matrix_t a = {0}, b = {0}, result;
  int res = 0;
  s21_create_matrix(3, 1, &b);
  init_matrix(&a, MAT8);
  init_matrix(&b, MAT9);
  res = s21_mult_matrix(&b, &a, &result);
  ck_assert_int_eq(INCORRECT_MATRIX, res);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

Suite *get_mult_matrix(void) {
  Suite *suite = suite_create("Mult_matrix_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, mult_matrix_1_test);
  tcase_add_test(tc, mult_matrix_2_test);
  tcase_add_test(tc, mult_matrix_3_test);
  tcase_add_test(tc, mult_matrix_4_test);
  tcase_add_test(tc, mult_matrix_5_test);
  tcase_add_test(tc, mult_matrix_6_test);
  tcase_add_test(tc, mult_matrix_7_test);
  tcase_add_test(tc, mult_matrix_8_test);

  return suite;
}

START_TEST(mult_number_1_test) {
  matrix_t a = {0}, res;
  int m = 3, n = 3;
  int res1 = 0, res_mul = 0;
  int num = 0.;
  res1 = s21_create_matrix(m, n, &a);
  init_matrix(&a, MAT1);
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res_mul);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_2_test) {
  matrix_t a = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res_mul = 0;
  int num = .0001;
  res1 = s21_create_matrix(m, n, &a);
  init_matrix(&a, MAT2);
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res_mul);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_3_test) {
  matrix_t a = {0}, res;
  int m = 1, n = 3;
  int res1 = 0, res_mul = 0;
  int num = 50;
  res1 = s21_create_matrix(m, n, &a);
  init_matrix(&a, MAT3);
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res_mul);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_4_test) {
  matrix_t a = {0}, res;
  int m = 3, n = 2;
  int res1 = 0, res_mul = 0;
  int num = -10;
  res1 = s21_create_matrix(m, n, &a);
  init_matrix(&a, MAT4);
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res_mul);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_5_test) {
  matrix_t a = {0}, res;
  int m = 3, n = 2;
  int res1 = 0, res_mul = 0;
  int num = -10.01;
  res1 = s21_create_matrix(m, n, &a);
  init_matrix(&a, MAT4);
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res_mul);
  s21_remove_matrix(&a);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(mult_number_6_test) {
  matrix_t a = {0}, res;
  int res_mul = 0;
  int num = 10;
  res_mul = s21_mult_number(&a, num, &res);
  ck_assert_int_eq(1, res_mul);
}
END_TEST

Suite *get_mult_number(void) {
  Suite *suite = suite_create("Mult_number_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, mult_number_1_test);
  tcase_add_test(tc, mult_number_2_test);
  tcase_add_test(tc, mult_number_3_test);
  tcase_add_test(tc, mult_number_4_test);
  tcase_add_test(tc, mult_number_5_test);
  tcase_add_test(tc, mult_number_6_test);

  return suite;
}

START_TEST(sub_1_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 3;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT1);
  init_matrix(&b, MAT1);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_2_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 2, n = 3;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT4);
  init_matrix(&b, MAT4);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_3_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 2;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT4);
  init_matrix(&b, MAT4);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_4_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_5_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 1, n = 3;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sub_6_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(1, 3, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(2, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_7_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sub = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(1, 3, &b);
  init_matrix(&a, MAT5);
  init_matrix(&b, MAT2);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(2, res_sub);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sub_8_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 1, n = 3;
  int res2 = 0;
  int res_sub = 0;
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&b, MAT2);
  res_sub = s21_sub_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(1, res_sub);
  s21_remove_matrix(&b);
}
END_TEST

Suite *get_sub_matrix_suite(void) {
  Suite *suite = suite_create("Sub_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, sub_1_test);
  tcase_add_test(tc, sub_2_test);
  tcase_add_test(tc, sub_3_test);
  tcase_add_test(tc, sub_4_test);
  tcase_add_test(tc, sub_5_test);
  tcase_add_test(tc, sub_6_test);
  tcase_add_test(tc, sub_7_test);
  tcase_add_test(tc, sub_8_test);

  return suite;
}

START_TEST(sum_1_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 3;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT1);
  init_matrix(&b, MAT1);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_2_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 2, n = 3;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT4);
  init_matrix(&b, MAT4);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_3_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 2;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT4);
  init_matrix(&b, MAT4);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_4_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_5_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 1, n = 3;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(sum_6_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(1, 3, &b);
  init_matrix(&a, MAT2);
  init_matrix(&b, MAT2);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(2, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}
END_TEST

START_TEST(sum_7_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int res_sum = 0;
  res1 = s21_create_matrix(m, n, &a);
  res2 = s21_create_matrix(1, 3, &b);
  init_matrix(&a, MAT5);
  init_matrix(&b, MAT2);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(2, res_sum);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

START_TEST(sum_8_test) {
  matrix_t a = {0}, b = {0}, res;
  int m = 1, n = 3;
  int res2 = 0;
  int res_sum = 0;
  res2 = s21_create_matrix(m, n, &b);
  init_matrix(&b, MAT2);
  res_sum = s21_sum_matrix(&a, &b, &res);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(1, res_sum);
  s21_remove_matrix(&b);
}
END_TEST

Suite *get_sum_matrix_suite(void) {
  Suite *suite = suite_create("Sum_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, sum_1_test);
  tcase_add_test(tc, sum_2_test);
  tcase_add_test(tc, sum_3_test);
  tcase_add_test(tc, sum_4_test);
  tcase_add_test(tc, sum_5_test);
  tcase_add_test(tc, sum_6_test);
  tcase_add_test(tc, sum_7_test);
  tcase_add_test(tc, sum_8_test);

  return suite;
}

START_TEST(is_eq_1_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 5, n = 5;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(1, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_2_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 5, n = 50;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(1, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_3_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 50, n = 5;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(1, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_4_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 3, n = 3;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  init_matrix(&mat1, MAT1);
  init_matrix(&mat2, MAT1);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(1, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_5_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 3, n = 1;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  init_matrix(&mat1, MAT2);
  init_matrix(&mat2, MAT2);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(1, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_6_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 1, n = 3;
  int res2 = 0;
  int is_eq = 0;
  res2 = s21_create_matrix(m, n, &mat2);
  init_matrix(&mat2, MAT3);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_7_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 1, n = 3;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, n, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  init_matrix(&mat1, MAT3);
  init_matrix(&mat2, MAT5);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

START_TEST(is_eq_8_test) {
  matrix_t mat1 = {0}, mat2 = {0};
  int m = 1, n = 3;
  int res1 = 0, res2 = 0;
  int is_eq = 0;
  res1 = s21_create_matrix(m, m, &mat1);
  res2 = s21_create_matrix(m, n, &mat2);
  init_matrix(&mat1, MAT3);
  init_matrix(&mat2, MAT5);
  is_eq = s21_eq_matrix(&mat1, &mat2);
  ck_assert_int_eq(0, res1);
  ck_assert_int_eq(0, res2);
  ck_assert_int_eq(0, is_eq);
  s21_remove_matrix(&mat1);
  s21_remove_matrix(&mat2);
}
END_TEST

Suite *get_is_eq_matrix_suite(void) {
  Suite *suite = suite_create("Is_eq_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, is_eq_1_test);
  tcase_add_test(tc, is_eq_2_test);
  tcase_add_test(tc, is_eq_3_test);
  tcase_add_test(tc, is_eq_4_test);
  tcase_add_test(tc, is_eq_5_test);
  tcase_add_test(tc, is_eq_6_test);
  tcase_add_test(tc, is_eq_7_test);
  tcase_add_test(tc, is_eq_8_test);

  return suite;
}

START_TEST(create_1_test) {
  matrix_t matrix = {0};
  int m = 4, n = 4;
  int res = s21_create_matrix(m, n, &matrix);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_2_test) {
  matrix_t matrix = {0};
  int m = -4, n = 4;
  int res = s21_create_matrix(m, n, &matrix);
  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(create_3_test) {
  matrix_t matrix = {0};
  int m = 4, n = 0;
  int res = s21_create_matrix(m, n, &matrix);
  ck_assert_int_eq(1, res);
}
END_TEST

START_TEST(create_4_test) {
  matrix_t matrix = {0};
  int m = 4, n = 40;
  int res = s21_create_matrix(m, n, &matrix);
  ck_assert_int_eq(0, res);
  s21_remove_matrix(&matrix);
}
END_TEST

Suite *get_create_suite(void) {
  Suite *suite = suite_create("The_create_tests");
  TCase *tc = tcase_create(TCASE_NAME);
  suite_add_tcase(suite, tc);

  tcase_add_test(tc, create_1_test);
  tcase_add_test(tc, create_2_test);
  tcase_add_test(tc, create_3_test);
  tcase_add_test(tc, create_4_test);

  return suite;
}

void init_matrix(matrix_t *A, double *array) {
  int k = 0;
  for (int i = 0; i < (*A).rows; i++) {
    for (int j = 0; j < (*A).columns; j++) {
      (*A).matrix[i][j] = array[k];
      k++;
    }
  }
}
