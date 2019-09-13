#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{int i=0,j=0,n,m,a[100][100],Ci,Cj,co,aux,Random_p,IC,Random_Gen,tnt_t=0;
 char c;
 HANDLE CO;
 CO = GetStdHandle(STD_OUTPUT_HANDLE);
n=22;
m=75;
srand(time(0));
//initial condition
cout<<"1-blank 2-beach 3-water"<<endl;
cin>>IC;
   for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
    {a[i][j]=1;
     a[1][j]=2;
     a[i][1]=2;
     a[n][j]=2;
     a[i][m]=2;
     Ci=12; Cj=35;
     a[Ci][Cj]=3;
     aux=1;
    }
//Generation
switch(IC)
{ //Blank Gen
   case 1:
    break;
 //Beach Gen
   case 2:
    {for(i=2;i<=n-1;i++)
     for(j=2;j<=m-1;j++)
      {Random_Gen=(rand()%3)+1;
       if(Random_Gen==1) a[i][j]=1;
       if(Random_Gen==2) a[i][j]=11;
       if(Random_Gen==3) a[i][j]=12;

      }
     break;
    }
 //Water Gen
   case 3:
    {for(i=2;i<=n-1;i++)
     for(j=2;j<=m-1;j++)
     {Random_Gen=(rand()%2)+1;
      if(Random_Gen==1) a[i][j]=1;
      if(Random_Gen==2) a[i][j]=12;
     }
     break;
    }






}
//update-----------------------------------------------------------------------start
while(1)
{a[Ci][Cj]=3;
 Random_p=(rand()%2)+1;

    //displaying------

    for(i=1;i<=n;i++)
    {for(j=1;j<=m;j++)
     if(a[i][j]==2){co=8; SetConsoleTextAttribute(CO, co);  cout<<"I";}
     else if(a[i][j]==1){co=8; SetConsoleTextAttribute(CO, co);  cout<<" ";}
     else if(a[i][j]==3){co=12; SetConsoleTextAttribute(CO, co);  cout<<".";}
     else if(a[i][j]==11){co=14; SetConsoleTextAttribute(CO, co);  cout<<"s";}
     else if(a[i][j]==12){co=17; SetConsoleTextAttribute(CO, co);  cout<<".";}
     else if(a[i][j]==13){co=12; SetConsoleTextAttribute(CO, co);  cout<<"T";}
    cout<<endl;
    {co=15; SetConsoleTextAttribute(CO, co);}
    }

     //physics-------

    a[Ci][Cj]=aux;

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
     {//sand
      if((a[i][j]==11)&&(a[i+1][j]==1)){a[i+1][j]=11; a[i][j]=1;}
      else  if((a[i][j]==11)&&(a[i+1][j]==12)){a[i+1][j]=11; a[i][j]=12;}
      //water
      if((a[i][j]==12)&&(a[i+1][j]==1)){a[i+1][j]=12; a[i][j]=1;}
      if((a[i][j]==12)&&((a[i][j+1]==1)||(a[i][j-1]==1)))
         {if((a[i][j+1]==1)&&(a[i][j-1]!=1))      {a[i][j+1]=12; a[i][j]=1;}
         else if ((a[i][j-1]==1)&&(a[i][j+1]!=1)) {a[i][j-1]=12; a[i][j]=1;}
         else if(Random_p==1) {a[i][j+1]=12; a[i][j]=1;}
         else if(Random_p==2) {a[i][j-1]=12; a[i][j]=1;}
         }
     //TNT
      if(a[i][j]==13)
        {tnt_t++;
          if(tnt_t==10)
          {if((a[i][j]!=12)&&(a[i][j]!=2)) a[i][j]=1;
           if((a[i-1][j]!=12)&&(a[i-1][j]!=2)&&(a[i-1][j]!=13)) a[i-1][j]=1;
           if((a[i+1][j]!=12)&&(a[i+1][j]!=2)&&(a[i+1][j]!=13)) a[i+1][j]=1;
           if((a[i][j-1]!=12)&&(a[i][j-1]!=2)&&(a[i][j-1]!=13)) a[i][j-1]=1;
           if((a[i][j+1]!=12)&&(a[i][j+1]!=2)&&(a[i][j+1]!=13)) a[i][j+1]=1;
           if((a[i-1][j-1]!=12)&&(a[i-1][j-1]!=2)&&(a[i-1][j-1]!=13)) a[i-1][j-1]=1;
           if((a[i-1][j+1]!=12)&&(a[i-1][j+1]!=2)&&(a[i-1][j+1]!=13)) a[i-1][j+1]=1;
           if((a[i+1][j-1]!=12)&&(a[i+1][j-1]!=2)&&(a[i+1][j-1]!=13)) a[i+1][j-1]=1;
           if((a[i+1][j+1]!=12)&&(a[i+1][j+1]!=2)&&(a[i+1][j+1]!=13)) a[i+1][j+1]=1;
           if((a[i-1][j]==13)||(a[i+1][j]==13)||(a[i][j-1]==13)||(a[i][j+1]==13)
              ||(a[i-1][j-1]==13)||(a[i-1][j+1]==13)||(a[i+1][j-1]==13)||(a[i+1][j+1]==13))
             tnt_t=9; else tnt_t=0;
          }

        }

     }


    //Controls-------

    cout<<"Input: wasd-Movement 0-Delete p-Wait 1-Sand 2-Water 3-TNT "<<endl;cin>>c;
    if(c=='w') {aux=a[Ci-1][Cj]; Ci=Ci-1;}
    if(c=='s') {aux=a[Ci+1][Cj]; Ci=Ci+1;}
    if(c=='a') {aux=a[Ci][Cj-1]; Cj=Cj-1;}
    if(c=='d') {aux=a[Ci][Cj+1]; Cj=Cj+1;}

    if(c=='0') {aux=1;}
    if(c=='1') {aux=11;}
    if(c=='2') {aux=12;}
    if(c=='3') {aux=13;}




}
//update----------------------------------------------------------------------end


  return 0 ; }
