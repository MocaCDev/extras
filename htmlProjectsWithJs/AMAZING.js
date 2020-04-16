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
    // Removing 0 in UserInp, the list has not yet been modified
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
    console.log(API.PRINT());
    document.getElementById('GetInfo').onclick = function(){
      document.getElementById('ShowInfo').innerHTML = `NO INFORMATION FOUND</br>{SORTED_INPUT:'${API.PRINT().SORTED_INPUT}',OUTPUT:'${API.PRINT().OUTPUT}',INCREMEMT_BY:'${API.PRINT().INCREMENT_BY}'}`.fontcolor('red').fixed().big();
    }
  }
});
