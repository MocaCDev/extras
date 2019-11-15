# Yal Language

****The YAL Language(Yet Another Language) is a language based off of Python and its compiler****
### What does it offer
****yal offers many easy-access-keywords. Don't think of yal as a easier and faster programming language****
<p>Yal is just another language that is compiled into the Python compiler, and is computed as a Python application</p>
<h1>Why did I make it then?</h1>
<p>I have always wanted to make a language. I had seen many other people make interesting languages using Python. So, I decided to make a language of my own</p>

# How does it work
*Note: The yal language is of the same syntax as Python, but many key-ideals within the language of Python are different within the language yal*</br>
*Also note: yal is not a actual language. You cannot just write, or create, a project of the file type .yal. </br> In order to write a program in the yal language, you have to create a python project, import os, then write the command:</br>***os.system('git clone https://github.com/ARACADERISE/extras/tree/master/python/yal_lang')****

# Examples of the language

```
-- This represents a message in yal. This will convert to "#" within a .py file
-[ This represents a multi-line message within a .py file ]-

-- PLEASE NOTE: When you are gathering a integer as input, please type INTEGER(gather_input())

-- This is a function in yal, also known as a "def" in python
-- Notice, we type "then" instead of ":" to indicate that we are starting the function.
-- "then" will be replaces with the ":" when the file is compiled into a .py file
func gather_name(name) then
  -- print_value will just print to the console. Also known as "print" within python
  print_value(name)
  -- This is a if statement
  -- Notice, we say "if not value of", which is the same as "if not name" within python
  -- "is equal to" is the same as "==" within python
  -- "then" is used to indicate the start of the "if" statement within yal
  if not value of name is equal to 'aidan' then
    -- This will raise an error
    -- Notice: There is no special error name in yal. All errors are the same as python, just a different name to assign a error
    err Exception('The name is not Aidan')
    -- "return_value" is the same as "return" within python. It can be used as "return_value(false)" or "return_value false"
    return_value false
  else then
    return_value true
 
 -- Calling a function is the same as Python, just type the function name
 -- We want to make sure that the user inputs a string, so we use "STRING(gather_input('name: '))"
 -- "STRING" is the same as "str" within Python
 -- "gather_input" is the same as "input" within Python. It gathers input from the user
 gather_name(STRING(gather_input('name: '))
  
```
