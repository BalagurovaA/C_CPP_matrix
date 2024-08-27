CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c++17 

OS = $(shell uname)

ifeq ($(OS),Linux)
    det_OS = -lgtest  -lm -lrt -lpthread -lsubunit
else
    det_OS = -lgtest -lm -lpthread
endif

all : clean s21_matrix_oop.a test gcov_report

test: 
	$(CC) $(CFLAGS) --coverage s21*.cc test.cc -lstdc++ -o test $(det_OS)
	./test

s21_matrix_oop.o: s21*.cc s21*.h
	$(CC) $(CFLAGS) s21*.cc  -c

s21_matrix_oop.a : s21_matrix_oop.o
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

gcov_report: test
	$(CC) $(CFLAGS) --coverage s21*.cc test.cc -lstdc++  -o test $(det_OS)
	./test
	lcov -t "result" -o res.info  --ignore-errors mismatch -c -d .
	lcov --remove res.info /c++/13 /usr/local/include/gtest -o filtered_coverage.info
	genhtml -o report filtered_coverage.info
	open report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -n *.cc *.h
	clang-format -style=Google -i *.cc *.h
	rm .clang-format

clean:
	rm -rf report *.gc* *.o *.info *.a test.dSYM test filtered_coverage.info report
	
rebuild: clean all