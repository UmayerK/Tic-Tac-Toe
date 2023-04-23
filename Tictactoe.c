

#include <stdio.h>
#include <time.h> 
#include <ctype.h>
#include <stdlib.h>
void reset();// reset the board 
void printboard(); // show the current board 
int checkspaces(); // check for open spaces 
void playermove(); // player moves 
void compmove(); // computers turn to move 
char checkwin();// check to see if 3 in a row 
void printwinner(char);  // print out who wins 
const char COMP = 'O'; 
const char PLAYER = 'X';
char board [3][3]; // 3x3 board 

///////////////////////////////////////////////////////////////////////////
int main()
{
    
char winner = ' ';
reset();

while (winner == ' ' &&  checkspaces() != 0) {
printboard(); //print current status 
playermove(); // player moves  
winner = checkwin();

if  (winner != ' '|| checkspaces()==0) {
   break;
}
compmove(); // compmoves 
winner = checkwin();
if  (winner != ' '|| checkspaces()==0){
     
   break;
    
}

}
printboard();
printwinner(winner);

return 0;
    



}



///////////////////////////////////////////////////////////////////////////
void reset(){
    for (int i=0; i<3;i++) { // nested for loop to go through all rows and columns
        for (int j=0; j<3;j++) {
        board [i][j]= ' '; // setting the rows and columns to empty space 
    }
    }
    
}
///////////////////////////////////////////////////////////////////////////
void printboard(){
    printf(" %c | %c | %c ", board [0][0], board[0][1], board[0][2]);
    printf("\n---|---|---|\n");
    printf(" %c | %c | %c ", board [1][0], board[1][1], board[1][2]);
    printf("\n---|---|---|\n");
    printf(" %c | %c | %c ", board [2][0], board[2][1], board[2][2]);
    printf("\n---|---|---|\n");
    printf("\n");
    
}
///////////////////////////////////////////////////////////////////////////
int checkspaces(){
    int freespaces =9; // there are 9 total
    for (int i=0; i<3;i++){
     for (int j=0; j<3;j++){
       if (board [i][j] != ' ') {
           freespaces-- ;
       } 
    }   
    }
    return freespaces;
    
}
///////////////////////////////////////////////////////////////////////////
void playermove(){
    int x,y;
    do {
        printf("Enter your row number 1-3 ");
    scanf("%d", &x);
    x--;
    printf("Enter your column number 1-3 ");
    scanf("%d", &y);
    y--;
    if (board [x][y] !=' ') {
        printf("Invalid ");
    } 
    else {
        board [x][y] = PLAYER;
        break;
    }
    } while (board [x][y] != ' ');
    
}
///////////////////////////////////////////////////////////////////////////
void compmove(){
    // make seed 
    srand(time(0));
    int x,y;
    if (checkspaces() > 0) {
        do {
            x = rand() % 3; // pick random x 
            y = rand () % 3; // pick random y
        }
        while (board [x][y] != ' '); // while the space isint occupied 
        board [x][y]= COMP;
    }
    else {
        printwinner(' ');
    }
    
}
///////////////////////////////////////////////////////////////////////////
char checkwin(){
    // check rows 
    for (int i=0; i<3; i++){
        if (board[i][0] == board[i][1]&&board [i][1]== board [i][2])
        return board [i][0];
    }
    // check columns 
    for (int j=0; j<3; j++){
        if (board[0][j] == board[1][j]&&board [1][j]== board [2][j])
        return board [0][j];
    }
    // check diags 
        if  (board[0][0] == board[1][1]&&board [0][0]== board [2][2]) {
        return board [0][0];
        }
        if  (board[0][2] == board[1][1]&&board [0][2]== board [2][0]) {
        return board [1][1];
        }
        return ' ';
    
}
///////////////////////////////////////////////////////////////////////////
void printwinner(char winner){ 
    if (winner == PLAYER) {
        printf("you win!!");
    }
    else if( winner == COMP){
        printf("you lose");
    }
    else {
        printf("its a tie");
    }
    
}
/////////////////////////
