CXX = g++
FLAGS = -g -pthread -std=c++11

OBJ_DIR = obj
BIN_DIR = bin
PRG_NAME = tic_tac_toe

READ_DIR = Read
FIELD_DIR = Field

OBJ = $(addprefix $(OBJ_DIR)/,\
main.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
field.o\
field_instance.o\
)

all: init $(PRG_NAME)

init :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(PRG_NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(BIN_DIR)/$(PRG_NAME)

$(OBJ_DIR)/%.o: %.cpp $(READ_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(FIELD_DIR)/%.cpp $(FIELD_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR) 