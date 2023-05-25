import random

# Define the card values
card_values = {
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '10': 10,
    'J': 10,
    'Q': 10,
    'K': 10,
    'A': 11
}

# Define the deck
deck = list(card_values.keys()) * 4

# Define the player and dealer hands
player_hand = []
dealer_hand = []

# Define the initial deal
for i in range(2):
    player_card = random.choice(deck)
    deck.remove(player_card)
    player_hand.append(player_card)

    dealer_card = random.choice(deck)
    deck.remove(dealer_card)
    dealer_hand.append(dealer_card)

# Define the function to calculate the hand value
def calculate_hand(hand):
    hand_value = 0
    num_aces = 0
    for card in hand:
        hand_value += card_values[card]
        if card == 'A':
            num_aces += 1

    while hand_value > 21 and num_aces:
        hand_value -= 10
        num_aces -= 1

    return hand_value

# Define the function to show the hands
def show_hands():
    print(f"Player's hand: {player_hand} ({calculate_hand(player_hand)})")
    print(f"Dealer's hand: {dealer_hand[0]} (X)")

# Show the initial hands
show_hands()

# Define the player's turn
while True:
    choice = input("Would you like to hit or stand? ")

    if choice.lower() == "hit":
        player_card = random.choice(deck)
        deck.remove(player_card)
        player_hand.append(player_card)

        show_hands()

        if calculate_hand(player_hand) > 21:
            print("Bust! Dealer wins.")
            break
    elif choice.lower() == "stand":
        break
    else:
        print("Invalid input. Please enter 'hit' or 'stand'.")

# Define the dealer's turn
if calculate_hand(player_hand) <= 21:
    while calculate_hand(dealer_hand) < 17:
        dealer_card = random.choice(deck)
        deck.remove(dealer_card)
        dealer_hand.append(dealer_card)

        show_hands()

        if calculate_hand(dealer_hand) > 21:
            print("Dealer busts! Player wins.")
            break

# Determine the winner
if calculate_hand(player_hand) > calculate_hand(dealer_hand):
    print("Player wins!")
elif calculate_hand(player_hand) < calculate_hand(dealer_hand):
    print("Dealer wins!")
else:
    print("It's a tie!")
