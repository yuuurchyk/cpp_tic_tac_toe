#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include <utility>
#include <ostream>
#include <set>

namespace Field{
    extern const int kN;
    extern const std::vector<std::pair<int, int> > kDelta;

    extern const char
        kFirstPlayer,
        kSecondPlayer,
        kEmpty;

    char get_opposite_player(char current_player);

    extern const std::set<char>
        kPlayersTokens;

    bool valid(std::pair<int, int> cell);

    class FieldInstance{
    public:
        FieldInstance();
        FieldInstance(const FieldInstance &other);
        FieldInstance& operator=(const FieldInstance &other);

        bool is_occupied(std::pair<int, int> cell) const;
        char get(std::pair<int, int> cell) const;
        bool set(std::pair<int, int> cell, char value);

        char is_winner() const;
        bool is_draw() const;
        int get_free_cells_left() const;
    private:
        std::vector<std::vector<char> > field;
        int free_cells_left;
    };

    std::ostream& operator<<(std::ostream &strm, const FieldInstance &field);
}

#endif