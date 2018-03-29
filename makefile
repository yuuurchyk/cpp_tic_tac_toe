CXX = g++
FLAGS = -g -pthread -std=c++11

OBJ_DIR = obj
BIN_DIR = bin
PRG_NAME = tic_tac_toe

READ_DIR = Read
COMMON_DIR = Common
TOKENS_DIR = Tokens
EXCEPTIONS_DIR = Exceptions

OBJ = $(addprefix $(OBJ_DIR)/,\
main.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
get_random_number.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
cell.o\
player.o\
tokens.o\
)

all: init $(PRG_NAME)

init :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(PRG_NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(BIN_DIR)/$(PRG_NAME)

$(OBJ_DIR)/%.o: %.cpp $(READ_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(COMMON_DIR)/%.cpp $(COMMON_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TOKENS_DIR)/%.cpp $(TOKENS_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(EXCEPTIONS_DIR)/%.cpp $(EXCEPTIONS_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR) 