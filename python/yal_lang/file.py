import os
from lang import read_

get_file = input('File: ')

if not '.yal' in get_file:
  raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(get_file)
