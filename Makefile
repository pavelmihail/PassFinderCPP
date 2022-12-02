CXX = g++
FLAGS = -lcrypto
build:
		$(CXX) tema3.cpp -o tema3 $(CXXFLAGS)
run:
		./tema3

clean:
		rm -rf tema3