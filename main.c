#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int is_alive;
    int live_neighbors;
} Cell;

Cell grid[WIDTH][HEIGHT];

char alive_character = '#';
char dead_character = ' ';

void initialize_grid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j].is_alive = 0;
        }
    }

    grid[5][5].is_alive = 1;
}

int count_live_neighbors(int x, int y) {
    int live_count = 0;

    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (grid[nx][ny].is_alive) {
            live_count++;
        }
    }

    return live_count;
}

void update_grid() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
        }
    }

    // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
    // Any live cell with two or three live neighbors lives on to the next generation.
    // Any live cell with more than three live neighbors dies, as if by overpopulation.
    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
}

void display_grid() {
    printf("\033[2J"); // Clear the screen
    printf("\033[H");  // Move cursor to top-left corner
    

}

int main() {

}
