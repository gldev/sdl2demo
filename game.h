#ifndef GAME_H_
#define GAME_H_

// tODO: move to enums

#define BOARD_SIZE 3
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CELL_WIDTH (SCREEN_WIDTH / BOARD_SIZE)
#define CELL_HEIGHT (SCREEN_HEIGHT / BOARD_SIZE)
#define EMPTY_BOARD 0
#define PLAYER_ONE_BOARD 1
#define PLAYER_TWO_BOARD 2

#define RUNNING 0
#define EXIT 1
#define TIE 2
#define QUIT 3

#define PLAYER_ONE_WINS 4
#define PLAYER_TWO_WINS 5

typedef struct {
    int board[BOARD_SIZE * BOARD_SIZE];
    int player;
    int state;
} game_t;



#endif