#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

char bombs [10][10];
int  numberneighbor [10][10];
char zirnamayesh [10][10];
char show[10][10];
int gheirebomb=0;
int freeHelp=0;
int helps =3;

int clickable (int i, int j)
{
    int x=show[i][j];
    if((49<=x && x<=57)|| show[i][j]==' ')
        return 0;
    return 1;
}

int CheckXY (int i, int j)
{
    if(i>-1&&j>-1&&i<10&&j<10)
        return 1;
    return 0;
}
int undershowNumberCheck (int i, int j)
{
    int x=zirnamayesh[i][j];
    if(49<=x && x<=57)
        return 1;
    return 0;
}

void white (int i,int j)
{
    if(undershowNumberCheck(i,j)==1)
    {
        show[i][j]=zirnamayesh[i][j];
        gheirebomb++;
        freeHelp++;
    }
    if(zirnamayesh[i][j]==NULL)
    {
        show[i][j]=' ';
        gheirebomb++;
        freeHelp++;
    }
}

void clicked (int i,int j)
{
    if(!CheckXY(i,j)||!clickable(i,j))
        return;

//age adad bood faghat khodesh sefid she => we need one fun for checking if it is a number
//age nabod chahar click va khodesh sefid she

    if((undershowNumberCheck(i,j)==1)||(zirnamayesh[i][j]=='B'))
        white(i,j);
    else
    {
        white(i,j);
        clicked(i-1,j);
        clicked(i,j+1);
        clicked(i+1,j);
        clicked(i,j-1);
    }
}

int  main(){

    //loadong
    Sleep(4000);
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                                                                              LOADING"<<endl<<endl;
    Sleep(1000);
    cout<<"                                                                                                 ";
    for(int i=0; i<17; i++)
    {
        cout<<"_";
        Sleep(150);
    }
    Sleep(800);
    for(int i=0; i<15; i++)
    {
        cout<<"_";
        Sleep(90);
    }
    Sleep(2000);
    cout<<endl<<endl<<endl<<endl;
    cout<<"                                                                                                          ' Minesweeper '";
    Sleep(6000);
    system("cls");

    //Entering the name
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                   Please Enter Your Name: ";
    string nameplayer;
    cin>>nameplayer;
    Sleep(500);

    //Welcoming
    cout<<endl<<endl;
    cout<<"                                                   You can use 'Help' 3 times!"<<endl<<endl;Sleep(500);
    cout<<"                                                   If you open 25 Cells without any help,we'll give you one for free!"<<endl<<endl;Sleep(500);
    cout<<"                                                   Be Careful.. 20 BOMBS are hidden there!"<<endl<<endl;Sleep(10000);







    //make bombs matrix 0
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            bombs[i][j]='0';
        }
    }

    //make bombs
    srand (time(NULL));
    int tbomb=0;
    while(tbomb<20)
    {
        int xranbomb,yranbomb;
        xranbomb= rand()%10;
        yranbomb= rand()%10;
        if(bombs[xranbomb][yranbomb]=='0')
        {
            bombs[xranbomb][yranbomb]='B';
            tbomb++;
        }
    }
/*
    //show bomb matrix
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            cout<<bombs[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    //make numbers zero
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            numberneighbor[i][j]=0;
        }
    }

    // calculate numbers
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(bombs[i][j]=='B')
            {
                if(i-1>=0 && j-1>=0)numberneighbor[i-1][j-1]++;
                if(i-1>=0)numberneighbor[i-1][j]++;
                if(i-1>=0 && j+1<=9)numberneighbor[i-1][j+1]++;
                if(j+1<=9)numberneighbor[i][j+1]++;
                if(i+1<=9 && j+1<=9)numberneighbor[i+1][j+1]++;
                if(i+1<=9)numberneighbor[i+1][j]++;
                if(i+1<=9 && j-1>=0)numberneighbor[i+1][j-1]++;
                if(j-1>=0)numberneighbor[i][j-1]++;
            }
        }
    }

    //make under show
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            zirnamayesh[i][j]==' ';
        }
    }

    //make bombs of under show
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(bombs[i][j]=='B')
            {
                zirnamayesh[i][j]='B';
            }
        }
    }

    //make numbers of under show
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(numberneighbor[i][j] != 0 && zirnamayesh[i][j] !='B')
            {
                if(numberneighbor[i][j]==1) zirnamayesh[i][j]=(char)49;
                if(numberneighbor[i][j]==2) zirnamayesh[i][j]=(char)50;
                if(numberneighbor[i][j]==3) zirnamayesh[i][j]=(char)51;
                if(numberneighbor[i][j]==4) zirnamayesh[i][j]=(char)52;
                if(numberneighbor[i][j]==5) zirnamayesh[i][j]=(char)53;
                if(numberneighbor[i][j]==6) zirnamayesh[i][j]=(char)54;
                if(numberneighbor[i][j]==7) zirnamayesh[i][j]=(char)55;
                if(numberneighbor[i][j]==8) zirnamayesh[i][j]=(char)56;
                if(numberneighbor[i][j]==9) zirnamayesh[i][j]=(char)57;

            }
        }

    }

    //make array show
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            show[i][j]='*';
        }
    }

    //start of time
    clock_t tstart = clock();

    // start of display
    while(true)
    {

        system("cls");
        cout<<endl<<endl<<endl<<endl;
        cout<<"                 "<<" 1    2    3    4    5    6    7    8    9   10"<<endl;
        for(int i=0; i<10; i++)
        {
            if(i<9)
            {
                cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                if(i==0)cout<<"                                       Cells remaining: "<<100-gheirebomb<<endl;
                else cout<<endl;
                cout <<"             "<<i+1<<"  "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][4]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                if(i==0)cout<<"                                       Helps Remaining: "<<helps<<" (Free Help Cells: "<<freeHelp<<" )"<<endl;
                else cout<<endl;
            }
            else
            {
                cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout<<endl;
                cout <<"             "<<i+1<<" "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][4]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<endl;
                    }
                }

        cout<<endl<<endl<<endl;


        //entering the task
        cout<<"                 Press f(for flag)/ c(for click)/ h(for help): ";
        char tcell;
        cin>>tcell;
        cout<<endl<<endl;
        //entering cell
        int xcell,ycell;
        if(tcell != 'h')
        {

            cout<<"                 Please enter the cell: ";
            cin>>xcell>>ycell;
            xcell--;
            ycell--;

        }

        if(tcell=='f')
        {
            show[xcell][ycell]='f';
        }
        else if(tcell=='c')
        {
            if(zirnamayesh[xcell][ycell]=='B')
            {
                cout<<"\a" <<endl<<endl<< "                 BOOOOMBBBBBBBBBBBBB!!!!"<< "\a"<<endl;
                Sleep(2500);

                for(int i=0; i<10; i++)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(zirnamayesh[i][j]=='B' && show[i][j] == '*')
                        {
                            show[i][j]='B';
                            show[xcell][ycell]='B';
                        }
                    }
                }
                system("cls");Sleep(100);
                cout<<endl<<endl<<endl<<endl;
                cout<<"                 "<<" 1    2    3    4    5    6    7    8    9   10"<<endl;
                for(int i=0; i<10; i++)
                {
                    if(i<9)
                    {
                        cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout<<endl;
                        cout <<"             "<<i+1<<"  "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                        cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][4]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                        cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<endl;
                    }
                    else
                    {
                        cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                        cout<<endl;
                        cout <<"             "<<i+1<<" "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                        cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                        cout << (char)179 << " "<<
                        show[i][4]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                        cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                        cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                        cout<<endl;
                    }
                }
                cout<<endl<<endl<<endl;
                cout<<"                 Sorry.. You Lost dear "<<nameplayer<<" :("<<endl<<endl;
                printf("                 Time taken: %.2fs\n", (double) (clock() - tstart)/CLOCKS_PER_SEC);
                cout<<endl<<"                 And your remaining cells was : "<<100-gheirebomb<<endl;
                int gmsg=100-gheirebomb;
                if(gmsg>=87) cout<<"                 You are ' Really Bad ' at this Game!";
                else if(gmsg<87 && gmsg>=50) cout<<"                 It wasn't Good!";
                else if(gmsg<50 && gmsg>=10) cout<<"                 Not bad! Well done my friend!";
                else cout<<"                 Awwww!! You were GREAT!";

                cout<<endl<<endl;
                return 0;

            }
            else
            {
                clicked(xcell,ycell);
                if(freeHelp>=25)
                {
                    helps++;
                    freeHelp-=25;
                }
            }
        }
        else if(tcell=='h' && helps>0)
        {

                    while(true)
                    {
                        int ihelp= rand()%10;
                        int jhelp= rand()%10;
                        if(zirnamayesh[ihelp][jhelp]!='B' && show[ihelp][jhelp] == '*')
                        {
                            clicked(ihelp,jhelp);
                            helps--;
                            break;
                        }
                    }
                    freeHelp=0;
        }
        else if(tcell=='h' && helps==0)
        {
            cout<<"                 There is no help left "<<nameplayer<<" :(";Sleep(2000);
        }
        if(gheirebomb==80)
        {
            system("cls");
        cout<<endl<<endl<<endl<<endl;
        cout<<"                 "<<" 1    2    3    4    5    6    7    8    9   10"<<endl;
        for(int i=0; i<10; i++)
        {
            if(i<9)
            {
                cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout<<endl;
                cout <<"             "<<i+1<<"  "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][4]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<endl;
            }
            else
            {
                cout <<"                "<< (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191;
                cout<<endl;
                cout <<"             "<<i+1<<" "<< (char)179 << " "<<show[i][0]<<" " << (char)179;
                cout << (char)179 << " "<<show[i][1]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][2]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][3]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][4]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][5]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][6]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][7]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][8]<<" "<< (char)179;
                cout << (char)179 << " "<<show[i][9]<<" "<< (char)179<<endl;
                cout<<"                "<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<(char) 192<< (char)196<<(char)196<<(char)196<<(char)217;
                cout<<endl;
            }
        }

        cout<<endl<<endl<<endl;
        Sleep(4000);
        cout<<"                 You Won the Game dear "<<nameplayer<<" :)"<<endl<<endl;
        printf("                 Time taken: %.2fs\n", (double) (clock() - tstart)/CLOCKS_PER_SEC);
        cout<<"                 But Haami's record was much better than you little baby! :D";
        cout<<endl<<endl;
        return 0;
        }
    }
    return 0;
}
