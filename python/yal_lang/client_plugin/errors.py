class IsAPrivateFile(Exception):
  "This will be raised if the user tries to use a file made private as a part of there Yal application"
  
  """
    A private file is basically a file locked as a main dir for the .yal application.
    
    NOTE:
      There will be a Yal Application compiler that compiles the locked file
  """
