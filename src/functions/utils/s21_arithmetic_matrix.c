#include "../../s21_matrix.h"

int s21_arithmetic_matrix(matrix_t* A, matrix_t* B, matrix_t* result,
                          char sign) {
  int answer = OK;
  if (A == NULL || B == NULL || s21_is_correct_matrix(A) ||
      s21_is_correct_matrix(B)) {
    answer = MATRIX_ERROR;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    answer = CALCULATION_ERROR;
  } else {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = MATRIX_INDEX; i < rows && !answer; ++i) {
      for (int j = MATRIX_INDEX; j < columns && !answer; ++j) {
        if (is_incorrect_value(A->matrix[i][j]) ||
            is_incorrect_value(B->matrix[i][j])) {
          answer = CALCULATION_ERROR;
        } else {
          if (sign == '+') {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          } else {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    }
  }
  return answer;
}