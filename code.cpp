#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct holder
{
    int choice;
    long long account_number = 856729153486;
    int account_number_transfer;
    int transfer_amount;
    int deposite;
    int withdraw;
    int password = 829607;
    int enter_password;
};

int main()
{
    vector<int> balance; // ✅ vector to store balances
    holder holders;

    // Load last balance from file
    ifstream fin("balance.txt");
    int lastBalance = 0;
    if (fin)
    {
        fin >> lastBalance;
        balance.push_back(lastBalance);
    }
    else
    {
        balance.push_back(0); // default starting balance
    }
    fin.close();

    bool running = true;

    cout << "=====Bank Management System======" << endl;

    while (running)
    {
        cout << "\n1. Show all Transaction History\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Transfer money\n";
        cout << "5. Display amount details\n";
        cout << "6. Save and exit\n";
        cout << "Enter your choice: ";
        cin >> holders.choice;

        switch (holders.choice)
        {
        case 1:
        {
            ifstream myfile("transaction_history.txt");
            if (!myfile)
            {
                cout << "No transaction history found." << endl;
            }
            else
            {
                string line;
                cout << "Transaction History:" << endl;
                while (getline(myfile, line))
                {
                    cout << line << endl;
                }
            }
            myfile.close();
            break;
        }

        case 2:
            cout << "Enter the Amount you Wanna deposit: ";
            cin >> holders.deposite;
            cout << "Enter your password: ";
            cin >> holders.enter_password;
            if (holders.enter_password == holders.password)
            {
                int newBalance = balance.back() + holders.deposite;
                balance.push_back(newBalance);

                ofstream fout("transaction_history.txt", ios::app);
                fout << "Deposited: " << holders.deposite << " | Balance: " << newBalance << endl;
                fout.close();

                cout << "Deposit Successful! Current Balance = " << newBalance << endl;
            }
            else
            {
                cout << "Deposit Failed! Incorrect Password." << endl;
            }
            break;

        case 3:
            cout << "Enter the Amount you Wanna Withdraw: ";
            cin >> holders.withdraw;
            cout << "Enter your password: ";
            cin >> holders.enter_password;
            if (holders.enter_password == holders.password)
            {
                if (holders.withdraw <= balance.back())
                {
                    int newBalance = balance.back() - holders.withdraw;
                    balance.push_back(newBalance);

                    ofstream fout("transaction_history.txt", ios::app);
                    fout << "Withdraw: " << holders.withdraw << " | Balance: " << newBalance << endl;
                    fout.close();

                    cout << "Withdraw Successful! Current Balance = " << newBalance << endl;
                }
                else
                {
                    cout << "Withdraw Failed! Insufficient Balance." << endl;
                }
            }
            else
            {
                cout << "Withdraw Failed! Incorrect Password." << endl;
            }
            break;

        case 4:
            cout << "Enter the Account Number you Wanna Transfer: ";
            cin >> holders.account_number_transfer;
            cout << "Enter the Amount you Wanna Transfer: ";
            cin >> holders.transfer_amount;
            cout << "Enter your password: ";
            cin >> holders.enter_password;
            if (holders.enter_password == holders.password)
            {
                if (holders.transfer_amount <= balance.back())
                {
                    int newBalance = balance.back() - holders.transfer_amount;
                    balance.push_back(newBalance);

                    ofstream fout("transaction_history.txt", ios::app);
                    fout << "Transfer: " << holders.transfer_amount << " to Acc " << holders.account_number_transfer << " | Balance: " << newBalance << endl;
                    fout.close();

                    cout << "Transfer Successful! Current Balance = " << newBalance << endl;
                }
                else
                {
                    cout << "Transfer Failed! Insufficient Balance." << endl;
                }
            }
            else
            {
                cout << "Transfer Failed! Incorrect Password." << endl;
            }
            break;

        case 5:
            cout << "Your Account Number: " << holders.account_number << endl;
            cout << "Your Balance: " << balance.back() << endl;
            break;

        case 6:
            // Save last balance to file
            ofstream fout("balance.txt");
            fout << balance.back();
            fout.close();

            cout << "===Thanks for your visit===" << endl;
            cout << "====You have a nice Day====" << endl;
            running = false;
            break;

        // default:
        //     cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
