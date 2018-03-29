#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include <utility>
#include <ostream>

#include "../Tokens/Tokens.h"
#include "../Exceptions/Exceptions.h"

namespace Field{
    extern const int kN;

    std::vector<std::pair<int, int>> initkCells();

    extern const std::vector<std::pair<int, int>> kCells;
    extern const std::vector<std::pair<int, int>> kDelta;

    class FieldInstance{
    public:
        FieldInstance();
        FieldInstance(const FieldInstance &other);
        FieldInstance& operator=(const FieldInstance &other);

        bool is_winner() const;
        bool is_draw() const;
        bool is_winner(const Tokens::Player &player)const;

        Tokens::Cell get(const std::pair<int, int> &cell_coordinates) const;
        bool set(
            const std::pair<int, int> &cell_coordinates,
            const Tokens::Cell &cell);
        
        private:
            size_t hash_;
            std::vector<std::vector<Tokens::Cell>> field_;

            int free_cells_left;

            bool is_draw_;
            bool is_winner_;
            Tokens::Player winner_;
    };

    std::ostream& operator<<(std::ostream &strm, const FieldInstance &field);

    bool is_valid(std::pair<int, int> cell_coordinates);
    std::pair<int, int> get_difference(
        const FieldInstance &l,
        const FieldInstance &r);
}

#endif