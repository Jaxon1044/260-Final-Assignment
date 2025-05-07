build:
	g++ -o morseConverter Main.cpp FunctionDefinitions.cpp

run:
	./morseConverter

clean:
	rm morseConverter
	rm output.txt

