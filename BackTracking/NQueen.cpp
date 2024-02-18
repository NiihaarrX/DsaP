#include <iostream>
#include <vector>

using namespace std;

bool place_queen(vector<vector<int>> &board,int row,int col) {
    int n = board.size();
    //Same Column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    //Left Diagonal 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    //Right Diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) if(board[i][j] == 1) return false;
    return true;
}

bool Queen(vector<vector<int>> &board,int k) {
    int n = board.size();
    if(k == n) return true;
    for(int i = 0; i < n;i++) {
        if(place_queen(board,k,i)) {
            board[k][i] = 1;
            if(Queen(board,k+1)) return true;
            else board[k][i] = 0;
        }
    }
    return false;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> board(n,vector<int>(n,0));
  bool ans = Queen(board,0);
  if(ans) {
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < n;j++) {
            cout << board[i][j] << " ";
        }cout << endl;
    }
  }
  else cout << "Solution Does Not Exist" << endl;
}
