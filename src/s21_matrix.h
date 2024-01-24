// Copyright [2023] jupitere
#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-7
#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define INCORRECT_CALCULATION 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/**
 * @return 0 - OK
 * @return 1 - error, uncorrect matrix
 * @return 2 Calculation error (mismatched matrix sizes, matrix that cannot be
 * calculated, etc.)
 */

//
double calculate_minor(int row, int column, matrix_t *A);
// mult matricies
void _mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/**
 * @brief whether the resulting matrix has been created; if not, create
 * @return OK if created and set \
 * @return INCORRECT_MATRIX if uncorrect size
 */
int _create_result_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/**
 * @brief checks the size of the matrix and the presence of the matrix itself
 * @return 0 is OK \
 * @return INCORRECT MATRIX if size is uncorrect
 */
int is_correct_matrix(matrix_t *A);
/**
 * @brief checks only the size of the two matrices
 * @return 0 is OK \
 * @return 1 is not equals
 */
int is_eq_size_matrix(matrix_t *A, matrix_t *B);
/**
 * @brief whether the resulting matrix has been created; if not, create \
 * @brief compares whether the matrices are the same and only then creates
 * @return OK if created and set \
 * @return INCORRECT_MATRIX if uncorrect size
 */
int _set_result_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @return 0 is OK \
 * @return 1 if uncorrect size of the matrix
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
/**
 * @return 1 if A equals B  \
 * @return 0 if A not equals B
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // S21_MATRIX_H_
