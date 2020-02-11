import os, json
from math import floor

def _to_stats_(type_:str,tage:str='$',print_:bool=True,stats_by:int=2) -> type:

		if stats_by > 100:
			raise OverflowError("Cannot multiply stats by 10. The indentation will be too large.")

		# knowing someone will possibly put 0, we have to catch it
		if stats_by == 0:
			stats_by = 1
		
		def _function_(func):

			def _argument_(arg):

				if type_ == 'file':
					try:
						arg = os.stat(os.path.abspath(arg)).st_size
					except:
						raise FileExistsError("There was a error locating the file. Either the open() method was passed or the file directory does not exists. Please try again")
					
				if len(arg) < 10 and len(arg) >= 0:
					a = floor(len(arg)+250/40) * stats_by
				if len(arg) >= 10 and len(arg) < 25:
					a = floor(len(arg)+120/50) * stats_by
				if len(arg) >= 25 and len(arg) < 500:
					a = floor(len(arg)+140/30) * stats_by
				if len(arg) >= 500 and len(arg) < 5000:
					a = floor(len(arg)+150/60) * stats_by
				if len(arg) >= 5000 and len(arg) < 15000:
					a = floor(len(arg)+100/170) * stats_by
				
				data = ''
				new_d = ''
				indent = '\n'
				space = ' '
				double_space = '  '
				double_spaced_t = 't__'
				double_spaced_r = 'r__'
				double_both = s=f'{double_spaced_t*2}::{double_spaced_r*2}'
				doubled_spaced_return = 'return->:'
				values = f'enco::{space*2}::[_{doubled_spaced_return if a < 800 else indent}_]'
				make_new = f'\nr_[encodes{values if a % 2 == 0 else double_spaced_r}:{double_both}]'
				rando = f'@$:{values}(#{True if a < 5000 else False}/\~{double_spaced_t})'

				for i in range(a):
					d = i + 14 if i + 14 < 500 else floor(i / 10)
					#d_2 = floor(d / 10 + 1)
					bytes_ = str(bytearray(floor(d)))
					bytes_ = bytes_.replace('b','enc')
					bytes_ = bytes_.replace('x',f'!@{space}_:_'*2)
					space = ' ' * d
					div_2 = floor(d/2)
					code=f'{rando}-[{values}]-"{double_space}<:>{double_spaced_r*2 if len(arg) >= 1 and len(arg) < 150 else doubled_spaced_return}_{arg +"<"+double_both+">"+ tage if len(arg) >= 1 and len(arg) < 150 else arg + "->as_err"}'
					space_ = '  ' * div_2
					new_char = f' @_-{d/4+12}-{double_space if d % 2 == 0 else False}_ '
					data += 'r-'+space+'d-'+space+'._.'+space_+new_char+f'{indent if d % 10 == 0 else double_space}|_{tage}:{len(arg)*d/40}_|--{bytes_}--'+doubled_spaced_return+f'_{double_spaced_t if d % 20 == 0 else double_both}'+values*2+f'({new_char}<->{make_new})'+f':"{rando*2 if div_2 % 4 == 0 else rando*3}":{space}'
					r = i * 2 if i * 2 < 1000 else floor(i /2)

					# this will end with the bytes. All the other is extra
					static_return = f'code5encode"{arg}"->[r-"{tage}{rando}_{new_char}<-:->{double_both if div_2 > 500 and div_2 < 1000 else double_both*2}|{rando if floor(div_2 % 10) == 0 else double_spaced_r}_->"]'+f' - {values} - {code}'
					#print(data)
					new_d += f' |{r*2/4}|{new_char}!\/\_!@ '+space
				with open('t.txt','w') as file:
					file.write(data)
					file.close()
				with open('d.txt','w') as file:
					file.write(new_d)
					file.close()
 
				func(arg)

				if print_:
					print(static_return)

				with open('d','w') as file:
					file.write(static_return)
					file.close()

			return _argument_
		
		return _function_

@_to_stats_(type_='str',stats_by=99)
def s(arg_):
	return arg_

s(input())
