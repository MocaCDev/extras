class IsAPrivateFile(Exception):
  "This will be raised if the user tries to use a file made private as a part of there Yal application"
  
  """
    A private file is basically a file locked as a main dir for the .yal application.
    
    NOTE:
      There will be a Yal Application compiler that compiles the locked file
  """

class SlugTimeError(TimeoutError):
  "this will be raised if the user sets a slug read timer for over 50 seconds"

  """
    The _slug_read_ function basically opens a file, and returns the result at a default time rate of 25 seconds.
    The user can change the default time rate to whatever they want, but must be under 150.
    
    NOTE:
      The soul purpose of the _slug_read_ function is to compile the file completely if it is greater than
      200 bytes, using os.stat('FILENAME').st_size, which just gets the total size of a file.

      The time rate increases as the file gets bigger.

      FUNCTION:
        def _slug_read_(self,file_name,timout:'int'=5)
  """

class LessThan800StorageAmount(Exception):

  """
    This will be raised if the user assigns there platform a storage amount less than 800
  """
