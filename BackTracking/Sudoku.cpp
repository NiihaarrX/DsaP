#include <bits/stdc++.h>

using namespace std;

bool place(vector<vector<int>> &grid,int i,int j,int k) {
    for(int x = 0;x < 9;x++) {
        if(grid[i][x] == k || grid[x][j] == k) return false;
    }
    int row = i - i % 3;
    int column = j - j % 3;
    for(int i = 0;i < 3;i++) {
        for(int j = 0; j < 3;j++) {
            if(grid[row + i][column + j] == k) return false;
        }
    }
    return true;
}

bool SolveSudoku(vector<vector<int>> &grid) {
    for(int i = 0; i < 9;i++) {
        for(int j = 0; j < 9;j++) {
            if(!grid[i][j]) {
                for(int k = 1;k <= 9;k++) {
                    if(place(grid,i,j,k)) {
                        grid[i][j] = k; 
                        if(SolveSudoku(grid)) return true;
                        else grid[i][j] = 0;
                    }
                }
                return false;
            }
        }    
    }
    return true;
}

int main() {
    int N = 9;
    vector<vector<int>> sudokuGrid = {
    {0, 0, 0, 2, 6, 0, 7, 0, 1},
    {6, 8, 0, 0, 7, 0, 0, 9, 0},
    {1, 9, 0, 0, 0, 4, 5, 0, 0},
    {8, 2, 0, 1, 0, 0, 0, 4, 0},
    {0, 0, 4, 6, 0, 2, 9, 0, 0},
    {0, 5, 0, 0, 0, 3, 0, 2, 8},
    {0, 0, 9, 3, 0, 0, 0, 7, 4},
    {0, 4, 0, 0, 5, 0, 0, 3, 6},
    {7, 0, 3, 0, 1, 8, 0, 0, 0}
};
    bool ans = SolveSudoku(sudokuGrid);
    for(int i = 0; i < 9;i++) {
        for(int j = 0; j < 9;j++) {
            cout << sudokuGrid[i][j] << " ";
        }cout << endl;
    }
}
