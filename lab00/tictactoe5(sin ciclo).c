#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */
#define CELL_MAX (5* 5 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[5][5])
{
    int cell = 0;

    print_sep(5);
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 5; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(5);
    }
}

char get_winner(char board[5][5])
{
    char winner = '-';
    
    /*Tomo las filas*/
    for (int row = 0; row < 5; ++row ){
        if (board[row][0] == board [row][1] && board[row][0] == board[row][2] && board[row][0] == board[row][3] && board[row][0] == board[row][4]){
            winner = board[row][0];
        }
    }
    /*Tomo las columnas*/
    for (int column = 0; column < 5; ++column ){
        if (board[0][column] == board [1][column] && board[0][column] == board[2][column] && board[0][column] == board[3][column] && board[0][column] == board[4][column]){
            winner = board[0][column];
        } 
    }
    /*Tomo las diagonales*/
    if (board[0][0] == board [1][1] && board[0][0] == board [2][2] && board[0][0] == board [3][3] && board[0][0] == board [4][4] ){
         winner = board[0][0];
    }
    if (board[4][0] == board [3][1] && board[4][0] == board [2][2] && board[4][0] == board [1][3] && board[4][0] == board [0][4] ){
         winner = board[4][0];
    }
    
    return winner;
}

bool has_free_cell(char board[5][5]){
    bool free_cell=false;
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 5; ++column) {
            if (board[row][column] == '-'){
                free_cell = true;
                }
        }
    }
    return free_cell;
}
int main(void){
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[5][5] = {
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' },
        { '-', '-', '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 5;
            int colum = cell % 5;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
