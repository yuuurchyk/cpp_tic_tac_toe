#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "Field/Field.h"
#include "Player/Player.h"

using std::cout;
using std::cin;
using std::endl;
using namespace Player;
using namespace Field;

int main(){
    FieldInstance field;

    std::vector<HumanPlayer> players;
    players.emplace_back(field, cin, cout, true);
    players.emplace_back(field, cin, cout, false);

    char winner;
    for
    (
        int index = 0;
        !field.is_winner(&winner) && field.get_free_cells_left() > 0;
        index ^= 1
    )
    {
        cout << field << endl;
        players[index].make_move();
    }

    cout << field << endl;

    if(field.is_draw())
        cout << "Draw" << endl;
    else{
        char winner;
        field.is_winner(&winner);
        cout << winner << " has won " << endl;
    }

    return 0;
}