import random

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

print(id)
