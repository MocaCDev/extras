let API;
let AmmountClicked;
let INFORMATION;

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
  if(FoundNumbers[0]!=null) {
    API = new MakeMiniApi(NumbersBefore,FoundNumbers,IncrementEach);
    INFORMATION = API.PRINT();

    document.getElementById('GetInfo').onclick = function(){
      AmmountClicked++;
      if(AmmountClicked=1) {
        document.getElementById('ShowInfo').innerHTML = `RETURNED {SORTED_INPUT:${INFORMATION.SORTED_INPUT},OUTPUT:${INFORMATION.OUTPUT},INCREMEMT_BY:${INFORMATION.INCREMENT_BY}}`.fixed().big();
      }
    }
    console.log(API.PRINT());
  } else {
    API = new MakeMiniApi('No Input','No Input','No Input');
    document.getElementById('GetInfo').onclick = function(){
      document.getElementById('ShowInfo').innerHTML = `NO INFORMATION FOUND</br>{SORTED_INPUT:'${API.PRINT().SORTED_INPUT}',OUTPUT:'${API.PRINT().OUTPUT}',INCREMEMT_BY:'${API.PRINT().INCREMENT_BY}'}`.fontcolor('red').fixed().big();

      // Creating a "Hide Information" button
      let NewBtn = document.createElement('button');
      NewBtn.className='button';
      let Information = document.createTextNode('Hide Information');
      NewBtn.appendChild(Information);
      let SpanElement = document.getElementById('HideBtn');
      SpanElement.appendChild(NewBtn);
      console.log('DONE');

      document.getElementById('HideBtn').onclick = function(){
        document.getElementById('ShowInfo').innerHTML='';
        
        let REMOVE = document.getElementById('GetInfo');
        let REMOVE2 = document.getElementById('HideBtn');
        REMOVE.remove();REMOVE2.remove();
      }
    }
    console.log(API.PRINT());
  }
});
