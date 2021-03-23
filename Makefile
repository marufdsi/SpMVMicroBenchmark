TARGET=micro
CXX=icpc
CXXFLAGS= -fopenmp -O3 -Wall -xCORE-AVX512 -qopt-zmm-usage=high
VEC_WIDTH=8

SRC_DIR := src
OBJ_DIR := obj
ASSEMBLY_DIR := assembly
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)	$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
ASSEMBLY_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(ASSEMBLY_DIR)/%.s,$(SRC_FILES))

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ) $(CXXFLAGS) $(LDFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -o $@ $^

GEN_ASM: $(ASSEMBLY_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -c -o $@ $<

$(ASSEMBLY_DIR)/%.s: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -S -o $@ $< 

.PHONY: clean

clean:
	rm -f $(TARGET)
