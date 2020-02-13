from math import floor
import json,os

def encode(stats_by:int=2) -> type:

	def _gather_(func):

		def func_(arg):

			func(arg)

			encoding = ''
			bytes_ = ''

			if isinstance(arg,str):

				t="string"

				a = floor(len(arg)*2 / 4 + 40)
			
			if isinstance(arg,float):

				t="float"
				
				a = floor(arg * 2 / 4 + 40)
			
			if isinstance(arg,int):

				t="integer"

				a = floor(arg * 2 / 4 + 40)
			
			if hasattr(type(arg),'function'):

				raise TypeError("Cannot encode type of " + type(arg))
			
			if hasattr(type(arg),'type'):

				raise TypeError("Cannot encode type of " + type(arg))
			
			le = len(arg)
			if le >= 50 and le < 250:
				l = le/24
			if le >= 250 and le< 450:
				l = le/40+10
			if le >= 450 and le < 850:
				l = le/80+10
			if le >= 850 and le < 1050:
				l = le/140+10
			if le >= 1050:
				l = le/800+10

			for i in range(a):

				d = floor(i/2)

				r = floor(a * d/40)

				t = "t_-T-_t"
				e = "r_-R-_r"
				f = "f_-F-_f"
				type_short=f'{f}:["{r+19}"_{r/2 if r >= 10 and r < 100 else r/4}]'
				type_long=f'\{"001"*int(le*2/4) if le >= 1 and le < 15 else "01"*int(le*2/8)}'

				enc = f'<|{"r" if le >= 1 and le < 50 else "l"}-{d/2*d if d < 100 else d*2/d}|>({"e#" if le >= 1 and le < 50 else "d#"}-{"^0d"+str(int(floor(8*le))) if le >= 1 and le < 50 else "^0b"+str(int(floor(8*le/2)))}:{t if le/2 >= 1 and r < 50 else e+" - "+f}^{type_short})-+-{"["+type_long+"]"}'

				bytes_ = f'/b->encodingTYPE->[{enc}]{" " if d < 100 else "  "}'

				encoding = f'/:"[0.{d*2},{t}]"_>{d+a}_>{bytes_}'
			
			os.system('clear')
			print(encoding)

			data = {'encoding':encoding}

			with open('encoding.json','w') as encoding:
				encoding.write(json.dumps(
					data,
					indent=2,
					sort_keys=False
				))
				encoding.flush()
				encoding.close()
		return func_
	return _gather_

@encode()
def yessir(arg):
	return arg
yessir(input('Type here: '))
