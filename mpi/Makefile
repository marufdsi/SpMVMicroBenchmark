TARGET=micro
CXX=icpc
CXXFLAGS= -qopenmp -O3 -Wall -xCORE-AVX512 #-qopt-zmm-usage=high
MPIFLAGS = -I/apps/pkg/openmpi/4.0.3/rhel7_u5/pbs/gnu/include/ -L/apps/pkg/openmpi/4.0.3/rhel7_u5/pbs/gnu/lib/

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
	$(CXX) $(OBJ) $(CXXFLAGS) $(LDFLAGS) $(MPIFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -o $@ $^

GEN_ASM: $(ASSEMBLY_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(MPIFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -c -o $@ $<

$(ASSEMBLY_DIR)/%.s: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(MPIFLAGS) -DVECTOR_WIDTH=$(VEC_WIDTH) -DN_CHAINED_FMAS=$(N_CHAINED_FMAS) -S -o $@ $<

.PHONY: clean

clean:
	rm -f $(TARGET)
