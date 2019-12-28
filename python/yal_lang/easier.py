import os, json
from time import sleep

class yal:

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
      use it in a if statement and continue from there
    """

    if 'look_for' in paths_to_see:
      if type(paths_to_see['look_for']) == list:
        raise TypeError('Cannot use a list to look for a certain rendered path')

      self.check_for = paths_to_see['look_for']

      if self.check_for in self.is_rendered_path:self.pre_validated=[f'{self.check_for}:{True}',True]
      else:self.pre_validated=[f'{self.check_for}:{False}',False]
    for i in range(len(paths_to_see['check'])):
      if paths_to_see['check'][i] in self.is_rendered_path:self.validated = True
      else:self.validated = False
    
    if 'look_for' in paths_to_see:
      for i in range(len(paths_to_see['check'])):
        if self.validated:return ((f'{paths_to_see["check"][i]}:{True}',True),(self.pre_validated[0],self.pre_validated[1]))
        else:return ((f'{paths_to_see[i]}:{False}',False),(self.pre_validated[0],self.pre_validated[1]))
    else:
      for i in range(len(paths_to_see['check'])):
        if self.validated:return f'{paths_to_see["check"][i]}:{True}'
        else:return f'{paths_to_see["check"][i]}:{False}'

  
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
