TARGET=micro
CXX=icpc
CXXFLAGS= -fopenmp -O3 -Wall -xCORE-512 -qopt-zmm-usage=high

SRC_DIR := src
OBJ_DIR := obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)	$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET)
