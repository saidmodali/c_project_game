#ifndef MDLI
#define	MDLI



void sleep_ms(int milliseconds);


void starting_animation(void);


void winner_animation(int winner);


void initialize_Game_Board(char ptr[][3]);


void show_Game_Board(char ptr[][3]);


int update_Game_Board(char ptr[][3], int row, int column, char val);


int check_for_Win(char ptr[][3]);


void start_Game(char ptr[][3], int player1, int player2);





#endif