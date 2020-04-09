let setter = 10;

let list = {
	item:[],
    set setupItem(ammountToSet) {
    	for(let i = 0; i < ammountToSet; i++) {
        	if(i%2!=0) {
            	setter+=i;
            }
            
            this.item.push(setter*i);
        }
        this.item = this.item.map(index => {
          return Math.floor(index/10);
        });
        this.item.sort();

        for(let i = 0; i < ammountToSet; i++) {
          if(this.item[i]>this.item[i+1]) {
            console.log(this.item[i+1]);
            this.item[i+1]=this.item[i]+1;
          }
        }
    },
    get Items() {
    	return this.item;
    }
};

list.setupItem=10;
console.log(list.Items);
