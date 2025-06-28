#include <stdio.h>

#define SIZE 3

char display[SIZE][SIZE];
char currentPlayer = 'O';

//①初期画面
void FirstDisplay(){
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            display[row][col] = ' ';
        }
        printf("\n");
    }
}

//②ゲーム画面
void PrintBoard(){
    printf("\n");
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            printf(" %c ", display[row][col]);
            if(col < SIZE - 1){
                printf("|");
            }
        }

        printf("\n");
        if(row < SIZE - 1){
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

//③配置可能か判定
int MakeMove(int row, int col){
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && display[row][col] == ' '){
        display[row][col] = currentPlayer;
        return 1;
    }
    
    return 0;
}

//④勝敗
int CheckWin(){
    //行と列
    for(int i = 0; i < SIZE; i++){
        if(display[i][0] == currentPlayer &&
           display[i][1] == currentPlayer &&
           display[i][2] == currentPlayer){
            return 1;    
        }
        if(display[0][i] == currentPlayer &&
           display[1][i] == currentPlayer &&
           display[2][i] == currentPlayer){
            return 1;    
        }
    }

    //斜め
    if(display[0][0] == currentPlayer &&
       display[1][1] == currentPlayer &&
       display[2][2] == currentPlayer){
        return 1;
    }

    if(display[0][2] == currentPlayer &&
       display[1][1] == currentPlayer &&
       display[2][0] == currentPlayer){
        return 1;
    }

    return 0;

}

//⑤引き分け
int IsDraw(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(display[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;

}

//配置するPlayer交換
void SwitchPlayer(){
    currentPlayer = ( currentPlayer == 'O' ) ? 'X' : 'O';
}


int main(){
    int row, col;
    FirstDisplay();

    while(1)
    {
        PrintBoard();
        printf("Player %c の番です（行、列）:", currentPlayer);
        scanf("%d %d", &row, &col);

        if(!MakeMove(row, col)){
            printf("無効な入力です。もう一度入力してください。\n");
            continue;
        }

        if(CheckWin()){
            PrintBoard();
            printf("Player %c の勝ちです。\n", currentPlayer);
            break;
        }

        if(IsDraw()){
            PrintBoard();
            printf("引き分けです。 \n");
            break;
        }

        SwitchPlayer();

    }

    return 0;
}