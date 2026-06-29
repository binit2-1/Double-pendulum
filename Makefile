# compiler
CXX = g++

# Compiler flags (-Wall shows warnings, -std=c++17 uses modern C++)
CXXFLAGS = -Wall -std=c++17

# Libraries to link
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -O3 -s

# Your source files and output name
SRC = src/*.cpp
OUT = bin/DoublePendulum

# The default build rule
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

# Rule to clean up the compiled file
clean:
	rm -f $(OUT)

start:
	$(OUT)
