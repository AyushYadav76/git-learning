#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
using namespace std;
class ATM {
private:
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;
public:
    void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a){
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }
    long int getAccountNO(){
        return account_no;
    }
    int getPIN(){
        return PIN;
    }
    string getName(){
        return name;
    }
    double getBalance(){
        return balance;
    }
    string getMobileNO(){
        return mobile_no;
    }
    void setMobile(string mob_prev, string mob_new){
        if(mob_prev == mobile_no){
            mobile_no = mob_new;
            cout << "Successfully updated mobile number" << endl;
            cout << endl << "Press any key to return to menu...";
        } else {
            cout << "Incorrect previous mobile number" << endl;
        }
    }
    void cashWithdrwal(double amount_a){
        if(amount_a >0 && amount_a <= balance){
            balance -= amount_a;
            cout << "Please collect your cash" << endl;
            cout << "Available balance: " << balance << endl;
            cout<<" Thankyou for using ATM Service"<<endl;
            cout << endl << "Press any key to return to menu... ";
            _getch();
        }else{
            cout << "Insufficient balance or invalid Input" << endl;
            cout << endl << "Press any key to return to menu...";
            _getch();
        }
    }
    void cashDeposit(double amount_a){
        if(amount_a > 0){
            balance += amount_a;
            cout << "Successfully deposited" << endl;
            cout << "Available balance: " << balance << endl;
            cout<<" Thankyou for using ATM Service"<<endl;
            cout << endl << "Press any key to return to menu...";
            _getch();
        }else{
            cout << "Invalid Input" << endl;
            cout << endl << "Press any key to return to menu...";
            _getch();
        }
    }
};    

int main(){
    int choice = 0, enterPIN;
    long int enterAccountNO;
    
    system("cls");
    vector<ATM> users;
    ATM user1;
    user1.setData(1234567, "John", 1234, 1000.0, "555-1234");
    users.push_back(user1);
    
    ATM user2;
    user2.setData(2345678, "Alice", 2345, 2000.0, "555-5678");
    users.push_back(user2);
    
    ATM user3;
    user3.setData(3456789, "Bob", 3456, 3000.0, "555-8765");
    users.push_back(user3);

    do{
        system("cls");
        cout << "****Welcome to ATM****" << endl;
        cout << "Enter account number: ";
        cin >> enterAccountNO;
        cout << "Enter PIN: ";
        cin >> enterPIN;

        bool found = false;
        ATM* activeUser = nullptr;
        for(int i=0; i<users.size(); i++){
            if((enterAccountNO == users[i].getAccountNO())&& (enterPIN == users[i].getPIN())){
                found = true;
                activeUser = &users[i];
                break;
            }
        }
        if(found){
            bool isUserActive = true;
            do{
                system("cls");
                cout << "***Welcome to ATM**"<< endl;
                cout<< "Select Option "<<endl;
                cout << "1. Cash Withdrawal" << endl;
                cout << "2. Cash Deposit" << endl;
                cout << "3. Check Balance" << endl;
                cout << "4. Update Mobile Number" << endl;
                cout << "5. Exit" << endl;
                cout << "6. Logout" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1: {
                        double amount;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        activeUser->cashWithdrwal(amount);
                        break;
                    }
                    case 2: {
                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        activeUser->cashDeposit(amount);
                        break;
                    }
                    case 3: {
                        cout << "Available balance: " << activeUser->getBalance() << endl;
                        cout << endl << "Press any key to return to menu...";
                        _getch();
                        break;
                    }
                    case 4: {
                        string prevMob, newMob;
                        cout << "Enter previous mobile number: ";
                        cin >> prevMob;
                        cout << "Enter new mobile number: ";
                        cin >> newMob;
                        activeUser->setMobile(prevMob, newMob);
                        _getch();
                        break;
                    }
                    case 5: {
                        cout << "Thank you for using the ATM. Goodbye!" << endl;
                        // _getch();
                        return 0;
                    }
                    case 6: {
                        isUserActive = false;
                        break;
                    }
                    default: {
                        cout << "Invalid choice. Please try again." << endl;
                        _getch();
                        break;
                    }
                }    
            }while(isUserActive);
                
        }else{
            cout << "User details are Invalid" <<endl;
            _getch();
        }
    } while(1);
    return 0;
}
