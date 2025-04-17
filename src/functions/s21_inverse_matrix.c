#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t* A, matrix_t* result) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else {
    double det = s21_calculate_recursive_det(A);
    if (diff(det, 0)) {
      answer = CALCULATION_ERROR;
    } else {
      int size = A->rows;
      s21_create_matrix(size, size, result);
      s21_calc_wo_create(A, result);
      s21_alone_transpose(result);
      det = 1 / det;
      s21_alone_mult_number(result, det);
    }
  }
  return answer;
}
