from files.server_setup import server_side
from __init__ import _composing_

_composing_(server_side.__composing__('.'))

server = server_side()
server._server_side_()
server.__up_status__()
