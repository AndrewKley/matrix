// Copyright [2023] jupitere
#include "./s21_matrix.h"

int is_correct_matrix(matrix_t *A) {
  int is_ok = OK;
  if (A != NULL) {
    if ((*A).rows > 0) is_ok++;
    if ((*A).columns > 0) is_ok++;
    if ((*A).matrix != NULL) is_ok++;
  }
  return is_ok == 3 ? OK : INCORRECT_MATRIX;
}

int is_eq_size_matrix(matrix_t *A, matrix_t *B) {
  int is_ok = OK;
  if (A != NULL && B != NULL) {
    if ((*A).rows == (*B).rows) is_ok++;
    if ((*A).columns == (*B).columns) is_ok++;
  }
  return is_ok == 2 ? OK : INCORRECT_MATRIX;
}

int _set_result_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (is_eq_size_matrix(A, B) == OK && result != NULL) {
    status = s21_create_matrix((*A).rows, (*A).columns, result);
  } else {
    status = INCORRECT_CALCULATION;
  }
  return status;
}

double calculate_minor(int m, int n, matrix_t *A) {
  double res = 0;
  matrix_t tmp = {0};
  s21_create_matrix((*A).rows - 1, (*A).columns - 1, &tmp);
  for (int i = 0, i_tmp = 0; i < (*A).rows; i++) {
    if (i != m) {
      for (int j = 0, j_tmp = 0; j < (*A).columns; j++) {
        if (j != n) {
          tmp.matrix[i_tmp][j_tmp] = (*A).matrix[i][j];
          j_tmp++;
        }
      }
      i_tmp++;
    }
  }
  if (tmp.rows == 2) {
    res = (tmp.matrix[0][0] * tmp.matrix[1][1]) -
          (tmp.matrix[0][1] * tmp.matrix[1][0]);
  } else {
    s21_determinant(&tmp, &res);
  }
  s21_remove_matrix(&tmp);
  return res;
}
