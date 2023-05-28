# Function to display the main menu
def display_menu():
    print("\n \n \nWelcome to the Library Catalog!")
    print("1. User Login")
    print("2. Manager Login")
    print("0. Exit \n")

# Function to handle user login
def user_login():
    username = input("\n=> Enter your username: ")
    password = input("=> Enter your password: ")

    if username in users and users[username] == password:
        display_user_menu()
    else:
        print("\nInvalid username or password. \n")

# Function to display the user menu
def display_user_menu():
    while True:
        print("\n User Menu:")
        print("1. Search Book")
        print("2. Borrow Book")
        print("0. Logout")

        choice = input("\n=> Enter your choice: ")
        if choice == '1':
            search_book()
        elif choice == '2':
            borrow_book()
        elif choice == '0':
            break
        else:
            print("\nInvalid choice. Try again.\n")

# Function to handle manager login
def manager_login():
    username = input("\n=>Enter your username: ")
    password = input("=>Enter your password: ")

    if username in managers and managers[username] == password:
        display_manager_menu()
    else:
        print("\nInvalid username or password.\n")

# Function to display the manager menu
def display_manager_menu():
    while True:
        print("\nManager Menu:")
        print("1. Add Book")
        print("2. View Catalog")
        print("0. Logout")

        choice = input("\n=>Enter your choice: ")
        if choice == '1':
            add_book()
        elif choice == '2':
            view_catalog()
        elif choice == '0':
            break
        else:
            print("\nInvalid choice. Try again.\n")

# Function to search for a book
def search_book():
    title = input("\nEnter the title of the book: ")
    found_books = []

    for book in catalog:
        if book['title'].lower() == title.lower():
            found_books.append(book)

    if found_books:
        print("\nFound book(s):")
        for book in found_books:
            print(f"Title: {book['title']}, Author: {book['author']}")
    else:
        print("\nNo books found.\n")

# Function to borrow a book
def borrow_book():
    title = input("\nEnter the title of the book to borrow: ")
    found_book = None

    for book in catalog:
        if book['title'].lower() == title.lower() and not book['borrowed']:
            found_book = book
            break

    if found_book:
        found_book['borrowed'] = True
        print("\nBook borrowed successfully.\n")
    else:
        print("\nBook not available for borrowing.\n")

# Function to add a book to the catalog
def add_book():
    title = input("\n=>Enter the title of the book: ")
    author = input("=>Enter the author of the book: ")
    catalog.append({'title': title, 'author': author, 'borrowed': False})
    print("\nBook added to the catalog.\n")

# Function to view the catalog
def view_catalog():
    print("\nLibrary Catalog:")
    for book in catalog:
        print(f"Title: {book['title']}, Author: {book['author']}, Borrowed: {book['borrowed']}")

# Dictionary to store user login information
users = {'user1': 'password1', 'user2': 'password2'}

# Dictionary to store manager login information
managers = {'manager1': 'password1', 'manager2': 'password2'}

# List to store books in the library catalog
catalog = []

# Main program loop
while True:
    display_menu()
    choice = input("\n=>Enter your choice: ")

    if choice == '1':
        user_login()
    elif choice == '2':
        manager_login()
    elif choice == '0':
        break
    else:
        print("\nInvalid choice. Try again.\n")
