all: parser.cpp scanner.cpp
	make clean
	bison -d -Wcounterexamples -o parser.cpp parser.y 2> /dev/null
	flex -o scanner.cpp lexer.l
	g++ -w parser.cpp scanner.cpp ast.cpp -o ../parser -std=c++11
	chmod +x parser conv_to_x86
	./parser test.py > /dev/null
	./conv_to_x86 --input=3ac.txt --output=5.s 2> /dev/null > /dev/null

clean:
	rm -f *.csv 5.s 3ac.txt 





























