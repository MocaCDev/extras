"""
  This is just a random Python project using 2 moudles:
    Flask, os and random
  
  What's the point?
    Basically all I want to do is create a random id each time the application is ran, and host it using Flask.
  
  NOTE:
    the module os is used just to pip install flask in the console
"""

import random, os
from flask import Flask

# this is if the user doesn't have flask installed
os.system('pip install flask')

# setting up flask
app = Flask(__name__)

list_of_variables = [
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',
  'A',
  'B',
  'C',
  'D',
  'E',
  'F',
  'G',
  'H'
]

# this will be the id
id = ''

# this will be a continous loop for random.choice
while True:

  # this will build the id
  # it will be different each time, due to the fact we are using the module random
  id += random.choice(list_of_variables)

  # the id will only be a length of 9 variables
  if len(id) > 9:
    break

# this will make a html version to use with flask
html_version = f"<h1>ID:{id}</h1>"

@app.route('/')
def hoster():
  return html_version
hoster()
