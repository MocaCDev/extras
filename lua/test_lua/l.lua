require 'get_name'
require 'get_number'
require 'check_ip'

-- Should just print the IP address
-- If the IP address was not 127.0.0.1, it would print a different message
print(check_ip("127.0.0.1"))
-- Should print AIDAN
print(get_name("AIDAN"))
-- Should print the number 500 + 200 * 2
print(get_number(500,200))
