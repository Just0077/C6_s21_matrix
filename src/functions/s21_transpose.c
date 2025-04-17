#include "../s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(columns, rows, result);
    for (int i = MATRIX_INDEX; i < result->rows; ++i) {
      for (int j = MATRIX_INDEX; j < result->columns; ++j) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return answer;
}