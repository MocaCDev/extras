// .forEach

let list = []

for(let i = 0; i < 100; i++) {
	list.push(i+1);
}

list.forEach(listItem => {
	console.log(listItem);
});

// .map
const newList = list.map(w => {
	return w+10;
});
newList.forEach(item => {
	console.log(item);
});

// .filter
const newList2 = newList.filter(item => {
	return item<110;
});
newList2.forEach(item => {
	console.log(item);
});

// .reduce
const total = newList2.reduce((itemToSum,accu) => {
	return itemToSum+accu;
});
console.log(total);

// .some
const check = arg1 => (arg1>0)?true:false;
const atLeastOne = newList2.some(check);
console.log(atLeastOne);

// .every
const checkEach = arg1 => (arg1==arg1+1-1*2)?true:false;
const isEvery = newList2.every(checkEach);
console.log(isEvery);

// getting index of 109
const index = newList2.findIndex(ind => {
	return ind == 109;
});
console.log(newList2[index]);
