let UserInput = prompt("Enter numbers"); // Getting numbers
let Increment = prompt("Increment By: ");
let FoundNumbers = []; // Appending numbers found
let NumbersBefore;
let ErrorNumber;
let IncrementEach;
let ButtonCicked;

if(Increment) {
  IncrementEach=parseInt(Increment);
} else {
  IncrementEach=1; // DEFAULT
}

if(UserInput==="") {
  document.getElementById("NoInput").innerHTML = "Clicked \"OK\".</br>User did not input anything".fontcolor('white').bold().fixed();
  throw new Error("No input");
} else if(UserInput) {
  UserInput += ' ';

  document.getElementById("userInput").innerHTML = `User input: ${UserInput}`.bold().fixed();
  document.getElementById('IncrementBy').innerHTML = `</br>Incrementing by: ${IncrementEach}`.bold().fixed();

  for(let i = 0; i < UserInput.length; i++) {
    if(UserInput[i]==' ') {
      if(UserInput[i-2]!=' '&&UserInput[i-1]!=' ') {
        if(UserInput[i-2]!=undefined) {
          let Number = UserInput[i-2]+UserInput[i-1];
          FoundNumbers.push(parseInt(Number));
        } else {
          /* Since i-2 is undefined i-1 should be a number */
          ErrorNumber = UserInput[i-1];
        }
      } else {
        /*
          We could've just left:
            FoundNumbers.push(parseInt(ErrorNumber))
          without the if statement, but it is more efficient if we do it this way
        */
        if(ErrorNumber!=null) {
          FoundNumbers.push(parseInt(ErrorNumber));
        }
        FoundNumbers.push(parseInt(UserInput[i-1]));
      }
    }
    NumbersBefore = FoundNumbers;
  }
} else {
  document.getElementById("NoInput").innerHTML = "Clicked \"CANCEL\"</br>User did not input anything".fontcolor('white').bold().fixed();
  throw new Error("No input");
}

// Sorting numbers
FoundNumbers.sort();

// Removing NaN from the list
for(let i = 0; i < FoundNumbers.length; i++) {
  if(isNaN(FoundNumbers[i])) {
    FoundNumbers[i]=0;
  }
}

document.getElementById('ListDuringParse').innerHTML = `</br>List During parse: [${FoundNumbers}](SORTED)`.bold().fixed();

// Removing duplicate numbers
for(let i = 0; i < FoundNumbers.length; i++) {
  if(FoundNumbers[i]==FoundNumbers[i+1]){
    document.getElementById('Removed').innerHTML = `</br>Removed items: ${FoundNumbers[i]}`.bold().fixed();
    FoundNumbers[i] = 0;
  }
}

FoundNumbers = FoundNumbers.filter(index => {
  return index > 0;
});

FoundNumbers = FoundNumbers.map(index => {
  return index + IncrementEach;
});

if(FoundNumbers[0]!=null) {
  document.getElementById('output').innerHTML = `</br><hr style='width:50%'>Output: [${FoundNumbers}]`.fontcolor('darkred').bold().fixed();
} else {
  document.getElementById('output').innerHTML =  `</br><hr style='width:50%'>Cannot take in ${UserInput}. Too large`.fontcolor('darkred').bold().fixed();
}
