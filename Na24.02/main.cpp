/*
 *  Author: Sebastian Paszkowski (B1ackBeltDev)
 *  created: 23.02.2025 21:07
**/

#include <bits/stdc++.h>
#define st first 
#define nd second
using namespace std;

const int N = 7;
const int M = 9;

vector<string> grid = {".........",
                       ".........",
                       "...XXX..X",
                       "...XXX..X",
                       "........X",
                       ".........",
                       "........."};

vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void print_grid(int epoch_id){
    cerr << "[DEBUG] Current grid on epoch: " << epoch_id << endl;
    for(string row : grid) cerr << row << endl;
}

int count_cells(int x, int y){
    int ans = 0;
    for(pair<int, int> dir : dirs){
        int nx = x + dir.st;
        int ny = y + dir.nd;

        if(nx == -1) nx = M-1;
        else if (nx == M) nx = 0;

        if(ny == -1) ny = N-1;
        else if(ny == N) ny = 0;
        
        if(grid[ny][nx] == 'X') ans++;
    }
    return ans;
}

void next_epoch(bool debug, int epoch_id){
    vector<string> new_grid(N, string(M, '.'));

    for(int x = 0; x < M; x++){
        for(int y = 0; y < N; y++){
            int cells = count_cells(x, y);
            if(grid[y][x] == 'X'){
                if(cells == 2 || cells == 3){
                    new_grid[y][x] = 'X';
                }
            }else{
                if(cells == 3){
                    new_grid[y][x] = 'X';
                }
            }
        }
    }

    grid = new_grid;

    if(debug) print_grid(epoch_id);
}

int liczba_sasiadow(int x, int y, int epoch, bool debug = false){
    for(int i = 1; i < epoch; i++) next_epoch(debug, i+1);
    return count_cells(x, y);
}

int main(){
    cout << liczba_sasiadow(4, 2, 3) << endl;

    return 0;
}