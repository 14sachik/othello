#include "player.hpp"
#include <stdio.h>
using namespace std;

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
	p_side = side; 
	if( side == WHITE)
		o_side = BLACK; 
	else
		o_side = WHITE; 
	board = new Board(); 
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
int Player::minimax(Board *board, Side side, int depth, Move *best_move)
{
	best_move = NULL; 
	if (depth == 0) 
	{
		return board->heuristic_score(side);
	}
	int best_score = -1000000; 
	int new_score; 
	Move *m0, *m1; 
	Board *new_board; 
	Side otherSide = side == BLACK ? WHITE : BLACK;
	cerr << "blah" << endl;

	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) 
		{
			m0 = new Move(i, j); 
			if(board->checkMove(m0, side))
			{
				new_board = board->copy();
				new_board->doMove(m0, side); 
				new_score = minimax(new_board, otherSide, depth - 1, m0); 
				if (depth%2 == 0) {
					if(new_score > best_score) 
					{
						best_score = new_score; 
						if( best_move != NULL)
						{
							delete best_move; 
						}
						best_move = m0; 
					}
					else
					{
						delete m0; 
					}
				}
				else {
					if(new_score < best_score) 
					{
						best_score = new_score; 
						if( best_move != NULL)
						{
							delete best_move; 
						}
						best_move = m0; 
					}
					else
					{
						delete m0; 
					}
				}   	   
			   }
		}
	}
	return best_score;
}

Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
	board->doMove(opponentsMove, o_side);
	Move *m1;
	minimax(board,p_side,2,m1);
	board->doMove(m1, p_side);
	
	
	
	
    return nullptr;
}
