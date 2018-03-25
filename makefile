CXX = g++
FLAGS = -g -pthread

OBJ_DIR = obj
BIN_DIR = bin
PRG_NAME = tic_tac_toe

READ_DIR = Read

OBJ = $(addprefix $(OBJ_DIR)/,\
main.o\
)

all: init $(PRG_NAME)

init :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(PRG_NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(BIN_DIR)/$(PRG_NAME)

$(OBJ_DIR)/%.o: %.cpp $(READ_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR) 