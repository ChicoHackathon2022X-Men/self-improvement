main: main.o question.o quiz.o level.o
	g++ -Wall -pedantic -g -o main main.o question.o quiz.o level.o

question.o: question.h question.cpp
	g++ -Wall -pedantic -g -std=c++20 -c question.cpp

main.o: level.h quiz.h main.cpp
	g++ -Wall -pedantic -g -std=c++20 -c main.cpp

quiz.o: quiz.h question.h quiz.cpp
	g++ -Wall -pedantic -g -std=c++20 -c quiz.cpp

level.o: level.h level.cpp
	g++ -Wall -pedantic -g -std=c++20 -c level.cpp

clean:
	rm -f main main.exe main.o question.o quiz.o level.o