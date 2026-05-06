#include <stdio.h>

typedef struct {
    int AcNumber;
    char CustName[100];
    float AvlBalance;
    char AccType[25];
}BankMgmt;

void withdrawal(BankMgmt *account) {
    float amount;
    printf("Enter amount to be withdrawn: ");
    scanf("%f",&amount);
    if(amount>account->AvlBalance) {
        printf("Insufficient Balance! Withdrawal Failed.\n");
    }
    else {
        account->AvlBalance-=amount;
        printf("Withdrawal Successful. Updated balance: %f\n",account->AvlBalance);
    }
}

void deposit(BankMgmt *account) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f",&amount);
    if(amount<0) {
        printf("Invalid deposit ammount.\n");
    }
    else {
        account->AvlBalance+=amount;
        printf("Deposit Successful. Updated balance: %f\n",account->AvlBalance);
    }
}

void displayBalance(BankMgmt *account) {
    printf("\nAccount Details\n");
    printf("Account Number: %d\n",account->AcNumber);
    printf("Customer Name: %s\n",account->CustName);
    printf("Available Balance: %f\n",account->AvlBalance);
    printf("Account Type: %s\n",account->AccType);
}

int main() {
    BankMgmt account;
    int ch=0;
    printf("Enter account number: ");
    scanf("%d",&account.AcNumber);
    getchar();
    printf("Enter customer name: ");
    fgets(account.CustName,sizeof(account.CustName),stdin);
    printf("Enter initial balance: ");
    scanf("%f",&account.AvlBalance);
    printf("Enter account type: ");
    scanf("%s",account.AccType);

    while(ch!=4) {
        printf("\nBank Management Application\n");
        printf("1. Withdrawal\n");
        printf("2. Deposit\n");
        printf("3. Dsplay Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
            withdrawal(&account);
            break;
            case 2:
            deposit(&account);
            break;
            case 3:
            displayBalance(&account);
            break;
            case 4:
            printf("Exiting the application!");
            return 1;
            default:
            printf("Invalid Choice!");
        }
    }
}
