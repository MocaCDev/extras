import json,os

def encode(encoding):
	 
	def _get_func_(func):

		def change(to_change):

			data = {'encoding':encoding}

			with open('data.json','w') as file:
				file.write(json.dumps(
					data,
					indent=2,
					sort_keys=False
				))
				file.flush()
				file.close()

			if isinstance(to_change,str):
				return print(f'/\r\rencPYTHON_STRING"[type PYTHON_STRING,<class "str">]",{encoding}/\r\r')
			if isinstance(to_change,int):
				return print(f'/\r\rencPYTHON_INT32"[type PYTHON_INT,<class "int">]",{encoding}/\r\r')
			if isinstance(to_change,type):
				return print(f'/\r\rencPYTHON_TYPE_CLASS"[type PYTHON_CLASS_TYPE,<class "type">]",{encoding}/\r\r')
			if isinstance(to_change,'function'):
				return print(f'/\r\rencPYTHON_FUNCTION"[type PYTHON_FUNCTION,<class "function">]",{encoding}/\r\r')
			if isinstance(to_change,float):
				return print(f'/\r\rencPYTHON_FLOAT"[type PYTHON_FLOAT],<class "float">]",{encoding}/\r\r')

			func(to_change)

		return change
	return _get_func_

@encode('a0')
def a(name):

	return name

a('aidan')
