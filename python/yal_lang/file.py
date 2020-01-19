import os
from lang import read_
from easier import yal
from time import sleep

# gathering all the functions
yal = yal()

yal._open_file_('data.txt',read=True)

# Setting up a platform
yal._setup_platform_('YAL_ORIGINAL')

# Rendering all yal files
yal._render_yal_files_()

os.system('clear')

main_path = os.environ.get('HOME')
path = os.getcwd().replace('/extras/python/yal_lang','')
os.chdir(path)
get_file = []

for i in range(len(os.listdir())):
  if '.yal' in os.listdir()[i]:
    if os.listdir()[i] == 'file.yal':
      raise NameError('The name ' + os.listdir()[i] + ' cannot be used\n\nThe file ' + os.listdir()[i] + ' has been deleted')
      os.remove('file.yal')
    get_file.append(path + '/' + os.listdir()[i])


#if not '.yal' in get_file:
  #raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(files=get_file,path=path)
