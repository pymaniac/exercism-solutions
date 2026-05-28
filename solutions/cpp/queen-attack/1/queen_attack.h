#pragma once

#include <utility>
#include <stdexcept>
#include <iostream>

typedef std::pair<int, int> pawn;

namespace queen_attack {

// TODO: add your solution here
class chess_board {
    public:
    chess_board(const pawn white, const pawn black) : w(white), b(black) {
        if (white == black) {
            throw std::domain_error("Invalid");
        }
        auto [wx, wy] = white;
        auto [bx, by] = black;
        if (wx < 0 || wy < 0 || bx < 0 || by < 0) {
            throw std::domain_error("Invalid");
        }
        if (wx > 7 || wy > 7 || bx > 7 || by > 7) {
            throw std::domain_error("Invalid");
        }
    }
    bool can_attack() const {
        auto x = std::abs(w.first - b.first);
        auto y = std::abs(w.second - b.second);
        return (!x || !y || x==y);
    }
    inline const pawn white() const { return w; }
    inline const pawn black() const { return b; }
    
    private:
    const pawn w, b;
}; 

}  // namespace queen_attack
