#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to hold bank account information
struct Account {
    int accountID;
    string accountHolderName;
    string accountType;
    double balance;
    double loanAmount = 0.0;
    double RepayAmount = 0.0;
	double DepositAmount = 0.0;
	double WithdrawAmount = 0.0;
	double TransferAmount = 0.0;
	string complain;
	 // New field for loan amount
};

// Function declarations
void addRecord();
void editRecord();
void viewRecords();
void searchRecord();
void deleteRecord();
void applyLoan();
void repayLoan();
void DepositAmount();
void WithdrawAmount();
void TransferAmount();
void CustomerReport();

int main() {
    int choice;
    do {
        // Display menu
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "\t\t\tBanking Management System";
         cout << "\n--------------------------------------------------------------------------------\n";
        cout << "1. Add Record\n";
        cout << "2. Edit Record\n";
        cout << "3. View Records\n";
        cout << "4. Search Record\n";
        cout << "5. Delete Record\n";
        cout << "6. Apply for Loan\n";
        cout << "7. Repay for Loan\n";
		cout << "8. Deposit Amount\n";
		cout << "9. Withdraw Amount\n";
		cout << "10. Transfer Amount\n";
		cout << "11. Customer Complaints\n"; // New menu option
        cout << "12. Exit\n";
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Menu options
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                editRecord();
                break;
            case 3:
                viewRecords();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                deleteRecord();
                break;
            case 6:
                applyLoan();
                break;
            case 7:
            	repayLoan();break;
            case 8:
            	DepositAmount();break;
            case 9:
            	WithdrawAmount();break;
            case 10:
            	TransferAmount();break;
            case 11:
            	CustomerReport();break;
            case 12:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 12);

    return 0;
}

void addRecord() {
    ofstream file("accounts.txt", ios::app); // Append mode to avoid overwriting
    Account acc;

    cout << "Enter Account ID: ";
    cin >> acc.accountID;
    cin.ignore(); // Ignore leftover newline
    cout << "Enter Account Holder Name: ";
    getline(cin, acc.accountHolderName);
    cout << "Enter Account Type: ";
    getline(cin, acc.accountType);
    cout << "Enter Balance: ";
    cin >> acc.balance;

    // Write to file
    file << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
         << acc.balance << " " << acc.loanAmount << "\n";
    file.close();

    cout << "Record added successfully!\n";
}

void editRecord() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to edit: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            found = true;
            cout << "Enter new Account Holder Name: ";
            cin.ignore();
            getline(cin, acc.accountHolderName);
            cout << "Enter new Account Type: ";
            getline(cin, acc.accountType);
            cout << "Enter new Balance: ";
            cin >> acc.balance;
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Record updated successfully!\n";
    else
        cout << "Record not found.\n";
}

void viewRecords() {
    ifstream file("accounts.txt");
    Account acc;

    cout << "\n-----------------------------------\n";
	cout << "\tAccount Records";
	cout << "\n-----------------------------------\n";
    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        cout << "Account ID: " << acc.accountID << "\n";
        cout << "Account Holder Name: " << acc.accountHolderName << "\n";
        cout << "Account Type: " << acc.accountType << "\n";
        cout << "Balance: " << acc.balance << "\n";
        cout << "Loan Amount: " << acc.loanAmount << "\n";
        cout << "-------------------------\n";
    }
    file.close();
}

void searchRecord() {
    ifstream file("accounts.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to search: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            cout << "\n-----------------------------------\n";
		    cout << "\tAccount Found";
		    cout << "\n-----------------------------------\n";
            cout << "Account ID: " << acc.accountID << "\n";
            cout << "Account Holder Name: " << acc.accountHolderName << "\n";
            cout << "Account Type: " << acc.accountType << "\n";
            cout << "Balance: " << acc.balance << "\n";
            cout << "Loan Amount: " << acc.loanAmount << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Record not found.\n";

    file.close();
}

void deleteRecord() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int deleteID;
    bool found = false;

    cout << "Enter Account ID to delete: ";
    cin >> deleteID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == deleteID) {
            found = true;
            continue; // Skip writing this record
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Record deleted successfully!\n";
    else
        cout << "Record not found.\n";
}

void applyLoan() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to apply for a loan: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            cout << "Enter Loan Amount: ";
            cin >> acc.loanAmount;
            found = true;
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Loan applied successfully!\n";
    else
        cout << "Account not found.\n";
}
void repayLoan() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to repay for a loan: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            cout << "Enter Repay Loan Amount: ";
            cin >> acc.RepayAmount;
            acc.loanAmount-=acc.RepayAmount;
            acc.balance-=acc.RepayAmount;
            found = true;
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount <<  "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Loan repaid successfully!\n";
    else
        cout << "Account not found.\n";
}
void DepositAmount() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to Deposit Amount: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            cout << "Enter Deposit Amount: ";
            cin >> acc.DepositAmount;
            acc.balance+=acc.DepositAmount;
            found = true;
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Amount Deposited successfully!\n";
    else
        cout << "Account not found.\n";
}
void WithdrawAmount() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int searchID;
    bool found = false;

    cout << "Enter Account ID to Withdraw Amount: ";
    cin >> searchID;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == searchID) {
            cout << "Enter Withdraw Amount: ";
            cin >> acc.WithdrawAmount;
            acc.balance-=acc.WithdrawAmount;
            found = true;
        }
        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    if (found)
        cout << "Amount Withdraw successfully!\n";
    else
        cout << "Account not found.\n";
}
void TransferAmount() {
    ifstream file("accounts.txt");
    ofstream tempFile("temp.txt");
    Account acc;
    int senderID, receiverID;
   // double transferAmount;
    bool senderFound = false, receiverFound = false;

    cout << "Enter Sender Account ID: ";
    cin >> senderID;
    cout << "Enter Receiver Account ID: ";
    cin >> receiverID;
    cout << "Enter Transfer Amount: ";
    cin>>acc.TransferAmount;

    while (file >> acc.accountID >> acc.accountHolderName >> acc.accountType >> acc.balance >> acc.loanAmount) {
        if (acc.accountID == senderID) {
            senderFound = true;
            if (acc.balance >= acc.TransferAmount) {
                acc.balance -= acc.TransferAmount; // Deduct from sender
                //senderAcc = acc; // Store updated sender data
            } else {
                cout << "Insufficient balance in sender's account.\n";
                tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " "
                         << acc.balance << " " << acc.loanAmount << "\n";
                continue; // Keep record as is
            }
        } else if (acc.accountID == receiverID) {
            receiverFound = true;
            acc.balance += acc.TransferAmount; // Add to receiver
        //    receiverAcc = acc; // Store updated receiver data
        }

        tempFile << acc.accountID << " " << acc.accountHolderName << " " << acc.accountType << " " 
                 << acc.balance << " " << acc.loanAmount << "\n";
    }

    file.close();
    tempFile.close();

    if (!senderFound || !receiverFound) {
        cout << "One or both accounts not found. Transaction canceled.\n";
        // Restore original data
        remove("temp.txt");
    } else {
        // Apply changes
        remove("accounts.txt");
        rename("temp.txt", "accounts.txt");
        cout << "Money transferred successfully from Account " << senderID
             << " to Account " << receiverID << ".\n";
    }
}
void CustomerReport(){
	 ifstream file("reports.txt");
    int reportCount = 0;
    Account acc;

    // Count how many reports are in the file
    while (file >> acc.accountID) {
        getline(file, acc.complain);
         cout <<reportCount+1<<" "<< acc.complain << "\n" ;
        reportCount++;
    }

    file.close();
    cout << "Total Customer Support Reports: " << reportCount << "\n";
}

