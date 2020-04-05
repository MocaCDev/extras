let available16BitNumbers = [];
let available24BitNumbers = [];
let FailedAttempts = [{'Failed int 16 check':[]},{'Failed int 24 check':[]}];

// takes a int and sees if it is greater than a int16
const uInt16 = (numbers) => {
	let ReturnStatus;
	for(let i = 0; i < numbers.length; i++) {
		if(Math.floor(Math.log2(numbers[i])) > 16) {
			numbers[i]=Math.abs(numbers[i]);
			FailedAttempts[0]['Failed int 16 check'].push(numbers[i]);
			ReturnStatus=1;
		} else {
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
		numbers[i]=Math.abs(numbers[i]);
		if(Math.floor(Math.log2(numbers[i])) > 24 || Math.floor(Math.log2(numbers[i])) < 16) {
			FailedAttempts[1]['Failed int 24 check'].push(numbers[i]);
			ReturnStatus=1;
		} else {
			available24BitNumbers.push(numbers[i]);
			ReturnStatus=0;
		}
	}
}

uInt16([10000,100,50,9000,180000,1900000]);
uInt24([1000000,800000,-1,5000,40,2,1]);

for(let d = 0; d < available16BitNumbers.length; d++) {
	console.log('Picked up on: '+`${available16BitNumbers[d]}`);
}
for(let x = 0; x < FailedAttempts.length; x++) {
	console.log('\n\033[3;33mFailed 16 bit checks: '+FailedAttempts[x]['Failed int 16 check']);
	console.log('\033[3;33mFailed 24 bit checks: '+FailedAttempts[x+1]['Failed int 24 check']);
	break;
}
