#include <iostream>
#include <cstring>

using namespace std;
const int maxrow = 6, maxcol = 6; // grid dimensions
class Life {
public:
void initialize(); //初始化配置，初始化一个二维数组
void print(); //输出当前配置(数组状态)
void update(); //一次迭代
private:
int grid[maxrow + 2][maxcol + 2];
int neighbor_count(int row, int col);
};

void Life::initialize() {
    memset(grid, 0, sizeof(grid));
    int row, col;
    while(true) {
        std::cin >> row >> col;
        if(row == -1 && col == -1)
            break;
        grid[row][col] = 1;
    }
}

void Life::update() {
    int tmp[maxrow + 2][maxcol + 2];
    memset(tmp, 0, sizeof(tmp));
    for(int i = 1; i <= maxrow; i++) {
        for(int j = 1; j <= maxcol; j++) {
            int cnt = neighbor_count(i,j);
            if(grid[i][j] == 1) {
                if(cnt == 2 || cnt == 3) {
                    tmp[i][j] = 1;
                } else {
                    tmp[i][j] = 0;
                }
            } else {
                if(cnt == 3) {
                    tmp[i][j] = 1;
                } else {
                    tmp[i][j] = 0;
                }
            }
        }
    }
    for( int i = 1; i <= maxrow; i++) {
        for(int j = 1; j <= maxcol; j++) {
            grid[i][j] = tmp[i][j];
        }
    }
}

int Life::neighbor_count(int row, int col) {
    int cnt = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            cnt += grid[i][j];
        }
    }
    cnt -= grid[row][col];
    return cnt;
}

void Life::print() {
    for(int i = 1; i <= maxrow; i++) {
        for(int j = 1; j <maxcol; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << grid[i][maxcol] << std::endl;
    }
}

int main() {
    int k;
    std::cin >> k;
    Life game;
    game.initialize();

    for(int i = 0; i < k; i++) {
        game.update();
    }

    game.print();

    return 0;
}