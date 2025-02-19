class Password_manager:
    def __init__(self):
        self.old_passwords=[]

    def get_password(self):
        if self.old_passwords:
            return self.old_passwords[-1]
        else:
            return None
        
    def set_password(self, new_password):
        if new_password not in self.old_passwords:
            self.old_passwords.append(new_password)
            print("Password updated successfully!")
        else:
            print("Password has been used before. Choose a different one.")

    def is_correct(self, password):
        return password==self.get_password()
    
manager=Password_manager()
manager.set_password("password123")
print(manager.get_password())

manager.set_password("password123")
manager.set_password("new_secure_pass")
print(manager.get_password())

print(manager.is_correct("wrong_pass"))
print(manager.is_correct("new_secure_pass"))