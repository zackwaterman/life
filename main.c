#include <stdio.h>

struct Cell {
    int is_alive;
    int live_neighbors;
};

struct Cell grid[10][10];

int number_of_cells = sizeof(grid) / sizeof(grid[0]);

void update_grid() {
    for (int i = 0; i < number_of_cells; i++) {
        
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
