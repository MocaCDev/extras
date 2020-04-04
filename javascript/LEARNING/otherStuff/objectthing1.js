let assi = {
	values:[],
	addBy:0,
	set Values(with_) {
		if(this.addBy===0) {
			this.addBy+=15;
		}
		for(let i = 0; i < 10; i++) {
			this.values[i].push(i*this.addBy/2);
		}
		this.values = this.values.filter(index=> {
			return index>0;
		});
	},
	get Values() {
		return this.values;
	},
	MultBy(mult) {
		this.values = this.values.map(index => {
			return index*mult;
		});
	}
};

assi.Values=100;
assi.MultBy(8);
assi.Values;

const keys = Object.assign({NAME:'AIDAN'},assi);
console.log(keys);
