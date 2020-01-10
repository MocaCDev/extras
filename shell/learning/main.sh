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
