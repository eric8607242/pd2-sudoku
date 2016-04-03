Sudoku:Sudoku.o project1.o
	g++ -o Sudoku project1.o Sudoku.o

Sudoku.o:Sudoku.cpp Sudoku.h
	g++ -c Sudoku.h
	g++ -c Sudoku.cpp
project1.o:project1.cpp Sudoku.h
	g++ -c project1.cpp

clean:
	rm Sudoku*o

