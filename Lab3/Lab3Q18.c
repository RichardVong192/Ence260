#include <stdio.h>

int isWonRow(char player, char game[3][3], int rowNum);

int main()
{
    //char game[3][3] = {{'X', 'O', ' '},{'X', 'X', 'X'}, {' ', ' ', ' '}};
    //printf("%d\n", isWonRow('X', game, 1));

    char game[3][3] = {{'X', 'O', ' '},{' ', ' ', ' '}, {'X', 'X', 'O'}};
    printf("%d\n", isWonRow('X', game, 2));

}

int isWonRow(char player, char game[3][3], int rowNum)
{
    if (game[rowNum][0] == player && game[rowNum][1] == player && game[rowNum][2] == player) {
        return 1;
    } else {
        return 0;
    }
}
