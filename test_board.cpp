#include "board.h"
#include "utils.h"

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    srand(time(NULL));

	Board *board=choose_game(OTHELLO);
	board->play_random_move(PLAYER_1);
    board->print();

    Board *copy=board->deepcopy();
    Token winner=board->play_random_game(PLAYER_2);
    if (winner==NOT_PLAYED) std::cout<<"draw"<<std::endl;
    else std::cout<<"player "<<winner<<" won"<<std::endl;
    board->print();
	delete board;

    copy->play_random_move(PLAYER_2);
    copy->print();
    delete copy;

	return 0;
}
