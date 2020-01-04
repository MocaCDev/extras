# this will be a plugin for the Yal Language App client
# and the Platform of which the user assigns the Yal
# app to

import os,json,sys

class yal_client_plugin:

  def _complete_platform_(self,storage_amount:'int'=500000):

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
  
  def _return_platform_(self):

    "this will just return os.name and sys.platform if it is found in new_os.json"
    
    if os.path.isdir(os.path.abspath('new_os.json'):
      open_new_os = json.loads(open('new_os.json','r').read())
    else:
      open_new_os = json.loads(open('new_os_name.json','r').read())
    
    return (os.name if os.name == sys.platform else print("You haven't completely setup the platform: {}".format(open_new_json['new_name'])))
