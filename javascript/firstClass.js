class Home {
  constructor(HomeName, HomeIp, HomeId) {
    this._HomeName=HomeName;
    this._HomeIp=HomeIp;
    this._HomeId=HomeId;
    this._HomeIPP=[];
  }

  /* SETTERS */
  set AppendHomeIPP(avgDevicesUsed) {this._HomeIPP.push(avgDevicesUsed);}

  /* UPDATERS */
  addHomeIPP(ammountToAdd) {this._HomeIPP[0]+=ammountToAdd}

  /* GETTERS */
  get AvgHomeIPP() {return this._HomeIPP[0];}
  get HomeName(){return this._HomeName;}
  get HomeIp(){return this._HomeIp;}
  get HomeId(){return this._HomeId;}
}

class SetupNewHome extends Home {
  constructor(HomeName,HomeIp,HomeId) {
    super(HomeName,HomeIp,HomeId);
  }
}

const Newhome = new SetupNewHome('Aidans Home','127.0.0.1','10yu');

Newhome.AppendHomeIPP=4;

/* LOGGING */
console.log('DEVICES-> '+Newhome.AvgHomeIPP);
console.log('HOME_NAME-> '+Newhome.HomeName);
console.log('HOME_IP-> '+Newhome.HomeIp);
console.log('HOME_ID-> '+Newhome.HomeId);
