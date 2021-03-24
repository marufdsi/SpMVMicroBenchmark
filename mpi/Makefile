TARGET=micro
CXX=mpicxx
CXXFLAGS= -O3 -Wall -xCORE-AVX512 #-qopt-zmm-usage=high
INCLUDE=-I/apps/pkg/intel/2019/compilers_and_libraries_2019.0.117/linux/compiler/include/
LIB=-L/apps/pkg/intel/2019/compilers_and_libraries_2019.0.117/linux/compiler/lib
VEC_WIDTH=8
N_CHAINED_FMAS=8
$(info	N_CHAINED_FMAS is $(N_CHAINED_FMAS))
SRC_DIR := src
OBJ_DIR := obj
ASSEMBLY_DIR := assembly
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)	$(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
ASSEMBLY_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(ASSEMBLY_DIR)/%.s,$(SRC_FILES))

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(OBJ) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE) $(LIB) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -o $@ $^

GEN_ASM: $(ASSEMBLY_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIB) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -c -o $@ $<

$(ASSEMBLY_DIR)/%.s: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(LIB) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -S -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET)
