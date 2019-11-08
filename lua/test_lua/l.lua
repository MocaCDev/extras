function get_name(name)
  return name
end

function get_number(num1,num2)
  local number = num1+num2*4
  return math.sqrt(number)
end

print(get_number(500,200))
print(get_name("aidan"))
