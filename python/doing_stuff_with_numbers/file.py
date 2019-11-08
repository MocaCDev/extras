from time import sleep
from math import floor
import json
d = []
r = True
while r:
  get_num_one = int(input('Number One >> '))
  get_num_two = int(input('Number Two >> '))
  total = get_num_one * get_num_two
  for i in range(total):
    d.append(i)
    print(i+1)
  r =False
op = open('data.txt','w')
op.write(str(d))
op.close()

FAILED_ATTEMPTS = []
SUCCESS_ATTEMPTS = []
get_mod = int(input('Remainder of number divided by >> '))
for i in d:
  try:
    if d[i] % get_mod == 0:
      FAILED_ATTEMPTS.append({f'failed_attempts':{i:i/8,'returned':0}})
      print('Failed on # ' + str(i) + '\nReturned ' + str(floor(i / 8)))
      sleep(.000000001)
    else:
      SUCCESS_ATTEMPTS.append({f'success_attempts':{i:f"{d[i]}*{d[i+1]}",'returned':d[i]*d[i+1]}})
      FAILED_ATTEMPTS[0].update({'SUCCESS_ATTEMPTS':SUCCESS_ATTEMPTS})
      print(str(d[i] * d[i+1] + 10000) + '\n')
  except IndexError:
    print('Done')

with open('data.json','w') as file:
  to_json = json.dumps(FAILED_ATTEMPTS,indent=2,sort_keys=False)
  file.write(to_json)
  file.close()
