import requests

# the api key and the url for the API to work properly
api_key = "ae2cc6dc9f311df7bdb4cc596dba3075"
url = f"http://api.coinlayer.com/live?access_key={api_key}"

# function to generate the live response for the crypto chain
def generate_response():
    # getting the response for the API
    response = requests.get(url)

    # if the response has errors, exit
    if response.status_code != 200:
        print("Unable to generate your response.")
        return

    # retrieving the data from the response
    data = response.json()

    # if the 'success' variable in the data is set to False
    if not data["success"]:
        print("API Couldn\'t generate your response.")
        return
    
    # returning rates of the data as per the USD rates
    return data['rates']

# the main function from where the program runs
def main():
    # controls the while-loop
    run = True

    # running until user stops
    while run:
        # asking for the crypto name and making it uppercase
        crypto_name = input("Enter the crypto you want to see rates for (0 to exit): ").upper()

        # if the crypto name starts with 0, exit
        if(crypto_name.startswith('0')):
            print("Closing the crypto machine.....")
            run = False

        # generating the crypto rates
        rates = generate_response()

        # if the crypto provided is not in the provided rates
        if not crypto_name in rates:
            print(f"{crypto_name} was not found.")
            continue
        
        # printing the rates
        print(f"The rates of {crypto_name} are ${rates[crypto_name]}")

# running the program
if __name__ == '__main__':
    main()
