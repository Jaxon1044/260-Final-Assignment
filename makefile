# Build the morse converter program:
build:
	g++ -o morseConverter Main.cpp FunctionDefinitions.cpp

# Run the main morse converter program:
run:
	./morseConverter --no-run

# Run tests:
test:
	./morseConverter 

# Remove used morse converter files:
clean:
	rm morseConverter
	rm output.txt

