#include <iostream>
using namespace std;

/*TIC-TAC-TOE-GAME*/

void printBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                cout << '-' << " ";
            }
            else
            {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        // check for rows
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        // check for columns
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }
    // check for diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char player = 'x';
    while (true)
    {
        cout << "turn of player " << player << endl;

    input:
        cout << "enter row and column where to place " << player << endl;
        cin >> row >> col;

        if (board[row][col] != ' ' || row > 2 || row < 0 || col > 2 || col < 0)
        {
            cout << "invalid location, enter row and column again " << endl;
            goto input;
        }

        board[row][col] = player;
        printBoard(board);

        bool won = checkWin(board, player);
        if (won == true)
        {
            cout << "player " << player << " has won " << endl;
            break;
        }

        bool draw = checkDraw(board);
        if (draw == true)
        {
            cout << "game is drawn " << endl;
            break;
        }
        player = (player == 'x') ? 'o' : 'x';
    }
    return 0;
}