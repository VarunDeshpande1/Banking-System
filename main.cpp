//VARUN DESHPANDE //
//PROJECT//
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<cstring>
#include<iomanip>
#include<ctype.h>
#include "masterKey.h"
#include<conio.h>
using namespace std;
int no;
class Bank{
            unsigned long int acctNo;
            unsigned long int balance;
            char firstName[50];
            char lastName[50];
            char acctType[8];
            char passwd[50];
            char security[50];

        public:
           ///////////////////////////////////CREATE ACCOUNT////////////////////////////////////////////////
            int createAccount();
            int checkAcct(unsigned long int);                                       ///////////FUNCTION TO CREATE ACCOUNT
           ////////////////////////////////////LOG IN/////////////////////////////////////////////////////
            void logIn();                                              ///////////FUNCTION TO LOG IN
            int showMenu();                                            ///////////FUNCTION TO SHOW MENU
            void depositMoney(unsigned long int,unsigned long int n);                ///////////FUNCTION TO DEPOSIT MONEY
            void withdrawMoney(unsigned long int,unsigned long int n);               ///////////FUNCTION TO WITHDRAW MONEY
            int displayAccount();                                      ///////////FUNCTION TO DISPLAY ACCOUNT
            void modify(int);                                          ///////////FUNCTION TO MODIFY ACCOUNT
            void change();                                             ///////////FUNCTION TO MODIFY ACCOUNT
            int deleteAccount(int n);                                  ///////////FUNCTION TO DELETE ACCOUNT
            /////////////////////////////////MICELLINAOUS FUNCTIONS//////////////////////////////////////////
            int passwordcheck();                                       ///////////FUNCTION TO CHECK PASSWORD
            int securityCheck();                                       ///////////FUNCTION TO RECOVER PASSWORD
            void displayInfo();                                        ///////////FUNCTION TO DISPLAY TITLE
            void report();                                             ///////////FUNCTION TO SHOW ALL ACCOUNTS
            int getAcctNo()                                            ///////////FUNCTION TO RETURN ACCOUNT NO.
            {
                return acctNo;
            }
            int getBalance()                                           ///////////FUNCTION TO RETURN BALANCE
            {
                return balance;
            }

           ////////////////////////////////////////////////////////////////////////////////////////////////////
}customer;

void Bank::displayInfo()
{
    cout<<"====================================================\n";
    cout<<"\n\t\tBETA BANK MANAGEMENT SYSTEM\n\n";
    cout<<"====================================================\n";

}
///////////////////////////////////CREATE ACCOUNT///////////////////////////////////////////////////
int Bank::createAccount()
{
    int i=0;
    unsigned long int num;
     char password[50],ch1;
go: system("cls");
    displayInfo();
    cout<<"ENTER ACCOUNT NUMBER:";
    cin>>num;
 if(checkAcct(num))
    {
      ofstream f;
      f.open("zapatron.dat",ios::binary|ios::app);
      acctNo=num;
      cout<<"ENTER YOUR FIRST NAME:";
      cin>>firstName;
      cout<<"ENTER YOUR LAST NAME:";
      cin>>lastName;
      cout<<"ENTER YOUR PASSWORD:";
      cin.ignore();
      gets(passwd);
      lable: cout<<"ENTER YOUR PASSWORD AGAIN:";
         while(ch1!=13)
        {
            ch1=getch();
            if(ch1==13) break;
            password[i]=ch1;
            cout<<ch1;
            i++;
        }
        password[i]='\0';
         ch1=' ';
         i=0;
         if(strcmp(passwd,password)==0)
         {
            typ:
             cout<<endl<<"ENTER THE TYPE OF ACCOUNT "<<endl<<"ENTER 'C' FOR CURRENT /'S' FOR SAVINGS:";
             cin>>acctType;
             if((acctType[0]=='c'||acctType[0]=='C'||(strcmp(acctType,"current")||strcmp(acctType,"Current"))==0)||(acctType[0]=='s'||acctType[0]=='S'||(strcmp(acctType,"savings")||strcmp(acctType,"Savings"))==0))
             {
                 cout<<"ENTER THE AMOUNT TO BE DEPOSITED:";
                 cin>>balance;
                 cout<<"ENTER YOUR FAVOURITE BOOK/MOVIE/ACTOR: ";
                 cin.ignore();
                 cin.getline(security,50);
             }
             else
             {
               cout<<"ERROR!!!"<<endl;
              system("pause");
              system("cls");
              displayInfo();
              cout<<"ENTER ACCOUNT NUMBER:";
              cout<<acctNo<<endl;
              cout<<"ENTER YOUR FIRST NAME:";
              cout<<firstName<<endl;
              cout<<"ENTER YOUR LAST NAME:";
              cout<<lastName<<endl;
              cout<<"ENTER YOUR PASSWORD:";
              puts(passwd);
              cout<<"ENTER YOUR PASSWORD AGAIN:";
              puts(passwd);
              goto typ;
             }

         }
         else
         {
            system("cls");
             cout<<"ENTER ACCOUNT NUMBER: "<<acctNo<<endl;
             cout<<"ENTER YOUR NAME: "<<firstName<<endl ;
             cout<<"ENTER YOUR PASSWORD "<<passwd<<endl;
            goto lable;
         }
           f.write((char*)&customer,sizeof(customer));
           f.close();
       }
       else
       {
         cout<<"ACCOUNT ALREADY EXSISTS"<<endl<<"ENTER ANOTHER ACCOUNT NO."<<endl;
         system("pause");
         goto go;
       }

    return 0;
}
int Bank::checkAcct(unsigned long int n)
{
    ifstream f;
    f.open("zapatron.dat",ios::binary|ios::in);
      f.seekg(0,ios::beg);
      while(f.read((char*)&customer,sizeof(customer)))
        {
            if(getAcctNo()==n)
            {
                return 0;
            }
        }
        return 1;

}
////////////////////////////////////LOG IN/////////////////////////////////////////////////////
void Bank::logIn()
{
    ifstream f;
    f.open("zapatron.dat",ios::binary|ios::in);
    int acctFound=0;
    cout<<"ENTER USER ID (ACCOUNT NO.): ";
    cin>>no;
      f.seekg(0,ios::beg);
      while(f.read((char*)&customer,sizeof(customer)))
        {
            if(getAcctNo()==no)
            {
                acctFound=1;
                if(customer.passwordcheck())
                {
                    f.close();
                    showMenu();
                }
            }
        }
        f.close();

        if(!acctFound)

            cout<<"ACCOUNT DOES NOT EXIST "<<endl;

}

int Bank::showMenu()
{
    int dep,withd;
    int choice;
lable: system("cls");
        displayInfo();
        cout<<"1.DEPOSIT MONEY"<<endl;
        cout<<"2.WITHDRAW MONEY"<<endl;
        cout<<"3.DISPLAY ACCOUNT "<<endl;
        cout<<"4.MODIFY ACCOUNT"<<endl;
        cout<<"5.DELETE ACCOUNT"<<endl;
        cout<<"6.LOG OFF"<<endl;
        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;
        if(choice==1||choice==2||choice==3||choice==4||choice==5||choice==6)
        {

                switch(choice)
                    {
                        case 1: system("cls");
                                displayInfo();
                                cout<<"ENTER MONEY TO BE DEPOSITED: ";
                                cin>>dep;
                                customer.depositMoney(dep,no);
                                cout<<"MONEY IN ACCOUNT : "<<customer.getBalance()<<endl;
                                system("pause");
                                break;

                          case 2:system("cls");
                                 displayInfo();
                                 cout<<"ENTER MONEY TO BE WITHDRAWN: ";
                                 cin>>withd;
                                 customer.withdrawMoney(withd,no);
                                 cout<<"MONEY IN ACCOUNT : "<<customer.getBalance()<<endl;
                                 system("pause");
                                 break;

                         case 3: {
                                   system("cls");
                                   displayInfo();
                                   customer.displayAccount();
                                   system("pause");
                                   break;
                                 }

                        case 4: {
                                   system("cls");
                                   displayInfo();
                                   customer.modify(no);
                                   system("pause");
                                   break;
                                }
                        case 5:{
                                customer.deleteAccount(no);
                                return 0;
                                }
                                break;
                        case 6: return 0;
                        default:cout<<"WRONG NUMBER :";
                    }

        }
         goto lable;
}

void Bank::depositMoney(unsigned long int x,unsigned long int n)
{
    fstream f;
    long pos;
    f.open("zapatron.dat",ios::binary|ios::in|ios::out);
     f.seekg(0);
     while(f.read((char*)&customer,sizeof(customer)))
        {

             if(getAcctNo()==n)
             {
                 pos=f.tellg();
                 f.seekp((pos-216));
                 balance+=x;
                 f.write((char*)&customer,sizeof(customer));
                 break;
             }

        }


        f.close();

}

void Bank::withdrawMoney(unsigned long int x,unsigned long int n)
{
     fstream f;
    long pos;
    f.open("zapatron.dat",ios::binary|ios::in|ios::out);
     f.seekg(0);
     while(f.read((char*)&customer,sizeof(customer)))
        {

             if(getAcctNo()==n)
             {
                 pos=f.tellg();
                 f.seekp((pos-216));
                 balance-=x;
                 f.write((char*)&customer,sizeof(customer));
                 break;
             }

        }


        f.close();
}

int Bank ::displayAccount()
{
    cout<<"YOUR ACCOUNT NO.:"<<acctNo<<endl;
    cout<<"YOUR  FIRST NAME:";
    puts(firstName);
    cout<<"YOUR  LAST NAME:";
    puts(lastName);
    cout<<"YOUR ACCOUNT TYPE:";
    if(acctType[0]=='c'||acctType[0]=='C'||(strcmp(acctType,"current")||strcmp(acctType,"Current"))==0)
      {
          cout<<"CURRENT"<<endl;
          strcpy(acctType,"C");
      }
    else
    {
        cout<<"SAVINGS"<<endl;
        strcpy(acctType,"S");
    }
    cout<<"AMOUNT DEPOSITED:"<<balance<<endl;
    return 0;
}

void Bank::modify(int x)
{
    long pos;
    fstream f;
    f.open("zapatron.dat",ios::binary|ios::in|ios::out);
    f.seekg(0,ios::beg);
      while(f.read((char*)&customer,sizeof(customer)))
        {

             if(getAcctNo()==x)
              {
                     pos=f.tellg();
                     cout<<"ENTER NEW DETAILS:"<<endl;
                     customer.change();
                     f.seekp((pos-216));
                     f.write((char*)&customer,sizeof(customer));
                     break;

              }



    }

    f.close();
    cout<<"**********ACCOUNT MODIFIED*******"<<endl;

}
void Bank::change()
{
    int deposit;
    char newName[50],type[8],choice,ch,newpassword[50];
    customer.displayAccount();
    cout<<"DO YOU WANT TO CHANGE PASSWORD(Y/N)";
    cin>>choice;
    if(choice=='y')
    if(customer.passwordcheck())
        {

            cout<<endl<<"ENTER NEW PASSWORD(ENTER '.' TO RETAIN OLD ONE):";
            cin>>newpassword;
            strcpy(passwd,newpassword);
        }
             cout<<endl<<"MODIFY ACCOUNT HOLDER'S FIRST NAME(ENTER '.' TO RETAIN OLD ONE): ";
             cin>>newName;
             if(strcmp(newName,".")!=0)
             strcpy(firstName,newName);
             cout<<endl<<"MODIFY ACCOUNT HOLDER'S LAST NAME(ENTER '.' TO RETAIN OLD ONE): ";
             cin>>newName;
             if(strcmp(newName,".")!=0)
             strcpy(lastName,newName);
      typ:       cout<<endl<<"MODIFY Modify the Type Of Account(ENTER '.' TO RETAIN OLD ONE):";
             cin>>type;
             if(type[0]!='.')
             {
                if((type[0]=='c'||type[0]=='C'||(strcmp(type,"current")||strcmp(type,"Current"))==0)||(type[0]=='s'||type[0]=='S'||(strcmp(type,"savings")||strcmp(type,"Savings"))==0))
                strcpy(acctType,type);

              else
              {
               cout<<"ERROR!!!"<<endl;
              system("pause");
              system("cls");
              displayInfo();
              cout<<"DO YOU WANT TO CHANGE PASSWORD(Y/N)";
              cout<<choice<<endl;
              cout<<endl<<"ENTER NEW PASSWORD(ENTER '.' TO RETAIN OLD ONE):";
              puts(passwd);
              cout<<endl<<"ENTER YOUR PASSWORD :";
              puts(passwd);
              cout<<"MODIFY ACCOUNT HOLDER'S FIRST NAME(ENTER '.' TO RETAIN OLD ONE):";
              cout<<firstName<<endl;
              cout<<endl<<"MODIFY ACCOUNT HOLDER'S LAST NAME(ENTER '.' TO RETAIN OLD ONE): ";
              cout<<lastName<<endl;
              goto typ;
             }
             }
             if(acctType[0]=='c'||acctType[0]=='C'||(strcmp(acctType,"current")||strcmp(acctType,"Current"))==0)
             strcpy(acctType,"C");
             else
             strcpy(acctType,"S");
             cout<<endl<<"MODIFY BALANCE AMOUNT(ENTER '-1' TO RETAIN OLD ONE):";
             cin>>deposit;
             if(deposit!=-1)
             balance=deposit;


}


int Bank::deleteAccount(int n)
{
    char choice;
    cout<<"DO YOU WANT TO DELETE DATA(Y/N)";
    cin>>choice;
    if(choice=='y')
    {ifstream infile;
        ofstream outfile;
        infile.open("zapatron.dat",ios::binary|ios::in);
        if(!infile)
        {
          cout<<"!!!!!!!!!FILE DOES NOT EXIST!!!!!!!!"<<endl;
        }
        outfile.open("tempero.dat",ios::binary|ios::app);
        infile.seekg(0);
        while(infile.read((char*)&customer,sizeof(customer)))
        {
            if(customer.getAcctNo()!=n)
            outfile.write((char*)&customer,sizeof(customer));
        }
        infile.close();
        outfile.close();
        remove("zapatron.dat");
        rename("tempero.dat","zapatron.dat");
        cout<<"**********ACCOUNT DELETED*******"<<endl;
        return 0;
    }
}
/////////////////////////////////MICELLINAOUS FUNCTIONS////////////////////////////////////////////////

int Bank::passwordcheck()
{
    int counter=0,a,i=0;
    char password[50],ch,ch1;
    enterpas: cout<<"ENTER YOUR PASSWORD: ";

    while(ch1!=13)
    {
        ch1=getch();
        if(ch1==13) break;
        password[i]=ch1;
        cout<<"*";
        i++;
    }
      password[i]='\0';
    if(password[0]=='\0')
    {
      cout<<endl<<"PROVIDE A PASSWORD"<<endl;
      ch1=' ';
      i=0;
      system("pause");
      system("cls");
      goto enterpas;
    }

    ch1=' ';
    i=0;

//    cin.ignore();
//    cin.getline(password,50);
     if(strcmp(password,passwd)==0)
        return 1;
    else{
         cout<<"\n!!!!!!WRONG PASSWORD!!!!!!!!"<<endl;
         cout<<"FORGOT PASSWORD?(y/n)";
         cin>>ch;
        if(ch=='y' || ch=='Y' )
        {
           a=securityCheck();
            if(a)
                showMenu();
        }
        else
            {
                counter++;
                if(counter<3)
                goto enterpas;
                 else
                {

                  cout<<"EXITING PROGRAM FOR THREE CONSEQUTIVE WRONG PASSWORD";
                  exit(0);
                }
            }
    }
}

int Bank::securityCheck()
{
    int counter=0;
    char Security[50];
    lable: system("cls");
    if(counter<3)
    {
            cout<<"ACCOUNT NO."<<no<<endl;
            cout<<"ENTER YOUR FAVOURITE BOOK/MOVIE/ACTOR: ";
            cin>>Security;
            if(strcmp(Security,security)==0)
            {
              cout<<"YOUR PASSWORD IS:"<<passwd<<endl;
              system("pause");
              return 1;
            }
            else{
                    cout<<"SECURITY PASSWORD INCORRECT"<<endl;
                    counter++;
                    goto lable;

                 }
    }
     else
                {

                  cout<<"EXITING PROGRAM FOR THREE CONSEQUTIVE WRONG ANSWERS";
                  exit(0);
                }

}


int display_all()
{

    ifstream inFile;
    inFile.open("zapatron.dat",ios::binary);
    if(!inFile)
    {
    cout<<"FILE COULD NOT OPEN!!"<<endl;
    system("pause");
    return 0;
    }
    cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================\n";
    cout<<"A/c no.          NAME           Type     Balance\n";
    cout<<"====================================================\n";
    while(inFile.read((char*)&customer,sizeof(customer)))
    {
        customer.report();

    }
    inFile.close();
    return 0;
}
void Bank::report()
{
   if(acctNo>0&&acctNo<10)
   {
     if(strlen(firstName)==1)
     cout<<customer.acctNo<<setw(16)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(16)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=10&&acctNo<100)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(15)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=100&&acctNo<1000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(14)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=1000&&acctNo<10000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(13)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=10000&&acctNo<100000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(12)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=100000&&acctNo<1000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(11)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=1000000&&acctNo<1000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(10)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=10000000&&acctNo<100000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(9)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=100000000&&acctNo<1000000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(8)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=1000000000&&acctNo<10000000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(7)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
   if(acctNo>=10000000000&&acctNo<100000000000)
   {
     if(strlen(firstName)==1)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(14)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==2)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(13)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==3)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(12)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==4)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(11)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==5)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(10)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==6)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(9)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==7)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(8)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==8)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(7)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==9)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(6)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==10)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(5)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==11)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(4)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
     else if(strlen(firstName)==12)
     cout<<acctNo<<setw(6)<<"  "<<firstName<<setw(3)<<"  "<<acctType<<setw(8)<<"  "<<balance<<endl;
   }
}

int main()
{
    int key,counter=0;
    char choice;
   lable:
      system("cls");
      customer.displayInfo();
      cout<<"1.CREATE AN ACCOUNT"<<endl;
      cout<<"2.LOG IN"<<endl;
      cout<<"3.DISPLAY ALL ACCOUNTS "<<endl;
        cout<<"4.EXIT"<<endl;
      cout<<"Enter Choice(1-4): ";
      cin>>choice;
      if(choice=='1'||choice=='2'||choice=='3'||choice=='4')
     {
               switch(choice)
               {
                case '1': customer.createAccount();
                         break;
                case '2': customer.logIn();
                          break;
                case '3':{

                         masterKey :system("cls");
                            customer.displayInfo();
                            cout<<"ENTER MASTER KEY: ";
                            cin>>key;
                            if(masterKey(key))
                                display_all();
                                else
                                {
                                    counter++;
                                    if(counter<3)
                                    goto masterKey;
                                    else
                                    {
                                        cout<<"EXITING PROGRAM FOR THREE CONSEQUTIVE WRONG PASSWORD";
                                        exit(0);
                                    }
                                }

                            }
                                   break;
                            case '4':exit(0);
                }
     }

      else
        goto lable;

                cout<<"THANK YOU FOR CHOOSING BETA BANK"<<endl;
                system("pause");
                goto lable;




    return 0;
    }

