#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <windows.h>


using namespace std;

class Client
{
protected:
	string username;
	string accountnum;
	string email;
	string phone;
	string type;
	double balance;
public:


    //Create Account for User and write his information to text file
    void greateAccount()
    {
        cout<<"Id : ";cin>>accountnum;
        cout<<"UserName(can't contain space / _ ) : ";cin>>username;
        cout<<"Email Address : ";cin>>email;
        cout<<"Phone Number : ";cin>>phone;
        cout<<"Enter Type of your Account(Credit/Saving) : ";cin>>type;
        cout<<"Balance : ";cin>>balance;
        cout<<"Account created....\n";
        ofstream outfile;
        outfile.open("UserAccount.txt",ios::app|ios::out);
        outfile<< accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
        outfile.close();
    }

    //this function to print Data of user
    void displayData()
    {
        string acno;

        /*
        int found variable to check if account number of user is found in text or not
        it can be boolean
        */
        int found=0;
        ifstream infile;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Please Enter your Id Number : ";
        cin>>acno;

        //this line read info txt file
        infile>> accountnum >> username >> email>> phone>>type>>balance;

        //make while loop to read all data from text file
        while(!infile.eof())
        {

            /*
            this if condition to check user data by its account number
            and print User information
            */
            if(accountnum==acno)
            {
                cout<<"=========================================================\n";
                cout<<"Account Number : "<<accountnum<<endl;
                cout<<"User name : "<<username<<endl;
                cout<<"Email Address : "<<email<<endl;
                cout<<"Phone Number : "<<phone<<endl;
                cout<<"Account type : "<<type<<endl;
                cout<<"Balance : "<<balance<<endl;
                found=1;

            }
            infile>> accountnum >> username >> email>> phone>>type>>balance;
        }
        if(found==0)
            cout<<"Record Doesn't Exist\n";
        infile.close();

    }



    /*
    this function make modify to user data in text file
    same idea as display function but to modify data for certain user by its account number
    */
    void modifyData()
    {
        bool found=false;
        string acno;
        fstream infile;
        fstream infile1;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Please Enter your Id Number : ";
        cin>>acno;
        /* Explain of this function
        we here make 2 objects from fstream one for read and second for write data
        to another to text file and then delete old text file and rename new text file with
        same name of old text file
        */
        infile1.open("User.txt",ios::app|ios::out);
        infile>> accountnum >> username >> email>> phone>>type>>balance;
        while(!infile.eof())
        {
            if(accountnum==acno)
            {
                cout<<"Id : ";cin>>accountnum;
                cout<<"UserName : ";cin>>username;
                cout<<"Email Address : ";cin>>email;
                cout<<"Phone Number : ";cin>>phone;
                cout<<"Account type : "<<type<<endl;
                cout<<"Balance : "<<balance<<endl;
                infile1<< accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
                found=true;
            }
            else
            {
               infile1<< accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
            }
            infile>> accountnum >> username >> email>> phone>>type>>balance;
        }
        if(found==false)
            cout<<"Record Doesn't Exist\n";
        infile.close();
        infile1.close();
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");
    }

    /*
    deposit function same as modify function by using 2 object from fstream
    one for read data from old text file and other to write data to new text file
    */
    void deposit()
    {
        double money;
        bool found=false;
        string acno;
        fstream infile;
        fstream infile1;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Please Enter your ID Number : ";cin>>acno;
        infile>>accountnum>>username>>email>>phone>>type>>balance;
        infile1.open("User.txt",ios::out|ios::app);
        while(!infile.eof())
        {
            if(accountnum==acno)
            {
                cout<<"Enter amount to be deposited : ";cin>>money;
                balance+=money;
                infile1<< accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
                found=true;
                cout<<"\nyour balance after deposited : "<<balance;
            }
            else
            {
               infile1<< accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
            }
             infile>>accountnum>>username>>email>>phone>>type>>balance;
        }
        if(found==false)
            cout<<"Record Doesn't Exist\n";
        infile.close();
        infile1.close();
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");
    }


    /*
    withdraw function same as modify function by using 2 object from fstream
    one for read data from old text file and other to write data to new text file
    */
    void withdraw()
    {
        double money;
        bool found=false;
        string acno;
        fstream infile;
        fstream myfile;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Enter your id Number : ";cin>>acno;
        infile>>accountnum>>username>>email>>phone>>type>>balance;
        myfile.open("User.txt",ios::out|ios::app);
        while(!infile.eof())
        {
            if(accountnum==acno)
            {
                cout<<"Enter amount to be withdraw : ";cin>>money;
                if(balance<money)
                {
                    cout<<"your amount is not sufficient\n";
                }
                else
                {
                    balance-=money;
                    myfile<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
                    cout<<"\nyour balance after withdraw : "<<balance;
                }
                found=true;
            }
            else
            {
               myfile<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
            }
            infile>>accountnum>>username>>email>>phone>>type>>balance;
        }
        infile.close();
        myfile.close();
        if(found==false)
            cout<<"Record Doesn't Exist\n";
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");
    }



    /*
    tranfer function same as modify function by using 2 object from fstream
    one for read data from old text file and other to write data to new text file
    but have different logic from other Function its explain in function{}
    */
    /*
    you need to write this function :
       1st to withdraw
       2nd to deposit
    */
    void tranfer()
    {
        /*
         Explain of function

         this function is Sum of function of (Deposit & withdraw)
        */
        double money;
        bool found=false;
        string acno;
        fstream infile;
        fstream myfile;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Enter your id Number : ";cin>>acno;
        cout<<"Enter amount you want to tranfer : ";cin>>money;
        infile>>accountnum>>username>>email>>phone>>type>>balance;
        myfile.open("User.txt",ios::app|ios::out);

        //first while loop to withdraw money from user and write withdraw in text file
        while(!infile.eof())
        {
            if(accountnum==acno)
            {
                if(balance<money)
                {
                    cout<<"insufficient Balance\n";
                }
                else
                {
                    balance-=money;
                    cout<<"Balance Become after transaction : "<<balance;
                    myfile<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
                }
            }
            else
            {
                myfile<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
            }
            found=true;
            infile>>accountnum>>username>>email>>phone>>type>>balance;
        }
        //and then close open text files and remove old file and rename new file by name of old file
        infile.close();
        myfile.close();
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");

        if(found==false)
            cout<<"Record Doesn't Exist\n";

        bool flag=false;
        string accno;
        //make new 2 objects 1st to read from old text file and 2nd to write to new text file
        //don't make error in code
        fstream infile1;
        fstream myfile1;
        infile1.open("UserAccount.txt",ios::in);
        cout<<"\nEnter another id Number : ";cin>>accno;
        infile1>>accountnum>>username>>email>>phone>>type>>balance;
        myfile1.open("User.txt",ios::app|ios::out);
        //2nd loop to deposit money to another wanted user and write new balance to new text file
        while(!infile1.eof())
        {

          if(accountnum==accno)
          {
              balance+=money;
              myfile1<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
              cout<<"Balance Become after transaction : "<<balance;
          }
          else
          {
              myfile1<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
          }
          flag=true;
          infile1>>accountnum>>username>>email>>phone>>type>>balance;
        }
        infile1.close();
        myfile1.close();
        if(flag==false)
            cout<<"Other Record Doesn't Exist\n";
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");
    }

};


//employee class will inherit from Client class to be able to use all function of Client class
class Employee : public Client
{
public:


    //this function make employee able to print all data of all users
    void displayAllUserData()
    {
        fstream infile;
        infile.open("UserAccount.txt",ios::in);
        infile>>accountnum>>username>>email>>phone>>type>>balance;
        while(!infile.eof())
        {
            cout<<"=========================================================\n";
            cout<<"Account Number : "<<accountnum<<endl;
            cout<<"User name : "<<username<<endl;
            cout<<"Email Address : "<<email<<endl;
            cout<<"Phone Number : "<<phone<<endl;
            cout<<"Account type : "<<type<<endl;
            cout<<"Balance : "<<balance<<endl;
            infile>>accountnum>>username>>email>>phone>>type>>balance;
        }

    }


    //this to delete user from text file and create new text file without this deleted user
    //same as function of deposit and modify but have different logic
    void deleteUser()
    {
        string acno;
        bool found = false;
        fstream myfile;
        fstream infile;
        infile.open("UserAccount.txt",ios::in);
        cout<<"Enter Account number you want to delete : ";
        cin>>acno;
        infile>>accountnum>>username>>email>>phone>>type>>balance;
        myfile.open("User.txt",ios::app|ios::out);
        while(!infile.eof())
        {
            if(accountnum!=acno)
            {
               myfile<<accountnum <<"   "<< username <<"   "<<email<<"   "<<phone<<"   "<<type<<"   "<<balance<<endl;
            }
            found=true;
            infile>>accountnum>>username>>email>>phone>>type>>balance;

        }
        infile.close();
        myfile.close();
        if(found==false)
            cout<<"Record Doesn't Exist\n";
        else
            cout<<"Successfully Deleted.....\n ";
        remove("UserAccount.txt");
        rename("User.txt","UserAccount.txt");
    }

};


//admin class will inherit from employee class to be able to use all function of Client class && employee class
class Admin : public Employee
{
private:
    string accnum,un,em,ph,pos,sector;
public:
    //this function make admin able to add employee to bank app
     void greateEmployee()
     {


         cout<<"Account Number : ";cin>>accnum;
         cout<<"UserName(can't contain space / _ ) : ";cin>>un;
         cout<<"Email Address : ";cin>>em;
         cout<<"Phone Number : ";cin>>ph;
         cout<<"Position : ";cin>>pos;
         cout<<"Sector : ";cin>>sector;
         cout<<"Employee Account Created ...\n";
         fstream outfile;
         outfile.open("EmployeeAccount.txt",ios::app|ios::out);
         outfile<<accnum<<"   "<<un<<"   "<<em<<"   "<<ph<<"   "<<pos<<"   "<<sector<<endl;
         outfile.close();
     }


     //this function make admin able to print certain employee data by its account number
     void displayEmplyeeData()
     {
        string acno;
        bool found=false;
        fstream infile;
        infile.open("EmployeeAccount.txt",ios::in);
        infile>>accnum>>un>>em>>ph>>pos>>sector;
        cout<<"Enter Employee Id Number : ";
        cin>>acno;
        while(!infile.eof())
        {
            if(accnum==acno)
            {
                cout<<"=========================================================\n";
                cout<<"Account Number : "<<accnum<<endl;
                cout<<"User Name : "<<un<<endl;
                cout<<"Email Address : "<<em<<endl;
                cout<<"Phone Number : "<<ph<<endl;
                cout<<"Position : "<<pos<<endl;
                cout<<"Sector Name : "<<sector<<endl;
            }
            infile>>accnum>>un>>em>>ph>>pos>>sector;
            found=true;
        }
        if(found==false)
            cout<<"Record Not Found...\n";
        infile.close();
     }


     //this function make admin able to print all data of employee
     void displayAllEmployeeData()
     {
         fstream infile;
         infile.open("EmployeeAccount.txt",ios::in);
         infile>>accnum>>un>>em>>ph>>pos>>sector;
         while(!infile.eof())
         {
            cout<<"=========================================================\n";
            cout<<"Account Number : "<<accnum<<endl;
            cout<<"User name : "<<un<<endl;
            cout<<"Email Address : "<<em<<endl;
            cout<<"Phone Number : "<<ph<<endl;
            cout<<"Position : "<<pos<<endl;
            cout<<"Sector Name : "<<sector<<endl;
            infile>>accnum>>un>>em>>ph>>pos>>sector;
         }
     }

    //function to delete employee from app
     void deleteEmployeeAccount()
     {
        string acno;
        bool found=false;
        fstream infile;
        fstream myfile;
        infile.open("EmployeeAccount.txt",ios::in);
        cout<<"Enter Employee Id Number : ";
        cin>>acno;
        infile>>accnum>>un>>em>>ph>>pos>>sector;
        myfile.open("Employee.txt",ios::app|ios::out);
        while(!infile.eof())
        {
            if(accnum!=acno)
            {
               myfile<<un<<"   "<<accnum<<"   "<<em<<"   "<<ph<<"   "<<pos<<"   "<<sector;
            }
            infile>>accnum>>un>>em>>ph>>pos>>sector;
            found=true;
        }
        if(found==false)
            cout<<"Record Not Found...\n";
        else
            cout<<"Employee Successfully Deleted....\n";
        infile.close();
        myfile.close();
        remove("EmployeeAccount.txt");
        rename("Employee.txt","EmployeeAccount.txt");
     }
};


//function prototype
void welcome();
void mainMenu();
void userMenu();
void employeeMenu();
void adminMenu();



int main()
{
    //this line to to make change colors console app(background&write)
    //system("color %")>>>this line will make you know colors you want to use

    system("color B4");
	mainMenu();
}



// its welcome function
void welcome()
{

    for(int i = 0 ; i < 8 ; i++)
    {
        cout<<"\n";
    }
    char path [] = "d://welcome.txt";
    string data;
    ifstream myfile;
    myfile.open(path);

    while(!myfile.eof())
   {
     cout<<"\t\t\t\t";
     getline(myfile,data);
     cout<<data<<endl;
   }

   cout<<"\n\n\t\t\t\t\t\t\t\t\t\tWelcome in our Bank Management System Simple Project\n";
   cout<<"\n\n\t\t\t\t\t\t\t\t\t\tMADE BY AHMED MOSTAFA & WAEL TAHA\n\n\n\n\n";

   cout<<"\t\t\t\t\t\t\t\t\t\tLoading";
   for(int i = 0 ; i<8 ; i++)
   {
       Sleep(500);
       cout<<".";
   }

   myfile.close();
}


/*
this main menu function will attached all function with each other
through do while loop and switch case
*/
void mainMenu()
{
    welcome();
	char ch ;
	int option;
	do
	{
		system("cls");
		cout << "\n\n\n\t\t\t-------------------------------------------\n";
		cout << "\t\t\t|            Bank Management System        |\n";
		cout << "\t\t\t-------------------------------------------\n";
		cout << "\t\t\t 1-USER OPERATION \n";
		cout << "\t\t\t 2-EMPLOYEE OPERATION \n";
		cout << "\t\t\t 3-ADMIN OPERATION \n";
		cout << "\t\t\t 4-EXIT APPLICATION \n";
		cout << "\t\t\t SELECT YOUR CHOICE : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		    userMenu();
			break;
		case '2':
		    employeeMenu();
			break;
		case '3':
		    adminMenu();
			break;
        case '4':
		    exit(0);
			break;
		default:
			cout << "Invalid Choice.....";
		}
	} while (ch != '4');
	cin.get();
	cin.ignore();
	getch();
}

//its user function menu
void userMenu()
{
   Client c1;
   char option;
   do
	{
		system("cls");
		cout << "\n\n\n\t\t\t-------------------------------------------\n";
		cout << "\t\t\t|              User Main Menu             |\n";
		cout << "\t\t\t-------------------------------------------\n";
		cout << "\t\t\t 1-GREATE ACCOUNT \n";
		cout << "\t\t\t 2-DISPLAY YOUR DATA \n";
		cout << "\t\t\t 3-MODIFY YOUR DATA \n";
		cout << "\t\t\t 4-DEPOSIT MONEY \n";
		cout << "\t\t\t 5-WITHDRAW MONEY \n";
		cout << "\t\t\t 6-TRANFER MONEY \n";
		cout << "\t\t\t 7-EXIT APLLICATION \n";
		cout << "\t\t\t SELECT YOUR CHOICE : ";
		cin >> option;
		switch (option)
		{
		case '1':
		    c1.greateAccount();
			break;
		case '2':
		    c1.displayData();
			break;
		case '3':
		    c1.modifyData();
			break;
		case '4':
		    c1.deposit();
			break;
        case '5':
		    c1.withdraw();
			break;
        case '6':
		    c1.tranfer();
			break;
        case '7':
		    exit(0);
			break;
		default:
			cout << "Invalid Choice.....";
		}
		getch();
	} while (option != '7');
}


//its employee function menu
void employeeMenu()
{
   Employee e1;
   char ch;
   do
   {
       system("cls");
       cout << "\n\n\n\t\t\t-------------------------------------------\n";
       cout << "\t\t\t|              Employee Main Menu           |\n";
       cout << "\t\t\t-------------------------------------------\n";
       cout << "\t\t\t 1-DISPLAY USER DATA \n";
       cout << "\t\t\t 2-DISPLAY ALL DATA \n";
       cout << "\t\t\t 3-MODIFY USER DATA \n";
       cout << "\t\t\t 4-DELETE USER DATA \n";
       cout << "\t\t\t 5-DEPOSIT MONEY \n";
       cout << "\t\t\t 6-WITHDRAW MONEY \n";
       cout << "\t\t\t 7-TRANSFER MONEY \n";
       cout << "\t\t\t 8-EXIT APPLICATION \n";
       cout << "\t\t\t SELECT YOUR CHOICE : ";
       cin >> ch;
       switch(ch)
       {
       case '1':
           e1.displayData();
        break;
       case '2':
           e1.displayAllUserData();
        break;
       case '3':
           e1.modifyData();
        break;
       case '4':
           e1.deleteUser();
        break;
       case '5':
           e1.deposit();
        break;
       case '6':
           e1.withdraw();
        break;
       case '7':
           e1.tranfer();
        break;
        case '8':
           exit(0);
        break;

       default:
        cout<<"Invalid Choice.....\n";
       }
       getch();
   }while(ch!='8');
}


////its admin function menu
void adminMenu()
{
   Admin d1;
   Employee e1;
   int ch;
   do
   {
       system("cls");
       cout << "\n\n\n\t\t\t-------------------------------------------\n";
       cout << "\t\t\t|              ADMIN Main Menu           |\n";
       cout << "\t\t\t-------------------------------------------\n";
       cout << "\t\t\t 1-GREATE USER ACCOUNT \n";
       cout << "\t\t\t 2-DISPLAY USER DATA \n";
       cout << "\t\t\t 3-DISPLAY ALL User DATA \n";
       cout << "\t\t\t 4-MODIFY USER DATA \n";
       cout << "\t\t\t 5-DELETE USER DATA \n";
       cout << "\t\t\t 6-DEPOSIT MONEY \n";
       cout << "\t\t\t 7-WITHDRAW MONEY \n";
       cout << "\t\t\t 8-TRANSFER MONEY \n";
       cout << "\t\t\t 9-ADD EMPLOYEE \n";
       cout << "\t\t\t 10-DISPLAY EMPLOYEE DATA \n";
       cout << "\t\t\t 11-DISPLAY ALL EMPLOYEE DATA \n";
       cout << "\t\t\t 12-DELETE EMPLOYEE DATA \n";
       cout << "\t\t\t 13-EXIT APPLICATION \n";
       cout << "\t\t\t SELECT YOUR CHOICE : ";
       cin >> ch;
       switch(ch)
       {
       case 1:
           d1.greateAccount();
           break;
       case 2:
           d1.displayData();
           break;
       case 3:
           d1.displayAllUserData();
           break;
       case 4:
           d1.modifyData();
           break;
       case 5:
           d1.deleteUser();
           break;
       case 6:
           d1.deposit();
           break;
       case 7:
           d1.withdraw();
           break;
       case 8:
           d1.tranfer();
           break;
       case 9:
           d1.greateEmployee();
           break;
        case 10:
           d1.displayEmplyeeData();
           break;
        case 11:
           d1.displayAllEmployeeData();
           break;
        case 12:
           d1.deleteEmployeeAccount();
            break;
        case 13:
            exit(0);
            break;
       default:
        cout<<"Invalid Choice.....\n";
       }
       getch();
   }while(ch!=13);
}

//Welcome in our Bank Management System Simple Project
//Made By Ahmed& Wael Taha















