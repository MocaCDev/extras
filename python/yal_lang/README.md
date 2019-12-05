# Yal Language

****The YAL Language(Yet Another Language) is a language based off of Python and its compiler****
### What does it offer
****yal offers many easy-access-keywords. Don't think of yal as a easier and faster programming language****
<p>Yal is just another language that is compiled into the Python compiler, and is computed as a Python application</p>
<h1>Why did I make it then?</h1>
<p>I have always wanted to make a language. I had seen many other people make interesting languages using Python. So, I decided to make a language of my own</p>

# How does it work
*Note: The yal language is of the same syntax as Python, but many key-ideals within the language of Python are different within the language yal*</br>
*Also note: yal is not a actual language. You cannot just write, or create, a project of the file type .yal. </br> In order to write a program in the yal language, you have to create a python project, import os, then write the command:</br>***os.system('git clone https://github.com/ARACADERISE/extras')***</br>See bottom of documentation to see step-by-step on how to compile your .yal file*

# Example of the language

```yal
-- This represents a message in yal. This will convert to "#" within a .py file
-[ This represents a multi-line message within a .py file ]-

-- PLEASE NOTE: When you are gathering a integer as input, please type INTEGER(gather_input())
-[ 
  PLEASE NOTE: The yal language is a key-sensitive language. If you write any keywords in a message
  or anywhere else within the language, it will compile it as lines of Python code and will most likely
  return an error 
]-

-- This is a function in yal, also known as a "def" in python
-- Notice, we type "then" instead of ":" to indicate that we are starting the function.
-- "then" will be replaced with the ":" when the file is compiled into a .py file
func gather_name(name) then
  -- print_value will just print to the console. Also known as "print" within python
  print_value(name)
  -- This is a if statement
  -- Notice, we say "if not value of name", which is the same as "if not name" within python
  -- "is equal to" is the same as "==" within python
  -- "then" is used to indicate the start of the "if" statement within yal
  -- Take note: within yal, the "t" in "true" and the "f" in "false" are not capitalized
  -- It will be converted from "true" --> "True", and "false" --> "False"
  if not value of name is equal to 'aidan' then
    -- This will raise an error
    -- Notice: There is no special error name in yal. All errors are the same as python 
    -- But, instead of using "raise" we use the keyword "err" to indicate we want a error
    err Exception('The name is not Aidan')
    -- "return_value" is the same as "return" within python. 
    -- It can be used as "return_value(false)" or "return_value false"
    return_value false
  else then
    return_value true
 
 -- Calling a function is the same as Python, just type the function name
 -- We want to make sure that the user inputs a string, so we use "STRING(gather_input('name: '))"
 -- "STRING" is the same as "str" within Python
 -- "gather_input" is the same as "input" within Python. It gathers input from the user
 gather_name(STRING(gather_input('name: '))
 
 -- Classes within yal are a bit different, look below
 
 -- In order to start a class, you must type "create class" to indicate you're wanting to make a class
 create class my_class:
  -- In a class, you can use a "class_msg_start" & "class_msg_end" to create a "multi-line" python comment
  -- or you can just use what I have been, "--" or "-[ ]-"
  -- Here is an example of a class_msg
  class_msg_start
  PUT YOUR MESSAGE IN HERE
  class_msg_end
  -- A "class init" is the same as "def __init__" within Python, but simpler
  -- "this" is the same as "self" within Python, the "class init" can take any argument
  class init(this,age,name) then
    -- Notice, "this" is going to be assigned the value of "age". So we write "this.age"
    -- Same as "self.age"
    this.age = age
    this.name = name
  -- Now, we can either use "func" or "class func"
  -- Whichever one you prefere, you use. There is no difference
  -- I am going to use both
  class func return_values(this) then
    return_value(this.name,STRING(this.age))
  func say_hey(this) then
    -- concatenating is the same as within Python
    print_value('Hello ' + this.name + '. I see you are ' + STRING(this.age)) 
  -- There is something known as a "class error" within yal. It is a error you can raise for the class
  -- Here is an example of how you raise a "class error"
  class func Errors(this,min_age) then
    if value of this.age < min_age then
      this.er = true
    else then
      this.er = false
    this.classname = "my_class"
    this.for_ = "age is too low"
    this.msg = "sorry, your age is too low"
  -- Now, you don't just type "class error". you have to make a class function that holds "class error" within it
  -- Example
  class func raise_if_er(this) then
    -- Now, instead of having to look for the function name of "class error" you just call the class function name
    -- YOU created!
    class error
-- Calling a class, and the classes functions, are the same as Python. Nothing different
n = my_class(STRING(gather_input('Name: '),INTEGER(gather_input('Age: '))
n.return_values()
n.say_hey()
-- If you want the "class error" to be compiled to check the values
-- then call it after you are done calling all the functions you want to run within the class
n.Errors(INTEGER(gather_input('Min Age: '))
-- Calling the class function name we created
-- If it finds a value similar to what we're looking for, then it will display a error
n.raise_if_er()
```

# FUNCTION
```yal
func user_info(name,age) then
  print_value("Hello " + name + " I see you're " + STRING(age))
  return_value(name,STRING(age))
```
# CLASS
```yal
create class user_info then
  class init(this,name,age) then
    this.name = name
    this.age = age
  class func return_vals(this) then
    return_value(this.name,STRING(this.age))
  func say_hey(this) then
    print_value("Hello " + this.name + " I see you're " + STRING(this.age))
    return true
u = user_info(STRING(gather_input('Name: '),INTEGER(gather_input('Age: '))
u.return_vals()
u.say_hey()
```
# CLASS ERROR
```yal
create class my_cl_er then
  class init(this,age) then
    this.age = age
  class func gather_err_info(this,min_age) then
    if value of this.age < min_age then
      this.er = true
    else then
      this.er = false
    this.classname = "my_cl_er"
    this.for_ = "age is too low"
    this.msg = "sorry, your age is too low"
  class func return_c_er(this) then
    class error
m = my_cl_er(INTEGER(gather_input('Age: '))
m.gather_err()
```  
# IMPORTING NAME ONLY
```yal
-- We are going to be importing json and os
import name json, os
```
***When you are importing in yal, make sure you import WITHIN the function, or WITHIN the class function, otherwise</br> what you imported tends to not be recognized***
# IMPORTING FROM MODULE
```yal
-- We are going to import sleep from time
from module time import name sleep
```
# WRITING TO FILE
Note: ```use as``` is a keyword in yal that indicates the keyword 
```python 
as
```
within Python</br>
Note: Instead of 
```python 
file.write()
``` 
it is ```file.send()```</br>
Note: Closing the file is same as in Python, "file.close()"</br>
***You can use another keyword other than "file". I just use "file" by default***
```yal
write_file('example.txt','w') use as file then
  file.send('this is an example of a written file in yal')
  file.close()
```
# OPENING AND READING FILE
Note: Instead of Python keyword 
```python 
open
``` 
we use ```open_file``` in yal to open the file we want</br>
Note: Instead of ".read()" we use ".read_value()" within yal
```
print_value(open_file('example.txt','r').read_value())
```
# USING SOMETHING YOU IMPORTED
*When you import in yal, it tends to not compile it as "imported". So in order to use a imported module, or a imported name from</br>a module, you must import that module, or the name from the module, inside the function, or the class-function*
```yal
-- Importing in a function
func using_time_and_os(file) then
  from module time import name sleep
  import name os
  if value of os.path.exists(os.path.abspath(file)) then
    sleep(3)
    print_value('it exists')
  else then
    sleep(2)
    err FileExistsError('The file ' + os.path.abspath(file) + ' does not exists')

-- Importing in a class
create class using_os_and_json then
  -- NOTE: You cannot import anything outside of a class-function
  class init(this) then
    pass
  
  class func import_and_use(this) then
    -- When you want to import and use something in a class, you must import it within the class-function
    import name json
    DATA = {'name':'aidan'}
    
    if not value of os.path.exists(os.path.abspath('data.json')) then
      write_file('data.json','w') use as file then
        to_json = json.dumps(DATA,indent=2,sort_keys=false)
        file.send(to_json)
        file.close()
      print_value('DONE')
    else then
      write_file('new_data.json','w') use as file then
        to_json = json.dumpa(DATA,indent=2,sort_keys=false)
        file.send(to_json)
        file.close()
      print_value('DONE')
n = using_os_and_json()
n.import_and_use()
```
# IF STATEMENT
*Checking if the value is true*
```yal
name = STRING(gather_input('Name: '))
if value of name is equal to 'aidan' then
  print_value('Hello Aidan')
else then
  print_value('Hello ' + name)
```
*Checking if the value is false*
```yal
if not value of name is equal to 'aidan' then
  print_value('Your name is not Aidan, but instead it is ' + name)
else then
  print_value('Your name is aidan!')
```
*Or statement*
```yal
-- Note: Instead of putting "if value of" again, we just get straight to the argument:
-- name is equal to 'jeff'
-- "||" stands for "or" in Python
if value of name is equal to 'aidan' || name is equal to 'jeff' then
  print_value('Your name is either Aidan or Jeff')
else then
  print_value('Your name is ' + name)
```
*And statement*
```yal
age = INTEGER(gather_input('Age: '))
if value of name is equal to 'aidan' && age < 50 then
  print_value('Hello ' + name + ', I see you are ' + age + ' years old')
else then
  print_value('Too old')
```
# LENGTH
```yal
name = STRING(gather_input('Name: '))
get_len = get_length(name)
if value of get_len > 10 then
  print_value('The length of your name is greater than 10, it is ' + STRING(get_len))
else then
  print_value('Then length of your name is less than 10, it is + STRING(get_len))
```
# BOOLEANS
```yal
-- "True" in Python
a = true
-- "False" in Python
b = false
-- "None" in Python
c = nil
```
# How to Write, and execute, a .yal file
*Step 1: import os*
```python
import os
```
*Step 2: use os.system to git the resporitory*
``` python
# If we don't have an if statement checking if the path of "extras" exists, we will always get
# an error
if not os.path.exists('extras'):
  os.system('cd && git clone https://github.com/ARACADERISE/extras')
```
*Step 3: use os.system to run "file.py"*
```python
# This will cd into the "extras" folder, then into the "python" folder, and then into "yal_lang" folder
# then will execute "file.py"
os.system('cd extras/python/yal_lang && python file.py')
```
*Note: Within extra/python/yal_lang, instead of having the user input the .yal filename, you can just open up file.py, and change get_file to the file name of your .yal file*
```python
# Here is an example
"this would ask the user for the filename"
MAIN_PATH = os.environ.get('HOME')

get_file = input('File: ')

get_file = MAIN_PATH + '/' + get_file

if not '.yal' in get_file:
  raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(get_file)

"now get_file is already assigned the file name"
"this is recommended if you're implementing a .yal file/application in your project"
MAIN_PATH = os.environ.get('HOME')

get_file = 'test.yal'

get_file = MAIN_PATH + '/' + get_file

"""
this if statement is useless when assigning get_file the .yal filename, so you can either keep the 
if statement or delete ir, no harm will be done
"""
if not '.yal' in get_file:
  raise Exception('Cannot open and execute ' + get_file + '\nNot a .yal file')

read_(get_file)
```
***It should compile "file.py" onto your Python terminal. It will ask for the name of your .yal file(MAKE SURE YOU INCLUDE .yal IN THE FILE NAME IT ASKS YOU FOR)***
## Disclaimer
*When you write a file in the yal language, it writes it to the folder extras/python/yal_lang</br>If you do not want this, then please do the following when writing a file:*
### For a class
```yal
create class write_ then
  class inite(this) then
    import name os
    this.main_path = os.environ.get('HOME')
  class func write_to_file(this) then
    write_file(this.main_path + '/' + 'name_of_your_file_here.whatever_lang_its_in','w') use as file then
      file.send('information you want to send')
      file.close()
```
### For function
```yal
func write_() then
  import name os
  main_path = os.environ.get('HOME')
  write_file(this.main_path + '/' + 'name_of_your_file_here.whatever_lang_its_in','w') use as file then
      file.send('information you want to send')
      file.close()
```
### Outside of a function and class
```yal
import name os
main_path = os.environ.get('HOME')
write_file(this.main_path + '/' + 'name_of_your_file_here.whatever_lang_its_in','w') use as file then
      file.send('information you want to send')
      file.close()
```
***Note, it is pretty much the same syntax for each one, but I still wanted to show you guys :)***
## Good Luck and ENJOY !
