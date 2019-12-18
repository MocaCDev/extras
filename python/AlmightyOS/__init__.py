import os

def _composing_(comp):
  if comp == None:
    while os.path.isfile(os.getcwd() + '/item_powers.json'):
      open_file = open(os.getcwd() + '/item_powers.json','r')
      print(open_file.read())
      break
    os.system('clear')
  else:
    return comp
