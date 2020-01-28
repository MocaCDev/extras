# this will be a plugin for the Yal Language App client
# and the Platform of which the user assigns the Yal
# app to
import os,json,sys
from time import sleep
from typing import Tuple
from client_plugin.errors import (
  LessThan800StorageAmount,
  NotEnoughStorage
)
from colorama import Fore, Style

class yal_client_plugin:

  def _complete_platform_(self,storage_amount:'int'=500000) -> list([int,[str,str]]):

    # !IMPORTANT
    self.platform_is_rendered = False

    """this will complete the platform setup

        You can change the storage amount of the platform,
        depending on what you're going to use the platform for.
        
        NOTE:
          The storage amount must be above 800, or another words the platform should be able to process
          at least one large file.
    """

    # the storage can't be below 800, the platform needs to be able to process at least 1 large files
    if storage_amount < 800:
      print('\n\n')
      raise LessThan800StorageAmount('\n\nThe storage amount must be above 799.\nYou requested ' + str(storage_amount) + ' which cannot be accepted.')

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
  
  def _render_platform_(self,render_to_host:str,connection_available:bool) -> list([str,bool]):

    "this will render the platform and set a host and a connection avaiability variable to it"

    self.render_host = render_to_host
    self.connection_available = connection_available

    data = {'platform':os.name,'platform_renderes_to_host':self.render_host,'available':self.connection_available}

    if self.connection_available:
      data.update({['Connection is unavailable. Other hosts and or platform names cannot connect to it through the yal application. You must creat a mod of your own if you want to connect to it.']})

    with open('render_platform.json','w') as render_plat_data:

      render_plat_data.write(json.dumps(
        data,
        indent=2,
        sort_keys=False
      ))
      render_plat_data.flush()
      render_plat_data.close()
    
    self.platform_is_rendered = True

    self.rendered_msg = "<RENDER PLATFORM:{0},\nsaved:{1},\nsaved_to_file:{2}"

    with open('rendered_info.bach','w') as file:

      self.rendered_msg = self.rendere_msg.format([os.name,sys.platform],True if self.platform_is_rendered else False,os.path.abspath('rendered_info.bach'))

      file.write(self.rendere_msg)
      file.close()
    
    return [self.rendered_msg,self.platform_is_rendered]
  
  def _update_storage_(self,take_out:'int') -> int:

    if self.platform_is_rendered == False:
      raise Exception('\n\nCannot add storage to a platform that has not been rendred\n\nPlease run yal._render_platform_ to render the platform')

    """
      This function will TAKE OUT from the platform_available_storage

      DO NOT MISTAKEN _update_storage_ WITH _add_storage_
    """

    update_file = json.loads(open(os.path.abspath('new_os.json'),'r').read())

    # This is checking to see if the total amount being subtracted is greater than the amount left
    if take_out > update_file['platform_available_storage']:raise NotEnoughStorage('There is not enough storage to carry out the action worth the size of ' + str(take_out) + '. Try adding storage with:\n\n_add_storage_')

    update_file['platform_available_storage'] = update_file['platform_available_storage']-take_out

    with open(os.path.abspath('new_os.json','r'),'w') as upd_file:
      upd_file.write(update_file)
      upd_file.close()
    
    return update_file['platform_available_storage'],print(Fore.CYAN + Style.BRIGHT + 'Updated storage: ' + str(update_file['platform_available_storage']))

  
  def _return_storage_amount_(self) -> int:

    if not self.platform_is_rendered:
      raise Exception('\n\nCannot return the storage ammount of a platform that has not been rendered\n\nPlease run yal._render_platform_ to render the platform.')

    """
      This will be used to return how much storage is left
    """

    # Since new_os.json is already a file we don't need to use os.path.isfile to check
    check_file = json.loads(open('new_os.json','r').read())

    return check_file['platform_available_storage'],print(Fore.CYAN + Style.BRIGHT + 'Storage Amount: ' + str(check_file['platform_available_storage']))
  
  def _return_platform_(self):

    if self.platform_is_rendered == False:
      raise Exception('\n\nCannot return the platorm of a platform that has not been rendered\n\nRun yal._render_platform_ to render the platform.')

    """this will just return os.name if the path new_os.json exists, which just means the platform has been setup completely
        
        It isn't needed, but is usefull to return the value of os.name, which is the same as sys.plaform,
        after completing the plaform setup
    """
    
    sleep(2.5)
    
    return (
      print(os.name + ' setup complete'),sleep(1),os.system('clear') if os.path.isfile(os.path.abspath('new_os.json')) else print("You haven't completely setup the platform: {}".format(json.loads(open('new_os.json','r').read()['new_name'])))
    )
  
  def _use_platform_(self) -> Tuple[str]:

    if self.platform_is_rendered == False:
      raise Exception('\n\nCannot use a platform that has not been rendered\n\nRun yal._render_platform_ to render the platform.')

    """this just returns the name in new_os.json if the path exists
        
        It is the same as _return_patform_, but it should be used when re-assigning os.name or sys.platform in your .py file
    """
    
    if os.path.isfile(os.path.abspath('new_os.json')):
      return (json.loads(open('new_os.json','r').read()['os_name'][1]))#returns name in os_name index of 1, see line 34,35,45
    else:return (os.name)#will re-assing os.name to os.name(same value), as well as sys.platform
  
  def _add_storage_(self,add):

    if self.platform_is_rendered == False:
      raise Exception('\n\nCannot add storage to a platform that has not been rendered\n\nRun yal._render_platform_ to render the platform.')

    """
      this will add more storage to the platform
    """

    open_data_file = json.loads(open('new_os.json','r').read())

    open_data_file['platform_available_storage'] = open_data_file['platform_available_storage']+add

    with open(os.environ.get('HOME')+'/new_os.json','w') as update_file:

      update_file.write(
        json.dumps(
          open_data_file,
          indent=2,
          sort_keys=False
      ))
      update_file.close()
