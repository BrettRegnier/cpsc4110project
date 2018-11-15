CC := g++
SRC_DIR := ./src
BIN_DIR := ./bin
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BIN_DIR)/%.o,$(SRC_FILES))
INC_FILES := ./inc
LDFLAGS := 
CPPFLAGS := 
CXXFLAGS := -I$(INC_FILES)
EXE = quantum

all: 
	make dir
	make clean
	make Quantum
	make move

Quantum: $(OBJ_FILES)
	$(CC) $(LDFLAGS) -o $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean: 
	rm $(BIN_DIR)/*.o $(BIN_DIR)/$(EXE) -f

move:
	mv $(EXE) $(BIN_DIR)

dir:
	rm $(BIN_DIR) -rf
	mkdir $(BIN_DIR)