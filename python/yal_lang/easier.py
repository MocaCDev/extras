import os, json, sys
from time import sleep

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
  primary_plats = (('AOP',12000),('NAWK',22000),('LA',32000))
  global local_plats
  local_plats = (('posix',12000),('nt',22000))

  def _setup_platform_(self,plat_to_use):

    """
      This will setup a primary or local platform name.
    """

    if plat_to_use == local_plats[0][0]:
      os.name = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      return '<Platform {} setup complete,\nOS name:{}>'.format(local_plats[0][0],os.name)
    if plat_to_use == local_plats[1][1]:
      os.name = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      return '<Platform {} setup complete,\nOS name:{}>'.format(local_plats[1][1],os.name)
    if plat_to_use == primary_plats[0][0]:
      os.name = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      return '<Platform {} setup complete,\nOS name:{}>'.format(primary_plats[0][0],os.name)
    if plat_to_use == primary_plats[1][1]:
      os.name = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      return '<Platform {} setup complete,\nOS name>'.format(primary_plats[1][1],os.name)
    if plat_to_use == primary_plats[2][2]:
      os.name = plat_to_use
      data = {'new_name':os.name}
      _json_write_('new_os_name.json',data)
      return '<Platform {} setup complete,\nOS name:{}>'.format(primary_plats[2][2],os.name)
    else:raise TypeError('The platform ' + plat_to_use + ' has not been added to the client')
  
  def has_platform(self):

    """
      This is used in a if statement and if it is true then it will return os.name
    """

    if os.path.isfile(os.path.abspath('new_os_name.json')):
      open_ = json.loads(open('new_os_name.json','r').read())

      self.os_name = open_['new_name']

      return (True,os.name)
    else:return False
  
  def _render_yal_files_(self):

    """
      This will render .yal files only in the same way it rendered the other files
    """

    self.yal_files = []
    self.render_yal_file_msg = []
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
    if self.FALSE > self.TRUE:
      if 'look_for' in paths_to_see:
        return (False(self.pre_validated[0],self.pre_validated[1]))
    if self.TRUE == self.FALSE:
      print("Static Render Msg\n<Could not contribute to True or False,\nTRUE:{},\nFALSE:{}>".format(self.TRUE,self.FALSE))
      return False
    
  
  def _return_rendered_(self,timer=4):

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
