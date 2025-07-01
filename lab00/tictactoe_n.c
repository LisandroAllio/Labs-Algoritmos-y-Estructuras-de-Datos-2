#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define TAM 3
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

bool diagonal_match1 (char board[TAM][TAM]){
    bool res = true;
    for (int diag = 0; diag < TAM -1; diag++) {
        res = res && board[diag][diag] == board[diag+1][diag+1];
    } 
    return res;
}
 
bool diagonal_match2 (char board[TAM][TAM]){
    bool res = true;
    for (int diag = 0; diag < TAM -1; diag++) {
        res = res && board[diag][TAM-1 - diag] == board[diag+1][TAM-2 -diag];
    } 
    return res;
}

bool row_match (char board[TAM][TAM], int row){
    bool res = true;
    for (int i = 0; i < TAM -1; i++){
        res = res && board[row][i] == board[row][i+1]; 
    }
    return res;
}

bool col_match (char board[TAM][TAM], int col){
    bool res = true;
    for (int i = 0; i < TAM -1; i++){
        res = res && board[i][col] == board[i+1][col]; 
    }
    return res;
}

char get_winner(char board[TAM][TAM]) {
    char winner = '-';

    //Tomo las diagonales
    winner = diagonal_match1(board) ? board[1][1] : winner; // if (condicional) -> board[1][1]  else -> winner
    winner = winner == '-' && diagonal_match2(board) ? board[0][TAM-1] : winner;

    //Tomo las filas
    for (int row = 0; row < TAM -1; row++) {
        winner = winner == '-' && row_match(board, row) ? board[row][0] : winner;
    }  
    //Tomo las columnas
    for (int col = 0; col < TAM -1; col++) {
        winner = winner == '-' && col_match(board, col) ? board[0][col] : winner;
    }      
    return winner;
}

bool has_free_cell(char board[TAM][TAM]){
    bool free_cell=false;
    for (int row = 0; row < TAM; row++) {
        for (int column = 0; column < TAM; column++) {
            free_cell = free_cell || board[row][column] == '-';
            
            /*  Es lo mismo que:
            if (board[row][column] == '-'){
                free_cell = true;
                } */ 
        }
    }
    return free_cell;
}
int main(void){
    printf("TicTacToe:'(]\n");

    char board[TAM][TAM]; 
    for (int  i=0; i<TAM; i ++){
        for (int j=0; j<TAM; j++){
            board[i][j] = '-';
        }
    }

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
