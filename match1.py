#Author:- Dynamax
#Opponent:- First Class
#Topic:- Memory Game

import random

# Create a deck of cards
deck = ['A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H']
random.shuffle(deck)

# Create a board to display the cards
board = ['*'] * 16

# Keep track of flipped cards
flipped_cards = []

# Function to display the board
def display_board():
    for i in range(0, 16, 4):
        print(board[i], board[i+1], board[i+2], board[i+3])

# Function to check if all cards are matched
def all_cards_matched():
    return all(card == ' ' for card in board)

# Main game loop
while not all_cards_matched():
    display_board()

    # Get the player's guess
    first_card_index = int(input("Enter the index of the first card to flip (0-15): "))
    second_card_index = int(input("Enter the index of the second card to flip (0-15): "))

    # Check if the cards are valid
    if first_card_index < 0 or first_card_index > 15 or second_card_index < 0 or second_card_index > 15:
        print("Invalid card index. Please try again.")
        continue

    # Check if the cards are already flipped or matched
    if board[first_card_index] != '*' or board[second_card_index] != '*':
        print("Those cards have already been flipped. Please try again.")
        continue

    # Flip the cards
    board[first_card_index] = deck[first_card_index]
    board[second_card_index] = deck[second_card_index]

    # Display the updated board
    display_board()

    # Check if the cards match
    if deck[first_card_index] == deck[second_card_index]:
        print("Match found!")
        flipped_cards.append(first_card_index)
        flipped_cards.append(second_card_index)
    else:
        # Cards don't match, flip them back
        board[first_card_index] = '*'
        board[second_card_index] = '*'
        print("No match. Try again.")

    # Clear the flipped cards if all cards have been matched
    if all_cards_matched():
        flipped_cards = []

# Game over
print("Congratulations! You have matched all the cards!")
