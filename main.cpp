#include <iostream>

using namespace std;

// functions

void printBoard(string board[3][3]);

void playTurn(string board[3][3], string player);

bool validateInput(string board[3][3], int rowSelection, int colSelection);

string checkForWin(string board[3][3]);

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

        cout << checkForWin(board) << endl;
    }
}

bool validateInput(string board[3][3], int rowSelection, int colSelection)
{
    if (board[rowSelection - 1][colSelection - 1] != " X " && board[rowSelection - 1][colSelection - 1] != " O ")
    {
        return true;
    }
    else
    {
        return false;
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

    cout << "Player " << player << " turn" << endl;
    cout << "Enter a row(1-3): ";
    cin >> rowSelection;
    cout << "Enter a col(1-3): ";
    cin >> colSelection;

    if (rowSelection < 4 && rowSelection > 0 && colSelection < 4 && colSelection > 0 && validateInput(board, rowSelection, colSelection) == true)
    {
        // cout << board[rowSelection - 1][colSelection - 1];
        board[rowSelection - 1][colSelection - 1] = " " + player + " ";
    }
    else
    {
        cout << "Invalid Input. Try again" << endl;
        playTurn(board, player);
    }
}

string checkForWin(string board[3][3])
{

    return "";
}