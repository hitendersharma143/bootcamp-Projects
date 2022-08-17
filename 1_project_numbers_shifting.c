// a number shifting game .
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
int get_arrow_only(int [][4]);
void yellow();
void reset();
void red();
void inputname(char []);
void gamerules(void);
int game(char[]);
int main()
{
    char name[20];
    int n;
    char ch;
    inputname(name);
    system("cls");
    gamerules();
again:
    n = game(name);
    system("cls");
    yellow();
    if (n < 0)
    {
        printf("\toops.... where are you going? \n");
    }
    else if (n > 0)
    {
        printf("congrats!! You have completed the game in %d moves\n", 200 - n);
    }
    else
    {
        red();
        system("cls");
        printf("\t\t YOU LOSE  !\n");
    }
repeat:
    red();
    printf("\t\tDo you want to play again(Y/N): \n");
    reset();
    ch = getch();
    if (ch == 'y' || ch == 'Y')
    {
        goto again;
    }
    else if (ch == 'n' || ch == 'N')
    {
        return 0;
    }
    else
    {
        printf("\n\t\t\t\t\tPlease enter Yes or NO.\n");
        goto repeat;
    }
    return 0;
}
int get_arrow_only(int a[][4])
{
    char ch;
    int temp, flag, i, j;
    printf("\n");
    while (1)
    {
        ch = getch();
        flag = 0;
        if (ch == 0 || ch == 224)
            ch = getch();
    exitloop:
        if (flag)
            break;
        if (ch == 72)
        {
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (a[i][j] == 0 && i != 0)
                    {
                        printf("\nyou pressed %d", ch);
                        flag = 1;
                        temp = a[i][j];
                        a[i][j] = a[i - 1][j];
                        a[i - 1][j] = temp;
                        goto exitloop;
                    }
                }
        }
        else if (ch == 80)
        {
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (a[i][j] == 0 && i != 3)
                    {
                        printf("\nyou pressed %d", ch);
                        flag = 1;
                        temp = a[i][j];
                        a[i][j] = a[i + 1][j];
                        a[i + 1][j] = temp;
                        goto exitloop;
                    }
                }
        }
        else if (ch == 75)
        {
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (a[i][j] == 0 && j != 0)
                    {
                        printf("\nyou pressed %d", ch);
                        flag = 1;
                        temp = a[i][j];
                        a[i][j] = a[i][j - 1];
                        a[i][j - 1] = temp;
                        goto exitloop;
                    }
                }
        }
        else if (ch == 77)
        {
            for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                {
                    if (a[i][j] == 0 && j != 3)
                    {
                        printf("\nyou pressed %d", ch);
                        flag = 1;
                        temp = a[i][j];
                        a[i][j] = a[i][j + 1];
                        a[i][j + 1] = temp;
                        goto exitloop;
                    }
                }
        }
        else if (ch == 'e' || ch == 'E')
        {
            return 1;
        }
    }
    return 0;
}
void yellow()
{
    printf("\033[1;33m");
}
void reset()
{
    printf("\033[0m");
}
void red()
{
    printf("\033[1;31m");
}
void inputname(char name[])
{
    printf("Player Name : ");
    // fgets(name, 20, stdin);
    gets(name);
}
void gamerules(void)
{
    printf("\t\t\tMATRIX PUZZLE\n\n");
    red();
    printf("\t\t RULES OF THE GAME\n\n");
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    reset();
    printf("\tMove Up : by Up Arrow Key\n");
    printf("\tMove Down : by Down Arrow Key\n");
    printf("\tMove Right: by Right Arrow Key\n");
    printf("\tMove Left : by Left Arrow Key\n");
    red();
    printf("2. You can move numbers at an empty position only.\n\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");
    printf("4. Winning Situation : 1. Number in a 4*4 matrix should be in order from 1 to 15\n\n");
    reset();
    printf("\t\tWinning Situation : \n");
    yellow();
    int a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i, j;
    for (int i = 0; i <= 20; i++)
        printf("-");
    printf("\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 3 && j == 3)
                printf("|    ");
            else
                printf("| %2d ", a[i][j]);
        }
        printf("|");
        printf("\n");
    }
    for (int i = 0; i <= 20; i++)
        printf("-");
    reset();
    printf("\n\n5. You can exit the game at anytime by pressing 'E' or 'e'\n so Try to win in minimumno of move\n\n\t\tHappy gaming , Good luck\n\nEnter any key to start....   ");
    getch();
}
int game(char name[])
{

    int move = 200, i, j, k, temp, l = 0, flag = 0, a[4][4], b[15];
    char ch;
    int c[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    srand(time(0));
    for (i = 0; i < 15; i++)
    {
        temp = rand() % 15 + 1;
        for (j = 0; j < i; j++)
        {
            if (temp == b[j])
                break;
        }
        if (i == j)
            b[i] = temp;
        else
            i--;
    }
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {
            a[i][j] = b[l];
            l++;
        }
    a[3][3] = 0;
    while (move)
    {
        system("cls");
        printf("Player name: %s, remaining moves %d \n", name, move);
        printf("\t\t\t\t exit - E/e\n");
        for (int i = 0; i <= 20; i++)
            printf("-");
        printf("\n");
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (a[i][j] == 0)
                    printf("|    ");
                else
                    printf("| %2d ", a[i][j]);
            }
            printf("|");
            printf("\n");
        }
        for (i = 0; i <= 20; i++)
            printf("-");
        k=0;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (a[i][j] == c[i][j])
                    k++;
            }
        }
        if (k >= 15)
            return move;
        if (get_arrow_only(a))
        {
            return -1;
        }
        move--;
    }
    return 0;
}
