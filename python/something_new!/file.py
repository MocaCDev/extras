import os, json

def _get_names_(names:'list'=[])->list:
  return names
  
def _append_paths(paths:'list'=[],append_paths:'dict'={})->dict:
  append_paths.update({'paths':paths})
  return append_paths

print(get_names_(['bob','jeff','trump'])
print(_append_paths(os.listdir())
