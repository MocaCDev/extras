/*
  I am trying to get back into JavaScript. This isn't stationary though, so do not expect this directory
  to stay.
*/

class SetupServer {
  // this will setup properties
  constructor(server_port,server_tunnel){
    this.server_port = server_port;
    this.server_tunnel = server_tunnel;
  }

  // this will just return the server port
  gather_port() {
    return this.server_port;
  }

  // this wil just return the server tunnel
  gather_tunnel() {
    return this.server_tunnel;
  }
}

// This will be the subclass to SetupServer
class StartServer extends SetupServer {
  constructor(port,tunnel,id) {
    super(port,tunnel);
    this.id = id
  }

  presentServer() {
    console.log(this.gather_port() + ' in contact with ' + this.gather_tunnel() + ' with id ' + this.id);
  }
}

server = new StartServer('18080','ssh','1');
server.presentServer();
