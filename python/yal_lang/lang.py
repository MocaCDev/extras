import os
def read_(file_to_read):
  open_file = open(file_to_read, 'r').read()

  # IMPORTANT
  open_file = open_file.replace('import name', 'import')
  open_file = open_file.replace('from module', 'from')

  open_file = open_file.replace('print_value','print')
  open_file = open_file.replace('create class','class')
  open_file = open_file.replace('class init','def __init__')
  open_file = open_file.replace('true','True')
  open_file = open_file.replace('false','False')
  open_file = open_file.replace('class error', open('templates/class_error.txt','r').read())
  open_file = open_file.replace('this','self')
  open_file = open_file.replace('class func','def')
  open_file = open_file.replace('end_with','end')
  open_file = open_file.replace('INTEGER','int')
  open_file = open_file.replace('replace_value','replace')
  open_file = open_file.replace('use as','as')
  open_file = open_file.replace('if value of', 'if')
  open_file = open_file.replace('if not value of','if not')
  open_file = open_file.replace('err','raise')
  open_file = open_file.replace('help_on','help')
  open_file = open_file.replace('--','#')
  open_file = open_file.replace('class_msg_start','"""')
  open_file = open_file.replace('class_msg_end','"""')
  open_file = open_file.replace('-[','"""')
  open_file = open_file.replace(']-','"""')
  open_file = open_file.replace('is equal to','==')
  open_file = open_file.replace('func','def')
  open_file = open_file.replace('write_file','with open')
  open_file = open_file.replace('open_file','open')
  open_file = open_file.replace('read_value','read')
  open_file = open_file.replace('return_value','return')
  open_file = open_file.replace('send','write')
  open_file = open_file.replace('gather_input','input')
  open_file = open_file.replace(' then', ':')
  open_file = open_file.replace('new ','')
  open_file = open_file.replace('STRING','str')
  if 'from module time import name sleep' in open_file:
    open_file = open_file.replace('setTimeout','sleep')
  elif 'import name time' in open_file:
    open_file = open_file.replace('setTimeout','time.sleep')

  with open(file_to_read.replace('.yal','.py'), 'w') as file:
    file.write(open_file)

  os.system('clear')
  exec(open(file_to_read.replace('.yal','.py'),'r').read())