#include <iostream>
#include <string>
using namespace std;
class account
{
    string name;
    long long int ac_no;
    char type_of_acc;

public:
    void setName(string x)
    {
        name = x;
    }
    void printName()
    {
        cout << "Enter customer's name:" << endl;
        cin >> name;
        cout << "\nCustomer's name: " << name << endl;
    }
    void set_ac_no(long long int x)
    {
        ac_no = x;
    }
    void show_ac_no()
    {
        cout << "Account number: " << ac_no << endl;
    }
    void set_type(char c)
    {
        type_of_acc = c;
    }
    void show_type()
    {
        cout << "Account type: " << type_of_acc << endl;
    }
};
class cur_acct : public account
{
    float balance = 10729;
    int dep, wdrl, minB = 3000;

public:
    void deposit()
    {
        cout <<"\nCurrent balance: " << balance <<" INR"<< endl;
        cout << "Enter amount to be deposited:" << endl;
        cin >> dep;
        cout << "Amount deposited: " << dep <<" INR"<< endl;
        balance = balance + dep;
        cout << "Updated balance: " << balance << " INR" << endl;
    }
    void withdrawl()
    {
        cout << "Current balance: " << balance << endl;
        cout << "Enter amount to be withdrawed:" << endl;
        cin >> wdrl;
        if (wdrl >= balance)
        {
            cout << "Can't withdraw to zero balance" << endl;
        }
        else
        {
            if (balance < minB)
            {
                cout << "Minimum balance(3000 INR) not maintained.Penalty may be applied.\n";
            }
            else
            {
                cout << "Amount debited: " << wdrl <<" INR"<< endl;
                balance = balance - wdrl;
                cout << "Updated balance: " << balance << " INR" << endl;
                if (balance < minB)
                {
                    cout << "\n-->Minimum balance(3000 INR) not maintained.Penalty may be applied.\n";
                }
            }
        }
    }
    void penalty()
    {
        if (balance < minB)
        {
            cout << "-->We are imposing penalty of 5% upon current balance." << endl;
            balance = balance - (0.05 * balance);
            cout << "Updated balance: " << balance << " INR" << endl;
        }
    }
};
class sav_acct : public account
{
public:
    float balance = 5000;
    int dep, wdrl;
    float intrst;
    void deposit()
    {
        cout << "Current balance= " << balance << endl;
        cout << "Enter amount to be deposited." << endl;
        cin >> dep;
        cout << "Amount deposited: " << dep <<" INR"<< endl;
        balance = balance + dep;
        cout << "Updated balance: " << balance << " INR" << endl;
    }
    void interest()
    {
        intrst = (balance * 4 * 3) / 100;
        balance = balance + intrst;
        cout << "-->Updated balance at 4% interest rate after 3 years: " << balance << " INR" << endl;
    }
};

int main()
{
    account a;
    cur_acct g;
    sav_acct s;
    cout << "\n\n\t\t\t******** Welcome to SBI Internet Banking portal! *********\n" << endl;
    a.setName(" ");
    a.set_ac_no(3229696777);
    a.set_type('C');
    a.printName();
    a.show_type();
    a.show_ac_no();
    cout << "\nChoose your options:\nPress 1 for depositing amount.\nPress 2 for amount withdrawl.\n";
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        g.deposit();
        break;
    case 2:
        g.withdrawl();
        g.penalty();
    }
    cout << "\nSavings account transactions:\n" << endl;
    s.deposit();
    s.interest();
    cout<<"\n\nThank you for choosing SBI Internet Banking. Please visit us again!"<<endl;
    // g.deposit();
    //  g.withdrawl();
    //  g.penalty();
    return 0;
}
