#include "queen_attack.h"

enum {
    MAX_CHESSBOARD = 7,
};

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (queen_1.row > MAX_CHESSBOARD || queen_1.column > MAX_CHESSBOARD ||
       queen_2.row > MAX_CHESSBOARD || queen_2.column > MAX_CHESSBOARD) {
        return INVALID_POSITION;
    }
    
    position_t diff = {.row = (queen_1.row > queen_2.row) ? queen_1.row - queen_2.row : queen_2.row - queen_1.row,
                       .column = (queen_1.column > queen_2.column) ? queen_1.column - queen_2.column: queen_2.column - queen_1.column,
    };

    if (!diff.row && !diff.column) return INVALID_POSITION;
    
    if (!diff.row || !diff.column || diff.row == diff.column) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}
