/*
 * Author : RaulSosa
 * https://linkedin.com/in/raulrsosa
 *
 *
 */
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
	string winnerIfStrategy;
	int scoreIfStrategy;

};

vector<Game> getPuzzleInput(string pathToFile);
int getYouTotalScore(vector<Game> round);
void setWinnerAndScoreOfGame(Game &game);
int getYouTotalScoreIfStrategy(vector<Game> tournament);

int main(){
	cout << getYouTotalScore(getPuzzleInput("src/input2"));
	cout << endl << getYouTotalScoreIfStrategy(getPuzzleInput("src/input2"));
	return 0;
}

void setWinnerAndScoreOfGame(Game &game){
	switch(game.opponentBet){

	case 'A':
		if(game.youBet == 'Y'){
			game.winner = "you";
			game.score = 2 + 6 ;
			game.winnerIfStrategy = "draw";
			game.scoreIfStrategy = 3 + 1;
		}else if(game.youBet == 'Z'){
			game.winner = "opponent";
			game.score = 3;
			game.winnerIfStrategy = "you";
			game.scoreIfStrategy = 6 + 2;
		}else{
			game.winner = "draw";
			game.score = 3 + 1;
			game.winnerIfStrategy = "opponent";
			game.scoreIfStrategy = 0 + 3;
		}
		break;

	case 'B':
		if(game.youBet == 'X'){
			game.winner = "opponent";
			game.score = 1;
			game.winnerIfStrategy = "opponent";
			game.scoreIfStrategy = 0 + 1;
		}else if(game.youBet == 'Z'){
			game.winner = "you";
			game.score = 6 + 3;
			game.winnerIfStrategy = "you";
			game.scoreIfStrategy = 6 + 3;
		}else{
			game.winner = "draw";
			game.score = 3 + 2;
			game.winnerIfStrategy = "draw";
			game.scoreIfStrategy = 3 + 2;
		}
		break;

	case 'C':
		if(game.youBet == 'X'){
			game.winner = "you";
			game.score = 1 + 6;
			game.winnerIfStrategy = "opponent";
			game.scoreIfStrategy = 0 + 2;
		}else if(game.youBet == 'Y'){
			game.winner = "opponent";
			game.score = 2;
			game.winnerIfStrategy = "draw";
			game.scoreIfStrategy = 3 + 3;
		}else{
			game.winner = "draw";
			game.score = 3 + 3;
			game.winnerIfStrategy = "you";
			game.scoreIfStrategy = 6 + 1;
		}
		break;
	}
}
vector<Game> getPuzzleInput(string pathToFile){
	ifstream puzzleInput(pathToFile);
	vector<Game> tournament;
	string line;

	if(puzzleInput.is_open()){
		while(!puzzleInput.eof()){
			getline(puzzleInput,line);
			Game newGame;
			newGame.opponentBet = line[0];
			newGame.youBet = line[2];
			setWinnerAndScoreOfGame(newGame);
			tournament.push_back(newGame);
		}

	}else{
			cout << "Can't open the file provided.";
	}
	return tournament;
}
int getYouTotalScore(vector<Game> tournament){
	int totalScoreInTournament = 0;
	for(unsigned int i = 0;i < tournament.size();i++){
		totalScoreInTournament += tournament[i].score;
	}
	return totalScoreInTournament;
}
int getYouTotalScoreIfStrategy(vector<Game> tournament){
	int totalScoreIfStrategyInTournament = 0;
	for(unsigned int i = 0;i < tournament.size();i++){
		totalScoreIfStrategyInTournament += tournament[i].scoreIfStrategy;
	}
	return totalScoreIfStrategyInTournament;
}
