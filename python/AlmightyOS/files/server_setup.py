import os, sys, json

"sets up server side of AlmightyOS"

class server_side:

  def _server_side_(self):

    "sets up a status report for the server, containing absolute directories etc"

    # we have not setup a connection port yet
    self.setup_ = ""
    self._abs_list_ = {'power_items':[],'items':[]}

    for i in range(len(os.listdir())):
      self._abs_list_['items'].append(os.path.abspath(os.listdir()[i]))
    
    for i in range(len(self._abs_list_)):
      self._abs_list_['items'][i].replace(os.environ.get('HOME')+'/',os.getcwd())
    
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
    self._power_ip_ = [
      '.100.0.0',
      '.101.0.0',
      '.303.0.0',
      '.401.0.0',
      '.506.0.1',
      '.606.0.9',
      '70.8.0',
      '.90.2.0',
      '.100.6.2',
      '.12.8.0'
    ]

    self.main_path = os.environ.get('HOME')
    self.working_path = os.getcwd()
  
  def __up_status__(self):

    "this will give each item in the list a 'power'"

    for i in range(len(self._powers_)):
      self._abs_list_['power_items'].append({self._abs_list_['items'][i]:self._powers_[i]})

      if i == len(self._powers_)-1:
        break
    
    with open('item_powers.json','w') as powers:
      to_json = json.dumps(
        self._abs_list_,
        indent=2,
        sort_keys=True
      )
      powers.write(to_json)
      powers.close()
  
  def _compose_(self):
    while os.path.isfile(self.main_path + '/item_powers.json'):
      op_file = open(self.main_path + '/item_powers.json','r')
      op_file = json.loads(op_file.read())
      with open('info.bach','w') as bach_file:
        for i in range(len(self._powers_)):
          name = self._abs_list_['items'][i]
          bach_file.write(name + ' : ' + str(op_file['power_items'][i][name]) + '\n')
        bach_file.close()
      return op_file
      break
  
  def __power_up__(self):

    "this will power up the server and the server powers"

    self._access_powers_ = {'data':{}}
    
    for i in range(len(self._power_ip_)):

      self._access_powers_['data'].update({self._powers_[i]:self._power_ip_[i]})

      if i == len(self._powers_)-1:
        break
