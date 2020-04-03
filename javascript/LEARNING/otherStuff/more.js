let list = {
	crewInfo: {
		crewLeft (arg) {
			console.log(arg*10);
		}
	},
	list_:[1,2,3,4,5,6]
};

list.crewInfo.crewLeft(5);

list.list_ = list.list_.filter(index => {
	return index>=4;
});
list.list_ = list.list_.map(index => {
	return index*2;
});

const remainderIsZero = argument => (argument%2==0)?console.log(`${argument}%2=${argument%2}->${true}`):console.log(`${argument}%2=${argument%2}->${false}`);
const check = list.list_.every(remainderIsZero);
