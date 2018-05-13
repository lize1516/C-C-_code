#ifndef _GAME_H__
#define _GAME_H__
#define ROWS 5
#define COLS 5

void init_arr(char arr[ROWS][COLS], int rows, int cols);
void display_arr(char arr[ROWS][COLS], int rows, int cols);
void player_move(char arr[ROWS][COLS], int rows, int cols);
char check_win(char arr[ROWS][COLS], int rows, int cols);
void computer_move(char arr[ROWS][COLS], int rows, int cols);
int is_full(char arr[ROWS][COLS], int rows, int cols);

#endif //GAME_H__