all: parser.cpp scanner.cpp
	make clean
	bison -d -Wcounterexamples -o parser.cpp parser.y 2> /dev/null
	flex -o scanner.cpp lexer.l
	g++ -w parser.cpp scanner.cpp ast.cpp -o parse -std=c++11

clean:
	rm -f *.csv
