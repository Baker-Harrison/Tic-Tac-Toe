#include <iostream>

using namespace std;

// functions

void printBoard(string board[3][3]);

void playTurn(string board[3][3], string player);

// constants

const int ROWS = 3;
const int COLS = 3;





const string PLAYER_1 = "X";
const string PLAYER_2 = "O";



int main()
{
    string board[ROWS][COLS] = {
    {" * ", " * ", " * "},
    {" * ", " * ", " * "},
    {" * ", " * ", " * "},
};
    bool running = true;
    
    int turn = 0;
    
    while (running)
    {
    printBoard(board);



    if (turn == 0)
    {
        playTurn(board, PLAYER_1);
        turn = 1;
    }
    else
    {
        playTurn(board, PLAYER_2);
        turn = 0;
    }





    }


}


void printBoard(string board[3][3])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void playTurn(string board[3][3], string player)
{
    
    int rowSelection;
    int colSelection;
    if (rowSelection < 4 && rowSelection > 0 && colSelection < 4 && colSelection > 0)
    {
    cout << "Player " <<  player << " turn" << endl;
    cout << "Enter a row(1-3): ";
    cin >> rowSelection;
    cout << "Enter a col(1-3): ";
    cin >> colSelection;

    

    board[rowSelection - 1][colSelection - 1] = " " + player + " ";
    }
    else
    {
        playTurn(board, player);
    }
}