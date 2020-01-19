class IsAPrivateFile(Exception):
  "This will be raised if the user tries to use a file made private as a part of there Yal application"
  
  """
    A private file is basically a file locked as a main dir for the .yal application.
    
    NOTE:
      There will be a Yal Application compiler that compiles the locked file
  """

class NotEnoughStorage(OverflowError):
  """
    This will be raised if the user is taking more storage out than what was assigned to the platform
  """

class CouldNotLocateFile(FileNotFoundError):
  """
    This will be raised if the yal application cannot find a file
  """

class SlugTimeError(TimeoutError):
  "this will be raised if the user sets a slug read timer for over 50 seconds"

  """
    The _slug_read_ function basically opens a file, and returns the result at a default time rate of 5 seconds.
    The user can change the default time rate to whatever they want, but must be under 50.
    
    NOTE:
      The soul purpose of the _slug_read_ function is to compile the file completely if it is greater than
      200 bytes, using os.stat('FILENAME').st_size, which just gets the total size of a file.

      The timeout will take place after a default time of 10 seconds. You can change this by adding the argument:
        second_til_timout=Your Number Here

      The time rate increases as the file gets bigger.

      FUNCTION:
        def _slug_read_(self,file_name,second_til_timout:'int'=10,timout:'int'=5)
  """

class CannotReadPdfFileError(Exception):
  """
  this will be raised if the user tries to read a .pdf file
  """

class CannotReadImageFileError(Exception):
  """
  This will be raised if the user tries to read a .img, .png, etc, type of file.
  """

class LessThan800StorageAmount(Exception):
  "This will be raised if the user assigns there platform a storage amount less than 800"
