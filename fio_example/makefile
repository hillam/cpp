PROGRAM = FileExample
FILES = main.cpp FileReader.cpp 

all: run
run: zip
zip: build
build: clean

run:
	./$(PROGRAM).o

zip:
	rm -f $(PROGRAM).zip
	zip $(PROGRAM).zip *.cpp *.h makefile

build:
	g++ -std=c++0x $(FILES) -o $(PROGRAM).o
    
clean:
	rm -f *.zip
	rm -f *.o
