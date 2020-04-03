let possibleOutcomes = [
  1,2,3,4,5,10,80,150
];
let outcomes = [];
let argumentToPass = 70;

const MyFunction = (functionCall,functionArgument) => {
  functionCall(functionArgument);
}

function addNumberByTen(arg) {
  arg=arg+10;

	for(let i = 0; i < possibleOutcomes.length; i++) {
    if(arg===possibleOutcomes[i]) {
      outcomes.push(arg);
    }
  }
}

MyFunction(addNumberByTen,argumentToPass);

console.log(outcomes);
