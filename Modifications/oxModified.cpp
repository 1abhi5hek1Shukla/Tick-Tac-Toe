#include<iostream>
using namespace std;
#define humanPlayer 0
#define computerPlayer 1
#define NEG_INFINITY -10000
class board
{
private:
	char grid[9];
	int current_player = 1;
	int other_player = 2;
	bool next_moves[9];
	int winner = 0;
	bool player1_occupied[9];
	bool player2_occupied[9];
public:
	board(){
		for(int i = 0; i<9; i++){
			grid[i] = 0;
			next_moves[i] = true;
			player1_occupied[i] = false; 
			player2_occupied[i] = false; 
		}

	};
	void displayBoard(){
		cout<<"  ";
		for (int i = 1; i < 4; i++)
			cout<<i<<" ";

		cout<<endl;
		for (int i = 0; i < 3; i++){
			cout<<i+1<<" ";
			for(int j = 0 ;j < 3;j++){
				switch (grid[3*i + j]){
					case 0: cout<<' ';break; 
					case 1: cout<<'O';break; 
					case 2: cout<<'X';break;
					default:break; 
				}
				cout<<" ";
				// cout<<<<" ";
			}
			cout<<endl;
		}
	}
	int get_current_player_id(){
		return current_player;
	}
	int get_other_player_id(){
		return other_player;
	}
	int get_next_move(){
		for(int i=0;i<9;i++){
			if(next_moves[i] == true){
				return (i+1);
			}	
		}
		return -1;
	}
	void makeMove(int n){
		grid[n-1] = current_player;
		next_moves[n-1] = false;
		swap(current_player,other_player);
	}
	bool check_3_in_a_row(){

		if(grid[0] != 0 && (((grid[0] == grid[1]) && (grid[1] == grid[2] ))|| ((grid[0] == grid[3]) && (grid[3] == grid[6])) || ((grid[0] == grid[4]) && (grid[4] == grid[8])))) {
			winner = grid[0];
			return true;	
		}
		else if(grid[4] != 0 && ((( grid[4] == grid[1]) && (grid[4] == grid[7])) || ((grid[4] == grid[3]) && (grid[4] == grid[5] ) ) || ((grid[4] == grid[2]) && (grid[4] == grid[6])))) {
			winner = grid[4];
			return true;	
		}
		else if(grid[8] != 0 && ((grid[8] == grid[7] && grid[8] == grid[6] )|| (grid[8] == grid[5] && grid[8] == grid[2]))){
			winner = grid[8];	
			return true;	
		}
		return false;
	}
	bool is_draw(){
		for(int i= 0;i<9;i++){
			// if any cell empty return false
			if(grid[i] == 0){
				return false;
			}
		}
		// else game drawn
		return true;
	}
	bool is_game_over(){
		// check if any three in a row is not present then watch if game drawn
		if(!check_3_in_a_row() ){
			if(is_draw()){
				return true;
			}
			else{
				return false;
			}
		}
		return true;
	}
	void prompt_next_move(int nextMove){
		
		if(next_moves[nextMove-1] == true){
			makeMove(nextMove);
		}
		else{
			cout<<"\n INVALID MOVE !!\n";
		}
	}
	int get_winner(){
		return winner;
	}
	bool get_grid_value(int index){
		return grid[index];
	}
	board checkNextMove(board testBoard,int i){

		testBoard.makeMove(i);
		// testBoard.displayBoard();
		// while(true);
		return testBoard;
	}
	bool* get_all_next_moves(){
		bool* i = next_moves;
		return i;
	}
};

int boardEvaluation(board boardEvaluate);
int thinker(board boardToEvaluate);
void run_game(int player1,int player2);
int main(int argc, char const *argv[])
{
	int p1,p2;
	cout<<"SET player 1:\n";
	cout<<"press 0 --- for humanPlayer \n";
	cout<<"press 1 --- for computerPlayer \n";
	cin>>p1;
	cout<<"SET player 2:\n";
	cout<<"press 0 --- for humanPlayer \n";
	cout<<"press 1 --- for computerPlayer \n";
	cin>>p2;

	// run_game(computerPlayer,computerPlayer);
	// run_game(computerPlayer,humanPlayer);
	// run_game(humanPlayer,computerPlayer);
	// run_game(computerPlayer,computerPlayer);
	run_game(p1,p2);
	return 0;
}
void run_game(int player1,int player2){
	board newBoard;
	if (player1 == humanPlayer && player2 == humanPlayer){
		int nextMove;
		while(!newBoard.is_game_over()){
			newBoard.displayBoard();
			cout<<"HUMAN Player "<<newBoard.get_current_player_id()<<" to move ::::===>>> ";
			cin>>nextMove;
			newBoard.prompt_next_move(nextMove);
		}
		newBoard.displayBoard();
		if (newBoard.get_winner() != 0){
			cout<<"Player "<<newBoard.get_winner()<<" Won!!\n";
		}else{
			cout<<"Its a draw\n";
		}
	}
	else if(player1 == humanPlayer && player2 == computerPlayer){
		int nextMove;
		while(!newBoard.is_game_over()){
			newBoard.displayBoard();
			if(newBoard.get_current_player_id() == 1){
				cout<<"HUMAN Player "<<" to move ::::===>>> ";
				cin>>nextMove;
				newBoard.prompt_next_move(nextMove);
			}else if(newBoard.get_current_player_id() == 2){
				cout<<"COMPUTER Player "<<" to move ::::===>>> \n";
				newBoard.prompt_next_move(thinker(newBoard));
			}
		}
		newBoard.displayBoard();
		if(newBoard.get_winner() == 1){
			cout<<"HUMAN Player "<<" won \n";
		}else if(newBoard.get_winner() == 2){
			cout<<"COMPUTER Player "<<" WON \n";
		}else{
			cout<<"Its a draw\n";
		}
	}
	else if(player1 == computerPlayer && player2 == humanPlayer){
		int nextMove;
		while(!newBoard.is_game_over()){
			newBoard.displayBoard();
			if(newBoard.get_current_player_id() == 2){
				cout<<"HUMAN Player "<<" to move ::::===>>> ";
				cin>>nextMove;
				newBoard.prompt_next_move(nextMove);
			}else if(newBoard.get_current_player_id() == 1){
				cout<<"COMPUTER Player "<<" to move ::::===>>> \n";
				newBoard.prompt_next_move(thinker(newBoard));
			}
		}
		newBoard.displayBoard();
		if(newBoard.get_winner() == 2){
			cout<<"HUMAN Player "<<" won \n";
		}else if(newBoard.get_winner() == 1){
			cout<<"COMPUTER Player "<<" WON \n";
		}else{
			cout<<"Its a draw\n";
		}
	}
	else if(player1 == computerPlayer && player2 == computerPlayer){
		while(!newBoard.is_game_over()){
			newBoard.displayBoard();
			cout<<"COMPUTER Player "<<newBoard.get_current_player_id()<<" to move ::::===>>> \n";
			newBoard.prompt_next_move(thinker(newBoard));
		}
		newBoard.displayBoard();
		if(newBoard.get_winner() != 0){
			cout<<"COMPUTER Player "<<newBoard.get_other_player_id()<<" WON \n";
		}
		else{
			cout<<"Its a draw\n";
		}
	}
}
int thinkHelper(board boardToEvaluate){
	if(boardToEvaluate.is_draw() || boardToEvaluate.check_3_in_a_row()){
		return boardEvaluation(boardToEvaluate);
	}
	int best_value = NEG_INFINITY;
	int value = 0;
	for(int i =0 ; i<9;i++){
		if((boardToEvaluate.get_all_next_moves())[i] == true){
			value = -1 * thinkHelper(boardToEvaluate.checkNextMove(boardToEvaluate,i+1));
			if (best_value == NEG_INFINITY || value > best_value){
				best_value = value;
			}
		}
	}
	return best_value;
}
int thinker(board boardToEvaluate){
	// return boardToEvaluate.get_next_move();
	
	int best_value = NEG_INFINITY;
	int value = 0;
	int move = -1;
	for(int i =0 ; i<9;i++){
		if((boardToEvaluate.get_all_next_moves())[i] == true){
			// boardToEvaluate.displayBoard();
			value = -1 * thinkHelper(boardToEvaluate.checkNextMove(boardToEvaluate,i+1));
			if (best_value == NEG_INFINITY || value > best_value){
				best_value = value;
				move = i+1;  
			}
		}
	}
	// cout<<move;
	return move;
}
int boardEvaluation(board boardEvaluate){
	if(boardEvaluate.check_3_in_a_row()){
		return -1000;
	}
	int score = 0;
	for(int i = 0;i<9;i++){
		if(boardEvaluate.get_grid_value(i) == boardEvaluate.get_current_player_id() && i%2 == 0){
			 score += 100;
		}else if(boardEvaluate.get_grid_value(i) == boardEvaluate.get_other_player_id() && i%2 == 0){
			score -= 100;
		}
	}
	return score;
}