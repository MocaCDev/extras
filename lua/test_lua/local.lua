-- This will return data that we will gain within l.lua
local function gather_data(gather)
  return gather
end

-- This will contain the data that we will gain within l.lua
function get_name_of_user(user_name)
  print(gather_data(user_name))
  return user_name
end
