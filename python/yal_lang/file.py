import os
from lang import read_

MAIN_PATH = os.environ.get('HOME')

get_file = input('File: ')

get_file = MAIN_PATH + '/' + get_file

if not '.yal' in get_file:
  raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(get_file)
