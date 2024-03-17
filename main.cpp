#include <iostream>

using namespace std;

// functions

void printBoard(string board[3][3]);

void playTurn(string board[3][3], string player);

bool validateInput(string board[3][3], int rowSelection, int colSelection);

string checkForWin(string board[3][3]);

bool checkForDraw(string board[3][3]);

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
    int times = 0;
    while (running)
    {

        printBoard(board);

        if (turn == 0)
        {
            playTurn(board, PLAYER_1);
            times++;
            turn = 1;
        }
        else
        {
            times++;
            playTurn(board, PLAYER_2);
            turn = 0;
        }

        if (checkForWin(board) == "X" || checkForWin(board) == "O")
        {
            printBoard(board);
            cout << "Player " << checkForWin(board) << " won the game!" << endl;
            break;
        }

        if (times == 9 && checkForDraw(board) == true)
        {
            cout << "Cat won!" << endl;
            break;
        }
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
    // CHECKING FOR WIN IN EACH ROW
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == " " + PLAYER_1 + " " && board[i][1] == " " + PLAYER_1 + " " && board[i][2] == " " + PLAYER_1 + " ")
        {
            return PLAYER_1;
        }
        else if (board[i][0] == " " + PLAYER_2 + " " && board[i][1] == " " + PLAYER_2 + " " && board[i][2] == " " + PLAYER_2 + " ")
        {
            return PLAYER_2;
        }
    }

    // CHECKING FOR WIN IN EACH COLUMN
    for (int j = 0; j < COLS; j++)
    {
        if (board[0][j] == " " + PLAYER_1 + " " && board[1][j] == " " + PLAYER_1 + " " && board[2][j] == " " + PLAYER_1 + " ")
        {
            return PLAYER_1;
        }
        else if (board[0][j] == " " + PLAYER_2 + " " && board[1][j] == " " + PLAYER_2 + " " && board[2][j] == " " + PLAYER_2 + " ")
        {
            return PLAYER_2;
        }
    }

    if (board[0][0] == " " + PLAYER_1 + " " && board[1][1] == " " + PLAYER_1 + " " && board[2][2] == " " + PLAYER_1 + " " ||
        board[0][2] == " " + PLAYER_1 + " " && board[1][1] == " " + PLAYER_1 + " " && board[2][0] == " " + PLAYER_1 + " ")
    {
        return PLAYER_1;
    }
    else if (board[0][0] == " " + PLAYER_2 + " " && board[1][1] == " " + PLAYER_2 + " " && board[2][2] == " " + PLAYER_2 + " " ||
             board[0][2] == " " + PLAYER_2 + " " && board[1][1] == " " + PLAYER_2 + " " && board[2][0] == " " + PLAYER_2 + " ")
    {
        return PLAYER_2;
    }
    return "_";
}

bool checkForDraw(string board[3][3])
{

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == " " + PLAYER_1 + " " || board[i][j] == " " + PLAYER_2 + " ")
            {
            }
            else
            {
                return false;
                break;
            }
            return true;
        }
    }
}