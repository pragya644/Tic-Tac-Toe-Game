#include <stdio.h>
#include <conio.h>

char box[10]={'0','1','2','3','4','5','6','7','8','9'};
void create_board();
void marking_board(int,char);
int checkforwin();
int choice;
int main()
{
    int player=1,i;
    char mark;
    do
    {
        create_board();
        printf("Please enter a number player %d :- ",player);
        scanf("%d",&choice);

        if(player==1)
            mark='X';
        else if(player==2)
            mark='O';
        marking_board(choice , mark);
        i = checkforwin();
        if(player==1)
            player=2;
        else if(player==2)
            player=1;
    }while (i==-1);
    create_board();

    if (i==1)
    {
        if(player==1)
           printf("\nPlayer 2 you have won the game");
        else if(player==2)
           printf("\nPlayer 1 you have won the game");
    }

    else
        printf("\n---------Draw---------\n");
    return 0;
}
void create_board()
{
    printf("\n\nTic Tac Toe\n\n");
    printf("Player 1 - 'X' and Player 2 - 'O'\n\n");
    printf("    |     |    \n");
    printf(" %c  |  %c  | %c  \n",box[1],box[2],box[3]);
    printf(" _  |  _  |  _ \n");
    printf("    |     |    \n");
    printf(" %c  |  %c  | %c  \n",box[4],box[5],box[6]);
    printf(" _  |  _  |  _  \n");
    printf("    |     |    \n");
    printf(" %c  |  %c  | %c  \n",box[7],box[8],box[9]);
    printf(" _  |  _  | _  \n");
    printf("    |     |      \n");
}
void marking_board(int choice,char mark)
{
    if (choice==1 && box[1]=='1')
        box[1]=mark;
    else if (choice==2 && box[2]=='2')
        box[2]=mark;
    else if (choice==3 && box[3]=='3')
        box[3]=mark;
    else if (choice==4 && box[4]=='4')
        box[4]=mark;
    else if (choice==5 && box[5]=='5')
        box[5]=mark;
    else if (choice==6 && box[6]=='6')
        box[6]=mark;
    else if (choice==7 && box[7]=='7')
        box[7]=mark;
    else if (choice==8 && box[8]=='8')
        box[8]=mark;
    else if (choice==9 && box[9]=='9')
        box[9]=mark;
    else
    {
        printf("Invalid move\n");
        printf("Enter Again :- ");
        scanf("%d",&choice);
        marking_board(choice,mark);
    }
}

int checkforwin()
{
    if (box[1]==box[2] && box[2]==box[3])
        return 1;
    else if (box[4]==box[5] && box[5]==box[6])
        return 1;
    else if (box[7]==box[8] && box[8]==box[9])
        return 1;
    else if (box[1]==box[4] && box[4]==box[7])
        return 1;
    else if (box[2]==box[5] && box[5]==box[8])
        return 1;
    else if (box[3]==box[6] && box[6]==box[9])
        return 1;
    else if (box[1]==box[5] && box[5]==box[9])
        return 1;
    else if (box[3]==box[5] && box[5]==box[7])
        return 1;
    else if (box[1]!='1' && box[2]!='2' && box[3]!='3' && box[4]!='4' && box[5]!='5' && box[6]!='6' && box[7]!='7' && box[8]!='8' && box[9]!='9')
        return 0;
    else
        return -1;
}