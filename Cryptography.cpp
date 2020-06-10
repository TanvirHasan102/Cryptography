#include<cstdio>
#include<cctype>
#include<iostream>
#include<conio.h>

using namespace std ;

int main()
{
   char choice ;
   string strDataSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ " ;
   string strInput ;
   int n ;
   int length ;

   printf("Please, Enter a string to encrypt : ") ;
   getline(cin,strInput) ;

   printf("Please, Enter the value of n to encrypt : ") ;
   scanf("%d",&n) ;

   for(int i = 0 ; strInput[i] != '\0' ; i++)
   {
       int position = strDataSet.find(strInput[i]) ;

       if(position < 0)
       {
           strDataSet.push_back(strInput[i]) ;
       }
   }
   length = strDataSet.length() ;

   for(int i = 0 ; strInput[i] != '\0' ; i++)
   {
       int position = strDataSet.find(strInput[i]) ;
       position = ((position + n) % length);
       strInput[i] = strDataSet[position] ;
   }

   //cout << strDataSet << endl;
   cout << strInput << endl;

   printf("Do you want to decrypt it ? If yes, then press y : ") ;
   choice = toupper(getch()) ;

   switch(choice)
   {
   case 'Y' :
    {
        for(int i = 0 ; strInput[i] != '\0' ; i++)
        {
           int position = strDataSet.find(strInput[i]) ;
           position = ((position - n) % length);

           if(position < 0)
           {
               position += length ;
           }

           strInput[i] = strDataSet[position] ;
        }

        cout << strInput ;
        break ;
    }
   default:
    {
        printf("Thank you.") ;
    }
   }
}
