import os, sys, json

"sets up server side of AlmightyOS"

class server_side:

  def _server_side_(self):

    "sets up a status report for the server, containing absolute directories etc"

    # we have not setup a connection port yet
    self.setup_ = ""
    self._abs_list_ = []

    for i in range(len(os.listdir())):
      self._abs_list_.append(os.path.abspath(os.listdir()[i]))
    
    for i in range(len(self._abs_list_)):
      self._abs_list_[i].replace(os.environ.get('HOME')+'/',os.getcwd())
    
    # keywords for items within the list
    self._powers_ = [
      '__show__',
      '__recide__',
      '__decieve__',
      '__declare__',
      '__report__',
      '__status__',
      '__ovel_net__',
      '__network__',
      '__exist__',
      '__configured__',
      '__runner__',
      '__files__'
    ]
  
  def __up_status__(self):

    "this will give each item in the list a 'power'"

    for i in range(len(self._abs_list_)):
      self._abs_list_.append({self._abs_list_[i]:self._powers_[i]})

      if i == len(self._powers_)-1:
        break
    
    with open('item_powers.json','w') as powers:
      to_json = json.dumps(
        self._abs_list_,
        indent=2,
        sort_keys=False
      )
      powers.write(to_json)
      powers.close()
  
  def __composing__(self):
    "used in __init__"
