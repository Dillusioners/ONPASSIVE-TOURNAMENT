import os

# function to sort files alphabetically
def alphabetically():
    print("")
    # iterating through the set version of listed directory
    for i in set(os.listdir()):
        print(i)

# function to sort based on file size
def filesize():
    # getting the directory list
    files = os.listdir()

    # bubblesorting the list based on file size
    for _ in range(len(files)):
        for j in range(len(files) - 1):
            # if the current index file size is greater than the next index file size
            if os.stat(files[j])[6] > os.stat(files[j + 1])[6]:
                # swapping the indexes
                temp = files[j]
                files[j] = files[j + 1]
                files[j + 1] = temp

    # printing the sorted list
    for itr in files:
        print(itr)

# function to sort based on file extensions
def fileext():
    # getting directory list
    files = os.listdir()

    # bubblesorting the list based on the file extensions
    for _ in range(len(files)):
        for j in range(len(files) - 1):
            # getting the file extensions of the current and next index
            ext1 = os.path.splitext(files[j])[1][1:]
            ext2 = os.path.splitext(files[j + 1])[1][1:]

            # if the current index is greater than the next index
            if ext1 > ext2:
                # swapping the values
                temp = files[j]
                files[j] = files[j + 1]
                files[j + 1] = temp

    # printing the sorted list
    for itr in files:
        print(itr)

# program execution starts from here
def main():
    run = True

    # running until user stops
    while(run):
        # printing menu and asking for user input
        print("\nFile Organizer Menu:")
        print("1. Alphabetically\n2. File Size\n3. File Extension\n4. Exit Program")
        choice = input(">> ")

        # sort alphabetically
        if(choice == "1"):
            alphabetically()
            
        # sort by file size
        elif(choice == "2"):
            filesize()

        # sort by file extension
        elif(choice == "3"):
            fileext()

        # exit program
        elif(choice == "4"):
            run = False
            continue

        # invalid literal
        else:
            print("Invalid choice provided.")

# running the program
if __name__ == "__main__":
    main()