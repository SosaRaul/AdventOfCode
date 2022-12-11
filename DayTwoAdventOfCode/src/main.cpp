#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

struct Game{
	char opponentBet;
	char youBet;
	string winner;
	int score;
};

// Returns vector with data gruop by round of three(represented like vector aswell)
void showRound(vector<Game> round);
vector<vector<Game>> getPuzzleInput(string pathToFile);
int getScoreOfRound(vector<int> round);
void setWinnerAndScoreOfGame(Game &game);
void showPuzzleInput(vector<vector<Game>> tournament);

int main(){
getPuzzleInput("src/input2");


	return 0;
}

void setWinnerAndScoreOfGame(Game &game){

	switch(game.opponentBet){

	case 'A':
		if(game.youBet == 'Y'){
			game.winner = "you";
			game.score = 2 + 6 ;
		}else if(game.youBet == 'Z'){
			game.winner = "opponent";
			game.score = 3;
		}else{
			game.winner = "draw";
			game.score = 3 + 1;
		}
		break;

	case 'B':
		if(game.youBet == 'X'){
			game.winner = "opponent";
			game.score = 1;
		}else if(game.youBet == 'Z'){
			game.winner = "you";
			game.score = 6 + 3;
		}else{
			game.winner = "draw";
			game.score = 3 + 2;
		}
		break;
	case 'C':
		if(game.youBet == 'X'){
			game.winner = "you";
			game.score = 1 + 6;
		}else if(game.youBet == 'Y'){
			game.winner = "opponent";
			game.score = 2;
		}else{
			game.winner = "draw";
			game.score = 3 + 3;
		}
		break;
	}
}
vector<vector<Game>> getPuzzleInput(string pathToFile){
	ifstream puzzleInput(pathToFile);
	vector<Game> round;
	vector<vector<Game>> tournament;
	int counterOfGames = 0;
	string line;

	if(puzzleInput.is_open()){
		while(!puzzleInput.eof()){
			streampos lastPosition = puzzleInput.tellg(); // Avoid lost one line
			getline(puzzleInput,line);
			// Save the round
			if(counterOfGames < 3){
				Game newGame;
				newGame.opponentBet = line[0];
				newGame.youBet = line[2];
				setWinnerAndScoreOfGame(newGame);
				round.push_back(newGame);
				cout << newGame.opponentBet << " " << newGame.youBet <<endl;
				counterOfGames++;
			}else{
				// I must read three games  and save it . Then next round and so on.
				cout << "Agregando round " << endl;
				tournament.push_back(round);
				round.clear();
				counterOfGames = 0;
				puzzleInput.seekg(lastPosition);
			}
		}
	}else{
			cout << "Can't open the file provided.";
	}
	return tournament;
}
void showPuzzleInput(vector<vector<Game>> tournament){
	for(unsigned int i = 0;i < tournament.size();i++){
		for(unsigned int j = 0;j < tournament[i].size();j++){
			//cout
		}
	}
}
void showRound(vector<Game> round){
	for(unsigned int i = 0;i < round.size();i++){
		cout << round[i].opponentBet << " " << round[i].youBet << endl;
	}
}
