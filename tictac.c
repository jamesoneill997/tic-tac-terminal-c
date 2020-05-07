#include <stdio.h>

enum state {win, draw, resume};

void makeBoard(char[], int size);
void move(char[], int size, int player);
enum state checkEnd(char board[], int size);

int main()
{
    char squares[9] = {'0', '1', '2', '3', '4', '5', '6', '7','8'};
    int playerTurn;
    makeBoard(squares,9);
    
    for (int i = 0; i <9;i++){
        playerTurn = i==0||i%2==0 ? 1:2;
        move(squares, 9, playerTurn);
        if (checkEnd(squares, 9) == win)
        {
            printf("Player %d wins!\n",playerTurn);
            break;
        }

        else if(checkEnd(squares, 9) == draw){
            printf("Draw!\n");
            break;
        }

         
    }
    
    return 0;
}

void makeBoard(char values[],int size){
    for(int i = 0; i <15;i++){
        if (i==5 || i==10)
        {
            printf("------------------------\n");
        }
        else if(i == 2){
            printf("   %c   |   %c   |   %c    \n",values[0],values[1],values[2]);
        }

        else if(i == 7){
            printf("   %c   |   %c   |   %c    \n",values[3],values[4],values[5]);
        }

        else if(i == 12){
            printf("   %c   |   %c   |   %c    \n",values[6],values[7],values[8]);
        }

        else
        {
            printf("       |       |        \n");
        }
        
        
    }
}

void move(char board[], int size, int player){
    int pos;
    printf("\n Player %d to move\n Select the tile you'd like to populate\n",player);
    scanf("%d",&pos);
    if ((board[pos] != 'X' && board[pos] != 'O')&&pos<=8)
    {
        board[pos] = player==1?'X':'O';
    }
    else
    {
        printf("Invalid move, please select a valid tile");
        move(board, size, player);
    }
    
    makeBoard(board, 9);
}

enum state checkEnd(char board[], int size){
    enum state gameState = resume;

    for (int i = 0; i < 9;i++){
        if(board[i] == ' ')
        {
            return gameState;
        }

        else if((board[i] == 'X' || board[i] == 'O') && i==8)
        {
            gameState = draw;
        }
    }

    _Bool winningStates[8] = {
        (board[0] == board[1] && board[1] == board[2]),
        (board[3] == board[4] && board[4] == board[5]),
        (board[6] == board[7] && board[7] == board[8]),
        (board[0] == board[3] && board[3] == board[6]),
        (board[1] == board[4] && board[4] == board[7]),
        (board[2] == board[5] && board[5] == board[8]),
        (board[0] == board[4] && board[4] == board[8]),
        (board[2] == board[4] && board[4] == board[6]),
    };

    for(int i=0; i<8; i++){
        if ((int)winningStates[i] == 1)
        {
            gameState = win;
        }
                
    }


    return gameState;
    

}