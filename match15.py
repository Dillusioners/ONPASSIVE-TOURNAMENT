import random
import time
import os

# List of colors
colors = ["red", "green", "blue", "yellow", "orange", "pink", "black", "white"]

# Function to generate a random sequence of colors
def generate_sequence(length):
    return [random.choice(colors) for _ in range(length)]

# Function to display the sequence to the player
def display_sequence(sequence):
    for color in sequence:
        print(color)
        time.sleep(1)
        clear_screen()

# Function to clear the screen
def clear_screen():
    os.system('cls')

# Function to get the player's guess
def get_player_guess():
    guess = input("Enter the sequence of colors, separated by spaces: ").lower().split()
    return guess

# Function to check if the player's guess matches the sequence
def check_guess(sequence, guess):
    return sequence == guess

# Function to play the game
def play_game():
    clear_screen()
    print("Welcome to Simon Says!")
    time.sleep(1)

    level = 1
    while True:
        print(f"Level {level}")
        sequence = generate_sequence(level)
        display_sequence(sequence)
        player_guess = get_player_guess()

        if check_guess(sequence, player_guess):
            print("Correct! Moving on to the next level...")
            level += 1
            time.sleep(2)
            clear_screen()
        else:
            print(f"Wrong answer! Game over. Your final score is: {level - 1}")
            break

# Main program
if __name__ == "__main__":
    play_game()
