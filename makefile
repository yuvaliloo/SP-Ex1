CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I. -g
TEST_TARGET = tests
MAIN_TARGET = main
SRC = Graph.cpp Algorithms.cpp Queue.cpp
OBJ = $(SRC:.cpp=.o)
TEST_SRC = Testing.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

DOCTEST_HEADER = doctest.hpp

$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ)

$(MAIN_TARGET): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $(MAIN_TARGET) $(OBJ) $(MAIN_OBJ)

Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp -o Algorithms.o

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp -o Queue.o

Testing.o: Testing.cpp Queue.hpp Graph.hpp Algorithms.hpp doctest.hpp
	$(CXX) $(CXXFLAGS) -c Testing.cpp -o Testing.o

main.o: main.cpp Queue.hpp Graph.hpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

valgrind: $(TEST_TARGET)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(MAIN_OBJ) $(TEST_TARGET) $(MAIN_TARGET)

all: clean $(TEST_TARGET) $(MAIN_TARGET)
