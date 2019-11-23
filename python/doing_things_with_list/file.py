import os, sys, subprocess, json, csv
from math import floor
from colorama import Fore,Style

"will store data in different styles"

get_range = int(input('Range: '))

# Will be used when writing csv file
exists = []

append_range = [i for i in range(get_range) if not get_range < 1]

# This will be what the numbers are divided by
divide_by = int(input('Divide each number by: '))

for i in append_range:
  if append_range[i] % 3 == 0:
    append_range[i] = [i,True,{'divided_by':3,'returns':floor(append_range[i]/3)}]
  else:
    if append_range[i] % divide_by == 0:
      append_range[i] = [i,True,{'divided_by':divide_by,'returns':append_range[i]/divide_by}]
    else:
      append_range[i] = [i,False,{'divided_by':divide_by,'returns':append_range[i]/divide_by}]

"Opens in .json format"
with open('data.json','w') as file:
  to_json = json.dumps(append_range,indent=2,sort_keys=False)
  file.write(to_json)
  file.close()

"Opens in .csv foramt"
with open('data.csv','w',newline='') as file:
  if not 'number_is_true' in exists:
    file.write('value,dividing_by,returns,number_is_true')
    exists.append('number_is_true')
  for i in range(len(append_range)):
    if True in append_range[i]:
      if append_range[i][0] / divide_by == i / divide_by:
        file.write('\n'+f'{i},{divide_by},{floor(append_range[i][0]/divide_by)},IS TRUE')
      else:
        file.write('\n'+f'{i},{divide_by},{floor(i/divide_by)},IS TRUE')
    else:
      if append_range[i][0] / divide_by == i / divide_by:
        file.write('\n'+f'{i},{divide_by},{append_range[i][0]/divide_by},IS FALSE')
      else:
        file.write('\n'+f'{i},{divide_by},{i/divide_by},IS FALSE')
    if append_range[i] == get_range-1:
      file.close()
      break

"Opens in .toml format"
with open('data.toml','w') as file:
  file.write('[number_DATA]')
  for i in range(len(append_range)):
    if i == 225:
      file.write('\n' + ' [divide]\n  number = ' + str(i) + '\n  divide_by = ' + str(divide_by) + '\n  returns = ' + str(225/divide_by))
    else:
      if append_range[i][0] / divide_by == i / divide_by:
        file.write('\n' + ' [divide]\n  number = ' + str(i) + '\n  divide_by = ' + str(divide_by) + '\n  returns = ' + str(append_range[i][0]/divide_by))
      else:
        file.write('\n' + ' [divide]\n  number = ' + str(i) + '\n  divide_by = ' + str(divide_by) + '\n  returns = ' + str(i/divide_by))
    if append_range[i] == get_range-1:
      file.close()
      break
