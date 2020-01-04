# this will be a plugin for the Yal Language App client
# and the Platform of which the user assigns the Yal
# app to

import os,json,sys
from time import sleep
from typing import (
  List
)

complete_info = List[int,[str,str]]

class yal_client_plugin:

  def _complete_platform_(self,storage_amount:'int'=500000) -> complete_info:

    """this will complete the platform setup

        You can change the storage amount of the platform,
        depending on what you're going to use the platform for.
    """

    # this will be the total amount of file data the platform will be able to handle
    self.total_storage = storage_amount

    # this is the new os name, assigned to os.name and sys.platform
    if os.path.isfile(os.path.abspath('new_os_name.json')):
      self.os_name = json.loads(open('new_os_name.json','r').read())['new_name']
    else:
      # os_name is the same as sys.platform
      self.os_name = json.loads(open('new_os.json','r').read())['os_name'][1]

    # re-assigning os.name and sys.platform
    os.name= self.os_name
    sys.platform = self.os_name

    # The following updates the file of new_os_name.json to
    # a new file name, with new data which will help
    # support the platform later on
    if os.path.isfile(os.path.abspath('new_os_name.json')):
      os.remove('new_os_name.json')
    
    with open('new_os.json','w') as new_os:
      # the two will be the same but we still want to store both os and sys
      data = {'os_name':['module::os',os.name],'sys_name':['module::sys',sys.platform],'platform_available_storage':self.total_storage}
      new_os.write(json.dumps(
        data,
        indent=2
      ))
      new_os.close()
    return [self.total_storage,[os.name,sys.platform]]
  
  def _return_platform_(self):

    """this will just return os.name if the path new_os.json exists, which just means the platform has been setup completely
        
        It isn't needed, but is usefull to return the value of os.name, which is the same as sys.plaform,
        after completing the plaform setup
    """
    
    sleep(2.5)
    
    return (
      print(os.name + ' setup complete'),sleep(1),os.system('clear') if os.path.isfile(os.path.abspath('new_os.json')) else print("You haven't completely setup the platform: {}".format(json.loads(open('new_os.json','r').read()['new_name'])))
    )
  def _use_platform_(self):
    """this just returns the name in new_os.json if the path exists
        
        It is the same as _return_patform_, but it should be used when re-assigning os.name or sys.platform in your .py file
    """
    
    if os.path.isfile(os.path.abspath('new_os.json')):
      return(json.loads(open('new_os.json','r').read()['os_name'][1]))#returns name in os_name index of 1, see line 34,35,45
    else:return(os.name)#will re-assing os.name to os.name(same value), as well as sys.platform
