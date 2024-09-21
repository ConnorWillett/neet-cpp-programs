#include <iostream>
using namespace std;

int main()
{
  const int ROWS = 3;
  const int COLUMNS = 3;
  char board[ROWS][COLUMNS]={{' ',' ',' '},
														 {' ',' ',' '},
														 {' ',' ',' '}};
  bool win = 0;
  int inputRow = 0;
  int inputCOLUMN = 0;
  int player = 1;

  cout << "welcome to TTT" << endl;

  cout << " 1 2 3" << endl;
  for (int i = 0; i < ROWS; ++i)
  {
    cout << i + 1;
    for (int j = 0; j < COLUMNS; ++j)
    {
      cout << board[i][j];
      cout << " ";
    }
    cout << endl;
  }
  while (win == 0)
  {
    if(player == 1)
    {
      cout << "player 1 input ROW:";
      cin >> inputRow;
      cout << "player 1 input COLUMN:";
      cin >> inputCOLUMN;
      board[inputRow-1][inputCOLUMN-1] = 'X';
      player++;

      if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

      else if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
      {
        cout << endl;
        cout << "player 1 wins" << endl;
        win = true;
      }

    }

    else if(player == 2)
    {
      cout << "player 2 input ROW:";
      cin >> inputRow;
      cout << "player 2 input COLUMN:";
      cin >> inputCOLUMN;
      board[inputRow-1][inputCOLUMN-1] = 'O';
      player--;

      if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

      else if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
      {
        cout << endl;
        cout << "player 2 wins" << endl;
        win = true;
      }

    }
    cout << " 1 2 3" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
      cout << i + 1;
      for (int j = 0; j < COLUMNS; ++j)
      {
        cout << board[i][j];
        cout << " ";
      }
      cout << endl;
    }

  }

   
    return 0;
}
