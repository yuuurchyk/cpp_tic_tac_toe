#ifndef FIELD_H_
#define FIELD_H_

#include "../Common/Common.h"
#include "../Exceptions/Exceptions.h"
#include "../Tokens/Tokens.h"

namespace TicTacToe{
    extern const int kN;

    extern const std::vector<std::pair<int, int>> kCellsCoordinates;
    extern const std::vector<std::pair<int, int>> kDelta;

    class Field{
    public:
        Field();
        Field(const Field &other);
        Field& operator=(const Field &other);

        bool is_draw() const;
        bool is_winner() const;
        bool is_winner(const Player &player)const;
        bool is_occupied(const std::pair<int, int> &cell_coordinates) const;

        size_t get_hash() const;

        Cell get(const std::pair<int, int> &cell_coordinates) const;
        bool set(
            const std::pair<int, int> &cell_coordinates,
            const Cell &cell);
        
        private:
            size_t hash_;
            std::vector<std::vector<Cell>> field_;

            bool is_draw_;
            bool is_winner_;
            Player winner_;

            int free_cells_left_;
    };

    bool is_valid(std::pair<int, int> cell_coordinates);
    std::pair<int, int> get_difference(
        const Field &l,
        const Field &r);
    
    std::ostream& operator<<(std::ostream &strm, const Field &field);
}

#endif