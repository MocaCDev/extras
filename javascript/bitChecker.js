// takes a int and sees if it is greater than a int16
const uInt16 = (number) => {
	if(Math.floor(Math.log2(number)) > 16) {
		console.log('\033[0;43m'+`The number ${number} is not 16 bits long instead it is ${Math.floor(Math.log2(number))}`+'\033[0;0m');
		return 1;
	} else {
		console.log('\033[0;32m'+`The number ${number} is ${Math.floor(Math.log2(number))} bits long`);
		return 0;
	}
};
const uInt24 = (number) => {
	if(Math.floor(Math.log2(number)) > 24) {
		console.log('\033[0;43m'+`The number ${number} is not 24 bits long instead it is ${Math.floor(Math.log2(number))}`+'\033[0;0m');
		return 1;
	} else {
		console.log('\033[0;32m'+`The number ${number} is ${Math.floor(Math.log2(number))} bits long`);
		return 0;
	}
}

uInt16(10000);
