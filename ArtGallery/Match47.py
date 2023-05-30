'''
    Author - Debag101
    Purpose - Art Gallery
    Date - 30 05 2023
'''

# importing os module and Image from pillow module
import os
from PIL import Image

# image files list
images = []
# image paths in a string
path = "H:\\ArtGallery\\Images"

def gallery_images_get(path):
    # Getting image files insdie the list
    image = [file for file in os.listdir(path) if file.endswith(".png")]
    # returning list
    return image


def openImages(images, choice):
    # Getting the filename of image to display
    image_to_display = images[choice - 1]
    # Creating actual path
    image_path = os.path.join(path, image_to_display)
    # Loading and displaying image
    image = Image.open(image_path)
    image.show()


def gallery_images_display():
    # Simple header 
    print("======= ART GALLERY =======\n")
    # Printing available images
    for index, image in enumerate(images):
        print(f"{index+1}> {image}")
    print("Enter 0 to exit !")

    #User can open as many images as he wants
    while(True):
        try:
            user_choice = int(input(">> Which image do you want to see => "))
            if user_choice < 0 or user_choice > len(images):
                print("Invalid choice !")
            elif user_choice == 0:
                break
            else:
                openImages(images, user_choice)
        except ValueError:
            print("Please enter numbers only")


# Driver code
images = gallery_images_get(path)
gallery_images_display()

print("Thank you for visiting !!!")
