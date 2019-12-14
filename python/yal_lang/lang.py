import os
from time import sleep
from colorama import Fore, Style
def read_(**file_to_read):

  for i in range(len(file_to_read['files'])):
    open_file = open(file_to_read['files'][i], 'r').read()
    
    if not os.path.exists(os.environ.get('HOME') + '/extras/python/yal_lang' + '/bach.bach'):
      with open(os.environ.get('HOME') + '/extras/python/yal_lang' + '/bach.bach','w') as bach_file:
        bach_file.write('[file.info]\n')
        bach_file.write(f'   - compiling {file_to_read["files"][i]}')
        bach_file.close()
    if os.path.isfile(os.environ.get('HOME') + '/extras/python/yal_lang' + '/bach.bach'):
      open_bach = open(os.environ.get('HOME') + '/extras/python/yal_lang' + '/bach.bach','r').read()
      if not file_to_read['files'][i] in open_bach:
        with open(os.environ.get('HOME') + '/extras/python/yal_lang' + '/bach.bach','w') as bach_file_:
          bach_file_.write(f'   - compiling {file_to_read["files"][i]}')
    
    read_data = open(os.environ.get('HOME') + '/extras/python/yal_lang/' + 'bach.bach').read()
    print(read_data)
    sleep(1.8)
    os.system('clear')
   
                      
                      

    # IMPORTANT
    open_file = open_file.replace('import name', 'import')
    open_file = open_file.replace('from module', 'from')
    open_file = open_file.replace('trying','try')
    open_file = open_file.replace('except err of','except')
    open_file = open_file.replace('con','f')

    open_file = open_file.replace('keep_track',open(f'{os.environ.get("HOME")}/extras/python/yal_lang/templates/keep_track_of_import.txt','r').read())
    open_file = open_file.replace('print_value','print')
    open_file = open_file.replace('create class','class')
    open_file = open_file.replace('for','for')
    open_file = open_file.replace('in','in')
    open_file = open_file.replace('range_of','range')
    open_file = open_file.replace('class init','def __init__')
    open_file = open_file.replace('true','True')
    open_file = open_file.replace('false','False')
    open_file = open_file.replace('nil','None')
    open_file = open_file.replace('class error', open(f'{os.environ.get("HOME")}/extras/python/yal_lang/templates/class_error.txt','r').read())
    open_file = open_file.replace('this','self')
    open_file = open_file.replace('class func','def')
    open_file = open_file.replace('get_length','len')
    open_file = open_file.replace('end_with','end')
    open_file = open_file.replace('INTEGER','int')
    open_file = open_file.replace('replace_value','replace')
    open_file = open_file.replace('use as','as')
    open_file = open_file.replace('null','None')
    open_file = open_file.replace('if value of', 'if')
    open_file = open_file.replace('||','or')
    open_file = open_file.replace('&&','and')
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

    with open(file_to_read['files'][i].replace('.yal','.py'), 'w') as file:
      file.write(open_file)

    os.system('clear')
    print(Fore.WHITE + 'EXECUTING_MAIN -> ' + file_to_read['files'][i])
    exec(open(file_to_read['files'][i].replace('.yal','.py'),'r').read())
