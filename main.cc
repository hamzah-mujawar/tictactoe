#include <iostream>

namespace Gameparams{
	constexpr char player1 {'X'};
	constexpr char player2 {'O'};
	constexpr int boardSize { 3 };
}


void displayBoard(char gameBoard[Gameparams::boardSize][Gameparams::boardSize]){
	for (int i { 0 }; i < Gameparams::boardSize; i++){
		for(int j { 0 }; j < Gameparams::boardSize; j++){
			std::cout << gameBoard[i][j];
		}
		std::cout << '\n';
	}
}

char playerTurn (char currentPlayer)
{
	return ((currentPlayer == 'X') ? 'O' : 'X');
}

int main() {

	char gameBoard[Gameparams::boardSize][Gameparams::boardSize] {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	char currentPlayer { Gameparams::player1 };


  // TODO find a way to update the board with a turn

  // TODO find a way to handle turns

  // TODO handle logic of who won the game, handle draws
  
  // TODO Ask player if they want to play another round
  
	return 0;
}
