// Copyright [2023] jupitere
#include "./s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (!is_correct_matrix(A)) {
    free(A->matrix);
    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) status = INCORRECT_MATRIX;

  if (!status) {
    (*result).rows = rows;
    (*result).columns = columns;
    (*result).matrix =
        malloc(rows * columns * sizeof(double) + rows * sizeof(double *));
    double *ptr = (double *)((*result).matrix + rows);

    for (int i = 0; i < rows; i++) (*result).matrix[i] = ptr + i * columns;

    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++) (*result).matrix[i][j] = 0;
  }
  return status;
}
