// Copyright [2023] jupitere
#include "./s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 0;
  if (is_correct_matrix(A) == OK && is_correct_matrix(B) == OK) {
    if ((*A).columns == (*B).columns) status++;
    if ((*A).rows == (*B).rows) status++;
    if (status == 2) {
      for (int i = 0; i < (*A).rows; i++)
        for (int j = 0; j < (*A).columns; j++)
          if (fabs((*A).matrix[i][j] - (*B).matrix[i][j]) >= EPS) {
            status = 0;
            break;
          }
      if (status == 2) status++;
    }
  }
  return status == 3 ? SUCCESS : FAILURE;
}
