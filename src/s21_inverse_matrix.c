// Copyright [2023] jupitere
#include "./s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double det = 0;
  if (is_correct_matrix(A) == OK && result) {
    int pass = s21_determinant(A, &det);
    if ((*A).rows == (*A).columns && (*A).rows > 1 && det != 0 && !pass) {
      matrix_t temp;
      s21_calc_complements(A, result);
      s21_transpose(result, &temp);
      s21_remove_matrix(result);
      s21_mult_number(&temp, (1 / det), result);
      s21_remove_matrix(&temp);
    } else {
      res = INCORRECT_CALCULATION;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}
