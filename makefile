# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I.  # -I. ensures it looks in the current directory

# Executable
TEST_TARGET = tests

# Source Files
SRC = Graph.cpp Algorithms.cpp Queue.cpp
OBJ = $(SRC:.cpp=.o)  # Converts .cpp files to .o files
TEST_SRC = Testing.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)  # Converts test sources to .o files

# Doctest Header (included manually)
DOCTEST_HEADER = doctest.hpp

# Build Tests
$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(OBJ) $(TEST_OBJ)

# Explicit Dependencies for Each File
Graph.o: Graph.cpp Graph.hpp
	$(CXX) $(CXXFLAGS) -c Graph.cpp -o Graph.o

Algorithms.o: Algorithms.cpp Algorithms.hpp
	$(CXX) $(CXXFLAGS) -c Algorithms.cpp -o Algorithms.o

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CXXFLAGS) -c Queue.cpp -o Queue.o

Testing.o: Testing.cpp Queue.hpp Graph.hpp Algorithms.hpp doctest.hpp
	$(CXX) $(CXXFLAGS) -c Testing.cpp -o Testing.o

# Run Tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Clean Build Files
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TEST_TARGET)

# Rebuild Everything
all: clean $(TEST_TARGET)
