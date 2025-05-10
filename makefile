# Build the morse converter program:
build:
	g++ -o morseConverter Main.cpp FunctionDefinitions.cpp

# Run the main morse converter program WITHOUT TESTS:
run:
	./morseConverter --no-run

# Run tests:
test:
	./morseConverter testing

# lint the files:
lint:

# Build the program on a docker image:
build-docker:

# Run the docker image:
run-docker:

# Remove used morse converter files:
clean:
	rm morseConverter
	rm output.txt

