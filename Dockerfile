# FROM used to be: node:lts-alpine
FROM ubuntu:latest

# Start at this working directory.
WORKDIR /app

# Copy all files into the image.
COPY . .

RUN apt-get update
RUN apt-get install g++

RUN g++ -o morseConverter Main.cpp FunctionDefinitions.cpp

# Run this command only after the docker image has completed setup.
CMD ["./morseConverter", "--no-run"]

# Expose this port
EXPOSE 3000