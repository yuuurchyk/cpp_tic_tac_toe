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

OBJ = $(addprefix $(OBJ_DIR)/, main.o)
OBJ += $(addprefix $(OBJ_DIR)/, Common.o)
OBJ += $(addprefix $(OBJ_DIR)/, Tokens.o)
OBJ += $(addprefix $(OBJ_DIR)/, Field.o)
OBJ += $(addprefix $(OBJ_DIR)/, MediumBotFieldTree.o)
OBJ += $(addprefix $(OBJ_DIR)/,\
AbstractPlayer.o\
HumanPlayer.o\
MediumBot.o\
)
OBJ += $(addprefix $(OBJ_DIR)/, Game.o)
OBJ += $(addprefix $(OBJ_DIR)/, PlayerFactory.o)

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