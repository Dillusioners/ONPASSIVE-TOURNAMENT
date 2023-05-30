'''
    Author - Debag101
    Purpose - News reader
    Date - 30 05 2023
'''

# importing requests and time modules
import requests
import time

# apiKey, NB - Couldn't give real key for security purposes
# Visit  'https://newsapi.org/docs/authentication' to get your own key

key = '****'
endPoint = 'https://newsapi.org/v2/everything?' # Defining end points

# Defining data parameters
data_params = {
    'q': 'big data', # query phrase
    'pageSize': 20,  # maximum is 100
    'apiKey': key # your own API key
}

# Sending requests 
data = requests.get(endPoint, params=data_params)

#Converting response to json
data_in_json = data.json()

# Printing articles with 10 s intervals
for i in data_in_json['articles']:
    print('Title :', i['title'],'\nAuthor : ', i['author'], '\n', i['content'], '\n', i['description'])
    time.sleep(10)

print("All articles have been printed ")