 import os, json, subprocess

_user_ = {}

def _gather_user_info_(info):
  global _user_
  _user_ = info

def _setup_user_(username,user_pass):
  information = {'username':username,'user_pass':user_pass}
  _gather_user_info_(information)

def _complete_user_setup_():
  with open('user_info.json','w') as file:
    to_json = json.dumps(_user_,indent=2,sort_keys=False)
    file.write(to_json)
    file.close()
  
  print('Done!')

def _login_(username,password):
  op = json.loads(open('user_info.json','r').read())

  if username == op['username']:
    if password == op['user_pass']:
      print('Logged into ' + op['username'])
      _user_.update({'LOGIN_DATA':{'login':'success','return_status':None}})

      with open('user_info.json','w') as file:
        to_json = json.dumps(_user_,indent=2,sort_keys=False)
        file.write(to_json)
        file.close()
    else:
      print('The password ' + password + ' does not match the password assigned to the account ' + op['username'])
      subprocess.call('exit 1',shell=True)
  else:
    print('There is no ' + username + ' in the user database. Sorry')
    subprocess.call('exit 1', shell=True)


username = input('Username: ')
password = input('Password: ')
_setup_user_(username, password)
_complete_user_setup_()

subprocess.call('clear',shell=True)

login_user = input('LOGIN\nUsername: ')
login_pass = input('LOGIN\nPassword: ')
_login_(login_user,login_pass)
