import os
from lang import read_

main_path = os.environ.get('HOME')
os.chdir(main_path)
get_file = []

for i in range(len(os.listdir())):
  if '.yal' in os.listdir()[i]:
    if 'main.yal' == os.listdir()[i]:
      os.remove
      raise NameError('The name ' + os.listdir()[i] + ' cannot be used')
    get_file.append(main_path + '/' + os.listdir()[i])


#if not '.yal' in get_file:
  #raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(files=get_file)
