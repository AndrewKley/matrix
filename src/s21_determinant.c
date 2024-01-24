// Copyright [2023] jupitere
#include "./s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int status = 0;
  if (is_correct_matrix(A) == OK && result) {
    if ((*A).rows == (*A).columns) {
      if ((*A).rows == 1) {
        *result = (*A).matrix[0][0];
      } else {
        if (result) {
          *result = 0;
          for (int i = 0; i < (*A).rows; i++) {
            *result +=
                (*A).matrix[i][0] * pow(-1, 2 + i) * calculate_minor(i, 0, A);
          }
        }
      }
    } else {
      status = INCORRECT_CALCULATION;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}
