#include <iostream>

// setting all constants in a global namespace
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

int getRows(){
	int row {}; 

	std::cout << "Row No: ";
	std::cin >> row;
	while(row > 2 || row < 0){
		std::cout << "Please enter a value between 0 and 2" << '\n';
		std::cin >> row;
	}
	return row;
}


int getCols(){
	int col{};

	std::cout << "Column No: ";
	std::cin >> col;
	while(col > 2 || col < 0){
		std::cout << "Please enter a value between 0 and 2" << '\n';
		std::cin >> col;
	}

	return col;
}

char makeTurn(char gameBoard[Gameparams::boardSize][Gameparams::boardSize], char currentPlayer){
	int placeRow {};
	int placeCol {};
	
	std::cout << "Where do you want to place " << currentPlayer << "?" << '\n';
	
	do{
		placeRow = getRows();
		placeCol = getCols();
		if(gameBoard[placeCol][placeRow] != ' ')
			std::cout << "This cells is occupied try again" << '\n';
	}while(gameBoard[placeCol][placeRow] != ' ');

	gameBoard[placeCol][placeRow] = currentPlayer;

	currentPlayer = playerTurn(currentPlayer);

	return currentPlayer;
}

int main() {

	char gameBoard[Gameparams::boardSize][Gameparams::boardSize] {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	char currentPlayer { Gameparams::player1 }; // setting player 1 to be X (game starts with X)

		
	currentPlayer = makeTurn(gameBoard, currentPlayer);
	displayBoard(gameBoard);
	currentPlayer = makeTurn(gameBoard, currentPlayer);
	displayBoard(gameBoard);
  // TODO find a way to update the board with a turn

  // TODO find a way to handle turns

  // TODO handle logic of who won the game, handle draws
  
  // TODO Ask player if they want to play another round
  
	return 0;
}
