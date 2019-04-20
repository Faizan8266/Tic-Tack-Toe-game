/********
 Develop Tic tack toe  game by using C language to implement this game.
 ************/

#include<stdio.h>
#include<string.h>

int board(char a[][3],char);
int main()
{

    int i,j,c,x=0,y=0,s1,s2,k;
	char a[3][3],ch,play[5],z[10],name1[10],name2[10],m[10],n[10];

	do
	{
		name1[0]='\0';
		name2[0]='\0';
		z[0]='\0';
        for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				a[i][j]='.';
		}
		printf("\n\n\tTic Tac Toe\n\n");
		printf("Enter a name for X Player:\n");
		gets(name1);
		printf("Enter a name for O Player:\n");
		gets(name2);
		do
		{
			s1=0;
            s2=0;
			c=0;
			printf("Who plays first, %s %s\n",name1,name2);
			gets(z);
			s1=strcmp(name1,z);
			s2=strcmp(name2,z);
			if((s1==0)||(s2==0))
			{
				c=0;
			}
			else
            {
                printf("%s is not a registered player.\n",z);
                c=1;
            }
		}while(c!=0);
		c=0;
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
				printf("%c ",a[x][y]);
			printf("\n");
		}
		for(i=0;i<9;i++)
		{
			if(i%2==0)
			{
				printf("Player of the current turn: %s\n",z);
				ch='X';
			}
			else
			{
				if(s1==0)
				printf("Player of the current turn: %s\n",name2);
				else if(s2==0)
				printf("Player of the current turn: %s\n",name1);
				ch='O';
			}
				k=0;
				do
                {
                    printf("Choose a row number (0 to 2) ");
                    scanf(" %s",&m);
                if(m[0]!='\0'&&m[1]=='\0')
                {
                       if(m[0]=='0'||m[0]=='1'||m[0]=='2')
                        k=0;
                    else
                    {
                        printf("not a valid number\n");
                        k=1;
                    }
                }
                else
                {
                    printf("not a valid number\n");
                        k=1;
                }
                }while(k!=0);
                k=0;
				do
                {
                    printf("Choose a column number (0 to 2) ");
                    scanf(" %s",&n);
                if(n[0]!='\0'&&n[1]=='\0')
                {
                    if(n[0]=='0'||n[0]=='1'||n[0]=='2')
                        k=0;
                    else
                    {
                        printf("not a valid number\n");
                        k=1;
                    }
                }
                else
                {
                    printf("not a valid number\n");
                        k=1;
                }
                }while(k!=0);
                if(a[m[0]-48][n[0]-48]=='.')
                {
                a[m[0]-48][n[0]-48]=ch;
//                system("cls");
                for(x=0;x<3;x++)
                {
				for(y=0;y<3;y++)
					printf("%c ",a[x][y]);
				printf("\n");
                }
                }
            else
            {
                printf("You have Choose wrong place already Choose\n");
                i=i-1;
            }



			c=board(a,ch);


			if(c==1)
			{
				printf("Game is over:\n");
				if(i%2==0)
                    printf("%s Wins!\n",z);
                else
                {
				if(s1==0)
				printf("%s Wins!\n",name2);
				else if(s2==0)
				printf("%s Wins!\n",name1);
                }
				break;
			}
		}
        if(c==0)
                printf("Game is over:\nit is a tie!\n");
		printf("Would you like to play again? (Y/N)\n");
		gets(play);
		do
		{
            gets(play);
			if((play[0]=='Y'||play[0]=='N')&&play[1]=='\0')
			    x=1;
			else
				printf("%s is not a valid answer.\n",play);
		}while(x!=1);
	}while(play[0]!='N');
	printf("BYE!\n");
}


int board(char a[][3],char no)
{


	if(a[0][0]==no&&a[0][0]==a[0][1]&&a[0][1]==a[0][2])
		return 1;
	else if(a[0][0]==no&&a[0][0]==a[1][0]&&a[1][0]==a[2][0])
		return 1;
	else if(a[0][0]==no&&a[0][0]==a[1][1]&&a[1][1]==a[2][2])
		return 1;
	else if(a[0][1]==no&&a[0][1]==a[1][1]&&a[1][1]==a[2][1])
		return 1;
	else if(a[0][2]==no&&a[0][2]==a[1][2]&&a[1][2]==a[2][2])
		return 1;
	else if(a[1][0]==no&&a[1][0]==a[1][1]&&a[1][1]==a[1][2])
		return 1;
	else if(a[2][0]==no&&a[2][0]==a[2][1]&&a[2][1]==a[2][2])
		return 1;
	else if(a[0][2]==no&&a[0][2]==a[1][1]&&a[1][1]==a[2][0])
		return 1;
	return 0;
}
