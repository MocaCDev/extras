/* 
  This file was intended to work with buttons,
  the console, and creating a basic API of the information being gathered
*/

let API;
let AmmountClicked;
let INFORMATION;

// HANDING EXITING THE PAGE
window.addEventListener('beforeunload', (e)=>{
  e.preventDefault();
  e.returnValue = '';
});

// If the "EXIT" button is clicked, the window will close
document.getElementById('EXIT').onclick = function(){
  let askToLeave = confirm("Are you sure you want to leave?");
  if(askToLeave) {
    window.close();
  }
}

const RemoveBtn = () => {
  // Creating a "Hide Information" button
  let NewBtn = document.createElement('button');
  NewBtn.className='DelButton';
  let Information = document.createTextNode('Delete Information');
  NewBtn.appendChild(Information);
  let SpanElement = document.getElementById('HideBtn');
  SpanElement.appendChild(NewBtn);

  document.getElementById('HideBtn').onclick = function(){
    let REMOVE = document.getElementById('GetInfo');
    let REMOVE2 = document.getElementById('HideBtn');
    let REMOVE3 = document.getElementById('ShowInfo');
    REMOVE.remove();REMOVE2.remove();REMOVE3.remove();
  }
};

class MakeMiniApi {
  constructor(UserInp, Output, IncrementBy) {
    this.UserInp = UserInp;
    this.OUT = Output;
    this.IncBy = IncrementBy;
  }

  PRINT() {
    /*
      Removing 0 in UserInp, the list has not yet been modified
      Checking if type is string. If user inputs nothing we set each ideal of the class
      to 'No Input' which is a string
     */
    if(typeof this.UserInp[0]!='string') {
      this.UserInp = this.UserInp.filter(index => index>0);
    }

    return {
      SORTED_INPUT:this.UserInp,
      OUTPUT:this.OUT,
      INCREMENT_BY:this.IncBy
    };
  }
}

$(function(){
  // Function used when we show the user the API information
  const ShowApiInfo = (API) => {
    document.getElementById('ShowInfo').innerHTML = `RETURNED {SORTED_INPUT:${API.PRINT().SORTED_INPUT},OUTPUT:${API.PRINT().OUTPUT},INCREMEMT_BY:${API.PRINT().INCREMENT_BY}}`.fixed().big();
    RemoveBtn();
  };
  console.log(FoundNumbers[0]);
  if(FoundNumbers[0]!=null) {
    API = new MakeMiniApi(NumbersBefore,FoundNumbers,IncrementEach);

    document.getElementById('GetInfo').onclick = function(){
      AmmountClicked++;
      if(AmmountClicked=1) {
        ShowApiInfo(API);
      }
    }
    console.log(API.PRINT());
  } else {
    API = new MakeMiniApi('No Input','No Input','No Input');
    document.getElementById('GetInfo').onclick = function(){
      ShowApiInfo(API);
    }
    console.log(API.PRINT());
  }
});
