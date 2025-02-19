import random

class Rock_paper_scissors:
    def __init__(self, total_rounds):
        self.total_rounds=total_rounds
        self.current_round=0
        self.user_wins=0
        self.computer_wins=0
        self.choices=["rock","paper","scissors"]


    def get_computer_choice(self):
        return random.choice(self.choices)
    
    def find_winner(self, user_choice, computer_choice):
        if user_choice==computer_choice:
            return "Tie"
        elif (user_choice=="rock" and computer_choice=="scissors") or (user_choice=="scissors" and computer_choice=="paper") or (user_choice=="paper" and computer_choice=="rock"):
            self.user_wins+=1
            return "User"
        else:
            self.computer_wins+=1
            return "Computer"
        
    def has_winner(self):
        if self.user_wins>self.total_rounds//2:
            return "User Wins the Game!"
        elif self.computer_wins>self.total_rounds//2:
            return "Computer Wins the Game!"
        return None
    
    def play_round(self, user_choice):
        if self.current_round>=self.total_rounds:
            return "Game Over!"
        
        self.current_round+=1
        computer_choice=self.get_computer_choice()
        round_winner=self.find_winner(user_choice, computer_choice)
        game_winner=self.has_winner()

        return {
            "round": self.current_round,
            "user_choice": user_choice,
            "computer_choice": computer_choice,
            "round_winner": round_winner,
            "game_winner": game_winner
        }
    
total_rounds=int(input("Enter the numbr of rounds: "))
game=Rock_paper_scissors(total_rounds)

while game.current_round < game.total_rounds:
    user_choice=input("Enter your choice (rock, paper, scissors): ").lower()
    if user_choice not in game.choices:
        print("Invalid choice. Try again.")
        continue
    result=game.play_round(user_choice)
    print(result)