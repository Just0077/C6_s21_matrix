#include "../../s21_matrix.h"

int s21_is_correct_matrix(matrix_t* A) {
  int result = OK;
  if (A->columns <= 0 || A->rows <= 0 || sizeof(*A) == 0) {
    result = MATRIX_ERROR;
  }
  return result;
}