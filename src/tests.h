// Copyright [2023] jupitere
#ifndef TESTS_H_
#define TESTS_H_
#include <check.h>

#include "./s21_matrix.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

double MAT1[] = {1, 2.0, 3., 4, 1, 6., 7, 2, 9, -1.2, 0.0001, 0.};
double MAT2[] = {0., -3., 0.132};
double MAT3[] = {-.1213, 4545, 0.3243};
double MAT4[] = {-134.234, 0., .023, -1, 0.243, 0};
double MAT5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
double MAT6[] = {1., 2., 3., 4., 1, 4, 3, 3, 1};
double MAT7[] = {1., 0., 2., 3.};
double MAT8[] = {5, -1, 0, 2, 1, 1};
double MAT9[] = {0, 2, 3, 1, -1, -2};
double MAT10[] = {-2, 1, 1, 1, 3, -5, 2, 4, 5};
double MAT11[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
double MAT12[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};

Suite *get_create_suite(void);
Suite *get_is_eq_matrix_suite(void);
Suite *get_sum_matrix_suite(void);
Suite *get_sub_matrix_suite(void);
Suite *get_mult_number(void);
Suite *get_mult_matrix(void);
Suite *get_transpose(void);
Suite *get_determinant(void);
Suite *get_calc_complements(void);
Suite *get_inverse(void);

void init_matrix(matrix_t *A, double *array);

#endif  // TESTS_H_
