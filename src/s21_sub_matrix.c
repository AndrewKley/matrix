// Copyright [2023] jupitere
#include "./s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK && result) {
    status = _set_result_matrix(A, B, result);
    if (status == OK) {
      for (int i = 0; i < (*A).rows; i++)
        for (int j = 0; j < (*A).columns; j++)
          (*result).matrix[i][j] = (*A).matrix[i][j] - (*B).matrix[i][j];
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}
