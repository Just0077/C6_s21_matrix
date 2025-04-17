#include "../s21_matrix.h"

int s21_calc_complements(matrix_t* A, matrix_t* result) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else if (A->rows != A->columns) {
    answer = CALCULATION_ERROR;
  } else {
    int size = A->rows;
    if (size == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[MATRIX_INDEX][MATRIX_INDEX] = 1;
    } else {
      int sign = 1;
      matrix_t temp = {0};
      s21_create_matrix(size - 1, size - 1, &temp);
      s21_create_matrix(size, size, result);
      for (int i = MATRIX_INDEX; i < size; ++i) {
        for (int j = MATRIX_INDEX; j < size; ++j) {
          s21_remove_matrix_order(A, &temp, i, j);
          sign = ((i + j) % 2 == 0) ? 1 : -1;
          result->matrix[i][j] = (sign)*s21_calculate_recursive_det(&temp);
        }
      }
      s21_remove_matrix(&temp);
    }
  }
  return answer;
}