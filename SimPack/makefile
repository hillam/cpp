PROGRAM = SimPack
FILES = SimWindow.cpp ParticlePlayground.cpp SimpleParticle.cpp Main.cpp

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
	g++ -std=c++11 $(FILES) -o $(PROGRAM).o `pkg-config gtkmm-3.0 --cflags --libs`
    
clean:
	rm -f *.zip
	rm -f *.o
