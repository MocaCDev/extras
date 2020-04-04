let available16BitNumbers = [];
let available24BitNumbers = [];

// takes a int and sees if it is greater than a int16
const uInt16 = (numbers) => {
	let ReturnStatus;
	for(let i = 0; i < numbers.length; i++) {
		if(Math.floor(Math.log2(numbers[i])) > 16) {
			console.log('\033[0;31m'+`The number ${numbers[i]} is not 16 bits long instead it is ${Math.floor(Math.log2(numbers[i]))}`+'\033[0;0m');
			 ReturnStatus=1;
		} else {
			console.log('\033[0;32m'+`The number ${numbers[i]} is ${Math.floor(Math.log2(numbers[i]))} bits long`);
			available16BitNumbers.push(numbers[i]);
			ReturnStatus=0;
		}
	}
	return ReturnStatus;
};

// takes a int and sees if it is greater than a int24
const uInt24 = (numbers) => {
	let ReturnStatus;
	for(let i = 0; i < numbers.length; i++) {
		if(Math.floor(Math.log2(numbers[i])) > 24) {
			console.log('\033[0;43m'+`The number ${numbers[i]} is not 24 bits long instead it is ${Math.floor(Math.log2(numbers[i]))}`+'\033[0;0m');
			ReturnStatus=1;
		} else {
			console.log('\033[0;32m'+`The number ${numbers[i]} is ${Math.floor(Math.log2(numbers[i]))} bits long`);
			available24BitNumbers.push(numbers[i]);
			ReturnStatus=0;
		}
	}
}

uInt16([10000,100,50,9000,180000]);
for(let d = 0; d < available16BitNumbers.length; d++) {
	console.log('Picked up on: '+`${available16BitNumbers[d]}`);
}
