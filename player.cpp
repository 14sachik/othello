#include "player.hpp"

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
int Player::minimax(Board *board, Side side, int depth, int lower_bound, int upper_bound, Move *&best_move)
{
	best_move = NULL; 
	if (depth == 0) 
	{
		return board->heuristic_score(side);
	}
	int best_score = -1000000; 
	int new_score; 
	Move *m0; 
	Board *new_board; 
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; i < 8; j++) 
		{
			new_move = new Move(i, j); 
			if(checkmove(new_move, i, j)
			   {
				   
			   }
		}
	}
}

Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
	board->doMove(opponentsMove, o_side); 
	
	
    return nullptr;
}
