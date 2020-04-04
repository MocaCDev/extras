let list = {
	crew: {
		passInfo: {
			name:'Aidan',
			id:[1,2,3,4,5]
		},
		isValid:true
	},
};

let idFound = [];

for(let i in list) {
	console.log(`${list[i].passInfo.name}->${list[i].isValid}`);
	idFound.push(list[i].passInfo.id);
}

const idRefactor = idFound[0].map(index => {
	return index*2;
});

console.log(idRefactor);
