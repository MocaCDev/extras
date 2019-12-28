import os, json
from time import sleep

class yal:

  def _render_path_(self,**paths_to_render):

    """
      All this will do is render a path, take it apart,
      and return a Render Message, which just returns
      the main path, the main path + the rendered path,
      and the directory path of the rendered path.
      EXAMPLE:
      Main path : /home/runner
      Main Path + rendered path: /home/runner/hey/t.txt
      Directory Path: /hey/t.txt
    """

    self.path_to_render = []
    self.render_msg = []

    if len(paths_to_render['path']) == 1:self.path_to_render.append(paths_to_render['path'][0])
    else:
      for i in range(len(paths_to_render['path'])):
        self.path_to_render.append(paths_to_render['path'][i])
    
    for i in range(len(self.path_to_render)):
      self.render_msg.append("<Rendered from main {},\nRendered into {},\nFrom Directory Path {}>".format(os.environ.get('HOME'),os.environ.get('HOME')+'/'+self.path_to_render[i],os.path.abspath(self.path_to_render[i]).replace(os.environ.get('HOME'),'')))
    
    with open('render_info.json','w') as render_info:
      render_info.write(json.dumps(self.render_msg,indent=2,sort_keys=False))
      render_info.close()
  
  def _return_rendered_(self,timer=4):

    """
      This will return a Render Message
    """

    if os.path.isfile('render_info.json'):
      op = json.loads(open('render_info.json','r').read())

      for i in range(len(op)):
        print(op[i] + '\n')
      
      sleep(timer)
      
      return 0
    else:pass
