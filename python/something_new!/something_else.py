from typing import Tuple, Generic, TypeVar, List, Callable

T = TypeVar('T')

class server(Generic[T]):

  def _gather_(server:List[str],call_render:Callable[[str,bool],None],append_server_info:List[str]=[]) -> Tuple[list,list,int]:

    for i in range(len(server)):
      append_server_info.append(server[i])
    
    if len(append_server_info) > 3:
      raise MemoryError('Cannot store more than 3 servers')

    return server,call_render,0

print(server._gather_(['180'],['180',True]))

def _call_(server:server[str]) -> str:
  
  return server

_call_('18080')
