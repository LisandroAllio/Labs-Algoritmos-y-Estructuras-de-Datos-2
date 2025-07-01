#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define TAM 4
#define CELL_MAX (TAM * TAM - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[TAM][TAM])
{
    int cell = 0;

    print_sep(TAM);
    for (int row = 0; row < TAM; ++row) {
        for (int column = 0; column < TAM; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(TAM);
    }
}

char get_winner(char board[TAM][TAM])
{
    char winner = '-';
    int aux = 0;;
    
    /*Tomo las filas*/
    for (int row = 0; row < TAM; ++row ){
        for (int column = 1; column < TAM; ++column)
            if (board[row][0] == board [row][column]){
            ++aux;
            }
            else {
                aux = 0;
            }

        if (aux == TAM-1){
        winner = board[row][0];
        }
        
    }
    aux = 0;
    
        /*if (board[row][0] == board [row][1] && board[row][0] == board[row][2]){
            winner = board[row][0];
        }
        */

    /*Tomo las columnas*/
    for (int column = 0; column < TAM; ++column ){
        for (int row = 1; row < TAM; ++row)
            if (board[0][column] == board [row][column]){
            ++aux;
            }
            else {
                aux = 0;
            }

        if (aux == TAM-1){
        winner = board[0][column];
        }

    }
    aux = 0;
        
        /*if (board[0][column] == board [1][column] && board[0][column] == board[2][column]){
            winner = board[0][column];
        } 
        */
    /*Tomo las diagonales*/
    for (int i = 1; i < TAM; ++i ){
            if (board[0][0] == board[i][i]) {
                ++aux;
            }
            else {
                aux = 0;
            }

            if (aux == TAM-1){
            winner = board[0][0];
            }
               
    }
    aux = 0;

    for (int i = 1; i < TAM; ++i ){
            if (board[TAM-1][0] == board[(TAM-1)-i][0+i]) {
                ++aux;
            }
            else {
                aux = 0;
            }

            if (aux == TAM-1){
            winner = board[TAM-1][0];
            }
               
    }

    /*
    if (board[0][0] == board [1][1] && board[0][0] == board [2][2] ){
         winner = board[0][0];
    }
    if (board[2][0] == board [1][1]  && board[2][0] == board [0][2] ){
         winner = board[2][0];
    }
    */

    
    return winner;
}

bool has_free_cell(char board[TAM][TAM]){
    bool free_cell=false;
    for (int row = 0; row < TAM; ++row) {
        for (int column = 0; column < TAM; ++column) {
            if (board[row][column] == '-'){
                free_cell = true;
                }
        }
    }
    return free_cell;
}
int main(void){
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[TAM][TAM] = {
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' },
        { '-', '-', '-', '-' }
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
            int row = cell / TAM;
            int colum = cell % TAM;
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
