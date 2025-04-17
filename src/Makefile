CFLAGS = -Wall -Werror -Wextra -std=c11
TEST_LIBS = -lcheck
SOURCES = $(wildcard */s21_*.c */utils/*.c)
OS = $(shell uname)
GCOV_FLAG = --no-external

ifneq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lsubunit -pthread -lrt -lm
	GCOV_FLAG =
endif

all: s21_matrix.a test gcov_report

s21_matrix.a:
	gcc $(CFLAGS) -c $(SOURCES)
	ar rcs s21_matrix.a *.o

test: s21_matrix.a
	checkmk clean_mode=1 tests.check > tests.c
	gcc $(CFLAGS) --coverage $(SOURCES) tests.c s21_matrix.a $(TEST_LIBS) -o s21_tests
	./s21_tests	
	
gcov_report: test
	lcov -o gcov_test.info $(GCOV_FLAG) -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

clean:
	rm -rf ./*.o ./*.a gcov_test ./*.gcno ./*.gcda report/ ./s21_tests ./test.c ./*.info tests.c

clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.h */*.c */*/*.c
	rm -rf .clang-format

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.h */*.c */*/*.c
	rm -rf .clang-format

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_tests

rebuild: clean all
