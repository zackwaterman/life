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
            grid[i][j].live_neighbors = 0;
        }
    }
}

void count_live_neighbors(int x, int y) {
    int live_count = 0;

    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
            if (grid[nx][ny].is_alive) {
                live_count++;
            }
        }
    }

    grid[x][y].live_neighbors = live_count;
}

void update_grid() {
    Cell temp_grid[WIDTH][HEIGHT];

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            count_live_neighbors(i, j);

            if (grid[i][j].is_alive) {
                if (grid[i][j].live_neighbors < 2 || grid[i][j].live_neighbors > 3) {
                    temp_grid[i][j].is_alive = 0;
                } else {
                    temp_grid[i][j].is_alive = 1;
                }
            } else {
                if (grid[i][j].live_neighbors == 3) {
                    temp_grid[i][j].is_alive = 1;
                } else {
                    temp_grid[i][j].is_alive = 0;
                }
            }
        }
    }

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }
}

void display_grid() {
    printf("\033[2J"); // Clear the screen
    printf("\033[H");  // Move cursor to top-left corner
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[x][y].is_alive) {
                printf("%c", alive_character);
            } else {
                printf("%c", dead_character);
            }
        }

        printf("\n");
    }
}

int main() {
    initialize_grid();

    while (1) {
        display_grid();

        update_grid();

        getchar();
    }
}
