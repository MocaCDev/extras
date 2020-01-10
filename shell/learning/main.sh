greeting="Hello, "
echo "${greeting} Aidan, I see you're learning shellscript!"

#Arrays
array=()
array[0]=apple
array[1]=tree

# getting length of array index 0
echo ${#array[0]}
# getting length of array
echo ${#array}
# printing the array off
echo ${array}

# Second Array example
arr = ("yes" "no" "maybe" "true" "false)
# printing index of no
echo ${arr[${#arr[@]}-3]}
