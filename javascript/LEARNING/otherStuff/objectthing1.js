let assi = {
	values:[],
	addBy:0,
	set Values(with_) {
		if(this.addBy===0) {
			this.addBy+=15;
		}
		for(let i = 0; i < 10; i++) {
			this.values[i]=i*this.addBy/2;
		}
	},
	get Values() {
		return this.values;
	}
};

assi.Values=100;
assi.Values;
