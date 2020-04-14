let UserInput = prompt("Enter numbers"); // Getting numbers
let Increment = prompt("Increment By: ");
let FoundNumbers = []; // Appending numbers found
let ErrorNumber;
let IncrementEach;

if(Increment) {
  IncrementEach=parseInt(Increment);
} else {
  IncrementEach=1; // DEFAULT
}

if(UserInput==="") {
  document.getElementById("NoInput").innerHTML = "Clicked \"OK\".</br>User did not input anything".fontcolor('red').fixed();
} else if(UserInput) {
  UserInput += ' ';

  document.getElementById("userInput").innerHTML = `User input: ${UserInput}`.fontcolor('blue').fixed();
  document.getElementById('IncrementBy').innerHTML = `</br>Incrementing by: ${IncrementEach}`.fontcolor('blue').fixed();

  for(let i = 0; i < UserInput.length; i++) {
    if(UserInput[i]==' ') {
      if(UserInput[i-2]!=' '&&UserInput[i-1]!=' ') {
        if(UserInput[i-2]!=undefined) {
          let Number = UserInput[i-2]+UserInput[i-1];
          FoundNumbers.push(parseInt(Number));
        } else {
          /* Since i-2 is undefined i-1 should be a numbers */
          ErrorNumber = UserInput[i-1];
        }
      } else {
        FoundNumbers.push(parseInt(ErrorNumber));
        FoundNumbers.push(parseInt(UserInput[i-1]));
      }
    }
  }
} else {
  document.getElementById("NoInput").innerHTML = "Clicked \"CANCEL\"</br>User did not input anything".fontcolor('red').fixed();
}

// Sorting numbers
FoundNumbers.sort();

// Remving NaN from the list
for(let i = 0; i < FoundNumbers.length; i++) {
  if(isNaN(FoundNumbers[i])) {
    FoundNumbers[i]=0;
  }
}

if(FoundNumbers[0]!=null) {
  document.getElementById('ListDuringParse').innerHTML = `</br>During parse: ${FoundNumbers}(SORTED)`.fontcolor('blue').fixed();
}

// Removing duplicate numbers
for(let i = 0; i < FoundNumbers.length; i++) {
  if(FoundNumbers[i]==FoundNumbers[i+1]){
    document.getElementById('Removed').innerHTML = `</br>Removed items: ${FoundNumbers[i]}`.fontcolor('blue').fixed();
    FoundNumbers[i] = 0;
  } else {
  }
}

FoundNumbers = FoundNumbers.filter(index => {
  return index > 0;
});

FoundNumbers = FoundNumbers.map(index => {
  return index + IncrementEach;
});

// This is a mess to look at, and I kinda don't like it, but it'll have to do for now
if(FoundNumbers[0]!=null) {
  document.getElementById('output').innerHTML = `</br><hr>Output: ${FoundNumbers}`.fontsize(16).fontcolor('cyan').fixed();
} else {
  if(UserInput=="") {
    document.getElementById('ParseError').innerHTML = `</br><hr>No user input`.fontsize('18 px').fontcolor('red').big().fixed();
  } else {
    document.getElementById('ParseError').innerHTML = `</br><hr>Cannot have sizes of ${UserInput}`.fontsize('18 px').fontcolor('red').big().fixed();
  }
}
