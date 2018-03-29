CXX = g++
FLAGS = -O3 -pthread -std=c++14

OBJ_DIR = obj
BIN_DIR = bin
PRG_NAME = tic_tac_toe

READ_DIR = Read
COMMON_DIR = Common
TOKENS_DIR = Tokens
EXCEPTIONS_DIR = Exceptions
FIELD_DIR = Field
FIELD_TREE_DIR = FieldTree
PLAYER_DIR = Player
GAME_DIR = Game
PLAYER_FACTORY_DIR = PlayerFactory

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
OBJ += $(addprefix $(OBJ_DIR)/,\
field.o\
field_instance.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
medium_bot_field_tree.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
abstract_player.o\
get_human_player_name.o\
get_medium_bot_player_name.o\
human_player.o\
medium_bot.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
game.o\
)
OBJ += $(addprefix $(OBJ_DIR)/,\
fill.o\
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

$(OBJ_DIR)/%.o: $(FIELD_DIR)/%.cpp $(FIELD_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(FIELD_TREE_DIR)/%.cpp $(FIELD_TREE_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PLAYER_DIR)/%.cpp $(PLAYER_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GAME_DIR)/%.cpp $(GAME_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PLAYER_FACTORY_DIR)/%.cpp $(PLAYER_FACTORY_DIR)/*.h
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR) 