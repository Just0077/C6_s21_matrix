#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int answer = OK;
  if (A == NULL || B == NULL || s21_is_correct_matrix(A) ||
      s21_is_correct_matrix(B)) {
    answer = MATRIX_ERROR;
  } else if (A->columns != B->rows || A->rows != B->columns) {
    answer = CALCULATION_ERROR;
  } else {
    int rows = A->rows;
    int columns = B->columns;
    int k = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = MATRIX_INDEX; i < rows && !answer; ++i) {
      for (int j = MATRIX_INDEX; j < columns && !answer; ++j) {
        double tmp = 0;
        for (int q = MATRIX_INDEX; q < k && !answer; ++q) {
          if (is_incorrect_value(A->matrix[i][q]) ||
              is_incorrect_value(B->matrix[q][j])) {
            answer = CALCULATION_ERROR;
          } else {
            tmp += A->matrix[i][q] * B->matrix[q][j];
          }
        }
        result->matrix[i][j] = tmp;
      }
    }
  }
  return answer;
}