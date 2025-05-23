CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wconversion -std=c++17 -Iheaders

SRC_DIR = src
INC_DIR = headers
EXAMPLES_DIR = examples

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
EXAMPLE_FILES = $(wildcard $(EXAMPLES_DIR)/Ejercicio*.cpp)

EXES = $(patsubst $(EXAMPLES_DIR)/%.cpp,%,$(EXAMPLE_FILES))

all: $(EXES)

%: $(EXAMPLES_DIR)/%.cpp $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXES)
