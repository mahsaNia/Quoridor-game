//The girls of coding
#include <iostream>
#include<windows.h>
#include <time.h> // for exit
#include <stdlib.h> // for exit and system
using namespace std;
void menu();//تابع منو و اصل بازی
void error404();//تابع بازی های آپدیت نشده
void fillarr (char t2 [17][17] );
void print_gametable (char x [17][17]); // تابع چاپ صفحه بازی
int enter_type_of_movement (); // تابعی که نوع حرکت را برمیگرداند (دیوار یا مهره)
int enter_wall_model (); // تابعی که نوع دیواری که کاربر میخواهد را برمیگرداند
int Horizontal_wall (int a);// دریافت سطر و ستون افقی
int Vertical_wall (int a); // دریافت سطر و ستون عمودی
void set_color  (int color_code); // تابع رنگ امیزی
int main()
{
   menu();
   return 0;
}
void fillarr (char t2 [17][17] )
{
  bool wall = false ;
    for(int i = 0 ; i < 17 ; i++) // قرار گیری کاراکتر های صفحه بازی در ارایه دو بعدی
        {
            for(int j = 0 ; j < 17 ; j++)
            {
                if(wall == true)
                {
                  t2 [i][j] = 32 ;
                  if(i % 2 == 0)
                  {
                     wall = false ;
                  }

                }
                else
                {
                   t2 [i][j] = 35 ;
                   wall = true ;
                }
            }
            if(i % 2 != 0)
            {
                wall = false ;
            }
        }
}
//
void print_gametable (char x [17][17]) // تابع چاپ صفحه بازی
{
    for(int i = 0 ; i < 17 ; i = i + 2) // چاپ اعداد افقی صفحه بازی
      {
         if(i == 0) // قبل اولین عدد یک اسپیس چاپ میشه
        {
            cout << "   " << i << "   " ;
        }
        else if(i == 2 || i == 4 || i == 6 || i == 8)
        {
            cout <<  i << "   " ;
        }
        else// i = 10 , 12 , 14 , 16
         {
            cout <<  i << "  " ;
         }
     }
        cout << endl ;



     for(int i = 0 ; i < 17 ; i++) // چاپ اعداد عمودی و صفحه بازی
       {

         if(i >= 0 && i <= 9)// یک رقمی پس اسپیس بیشتر
           {
             cout <<  i << "  " ;
           }
           else
           {
             cout << i << " " ;
           }

           for(int j = 0 ; j < 17 ; j++)
            {
              if(x [i][j] == 45 && x [i][j + 1] == 45)
              {
                 cout << x [i][j];
              }
              else
              {
                 cout << x [i][j] << " " ;
              }

            }

             cout << endl ;
       }
     for(int i = 1 ; i < 17 ; i = i + 2) // اعداد زیر صفحه بازی
     {
         if(i == 1) // قبل اولین عدد یک اسپیس چاپ میشه
        {
            cout << "     " << i << "   " ;
        }
        else if(i == 3 || i == 5 || i == 7 || i == 9)
        {
            cout <<  i << "   " ;
        }
        else// i = 11 , 13 , 15
         {
            cout <<  i << "  " ;
         }
     }
     cout << endl << endl ;

}
//
int enter_type_of_movement () // تابعی که نوع حرکت را برمیگرداند (دیوار یا مهره)
{
    cout << "move your pawn or put a wall" << endl ;
    cout << "pawn : Enter 1" << endl ;
    cout << "wall : Enter 2" << endl ;
    int type_of_movement ;
    cin >> type_of_movement ;
    return type_of_movement ;
}
//
int enter_wall_model () // تابعی که نوع دیواری که کاربر میخواهد را برمیگرداند
{
    int wall_model ;
    cout << "What kind of wall do you want?" << endl ;
    cout << "1) -  or  2) |" << "  " << "Enter the number:" ;
    cin >> wall_model ;
    return wall_model ;
}
//
int Horizontal_wall (int a) // دریافت سطر و ستون دیوار افقی
{
    int r , c , c2 ;
    if(a == 1)
    {
        cout << "Enter the number of row :" ;
        cin >> r ;
        while(r % 2 == 0)
        {
            cout<<"\aThe input number must be Odd.Please Enter the number again"<<endl;
            cin >> r;
        }
        return r ;
    }
    else if(a == 2)
    {
        cout << "enter the column of two cells you want to put a wall in front of them:" << endl ;//دوتا ستون برا دیوار افقی
        cout << "column 1 :" ;
        cin >> c ;
        cout << endl ;
        while(c % 2 != 0)
        {
            cout<<"\aThe input numbers must be even.Please Enter the number again"<<endl;
            cin >> c ;
        }
        return c ;
    }
    else // a == 3
    {
        cout << "column 2 :";
        cin >> c2 ;
        while(c2 % 2 != 0)
        {
            cout<<"\aThe input numbers must be even.Please Enter the number again"<<endl;
            cin >> c2 ;
        }
        return c2 ;
    }
}
//
int Vertical_wall (int a)
{
   int r , r2 , c ;
   if(a == 1)
   {
       cout << "enter the row of two cells you want to put a wall in front of them :" << endl ;// دوتا سطر برای دیوار عمودی
       cout << "row 1 :" ;
       cin >> r ;
       cout << endl ;
       while(r % 2 != 0)
       {
           cout<<"\aThe input numbers must be even.Please Enter the number again"<<endl;
           cin >> r;
       }
       return r ;
   }
   else if(a == 2)
   {
      cout << "row 2 :" ;
      cin >> r2 ;
      while(r2 % 2 != 0)
      {
          cout<<"\aThe input numbers must be even.Please Enter the number again"<<endl;
          cin >> r2;
      }
      return r2 ;
   }
   else // a == 3
   {
       cout << "Enter the column:" ;
       cin >> c;
       while(c % 2 == 0)
       {
           cout<<"\aThe input number must be Odd.Please Enter the number again"<<endl;
           cin >> c;
       }
       return c ;
   }
}
//
void error404()
{
    cout << "\tsorry! This game has not been made in this version yet :("<<endl
         <<"\tStay tuned for our next updates :P "<<endl
         <<endl
         << "\tDo you want to choose another game?"<< endl
         << "\tEnter Your Choice : "<<" No : 0"<<"    yes : 1"<<endl
         <<"\t";
    int answer;
    cin >> answer;
    if (answer == 1)
        menu();
    else
        cout << "\tGoodbye :D ( by The girls of coding )";
}
//
void set_color  (  int color_code  )
  {
          SetConsoleTextAttribute ( GetStdHandle (STD_OUTPUT_HANDLE) ,   color_code   )  ;
  }
//
void menu()
{
      system("cls");

    cout << "************* Welcome To The Quoridor GAME ! *************" << endl << endl ;

    cout << "\tMenu:" << endl;
    cout << "\t<1> : Leaderboard" << endl
         << "\t<2> : Classic two-player game" << endl//کلاسیک دو نفره
         << "\t<3> : Daliz game" << endl //دالیز
         << "\t<4> : Daliz two-player game" << endl // دالیز دو نفره
         << "\t<5> : Classic four-player game" << endl //  کلاسیک چهار نفره
         << "\t<6> : Daliz four-player game" << endl //دالیز چهارنفره
         << "\t<7> : Daliz Three-player game" << endl //بازی سه نفره دالیز
         << "\t<8> : Classic and Daliz four-player tournament games" << endl // بازی های تورنمنت چهارنفره کلاسیک و دالیز
         << "\t<9> : The Rules"<<endl
         << "\t<0> : Exit" << endl;
          cout << endl
            << "\tEnter Your Choice : ";

    string name[5][400];  //ارایه برای دریافت نام بازیکن ها
    int xx = 1;
    short m;
    cin >> m;
    switch (m)
    {
    case 0:
        cout << "\tThanks For Playing Quoridor ( by The girls of coding ) \n" << endl;
        system("pause");
    case 1:
    {
        set_color(3) ;
    cout<<"Our team believes that being a winner or loser does not matter. If you enjoy playing this game ,it means you are the winner!"<<endl;
         set_color(7) ;
    }
    break;

    case 2:
    {
////////////////////////////////////////////////////////////////شروع بازی دو نفره ///////////////////////////////////////////////////////////////////
    cout << "\tEnter Your Name : "<< endl;
      for(int i =0; i < 4; i++)
      {
        cout << "\t";
        cin >> name[i][400];
        cout <<"\t"<<name[i][400] <<" you are the player number " << xx <<" and your pawn is "<< (char)(65 + i)<<" and "<<(char)(65 + ++i)<< endl;
        xx ++;
      }
    //
    //
          int h1 , h2 ;
         int divar1=0 ,divar2=0, nn1 = 0, nn2 = 0 , r , r2 , c, c2 , m , n , k , l , x1 ,x2 ,x3 ,x4, y1 ,y2 ,y3 , y4 , z1 , z2 ,z3 ,z4 , which_pawn , f , g ,w,z ;
         bool aval1 = true , aval2 = true , aval3 = true , aval4 = true , aval5 = true , aval6 =true , aval7 = true , aval8 =true;
          char t2 [17][17] ;
          fillarr (t2) ;
          t2 [8][0] = 65 ;
          t2 [8][16] = 67 ;
          cout <<endl;
          print_gametable (t2) ;
          cout<<"Player number 1 In which cell of the zero column do you want to place the second pawn?"<<endl
          <<"Enter the row: ";
          cin >> h1;
          while(h1 % 2 != 0)
          {
              cout<<"please enter a even number:  ";
              cin >> h1;
          }
          int hh1 = h1;
          t2[h1][0] = 66;

          cout<<"Player number 2 In which cell of the 16 column do you want to place the second pawn?"<<endl
          <<"Enter the row: ";
          cin >> h2;
          while(h2 % 2 != 0)
          {
              cout<<"please enter a even number:  ";
              cin >> h2;
          }
          int hh2 = h2;
          t2[h2][16] = 68;
          system("cls") ;
          print_gametable (t2) ;
          int p = 1;
          set_color(12) ;
                cout<<"Pay attention !!\nPlayers are not allowed to completely close the paths to reach the goal!\n"  <<endl;
          set_color(7) ;
 while ( p != 3)
 {

    if(p == 1) //player number 1
    {
       cout <<"it's the turn of player number 1"<<endl;
      int type_of_movement , wall_model ;
      type_of_movement = enter_type_of_movement () ;
      if(type_of_movement == 2)
     {
          if ( divar1 > 9 )
           {
             cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
             type_of_movement = 1 ;
             nn1=1;
           }

         if ( divar1 <= 9 && nn1==0)
          {
        wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

         if(wall_model == 1) // تابع
        {
           int a1 = 1 , a2 = 2 , a3 = 3 ;
           r = Horizontal_wall (a1) ;
           c = Horizontal_wall  (a2) ;
           c2 = Horizontal_wall (a3) ;
        }

        else // wall_model == 2
        {
            int b1 = 1 , b2 = 2 , b3 = 3 ;
            r = Vertical_wall (b1) ;
            r2 = Vertical_wall (b2) ;
            c =  Vertical_wall (b3) ;
        }
        divar1 ++ ;
         }
     }
    if(type_of_movement == 1)
    {
        cout<<"Which pawn do you want to move?"<<endl
        <<"Enter the number:  1) A   2) B";
        cin >> which_pawn ; //برای اینکه هر دفعه بازیکن کدام مهره را میخواد تکان بدهد
        if (which_pawn == 1) // تکان دادن مهره A
        {
            cout << "Enter the number of row :" ;
            cin >> r ;
            while(r % 2 != 0 )
            {
                cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                cin >> r;
            }
            cout << "Enter the number of column:" ;
            cin >> c ;
            while(c % 2 != 0)
            {
                cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                cin >> c;
            }
       if (aval5 == true)
        {
            while(  ((r!=8 || c!=2) && (r!=6 || c!=0) && (r!=10 || c!=0))    ||    ((t2[8][1]== char(33)) && (r==8 && c==2)) || ((t2[9][0]==char(61)) && (r==10 && c==0)) || ((t2[7][0]== char(33)) && (r==6 && c==0))  )
             {
                if(  ((r!=8 || c!=2) && (r!=6 || c!=0) && (r!=10 || c!=0))  )
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if(  ((t2[8][1]== char(33)) && (r==8 && c==2)) || ((t2[9][0]==char(61)) && (r==10 && c==0)) || ((t2[7][0]== char(33)) && (r==6 && c==0))  )
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                 m = r;
                 n = c;
           aval5 = false  ;
          }
       else
          {

             while(((r!=m+2 || c!=n) && (r!=m-2 || c!=n) && (r!=m || c!=n+2) && (r!=m || c!=n-2))   ||   (((t2[m+1][n]==char(61)) && (r==m+2 && c==n)) || ((t2[m - 1][n]== char(61)) && (r==m-2 && c==n)) || ((t2[m][n+ 1]== char(33)) && (r==m && c==n+2)) || ((t2[m][n- 1]== char(33)) && (r==m && c==n-2))))
              {
                 if( ((r==m+2 && c==n) && (t2[m+ 1][n]==char(61))) || ((r==m-2 && c==n) && (t2[m - 1][n]== char(61)))|| ((r==m && c==n-2) && (t2[m][n- 1]== char(33))) || ((t2[m][n+ 1]== char(33)) && (r==m && c==n+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=m+2 || c!=n) && (r!=m-2 || c!=n) && (r!=m || c!=n+2) && (r!=m || c!=n-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == m+2 && c==n) //جلو
              {
                if ( (t2[m+2][n]== char(66)) || (t2[m+2][n]== char(67))|| (t2[m+2][n]== char(68)) )
                {
                  if ( (t2[m+4][n]== char(66)) || (t2[m+4][n]== char(67))|| (t2[m+4][n]== char(68)) )
                  {
                    if ( (t2[m+6][n]== char(66)) || (t2[m+6][n]== char(67))|| (t2[m+6][n]== char(68)) )
                      {
                         r=m+8;
                      }
                     else
                     {
                        r=m+6;
                     }
                  }
                    else
                    {
                       r=m+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == m && c==n+2) // راست
              {
                if ( (t2[m][n+2]== char(66)) || (t2[m][n+2]== char(67))|| (t2[m][n+2]== char(68)) )
                {
                  if ( (t2[m][n+4]== char(66)) || (t2[m][n+4]== char(67))|| (t2[m][n+4]== char(68)))
                  {
                    if ( (t2[m][n+6]== char(66)) || (t2[m][n+6]== char(67))|| (t2[m][n+6]== char(68)) )
                      {
                         c=n+8;
                      }
                     else
                    {
                      c=n+6;
                    }
                  }
                    else
                    {
                       c=n+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == m && c==n-2)  // چپ
              {
                if ( (t2[m][n-2]== char(66)) || (t2[m][n-2]== char(67))|| (t2[m][n-2]== char(68)) )
                {
                  if ( (t2[m][n-4]== char(66)) || (t2[m][n-4]== char(67))|| (t2[m][n-4]== char(68)))
                  {
                    if ( (t2[m][n-6]== char(66)) || (t2[m][n-6]== char(67))|| (t2[m][n-6]== char(68)) )
                      {
                         c=n-8;
                      }
                     else
                    {
                      c=n-6;
                    }
                  }
                    else
                    {
                       c=n-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == m-2 && c==n) //عقب
              {
                if ( (t2[m-2][n]== char(66)) || (t2[m-2][n]== char(67))|| (t2[m-2][n]== char(68)) )
                {
                  if ( (t2[m-4][n]== char(66)) || (t2[m-4][n]== char(67))|| (t2[m-4][n]== char(68)))
                  {
                    if ( (t2[m-6][n]== char(66)) || (t2[m-6][n]== char(67))|| (t2[m-6][n]== char(68)) )
                      {
                         r=m-8;
                      }
                     else
                    {
                      r=m-6;
                    }
                  }
                    else
                    {
                       r=m-4;
                    }
                }
              }
/////////////////////////////////////////

                m=r;
                n=c;
           }
        }
////////////////////////////////////////////////////پایان دستور های مربوط به حرکت مهره اول نفر اول (A)



        if(which_pawn == 2)
        {
            cout << "Enter the number of row :" ;
            cin >> r ;
            while(r % 2 != 0 )
            {
                cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                cin >> r;
            }
            cout << "Enter the number of column:" ;
            cin >> c ;
            while(c % 2 != 0)
            {
                cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                cin >> c;
            }
       if (aval6 == true)
        {
            while(  ((r!=hh1 -2 || c!=0) && (r!=hh1+2 || c!=0) && (r!=hh1 || c!=2))    ||    (((t2[hh1-1][0]== char(61)) && (r==hh1-2 && c==0)) || ((t2[hh1+1][0]==char(61)) && (r==hh1+2 && c==0)) || ((t2[hh1][1]== char(33)) && (r==hh1 && c==2))))
             {
                if(  ((r!=hh1 -2 || c!=0) && (r!=hh1+2 || c!=0) && (r!=hh1 || c!=2))  )
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if(  ((t2[hh1-1][0]== char(61)) && (r==hh1-2 && c==0)) || ((t2[hh1+1][0]==char(61)) && (r==hh1+2 && c==0)) || ((t2[hh1][1]== char(33)) && (r==hh1 && c==2))  )
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                 k = r;
                 l = c;
           aval6 = false  ;
          }
       else
          {

             while(((r!=k+2 || c!=l) && (r!=k-2 || c!=l) && (r!=k || c!=l+2) && (r!=k || c!=l-2))   ||   (((t2[k+1][l]==char(61)) && (r==k+2 && c==l)) || ((t2[k - 1][l]== char(61)) && (r==k-2 && c==l)) || ((t2[k][l+ 1]== char(33)) && (r==k && c==l+2)) || ((t2[k][l- 1]== char(33)) && (r==k && c==l-2))))
              {
                 if( ((r==k+2 && c==l) && (t2[k+ 1][l]==char(61))) || ((r==k-2 && c==l) && (t2[k - 1][l]== char(61)))|| ((r==k && c==l-2) && (t2[k][l- 1]== char(33))) || ((t2[k][l+ 1]== char(33)) && (r==k && c==l+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=k+2 || c!=l) && (r!=k-2 || c!=l) && (r!=k || c!=l+2) && (r!=k || c!=l-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == k+2 && c==l) //جلو
              {
                if ( (t2[k+2][l]== char(65)) || (t2[k+2][l]== char(67))|| (t2[k+2][l]== char(68)) )
                {
                  if ( (t2[k+4][l]== char(65)) || (t2[k+4][l]== char(67))|| (t2[k+4][l]== char(68)) )
                  {
                    if ( (t2[k+6][l]== char(65)) || (t2[k+6][l]== char(67))|| (t2[k+6][l]== char(68)) )
                      {
                         r=k+8;
                      }
                     else
                     {
                        r=k+6;
                     }
                  }
                    else
                    {
                       r=k+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == k && c==l+2) // راست
              {
                if ( (t2[k][l+2]== char(65)) || (t2[k][l+2]== char(67))|| (t2[k][l+2]== char(68)) )
                {
                  if ( (t2[k][l+4]== char(65)) || (t2[k][l+4]== char(67))|| (t2[k][l+4]== char(68)))
                  {
                    if ( (t2[k][l+6]== char(65)) || (t2[k][l+6]== char(67))|| (t2[k][l+6]== char(68)) )
                      {
                         c=l+8;
                      }
                     else
                    {
                      c=l+6;
                    }
                  }
                    else
                    {
                       c=l+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == k && c==l-2)  // چپ
              {
                if ( (t2[k][l-2]== char(65)) || (t2[k][l-2]== char(67))|| (t2[k][l-2]== char(68)) )
                {
                  if ( (t2[k][l-4]== char(65)) || (t2[k][l-4]== char(67))|| (t2[k][l-4]== char(68)))
                  {
                    if ( (t2[k][l-6]== char(65)) || (t2[k][l-6]== char(67))|| (t2[k][l-6]== char(68)) )
                      {
                         c=l-8;
                      }
                     else
                    {
                      c=l-6;
                    }
                  }
                    else
                    {
                       c=l-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == k-2 && c==l) //عقب
              {
                if ( (t2[k-2][l]== char(65)) || (t2[k-2][l]== char(67))|| (t2[k-2][l]== char(68)) )
                {
                  if ( (t2[k-4][l]== char(65)) || (t2[k-4][l]== char(67))|| (t2[k-4][l]== char(68)))
                  {
                    if ( (t2[k-6][l]== char(65)) || (t2[k-6][l]== char(67))|| (t2[k-6][l]== char(68)) )
                      {
                         r=k-8;
                      }
                     else
                    {
                      r=k-6;
                    }
                  }
                    else
                    {
                       r=k-4;
                    }
                }
              }
/////////////////////////////////////////

                k=r;
                l=c;
           }
        }
    }
        ///////////////////////////////////////پایان دستورات مربوط به حرکت مهره دوم نفر اول (B)
        if(type_of_movement == 1) // pawn
        {
            if(which_pawn == 1) // مهره A
            {
                if (aval1 == true)
                 {
                    x1 = r ; // برای داشتن ادرس مهره
                    y1 = c ;
                    z1 = t2 [8][0] ;
                    t2 [8][0] = t2 [r][c] ;
                    t2 [r][c] = z1 ;
                    aval1 = false  ;
                 }
                else
                {
                   z1 = t2 [x1][y1] ;
                   t2 [x1] [y1] = t2 [r][c] ;
                   t2 [r][c] = z1 ;
                   x1 = r ;// اپدیت ادرس مهره
                   y1 = c ;
                }
            }

            else if(which_pawn == 2) // مهره B
            {
                if (aval2 == true)
                 {
                    x2 = r ; // برای داشتن ادرس مهره
                    y2 = c ;
                    z2 = t2 [hh1][0] ;
                    t2 [hh1][0] = t2 [r][c] ;
                    t2 [r][c] = z2 ;
                    aval2 = false  ;
                 }
                else
                {
                   z2 = t2 [x2][y2] ;
                   t2 [x2] [y2] = t2 [r][c] ;
                   t2 [r][c] = z2 ;
                   x2 = r ;// اپدیت ادرس مهره
                   y2 = c ;
                }
            }
            system("cls"); // پاک کردن صفحه
            print_gametable (t2) ;
            if(n == 16 && l == 16)
            {
                set_color(10) ;
                cout<<"\aPlayer number one is the winner :D"<<endl;
                set_color(7) ;
                break ;
            }
        }

        else if(type_of_movement == 2) // wall
        {
          if(wall_model == 1) //دیوار افقی
          {
              t2 [r][c] = 61 ;
              t2 [r][c + 1] = 61 ;
              t2 [r][c2] = 61 ;
              system("cls") ;
              print_gametable (t2) ;
          }
          else // wall_model == 2 , دیوار عمودی
          {
              t2 [r][c] = 33 ;
              t2 [r + 1][c] = 33 ;
              t2 [r2][c] = 33 ;
              system("cls") ;
              print_gametable (t2) ;
          }
        }
        p++;

  }



    if(p == 2)///////// بازیکن دوم
    {
        cout <<"it's the turn of player number 2"<<endl;
        int type_of_movement , wall_model ;
        type_of_movement = enter_type_of_movement () ;
        if(type_of_movement == 2)
       {
            if ( divar2 > 9 )
             {
               cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
               type_of_movement = 1 ;
               nn2=1;
             }

           if ( divar2 <= 9 && nn2==0)
            {
          wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

           if(wall_model == 1) // تابع
          {
             int a1 = 1 , a2 = 2 , a3 = 3 ;
             r = Horizontal_wall (a1) ;
             c = Horizontal_wall  (a2) ;
             c2 = Horizontal_wall (a3) ;
          }

          else // wall_model == 2
          {
              int b1 = 1 , b2 = 2 , b3 = 3 ;
              r = Vertical_wall (b1) ;
              r2 = Vertical_wall (b2) ;
              c =  Vertical_wall (b3) ;
          }
          divar2 ++ ;
           }
       }

       if(type_of_movement == 1)
       {
           cout<<"Which pawn do you want to move?"<<endl
           <<"Enter the number:  1)C   2) D";
           cin >> which_pawn ; // برای اینکه هر دفعه بازیکن کدام مهره را میخواد تکان بدهد
           if (which_pawn == 1) // تکان دادن مهره C
           {
               cout << "Enter the number of row :" ;
               cin >> r ;
               while(r % 2 != 0 )
               {
                   cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                   cin >> r;
               }
               cout << "Enter the number of column:" ;
               cin >> c ;
               while(c % 2 != 0)
               {
                   cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                   cin >> c;
               }

               if (aval7 == true)
                {
                    while (((r!=10 || c!=16) && (r!=8 || c!=14) && (r!=6 || c!=16))    ||    ((t2[8][15]== char(33)) && (r==8 && c==14)) || ((t2[9][16]==char(61)) && (r==10 && c==16)) || ((t2[7][16]== char(61)) && (r==6 && c==16) ))
                     {
                        if(((r!=10 || c!=16) && (r!=8 || c!=14) && (r!=6 || c!=16)))
                        {
                            cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                        }
                        if( ((t2[8][15]== char(33)) && (r==8 && c==14)) || ((t2[9][16]==char(61)) && (r==10 && c==16)) || ((t2[7][16]== char(61)) && (r==6 && c==16) ))
                        {
                            cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                        }
                         cout << "Enter the number of row :" ;
                         cin >> r ;
                           while(r % 2 != 0 )
                         {
                               cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                               cin >> r;
                         }
                             cout << "Enter the number of column:" ;
                             cin >> c ;
                            while(c % 2 != 0)
                          {
                              cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                              cin >> c;
                          }

                       }
                        f = r;
                        g = c;
                   aval7 = false  ;
                  }

               else
                {

                   while(((r!=f+2 || c!=g) && (r!=f-2 || c!=g) && (r!=f || c!=g+2) && (r!=f || c!=g-2))   ||   (((t2[f+1][g]==char(61)) && (r==f+2 && c==g)) || ((t2[f - 1][g]== char(61)) && (r==f-2 && c==g)) || ((t2[f][g+ 1]== char(33)) && (r==f && c==g+2)) || ((t2[f][g- 1]== char(33)) && (r==f && c==g-2))))
                    {
                       if( ((r==f+2 && c==g) && (t2[f+ 1][g]==char(61))) || ((r==f-2 && c==g) && (t2[f - 1][g]== char(61)))|| ((r==f && c==g-2) && (t2[f][g- 1]== char(33))) || ((t2[f][g+ 1]== char(33)) && (r==f && c==g+2)) )
                          {
                            cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                          }
                             if ((r!=f+2 || c!=g) && (r!=f-2 || c!=g) && (r!=f || c!=g+2) && (r!=f || c!=g-2) )
                           {
                            cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                           }
                       cout << "Enter the number of row :" ;
                       cin >> r ;
                         while(r % 2 != 0 )
                       {
                             cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                             cin >> r;
                       }
                           cout << "Enter the number of column:" ;
                           cin >> c ;
                          while(c % 2 != 0)
                        {
                            cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                            cin >> c;
                        }
                   }
/////////////////////////////////
                   if (r == f+2 && c==g) //جلو
                   {
                     if ( (t2[f+2][g]== char(65)) || (t2[f+2][g]== char(66))|| (t2[f+2][g]== char(68)) )
                     {
                       if ( (t2[f+4][g]== char(65)) || (t2[f+4][g]== char(66))|| (t2[f+4][g]== char(68)) )
                       {
                         if ( (t2[f+6][g]== char(65)) || (t2[f+6][g]== char(66))|| (t2[f+6][g]== char(68)) )
                           {
                              r=f+8;
                           }
                          else
                          {
                             r=f+6;
                          }
                       }
                         else
                         {
                            r=f+4;
                         }
                     }
                   }
 /////////////////////////////////////////////
                if (r == m && c==n+2) // راست
              {
                if ( (t2[f][g+2]== char(65)) || (t2[f][g+2]== char(66))|| (t2[f][g+2]== char(68)) )
                {
                  if ( (t2[f][g+4]== char(65)) || (t2[f][g+4]== char(66))|| (t2[f][g+4]== char(68)))
                  {
                    if ( (t2[f][g+6]== char(65)) || (t2[f][g+6]== char(66))|| (t2[f][g+6]== char(68)) )
                      {
                         c=g+8;
                      }
                     else
                    {
                      c=g+6;
                    }
                  }
                    else
                    {
                       c=g+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == f && c==g-2)  // چپ
              {
                if ( (t2[f][g-2]== char(65)) || (t2[f][g-2]== char(66))|| (t2[f][g-2]== char(68)) )
                {
                  if ( (t2[f][g-4]== char(65)) || (t2[f][g-4]== char(66))|| (t2[f][g-4]== char(68)))
                  {
                    if ( (t2[f][g-6]== char(65)) || (t2[f][g-6]== char(66))|| (t2[f][g-6]== char(68)) )
                      {
                         c=g-8;
                      }
                     else
                    {
                      c=g-6;
                    }
                  }
                    else
                    {
                       c=g-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == f-2 && c==g) //عقب
              {
                if ( (t2[f-2][g]== char(65)) || (t2[f-2][g]== char(66))|| (t2[f-2][g]== char(68)) )
                {
                  if ( (t2[f-4][g]== char(65)) || (t2[f-4][g]== char(66))|| (t2[f-4][g]== char(68)))
                  {
                    if ( (t2[f-6][g]== char(65)) || (t2[f-6][g]== char(66))|| (t2[f-6][g]== char(68)) )
                      {
                         r=f-8;
                      }
                     else
                    {
                      r=f-6;
                    }
                  }
                    else
                    {
                       r=f-4;
                    }
                }
              }
/////////////////////////////////////////

                f=r;
                g=c;
           }
      }
/////////////////////////////////////////////////// پایان دستورات مربوط به حرکت مهره اول نفر دوم   C
      if (which_pawn == 2) // تکان دادن مهره D
           {
               cout << "Enter the number of row :" ;
               cin >> r ;
               while(r % 2 != 0 )
               {
                   cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                   cin >> r;
               }
               cout << "Enter the number of column:" ;
               cin >> c ;
               while(c % 2 != 0)
               {
                   cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                   cin >> c;
               }

                if (aval8 == true)
        {
            while(  ((r!=hh2 -2 || c!=16) && (r!=hh2+2 || c!=16) && (r!=hh2 || c!=14))    ||    (((t2[hh2-1][16]== char(61)) && (r==hh2-2 && c==16)) || ((t2[hh2+1][16]==char(61)) && (r==hh2+2 && c==16)) || ((t2[hh2][15]== char(33)) && (r==hh2 && c==14))))
             {
                if(  ((r!=hh2 -2 || c!=16) && (r!=hh2+2 || c!=16) && (r!=hh2 || c!=14))  )
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if(  ((t2[hh2-1][16]== char(61)) && (r==hh2-2 && c==16)) || ((t2[hh2+1][16]==char(61)) && (r==hh2+2 && c==16)) || ((t2[hh2][15]== char(33)) && (r==hh2 && c==14))  )
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                 z = r;
                 w = c;
           aval8 = false  ;
          }
             else
          {
             while(((r!=z+2 || c!=w) && (r!=z-2 || c!=w) && (r!=z || c!=w+2) && (r!=z || c!=w-2))   ||   (((t2[z+1][w]==char(61)) && (r==z+2 && c==w)) || ((t2[z - 1][w]== char(61)) && (r==z-2 && c==w)) || ((t2[z][w+ 1]== char(33)) && (r==z && c==w+2)) || ((t2[z][w- 1]== char(33)) && (r==z && c==w-2))))
              {
                 if( ((r==z+2 && c==w) && (t2[z+ 1][w]==char(61))) || ((r==z-2 && c==w) && (t2[z - 1][w]== char(61)))|| ((r==z && c==w-2) && (t2[z][w- 1]== char(33))) || ((t2[z][w+ 1]== char(33)) && (r==z && c==w+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=z+2 || c!=w) && (r!=z-2 || c!=w) && (r!=z || c!=w+2) && (r!=z || c!=w-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == z+2 && c==w) //جلو
              {
                if ( (t2[z+2][w]== char(66)) || (t2[z+2][w]== char(67))|| (t2[z+2][w]== char(65)) )
                {
                  if ( (t2[z+4][w]== char(66)) || (t2[z+4][w]== char(67))|| (t2[z+4][w]== char(65)) )
                  {
                    if ( (t2[z+6][w]== char(66)) || (t2[z+6][w]== char(67))|| (t2[z+6][w]== char(65)) )
                      {
                         r=z+8;
                      }
                     else
                     {
                        r=z+6;
                     }
                  }
                    else
                    {
                       r=z+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == z && c==w+2) // راست
              {
                if ( (t2[z][w+2]== char(66)) || (t2[z][w+2]== char(67))|| (t2[z][w+2]== char(65)) )
                {
                  if ( (t2[z][w+4]== char(66)) || (t2[z][w+4]== char(67))|| (t2[z][w+4]== char(65)))
                  {
                    if ( (t2[z][w+6]== char(66)) || (t2[z][w+6]== char(67))|| (t2[z][w+6]== char(65)) )
                      {
                         c=w+8;
                      }
                     else
                    {
                      c=w+6;
                    }
                  }
                    else
                    {
                       c=w+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == z && c==w-2)  // چپ
              {
                if ( (t2[z][w-2]== char(66)) || (t2[z][w-2]== char(67))|| (t2[z][w-2]== char(65)) )
                {
                  if ( (t2[z][w-4]== char(66)) || (t2[z][w-4]== char(67))|| (t2[z][w-4]== char(65)))
                  {
                    if ( (t2[z][w-6]== char(66)) || (t2[z][w-6]== char(67))|| (t2[z][w-6]== char(65)) )
                      {
                         c=w-8;
                      }
                     else
                    {
                      c=w-6;
                    }
                  }
                    else
                    {
                       c=w-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == z-2 && c==w ) //عقب
              {
                if ( (t2[z-2][w]== char(66)) || (t2[z-2][w]== char(67))|| (t2[z-2][w]== char(65)) )
                {
                  if ( (t2[z-4][w]== char(66)) || (t2[z-4][w]== char(67))|| (t2[z-4][w]== char(65)))
                  {
                    if ( (t2[z-6][w]== char(66)) || (t2[z-6][w]== char(67))|| (t2[z-6][w]== char(65)) )
                      {
                         r=z-8;
                      }
                     else
                    {
                      r=z-6;
                    }
                  }
                    else
                    {
                       r=z-4;
                    }
                }
              }
/////////////////////////////////////////

                z=r;
                w=c;
           }
       }
    }
             ///////////////////////////////////////    پایان دستورات مربوط به حرکت مهره دوم نفر دوم (D)
            if(type_of_movement == 1) // pawn
          {
            if(which_pawn == 1) // مهره  C
            {
                if (aval3 == true)
                 {
                    x3 = r ; // برای داشتن ادرس مهره
                    y3 = c ;
                    z3 = t2 [8][16] ;
                    t2 [8][16] = t2 [r][c] ;
                    t2 [r][c] = z3 ;
                    aval3 = false  ;
                 }
                else
                {
                   z3 = t2 [x3][y3] ;
                   t2 [x3] [y3] = t2 [r][c] ;
                   t2 [r][c] = z3 ;
                   x3 = r ;// اپدیت ادرس مهره
                   y3 = c ;
                }
            }

            else if(which_pawn == 2) // مهره D
            {
                if (aval4 == true)
                 {
                    x4 = r ; // برای داشتن ادرس مهره
                    y4 = c ;
                    z4 = t2 [hh2][16] ;
                    t2 [hh2][16] = t2 [r][c] ;
                    t2 [r][c] = z4 ;
                    aval4 = false  ;
                 }
                else
                {
                   z4 = t2 [x4][y4] ;
                   t2 [x4] [y4] = t2 [r][c] ;
                   t2 [r][c] = z4 ;
                   x4 = r ;// اپدیت ادرس مهره
                   y4 = c ;
                }
            }
            system("cls"); // پاک کردن صفحه
            print_gametable (t2) ;
            if(g == 0 && w == 0)
            {
                set_color(10) ;
                cout<<"\aPlayer number two is the winner :D"<<endl;
                set_color(7) ;
                break ;
            }
        }

        else if(type_of_movement == 2) // wall
        {
          if(wall_model == 1) //دیوار افقی
          {
              t2 [r][c] = 61 ;
              t2 [r][c + 1] = 61 ;
              t2 [r][c2] = 61 ;
              system("cls") ;
              print_gametable (t2) ;
          }
          else // wall_model == 2 , دیوار عمودی
          {
              t2 [r][c] = 33 ;
              t2 [r + 1][c] = 33 ;
              t2 [r2][c] = 33 ;
              system("cls") ;
              print_gametable (t2) ;
          }
        }
        p=1;
    }

 }
    }
    menu();
        break;

    case 3:
        error404 ();
        break;

    case 4:
        error404 ();
        break;

    case 5:
    {
    cout << "\tEnter Your Name : "<< endl;
    for(int i =0; i < 4; i++)
    {
        cout << "\t";
        cin >> name[i][500];
        cout <<"\t"<<name[i][500] <<" you are the player number " << xx <<" and your pawn is "<< (char)(65 + i)<< endl;
        xx ++;
    }
    //
    //
          int r , r2 , c , c2 ,p=1 , x1 , y1 , x2 , y2 , x3 , y3 , x4 , y4 , k , l ,divar1=0 ,nn1=0,divar2=0,nn2=0,divar3=0,nn3=0,divar4=0,nn4=0,m,n,f,g,z,w;
          bool aval1 = true , aval2 = true , aval3 = true , aval4 = true , aval5 = true , aval6 =true , aval7 = true , aval8 =true;
          char z1 , z2 , z3 , z4 ;
          char t2 [17][17] ;
          fillarr (t2) ;
          t2 [0][8] = 65 ;
          t2 [8][0] = 66 ;
          t2 [8][16] = 67 ;
          t2 [16][8] = 68 ;
          cout <<endl;
          print_gametable (t2) ;
          set_color(12) ;
      cout<<"Pay attention !!\nPlayers are not allowed to completely close the paths to reach the goal!\n"  <<endl;
          set_color(7) ;
 while ( p != 5)
 {
   if ( p==1) //player number 1 // A
   {
     cout <<"it's the turn of player number 1"<<endl;
     int type_of_movement , wall_model ;
     type_of_movement = enter_type_of_movement () ;
      if(type_of_movement == 2)
     {
          if ( divar1 > 4 )
           {
             cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
             type_of_movement = 1 ;
             nn1=1;
           }

         if ( divar1 <= 4 && nn1==0)
          {
        wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

         if(wall_model == 1) // تابع
        {
           int a1 = 1 , a2 = 2 , a3 = 3 ;
           r = Horizontal_wall (a1) ;
           c = Horizontal_wall  (a2) ;
           c2 = Horizontal_wall (a3) ;
        }

        else // wall_model == 2
        {
            int b1 = 1 , b2 = 2 , b3 = 3 ;
            r = Vertical_wall (b1) ;
            r2 = Vertical_wall (b2) ;
            c =  Vertical_wall (b3) ;
        }
        divar1 ++ ;
         }
     }
    if(type_of_movement == 1)
    {
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
       if (aval5 == true)
        {
            while (((r!=2 || c!=8) && (r!=0 || c!=10) && (r!=0 || c!=6))    ||    ((t2[0][9]== char(33)) && (r==0 && c==10)) || ((t2[1][8]==char(61)) && (r==2 && c==8)) || ((t2[0][7]== char(33)) && (r==0 && c==6) ))
             {
                if(((r!=2 || c!=8) && (r!=0 || c!=10) && (r!=0 || c!=6)))
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if( ((t2[0][9]== char(33)) && (r==0 && c==10)) || ((t2[1][8]==char(61)) && (r==2 && c==8)) || ((t2[0][7]== char(33)) && (r==0 && c==6) ))
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                k = r;
                l = c;
           aval5 = false  ;
          }
         else
          {

             while(((r!=k+2 || c!=l) && (r!=k-2 || c!=l) && (r!=k || c!=l+2) && (r!=k || c!=l-2))   ||   (((t2[k+1][l]==char(61)) && (r==k+2 && c==l)) || ((t2[k - 1][l]== char(61)) && (r==k-2 && c==l)) || ((t2[k][l+ 1]== char(33)) && (r==k && c==l+2)) || ((t2[k][l- 1]== char(33)) && (r==k && c==l-2))))
              {
                 if( ((r==k+2 && c==l) && (t2[k+ 1][l]==char(61))) || ((r==k-2 && c==l) && (t2[k - 1][l]== char(61)))|| ((r==k && c==l-2) && (t2[k][l- 1]== char(33))) || ((t2[k][l+ 1]== char(33)) && (r==k && c==l+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=k+2 || c!=l) && (r!=k-2 || c!=l) && (r!=k || c!=l+2) && (r!=k || c!=l-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == k+2 && c==l) //جلو
              {
                if ( (t2[k+2][l]== char(66)) || (t2[k+2][l]== char(67))|| (t2[k+2][l]== char(68)) ) //اگه جلوش مهره بود
                {
                   if ( (t2[k+4][l]== char(66)) || (t2[k+4][l]== char(67))|| (t2[k+4][l]== char(68)) )
                  {
                    if ( t2[k+5][l] == char(61))  //اگر بعد از مهره دیوار بود ، باید و نباید ها شماره4
                    {
                        if ( t2[k+4][l-1] == char(33) && t2[k+4][l+1] != char(33) ) // اگر فقط سمت چپ دیوار بود
                          {
                             r=k+4;
                             c=l+2;
                          }
                        if ( t2[k+4][l-1] != char(33) && t2[k+4][l+1] == char(33) ) //  اگر فقط سمت راست دیوار بود
                          {
                             r=k+4;
                             c=l-2;
                          }
                    }
                       else  if ( (t2[k+6][l]== char(66)) || (t2[k+6][l]== char(67))|| (t2[k+6][l]== char(68)) )
                      {
                         r=k+8;
                      }
                     else
                     {
                        r=k+6;
                     }
                  }
                    else
                    {
                       r=k+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == k && c==l+2) // راست
              {
                if ( (t2[k][l+2]== char(66)) || (t2[k][l+2]== char(67))|| (t2[k][l+2]== char(68)) )
                {
                  if ( (t2[k][l+4]== char(66)) || (t2[k][l+4]== char(67))|| (t2[k][l+4]== char(68)))
                  {
                    if ( (t2[k][l+6]== char(66)) || (t2[k][l+6]== char(67))|| (t2[k][l+6]== char(68)) )
                      {
                         c=l+8;
                      }
                     else
                    {
                      c=l+6;
                    }
                  }
                    else
                    {
                       c=l+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == k && c==l-2)  // چپ
              {
                if ( (t2[k][l-2]== char(66)) || (t2[k][l-2]== char(67))|| (t2[k][l-2]== char(68)) )
                {
                  if ( (t2[k][l-4]== char(66)) || (t2[k][l-4]== char(67))|| (t2[k][l-4]== char(68)))
                  {
                    if ( (t2[k][l-6]== char(66)) || (t2[k][l-6]== char(67))|| (t2[k][l-6]== char(68)) )
                      {
                         c=l-8;
                      }
                     else
                    {
                      c=l-6;
                    }
                  }
                    else
                    {
                       c=l-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == k-2 && c==l) //عقب
              {
                if ( (t2[k-2][l]== char(66)) || (t2[k-2][l]== char(67))|| (t2[k-2][l]== char(68)) )
                {
                  if ( (t2[k-4][l]== char(66)) || (t2[k-4][l]== char(67))|| (t2[k-4][l]== char(68)))
                  {
                    if ( (t2[k-6][l]== char(66)) || (t2[k-6][l]== char(67))|| (t2[k-6][l]== char(68)) )
                      {
                         r=k-8;
                      }
                     else
                    {
                      r=k-6;
                    }
                  }
                    else
                    {
                       r=k-4;
                    }
                }
              }
/////////////////////////////////////////

                k=r;
                l=c;
           }
     }

     if(type_of_movement == 1) // pawn
       {

           if (aval1 == true)
            {
               x1 = r ; // برای داشتن ادرس مهره
               y1 = c ;
               z1 = t2 [0][8] ;
               t2 [0][8] = t2 [r][c] ;
               t2 [r][c] = z1 ;
               aval1 = false  ;
            }
           else
           {
              z1 = t2 [x1][y1] ;
              t2 [x1] [y1] = t2 [r][c] ;
              t2 [r][c] = z1 ;
              x1 = r ;// اپدیت ادرس مهره
              y1 = c ;
           }
          system("cls"); // پاک کردن صفحه
          print_gametable (t2) ;
           if (r==16) //winner
              {
               set_color(10) ;
                cout<<"\aPlayer number one is the winner :D"<<endl;
                set_color(7) ;
                break ;
              }
       }
     else if(type_of_movement == 2) //  wall
     {
       if(wall_model == 1) //دیوار افقی
       {
           t2 [r][c] = 61 ;
           t2 [r][c + 1] = 61 ;
           t2 [r][c2] = 61 ;
           system("cls") ;
           print_gametable (t2) ;
       }
       else // wall_model == 2 , دیوار عمودی
       {
           t2 [r][c] = 33 ;
           t2 [r + 1][c] = 33 ;
           t2 [r2][c] = 33 ;
           system("cls") ;
           print_gametable (t2) ;
       }
     }
     p++;
   }
   if ( p==2) //player number 2 // B
   {
     cout <<"it's the turn of player number 2"<<endl;
     int type_of_movement , wall_model ;
     type_of_movement = enter_type_of_movement () ;
     if(type_of_movement == 2)
     {
          if ( divar2 > 4 )
           {
             cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
             type_of_movement = 1 ;
             nn2=1;
           }

         if ( divar2 <= 4 && nn2==0)
          {
        wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

         if(wall_model == 1) // تابع
        {
           int a1 = 1 , a2 = 2 , a3 = 3 ;
           r = Horizontal_wall (a1) ;
           c = Horizontal_wall  (a2) ;
           c2 = Horizontal_wall (a3) ;
        }

        else // wall_model == 2
        {
            int b1 = 1 , b2 = 2 , b3 = 3 ;
            r = Vertical_wall (b1) ;
            r2 = Vertical_wall (b2) ;
            c =  Vertical_wall (b3) ;
        }
        divar2 ++ ;
         }
     }
          if(type_of_movement == 1)
    {
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
       if (aval6 == true)
        {
            while (((r!=10 || c!=0) && (r!=8 || c!=2) && (r!=6 || c!=0))    ||    ((t2[8][1]== char(33)) && (r==8 && c==2)) || ((t2[9][0]==char(61)) && (r==10 && c==0)) || ((t2[7][0]== char(61)) && (r==6 && c==0) ))
             {
                if(((r!=10 || c!=0) && (r!=8 || c!=2) && (r!=6 || c!=0)))
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if( ((t2[8][1]== char(33)) && (r==8 && c==2)) || ((t2[9][0]==char(61)) && (r==10 && c==0)) || ((t2[7][0]== char(61)) && (r==6 && c==0) ))
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                m = r;
                n = c;
           aval6 = false  ;
          }
         else
          {

             while(((r!=m+2 || c!=n) && (r!=m-2 || c!=n) && (r!=m || c!=n+2) && (r!=m || c!=n-2))   ||   (((t2[m+1][n]==char(61)) && (r==m+2 && c==n)) || ((t2[m - 1][n]== char(61)) && (r==m-2 && c==n)) || ((t2[m][n+ 1]== char(33)) && (r==m && c==n+2)) || ((t2[m][n- 1]== char(33)) && (r==m && c==n-2))))
              {
                 if( ((r==m+2 && c==n) && (t2[m+ 1][n]==char(61))) || ((r==m-2 && c==n) && (t2[m - 1][n]== char(61)))|| ((r==m && c==n-2) && (t2[m][n- 1]== char(33))) || ((t2[m][n+ 1]== char(33)) && (r==m && c==n+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=m+2 || c!=n) && (r!=m-2 || c!=n) && (r!=m || c!=n+2) && (r!=m || c!=n-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == m+2 && c==n) //جلو
              {
                if ( (t2[m+2][n]== char(65)) || (t2[m+2][n]== char(67))|| (t2[m+2][n]== char(68)) )
                {
                  if ( (t2[m+4][n]== char(65)) || (t2[m+4][n]== char(67))|| (t2[m+4][n]== char(68)) )
                  {
                    if ( (t2[m+6][n]== char(65)) || (t2[m+6][n]== char(67))|| (t2[m+6][n]== char(68)) )
                      {
                         r=m+8;
                      }
                     else
                     {
                        r=m+6;
                     }
                  }
                    else
                    {
                       r=m+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == m && c==n+2) // راست
              {
                if ( (t2[m][n+2]== char(65)) || (t2[m][n+2]== char(67))|| (t2[m][n+2]== char(68)) )
                {
                  if ( (t2[m][n+4]== char(65)) || (t2[m][n+4]== char(67))|| (t2[m][n+4]== char(68)))
                  {
                    if ( (t2[m][n+6]== char(65)) || (t2[m][n+6]== char(67))|| (t2[m][n+6]== char(68)) )
                      {
                         c=n+8;
                      }
                     else
                    {
                      c=n+6;
                    }
                  }
                    else
                    {
                       c=n+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == m && c==n-2)  // چپ
              {
                if ( (t2[m][n-2]== char(65)) || (t2[m][n-2]== char(67))|| (t2[m][n-2]== char(68)) )
                {
                  if ( (t2[m][n-4]== char(65)) || (t2[m][n-4]== char(67))|| (t2[m][n-4]== char(68)))
                  {
                    if ( (t2[m][n-6]== char(65)) || (t2[m][n-6]== char(67))|| (t2[m][n-6]== char(68)) )
                      {
                         c=n-8;
                      }
                     else
                    {
                      c=n-6;
                    }
                  }
                    else
                    {
                       c=n-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == m-2 && c==n) //عقب
              {
                if ( (t2[m-2][n]== char(65)) || (t2[m-2][n]== char(67))|| (t2[m-2][n]== char(68)) )
                {
                  if ( (t2[m-4][n]== char(65)) || (t2[m-4][n]== char(67))|| (t2[m-4][n]== char(68)))
                  {
                    if ( (t2[m-6][n]== char(65)) || (t2[m-6][n]== char(67))|| (t2[m-6][n]== char(68)) )
                      {
                         r=m-8;
                      }
                     else
                    {
                      r=m-6;
                    }
                  }
                    else
                    {
                       r=m-4;
                    }
                }
              }
/////////////////////////////////////////

                m=r;
                n=c;
           }
     }

     if(type_of_movement == 1) // pawn
       {
         if (aval2 == true)
          {
             x2 = r ; // برای داشتن ادرس مهره
             y2 = c ;
             z2 = t2 [8][0] ;
             t2 [8][0] = t2 [r][c] ;
             t2 [r][c] = z2 ;
             aval2 = false  ;
          }
         else
         {
            z2 = t2 [x2][y2] ;
            t2 [x2] [y2] = t2 [r][c] ;
            t2 [r][c] = z2 ;
            x2 = r ;// اپدیت ادرس مهره
            y2 = c ;
         }

          system("cls"); // پاک کردن صفحه
          print_gametable (t2) ;

          if (c==16) //winner
              {
              set_color(10) ;
                cout<<"\aPlayer number two is the winner :D"<<endl;
                set_color(7) ;
                break ;
              }
       }
     else if(type_of_movement == 2) // wall
     {
       if(wall_model == 1) //دیوار افقی
       {
           t2 [r][c] = 61 ;
           t2 [r][c + 1] = 61 ;
           t2 [r][c2] = 61 ;
           system("cls") ;
           print_gametable (t2) ;
       }
       else // wall_model == 2 , دیوار عمودی
       {
           t2 [r][c] = 33 ;
           t2 [r + 1][c] = 33 ;
           t2 [r2][c] = 33 ;
           system("cls") ;
           print_gametable (t2) ;
       }
     }
     p++;
   }
   if ( p==3) //player number 3 // C
   {
       cout <<"it's the turn of player number 3"<<endl;
      int type_of_movement , wall_model ;
     type_of_movement = enter_type_of_movement () ;
     if(type_of_movement == 2)
     {
          if ( divar3 > 4 )
           {
             cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
             type_of_movement = 1 ;
             nn3=1;
           }

         if ( divar3 <= 4 && nn3==0)
          {
        wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

         if(wall_model == 1) // تابع
        {
           int a1 = 1 , a2 = 2 , a3 = 3 ;
           r = Horizontal_wall (a1) ;
           c = Horizontal_wall  (a2) ;
           c2 = Horizontal_wall (a3) ;
        }

        else // wall_model == 2
        {
            int b1 = 1 , b2 = 2 , b3 = 3 ;
            r = Vertical_wall (b1) ;
            r2 = Vertical_wall (b2) ;
            c =  Vertical_wall (b3) ;
        }
        divar3 ++ ;
         }
     }
               if(type_of_movement == 1)
    {
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
       if (aval7 == true)
        {
            while (((r!=10 || c!=16) && (r!=8 || c!=14) && (r!=6 || c!=16))    ||    ((t2[8][15]== char(33)) && (r==8 && c==14)) || ((t2[9][16]==char(61)) && (r==10 && c==16)) || ((t2[7][16]== char(61)) && (r==6 && c==16) ))
             {
                if(((r!=10 || c!=16) && (r!=8 || c!=14) && (r!=6 || c!=16)))
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if( ((t2[8][15]== char(33)) && (r==8 && c==14)) || ((t2[9][16]==char(61)) && (r==10 && c==16)) || ((t2[7][16]== char(61)) && (r==6 && c==16) ))
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                f = r;
                g = c;
           aval7 = false  ;
          }
         else
          {

             while(((r!=f+2 || c!=g) && (r!=f-2 || c!=g) && (r!=f || c!=g+2) && (r!=f || c!=g-2))   ||   (((t2[f+1][g]==char(61)) && (r==f+2 && c==g)) || ((t2[f - 1][g]== char(61)) && (r==f-2 && c==g)) || ((t2[f][g+ 1]== char(33)) && (r==f && c==g+2)) || ((t2[f][g- 1]== char(33)) && (r==f && c==g-2))))
              {
                 if( ((r==f+2 && c==g) && (t2[f+ 1][g]==char(61))) || ((r==f-2 && c==g) && (t2[f - 1][g]== char(61)))|| ((r==f && c==g-2) && (t2[f][g- 1]== char(33))) || ((t2[f][g+ 1]== char(33)) && (r==f && c==g+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=f+2 || c!=g) && (r!=f-2 || c!=g) && (r!=f || c!=g+2) && (r!=f || c!=g-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == f+2 && c==g) //جلو
              {
                if ( (t2[f+2][g]== char(65)) || (t2[f+2][g]== char(66))|| (t2[f+2][g]== char(68)) )
                {
                  if ( (t2[f+4][g]== char(65)) || (t2[f+4][g]== char(66))|| (t2[f+4][g]== char(68)) )
                  {
                    if ( (t2[f+6][g]== char(65)) || (t2[f+6][g]== char(66))|| (t2[f+6][g]== char(68)) )
                      {
                         r=f+8;
                      }
                     else
                     {
                        r=f+6;
                     }
                  }
                    else
                    {
                       r=f+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == m && c==n+2) // راست
              {
                if ( (t2[f][g+2]== char(65)) || (t2[f][g+2]== char(66))|| (t2[f][g+2]== char(68)) )
                {
                  if ( (t2[f][g+4]== char(65)) || (t2[f][g+4]== char(66))|| (t2[f][g+4]== char(68)))
                  {
                    if ( (t2[f][g+6]== char(65)) || (t2[f][g+6]== char(66))|| (t2[f][g+6]== char(68)) )
                      {
                         c=g+8;
                      }
                     else
                    {
                      c=g+6;
                    }
                  }
                    else
                    {
                       c=g+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == f && c==g-2)  // چپ
              {
                if ( (t2[f][g-2]== char(65)) || (t2[f][g-2]== char(66))|| (t2[f][g-2]== char(68)) )
                {
                  if ( (t2[f][g-4]== char(65)) || (t2[f][g-4]== char(66))|| (t2[f][g-4]== char(68)))
                  {
                    if ( (t2[f][g-6]== char(65)) || (t2[f][g-6]== char(66))|| (t2[f][g-6]== char(68)) )
                      {
                         c=g-8;
                      }
                     else
                    {
                      c=g-6;
                    }
                  }
                    else
                    {
                       c=g-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == f-2 && c==g) //عقب
              {
                if ( (t2[f-2][g]== char(65)) || (t2[f-2][g]== char(66))|| (t2[f-2][g]== char(68)) )
                {
                  if ( (t2[f-4][g]== char(65)) || (t2[f-4][g]== char(66))|| (t2[f-4][g]== char(68)))
                  {
                    if ( (t2[f-6][g]== char(65)) || (t2[f-6][g]== char(66))|| (t2[f-6][g]== char(68)) )
                      {
                         r=f-8;
                      }
                     else
                    {
                      r=f-6;
                    }
                  }
                    else
                    {
                       r=f-4;
                    }
                }
              }
/////////////////////////////////////////

                f=r;
                g=c;
           }
     }


     if(type_of_movement == 1) // pawn
       {
         if (aval3 == true)
          {
             x3 = r ; // برای داشتن ادرس مهره
             y3 = c ;
             z3 = t2 [8][16] ;
             t2 [8][16] = t2 [r][c] ;
             t2 [r][c] = z3 ;
             aval3 = false  ;
          }
         else
         {
            z3 = t2 [x3][y3] ;
            t2 [x3] [y3] = t2 [r][c] ;
            t2 [r][c] = z3 ;
            x3 = r ;// اپدیت ادرس مهره
            y3 = c ;
         }
          system("cls"); // پاک کردن صفحه
          print_gametable (t2) ;

          if (c==0) //winner
              {
              set_color(10) ;
                cout<<"\aPlayer number three is the winner :D"<<endl;
                set_color(7) ;
                break ;
              }
       }
     else if(type_of_movement == 2) // wall
     {
       if(wall_model == 1) //دیوار افقی
       {
           t2 [r][c] = 61 ;
           t2 [r][c + 1] = 61 ;
           t2 [r][c2] = 61 ;
           system("cls") ;
           print_gametable (t2) ;
       }
       else // wall_model == 2 , دیوار عمودی
       {
           t2 [r][c] = 33 ;
           t2 [r + 1][c] = 33 ;
           t2 [r2][c] = 33 ;
           system("cls") ;
           print_gametable (t2) ;
       }
     }
     p++;
   }
   if ( p==4) //player number 4 // D
   {
     cout <<"it's the turn of player number 4"<<endl;
     int type_of_movement , wall_model ;
     type_of_movement = enter_type_of_movement () ;
     if(type_of_movement == 2)
     {
          if ( divar4 > 4 )
           {
             cout<<"\aYou don't have wall anymore !  please move your pawn"<<endl;
             type_of_movement = 1 ;
             nn4=1;
           }

         if ( divar4 <= 4 && nn4==0)
          {
        wall_model = enter_wall_model () ; // چاپ عبارات برای انتخاب مدل دیوار

         if(wall_model == 1) // تابع
        {
           int a1 = 1 , a2 = 2 , a3 = 3 ;
           r = Horizontal_wall (a1) ;
           c = Horizontal_wall  (a2) ;
           c2 = Horizontal_wall (a3) ;
        }

        else // wall_model == 2
        {
            int b1 = 1 , b2 = 2 , b3 = 3 ;
            r = Vertical_wall (b1) ;
            r2 = Vertical_wall (b2) ;
            c =  Vertical_wall (b3) ;
        }
        divar4 ++ ;
         }
     }
    if(type_of_movement == 1)
    {
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
       if (aval8 == true)
        {
            while (((r!=14 || c!=8) && (r!=16 || c!=10) && (r!=16 || c!=6))    ||    ((t2[16][9]== char(33)) && (r==16 && c==10)) || ((t2[15][8]==char(61)) && (r==14 && c==8)) || ((t2[16][7]== char(33)) && (r==16 && c==6) ))
             {
                if(((r!=14 || c!=8) && (r!=16 || c!=10) && (r!=16 || c!=6)))
                {
                    cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                }
                if( ((t2[16][9]== char(33)) && (r==16 && c==10)) || ((t2[15][8]==char(61)) && (r==14 && c==8)) || ((t2[16][7]== char(33)) && (r==16 && c==6) ))
                {
                    cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Plese Enter the number again"<<endl;
                      cin >> c;
                  }

               }
                z = r;
                w = c;
           aval8 = false  ;
          }
         else
          {

             while(((r!=z+2 || c!=w) && (r!=z-2 || c!=w) && (r!=z || c!=w+2) && (r!=z || c!=w-2))   ||   (((t2[z+1][w]==char(61)) && (r==z+2 && c==w)) || ((t2[z - 1][w]== char(61)) && (r==z-2 && c==w)) || ((t2[z][w+ 1]== char(33)) && (r==z && c==w+2)) || ((t2[z][w- 1]== char(33)) && (r==z && c==w-2))))
              {
                 if( ((r==z+2 && c==w) && (t2[z+ 1][w]==char(61))) || ((r==z-2 && c==w) && (t2[z - 1][w]== char(61)))|| ((r==z && c==w-2) && (t2[z][w- 1]== char(33))) || ((t2[z][w+ 1]== char(33)) && (r==z && c==w+2)) )
                    {
                      cout<<"\aThe path is blocked !"<<endl; //مسیر حرکت مسدود شده
                    }
                       if ((r!=z+2 || c!=w) && (r!=z-2 || c!=w) && (r!=z || c!=w+2) && (r!=z || c!=w-2) )
                     {
                      cout<<"\aMovement is not allowed !"<<endl; //حرکت مجاز نیست
                     }
                 cout << "Enter the number of row :" ;
                 cin >> r ;
                   while(r % 2 != 0 )
                 {
                       cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                       cin >> r;
                 }
                     cout << "Enter the number of column:" ;
                     cin >> c ;
                    while(c % 2 != 0)
                  {
                      cout<<"\aThe input number must be even.Please Enter the number again"<<endl;
                      cin >> c;
                  }
             }
//////////////////////////////////////////////////
              if (r == z+2 && c==w) //جلو
              {
                if ( (t2[z+2][w]== char(66)) || (t2[z+2][w]== char(67))|| (t2[z+2][w]== char(65)) )
                {
                  if ( (t2[z+4][w]== char(66)) || (t2[z+4][w]== char(67))|| (t2[z+4][w]== char(65)) )
                  {
                    if ( (t2[z+6][w]== char(66)) || (t2[z+6][w]== char(67))|| (t2[z+6][w]== char(65)) )
                      {
                         r=z+8;
                      }
                     else
                     {
                        r=z+6;
                     }
                  }
                    else
                    {
                       r=z+4;
                    }
                }
              }
/////////////////////////////////////////////
                if (r == z && c==w+2) // راست
              {
                if ( (t2[z][w+2]== char(66)) || (t2[z][w+2]== char(67))|| (t2[z][w+2]== char(65)) )
                {
                  if ( (t2[z][w+4]== char(66)) || (t2[z][w+4]== char(67))|| (t2[z][w+4]== char(65)))
                  {
                    if ( (t2[z][w+6]== char(66)) || (t2[z][w+6]== char(67))|| (t2[z][w+6]== char(65)) )
                      {
                         c=w+8;
                      }
                     else
                    {
                      c=w+6;
                    }
                  }
                    else
                    {
                       c=w+4;
                    }
                }
              }
///////////////////////////////////////////////
                  if (r == z && c==w-2)  // چپ
              {
                if ( (t2[z][w-2]== char(66)) || (t2[z][w-2]== char(67))|| (t2[z][w-2]== char(65)) )
                {
                  if ( (t2[z][w-4]== char(66)) || (t2[z][w-4]== char(67))|| (t2[z][w-4]== char(65)))
                  {
                    if ( (t2[z][w-6]== char(66)) || (t2[z][w-6]== char(67))|| (t2[z][w-6]== char(65)) )
                      {
                         c=w-8;
                      }
                     else
                    {
                      c=w-6;
                    }
                  }
                    else
                    {
                       c=w-4;
                    }
                }
              }
/////////////////////////////////////////
            if (r == z-2 && c==w ) //عقب
              {
                if ( (t2[z-2][w]== char(66)) || (t2[z-2][w]== char(67))|| (t2[z-2][w]== char(65)) )
                {
                  if ( (t2[z-4][w]== char(66)) || (t2[z-4][w]== char(67))|| (t2[z-4][w]== char(65)))
                  {
                    if ( (t2[z-6][w]== char(66)) || (t2[z-6][w]== char(67))|| (t2[z-6][w]== char(65)) )
                      {
                         r=z-8;
                      }
                     else
                    {
                      r=z-6;
                    }
                  }
                    else
                    {
                       r=z-4;
                    }
                }
              }
/////////////////////////////////////////

                z=r;
                w=c;
           }
     }


     if(type_of_movement == 1) // pawn
       {
         if (aval4 == true)
          {
             x4 = r ; // برای داشتن ادرس مهره
             y4 = c ;
             z4 = t2 [16][8] ;
             t2 [16][8] = t2 [r][c] ;
             t2 [r][c] = z4 ;
             aval4 = false  ;
          }
         else
         {
            z4 = t2 [x4][y4] ;
            t2 [x4][y4] = t2 [r][c] ;
            t2 [r][c] = z4 ;
            x4 = r ;// اپدیت ادرس مهره
            y4 = c ;
         }

          system("cls"); // پاک کردن صفحه
          print_gametable (t2) ;

          if (r==0) //winner
              {
              set_color(10) ;
                cout<<"\aPlayer number four is the winner :D"<<endl;
                set_color(7) ;
                break ;
              }
       }
     else if (type_of_movement == 2) // wall
     {
       if(wall_model == 1) //دیوار افقی
       {
           t2 [r][c] = 61 ;
           t2 [r][c + 1] = 61 ;
           t2 [r][c2] = 61 ;
           system("cls") ;
           print_gametable (t2) ;
       }
       else // wall_model == 2 , دیوار عمودی
       {
           t2 [r][c] = 33 ;
           t2 [r + 1][c] = 33 ;
           t2 [r2][c] = 33 ;
           system("cls") ;
           print_gametable (t2) ;
       }
     }
     p=1;
   }
 }

    }
    menu();
        break;
    case 6:
        error404 ();
        break;

    case 7:
        error404 ();
        break;

    case 8:
        error404 ();
        break;

    case 9 :
    {
        set_color(13) ;
        cout<<"\t1: This is just a friendly game to strengthen the mind. Keep calm :) "
            <<endl
            <<"\t2: If there is a wall behind the said pawn, the player can place his pawn to the left or the right of the other pawn!"
            <<endl
            <<"\t3: The pawns must bypass the wall. If, while you move, you face your opponent's pawn you can jump over."
            <<endl
            <<"\t4: The pawns are moved one square at a time, horizontally or vertically, forwards or backwards, never diagonal"
            <<endl;
        set_color(7) ;
    }
        break;
   default:
        cout <<":| " ;

    }

    return;
}






