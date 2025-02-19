class BankAccount:
    def __init__(self, account_number, holder_name, balance=0):
        self.account_number=account_number
        self.holder_name=holder_name
        self.balance=balance

    def deposit(self, amount):
        if amount>0:
            self.balance+=amount
            print(f"Deposited {amount}. New balance: {self.balance}")
        else:
            print("Deposit amount must be positive")

    def withdraw(self, amount):
        if 0<amount<self.balance:
            self.balance-=amount
            print(f"Withdrew {amount}. New balance: {self.balance}")
        else:
            print("Insufficient balance or invalid amount")

    def get_balance(self):
        return self.balance
    
class Bank:
    def __init__(self):
        self.accounts={}

    def create_account(self, account_number, holder_name, initial_deposit=0):
        if account_number in self.accounts:
            print("Account already exists.")
            return
        self.accounts[account_number]=BankAccount(account_number, holder_name, initial_deposit)
        print(f"Account created for {holder_name} with balance {initial_deposit}")

    def get_account(self, account_number):
        return self.accounts.get(account_number, None)
    
bank = Bank()
bank.create_account("12345", "John Doe", 1000)
account = bank.get_account("12345")
if account:
    account.deposit(500)
    account.withdraw(200)
    print(f"Final balance: {account.get_balance()}")