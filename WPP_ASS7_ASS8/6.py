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

    def display(self):
        return self.balance
    
account = BankAccount("123456789", 1000)
account.display()
account.deposit(500)
account.withdraw(300)
account.display()