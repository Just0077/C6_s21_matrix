#include "../s21_matrix.h"

int s21_determinant(matrix_t* A, double* result) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else if (A->columns != A->rows) {
    answer = MATRIX_ERROR;
  } else {
    *result = s21_calculate_recursive_det(A);
  }
  return answer;
}
