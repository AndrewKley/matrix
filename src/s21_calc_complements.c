// Copyright [2023] jupitere
#include "./s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (is_correct_matrix(A) == OK && result) {
    if ((*A).rows == (*A).columns) {
      s21_create_matrix((*A).rows, (*A).columns, result);
      for (int i = 0; i < (*A).rows; i++) {
        for (int j = 0; j < (*A).columns; j++) {
          (*result).matrix[i][j] = pow(-1, i + j) * calculate_minor(i, j, A);
        }
      }
    } else {
      res = INCORRECT_CALCULATION;
    }
  } else {
    res = INCORRECT_MATRIX;
  }
  return res;
}
