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

	/*
	 * We need to getRows and getCols at least once that's why we use a do while
	 * If the user tries to enter a row/column that's full it will loop back
	 */
	do{
		placeRow = getRows();
		placeCol = getCols();
		if(gameBoard[placeRow][placeCol] != ' ')
			std::cout << "This cells is occupied try again" << '\n';
	}while(gameBoard[placeRow][placeCol] != ' ');

	gameBoard[placeRow][placeCol] = currentPlayer; // place the X/O 

	currentPlayer = playerTurn(currentPlayer); // swap the current player

	return currentPlayer;  
}


bool checkRows(char gameBoard[Gameparams::boardSize][Gameparams::boardSize], char player){
	for(int i = 0; i < Gameparams::boardSize; i++){
		if(gameBoard[i][0] == player && 
				gameBoard[i][1] == player &&
				gameBoard[i][2] == player)
			return true;
	}
	return false;
}

bool checkCols(char gameBoard[Gameparams::boardSize][Gameparams::boardSize], char player){
	for(int i = 0; i < Gameparams::boardSize; i++){
		if(gameBoard[0][i] == player &&
				gameBoard[1][i] == player &&
				gameBoard[2][i] == player)
			return true;
	}
	return false;
}

bool checkDiags(char gameBoard[Gameparams::boardSize][Gameparams::boardSize], char player){
	if(gameBoard[0][0] == player &&
			gameBoard[1][1] == player &&
			gameBoard[2][2] == player)
		return true;
	else if(gameBoard[2][0] == player &&
			gameBoard[1][1] == player &&
			gameBoard[0][2] == player)
		return true;
	return false;
}


bool checkWin(char gameBoard[Gameparams::boardSize][Gameparams::boardSize], char player){
	return (checkRows(gameBoard, player) || checkCols(gameBoard, player) || checkDiags(gameBoard, player));
}

int main() {

	char gameBoard[Gameparams::boardSize][Gameparams::boardSize] {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};

	char currentPlayer { Gameparams::player1 }; // setting player 1 to be X (game starts with X)
	
	bool checkWinner = checkWin(gameBoard, currentPlayer);

	while(!checkWinner){		
		char playerBeforeTurn { currentPlayer }; // save prev player
		currentPlayer = makeTurn(gameBoard, currentPlayer); // this function returns the next player
		displayBoard(gameBoard);
		checkWinner = checkWin(gameBoard, playerBeforeTurn);
		if(checkWinner)
			std::cout << "Player " << playerBeforeTurn << " wins\n";

	}
  
  // TODO Ask player if they want to play another round and handle draws
  
	return 0;
}
