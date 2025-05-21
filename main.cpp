#include <iostream>
#include <fstream>
using namespace std;

class onlineBank{
private:
    string Name, Password, address, ID_No, Account_Type;
    int Accunt_NO;

public:
    void userLogain();
    void openAccount();
    void accountDeposit();
    void accountBalance();
    void accountWithdraw();
    void accountStatement();
};

void onlineBank::openAccount(){
 cout << "Enter ID number: ";
  cin >> ID_No;
 cout << "Enter your Addrress: ";
  cin >> address;
 cout << "Choose Account Type: ";
  cin >> Account_Type;
 cout << "Enter Username: ";
  cin >> Name;
 cout << "create Password: ";
  cin >> Password;
  Accunt_NO = 123456;

  ofstream MyFile("Account_details.txt");
  MyFile << Name <<" "<< ID_No <<" "<< address <<" "<< Account_Type <<" "<< Accunt_NO <<" "<< Password <<endl;
  MyFile.close();
}

void onlineBank::userLogain(){
    string U_name, P_word;
    bool verify = true;
 cout << "Enter Your UserName: ";
  cin >> U_name;
 cout << "Enter Password: ";
  cin >> P_word;

ifstream MyFile("Account_details.txt");
while(MyFile >> U_name >> P_word){
    if(U_name == Name && P_word == Password){
        verify = true;
        break;
    }
}
MyFile.close();

if(verify){
    cout << "****Login Successful****" <<endl;
    int option;
    cout << "Deposit" <<endl;
    cout << "Balance" <<endl;
    cout << "Withdraw" <<endl;
    cout << "Exit" <<endl;
    cout << "__Select option__" <<endl;
    cin >> option;
    switch(option){
    case 1:
        accountDeposit();
        break;
    case 2:
        accountBalance();
        break;
    case 3:
        accountWithdraw();
        break;
    case 4:
        cout << "Exited" <<endl;
        break;
    default:
        cout << "Invalid option!" <<endl;
    }
}
 else{
        cout << "Wrong Username or password!" <<endl;
        cout << "TRY AGAIN 2X" <<endl;
         userLogain();
    }
}
void onlineBank::accountDeposit(){
    int Deposit;
    double Balance = 2000.00;
    cout << "Enter Amount you want to deposit" <<endl;
   cin >> Deposit;
    double Avaliable_Balance = Deposit + Balance;
  cout << "****PRINT RECEIPT****" <<endl;
  cout << "____Receipt____" <<endl;
  cout << "Deposited amount = R" << Deposit <<endl;
  cout << "Avaliable Balance: R" << Avaliable_Balance <<endl;
}

void onlineBank::accountBalance(){
    int option;
    double Amount = 2000.00;
  cout << "1. Check Balance" <<endl;
  cout << "2. Print Statement" <<endl;
  cin >> option;
  switch(option){
  case 1:
   cout << " Your Balance = R" << Amount <<endl;
  break;
  case 2:
    cout << "____Receipt____" <<endl;
    cout << " Avaliable Balance: R" << Amount <<endl;
    break;
      }
}

void onlineBank::accountWithdraw(){
 double Avaliable_amount = 2000.00;
 int withdraw;
 cout << " Enter Amount you want to withdraw" <<endl;
 cin >> withdraw;

 double withdrawal = Avaliable_amount - withdraw;
 if(withdrawal >= Avaliable_amount){

    cout << "___RECEIPT____" <<endl;
    cout << "Insufiant Amount!" <<endl;
 }
 else if(withdrawal < Avaliable_amount){
    cout << "Your withdrawal = R" << withdrawal <<endl;
    cout << "____PRINT RECEEIPT____ " <<endl;
    cout << " withdrawal: R" << withdraw <<endl;
    cout << " Avaliable Balance: R" << Avaliable_amount - withdraw <<endl;
   }
}

void onlineBank::accountStatement(){
 ofstream MyFile("Statement.txt");
 MyFile << "___Amount of transaction___" <<endl;
 MyFile.close();
}

int main()
{
 onlineBank MyBank;
 int option;

 while(option !=3){
 cout << "1. LOGIN" <<endl;
 cout << "2. SIGN UP" << endl;
 cout << "3. Exit" <<endl;
 cin >> option;

 switch(option){
 case 1:
    MyBank.userLogain();
    break;
 case 2:
    MyBank.openAccount();
    break;
 case 3:
    cout << "Goodbye!. Take your card." <<endl;
    break;
 default:
    cout << "Invalid option!" <<endl;
 }
     }
    return 0;
}
