import os, json, sys
from time import sleep
from colorama import Fore
from client_plugin.client_plug import yal_client_plugin
from client_plugin.errors import (
  CouldNotLocateFile
)

y_c_p = yal_client_plugin()

primary_plats = ()
local_plats = ()

def _json_write_(file_name,data):

  """
    This is a function that is to only be used if you are writing data that has been loaded by the json module:
      json.load
      json.loads
  """

  with open(file_name,'w') as file:
    file.write(json.dumps(data,indent=2))
    file.close()

class yal:

  # This will be primary systems for yal(all made up by .yal language)
  global primary_plats
  primary_plats = ('AOP','NAWK','LA','YAL_ORIGINAL')
  # This will be local systems for yal
  global local_plats
  local_plats = ('posix','nt')

  def _setup_platform_(self,plat_to_use):

    """
      This will setup a primary or local platform name.
    """


    if plat_to_use == local_plats[0]:
      os.name,sys.platform = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=5000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name:{}>'.format(local_plats[0],os.name)
    if plat_to_use == local_plats[1]:
      os.name,sys.platform = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=6000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name:{}>'.format(local_plats[1],os.name)
    if plat_to_use == primary_plats[0]:
      os.name,sys.platform = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=7000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name:{}>'.format(primary_plats[0],os.name)
    if plat_to_use == primary_plats[1]:
      os.name,sys.platform = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=8000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name>'.format(primary_plats[1],os.name)
    if plat_to_use == primary_plats[2]:
      os.name,sys.platform = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=9000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name:{}>'.format(primary_plats[2],os.name)
    if plat_to_use == primary_plats[3]:
      os.name = primary_plats[3]
      sys.platform = primary_plats[3]
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      y_c_p._complete_platform_(storage_amount=10000000000000)
      y_c_p._return_platform_()
      return '<Platform {} setup complete,\nOS name:{}>'.format(primary_plats[3],os.name)
      sleep(10)
    else:raise TypeError('The platform ' + plat_to_use + ' has not been added to the client')
  
  def has_platform(self):

    """
      This is used in a if statement and if it is true then it will return os.name

      Since y_c_p._complete_platform_ deletes new_os_name.json, we will just check if the file new_os.json exists
    """

    if os.path.isfile(os.path.abspath('new_os.json')):
      open_ = json.loads(open('new_os.json','r').read())

      self.os_name = open_['os_name'][1]

      y_c_p._return_storage_amount_()

      return True
    else:return False
  
  "this function goes along with has_platform"
  def _return_platform_name_(self):

    "this will just return the platform name"
    return os.name
  
  def _yal_filenames_(self) -> tuple:

    """This will gather all yal filenames.
       
       This function will be important later on in case the developer wants to do stuff with the list of .yal files it finds
    """

    self.files = ()
    self.append_files = []

    for i in range(len(os.listdir())):
      if '.yal' in os.listdir()[i]:
        self.append_files.append(os.listdir()[i])
    
    self.files = tuple(self.append_files)
    
    return self.files
  
  def _is_yal_file_(self,filename) -> bool:

    """This is used in a if statement

       This will be used to check if the filename of which is given to the argument filename is in self.files.
    """

    if filename in self.files:return True
    else:return False
  
  def _open_file_(self,file_to_open:'str',read=False):

    """
      This will open a file and then root it to the terminal.

      Files created:
        IMPORTANT.json:
          - Defines the files that are important to the Yal Application
      
      Arguments:
        file_to_open: The file of which you want to open
        read: Print the values of the file to the terminal
      
      The function _open_file_ will open the file, root the file as a copy, and store data about the file in a .json database.
    """

    # /data/data/com.termux/files/usr/bin/
    # /home/runner/yal/client_plugin/


    if os.path.isfile(os.path.abspath(file_to_open)):

      bash_run = '''if [ ! -d /data/data/com.termux/files/usr/bin/{0} ]; then
  mv -v {1} /data/data/com.termux/files/usr/bin/
  chmod +x /data/data/com.termux/files/usr/bin/{2}
  echo "==> DONE!"
  cd
  exit
fi
fi'''

      if file_to_open.endswith('.json'):open_ = json.loads(open(os.path.abspath(file_to_open),'r').read())
      else:open_ = open(os.path.abspath(file_to_open),'r').read()

      if read:
        print(open_)
      
      file_to_open = file_to_open.replace(file_to_open[0],file_to_open[0].upper())

      with open(file_to_open,'w') as file:
        file.write(open_)
        file.close()
      
      if not os.path.isfile(f'/data/data/com.termux/files/usr/bin/{file_to_open}'):
        os.system(bash_run.format(file_to_open,file_to_open,file_to_open))

      sleep(2)

      os.system('clear')
    
    else:raise CouldNotLocateFile('Could not locate the file ' + file_to_open + ', with root: ' + os.path.abspath(file_to_open))
  
  def _root_dir_(self,directory:'str') -> [str,str]:
    
    """
      This will root a whole directory. This is a very powerful function due to the fact it is rooting a whole directory
    """
    
    bash_run = '''if [ ! -d /data/data/com.termux/files/usr/bin/{0} ]; then
  mv -v {1} /data/data/com.termux/files/usr/bin/
  echo "==> DONE!"
  cd
  exit
fi
fi'''

    if not os.path.isfile('root_info.json'):
      os.system(bash_run.format(directory,directory,directory))

    new_dir = f'/data/data/com.termux/files/usr/bin/{directory.replace(os.path.abspath("."),"")}'
    
    if '/data/data/com.termux/files/home' in directory:
      directory = directory.replace('/data/data/com.termux/files/home')
    
    root_info_ = {'rooted':directory,'to':f'/data/data/com.termux/files/usr/bin/{directory}'}
    
    with open('root_info.json','w') as root_info:
      root_info.write(json.dumps(
        root_info_,
        indent=2,
        sort_keys=False
      ))
      root_info.close()

    return print([directory,new_dir]) # index 1: old dir, index 2: new dir

  
  def _render_yal_files_(self):

    """
      This will render .yal files only in the same way it rendered the other files
    """

    self.yal_files = []
    self.render_yal_file_msg = []
    self.rendered_yal_files = []
    self.is_yal_file = None

    for i in range(len(os.listdir())):
      if '.yal' in os.listdir()[i]:
        self.yal_files.append(os.listdir()[i])
    
    for i in range(len(self.yal_files)):

      if os.path.isfile(os.path.abspath(os.listdir()[i])):
        self.is_yal_file = True
      
      if self.is_yal_file:
        message_to_admit = '''-- This file has been rendered by the Yal Language Application(easier.py)\n--Message admitted by ARACADERISE'''
        old_info = open(os.path.abspath(self.yal_files[i]),'r').read()
        if message_to_admit in open(os.path.abspath(self.yal_files[i]),'r').read():pass
        else:
          with open(os.path.abspath(self.yal_files[i]),'w') as update_file:
            update_file.write(message_to_admit)
            update_file.write('\n'+old_info)
            update_file.close()
      
      self.render_yal_file_msg.append('<Rendered from main {},\nRendered into {},\nFrom Directory Path {},\nPrimary Path {},\nIs A Dir: {}>'.format(os.environ.get('HOME'),os.environ.get('HOME')+'/'+self.yal_files[i],os.path.abspath(self.yal_files[i]).replace(os.environ.get('HOME'),''),self.yal_files[i],self.is_yal_file))
      self.rendered_yal_files.append(self.yal_files[i])
    
    with open('render_yal_files.json','w') as file:
      file.write(json.dumps(self.rendered_yal_files,indent=2))
      file.close()
    
  def _return_rendered_yal_files_(self) -> list:

    "this will just return the list of rendered yal files"

    if os.path.isfile(os.path.abspath('render_yal_files.json')):
      return self.rendered_yal_files
    else:
      print('You have not rendered any .yal files through yal._render_yal_files_')

  def _render_path_(self,**paths_to_render):

    """
      All this will do is render a path, take it apart,
      and return a Render Message, which just returns
      the main path, the main path + the rendered path,
      the directory path of the rendered path, and the
      primary path. Last but not least, Is A Dir.
      EXAMPLE:
      Main path : /home/runner
      Main Path + rendered path: /home/runner/hey/t.txt
      Directory Path: /hey/t.txt
      Primary Path: hey/t.xt
      Is A Dir: False
    """

    self.path_to_render = []
    self.render_msg = []
    self.is_rendered_path = []

    if len(paths_to_render['path']) == 1:self.path_to_render.append(paths_to_render['path'][0])
    else:
      for i in range(len(paths_to_render['path'])):
        self.path_to_render.append(paths_to_render['path'][i])
    
    for i in range(len(self.path_to_render)):
      if os.path.isfile(os.path.abspath(self.path_to_render[i])):self.is_dir=True
      else:self.is_dir=False
          
      self.render_msg.append("<Rendered from main {},\nRendered into {},\nFrom Directory Path {},\nPrimary Path {},\nIs A Dir: {}>".format(os.environ.get('HOME'),os.environ.get('HOME')+'/'+self.path_to_render[i],os.path.abspath(self.path_to_render[i]).replace(os.environ.get('HOME'),''),self.path_to_render[i],self.is_dir))
      self.is_rendered_path.append(self.path_to_render[i])
    
    sys.path.append(self.is_rendered_path)

    with open('render_info.json','w') as render_info:
      render_info.write(json.dumps(self.render_msg,indent=2,sort_keys=False))
      render_info.close()
  
  def is_a_rendered_path(self,**paths_to_see):

    """
      Checks to see if a path is rendered.
      Arguments:
        check: must be a list of at least a length of 1
        look_for: must be a string of which you are looking for a certain rendered path, if it exists
      You can print this to get the returned data, or
      use it in a if statement and continue from there.

      NOTE:
        The majority count will control what way the if statement goes.
        Example:
        2 True, 1 False, the if statement is True and will compile
        If it is 1 True 1 False it will return a "Static Render Msg"
    """

    self.validated = []
    self.TRUE = 0
    self.FALSE = 0
    self.return_ = tuple

    if 'look_for' in paths_to_see:
      if type(paths_to_see['look_for']) != str:
        raise TypeError('The type of "look_for" must be of type str, not ' + str(type(paths_to_see['look_for'])))
      
      self.check_for = paths_to_see['look_for']

      if self.check_for in self.is_rendered_path:self.pre_validated=[f'{self.check_for}:{True}',True]
      else:self.pre_validated=[f'{self.check_for}:{False}',False]

    for i in range(len(paths_to_see['check'])):
      if paths_to_see['check'][i] in self.is_rendered_path:self.validated.append(True)
      else:self.validated.append(False)
    
    for i in range(len(self.validated)):
      if self.validated[i] is True:self.TRUE += 1
      else:self.FALSE += 1
    
    if self.TRUE > self.FALSE:
      if 'look_for' in paths_to_see:
        return (True,(self.pre_validated[0],self.pre_validated[1]))
      else:
        return True
    if self.FALSE > self.TRUE:
      if 'look_for' in paths_to_see:
        return (False,(self.pre_validated[0],self.pre_validated[1]))
      else:
        return False
    if self.TRUE == self.FALSE:
      print("Static Render Msg\n<Could not contribute to True or False,\nTRUE:{},\nFALSE:{}>".format(self.TRUE,self.FALSE))
      return (False,'Static Render Message')
    
  
  def _return_rendered_(self,timer=4) -> list:

    """
      This will return a Render Message
    """
    
    self.return_render_msg = []

    if os.path.isfile('render_info.json'):
      op = json.loads(open('render_info.json','r').read())

      for i in range(len(op)):
        print(op[i] + '\n')
        self.return_render_msg.append(op[i])
      
      sleep(timer)

      os.system('clear')

      return self.return_render_msg
    else:pass
