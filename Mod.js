let name = document.getElementById('gameName');
let EnterButton = document.getElementById('enterGame');
//let username = document.getElementById('nameInput');
let chat = document.getElementById('chatBox');

document.title = "MINECRAFT";
document.getElementById('pre-content-container').remove();

name.innerHTML = "<span style='color:red'>M</span> <span style='color:green'>I</span> <span style='color:yellow'>N E C R</span> <span style='color:brown'>A F T</span><h1 style='font-size:50px'><span style='color:pink'>MINI</span> <span style='font-size:15px; color:green'>MOO</span> <span style='font-size:50px; color:red'>MOD</span></h1>";
document.getElementById('loadingText').innerHTML = 'LOADING BRUH WAIT';
document.getElementById('desktopInstructions').innerHTML = 'You should know how to play, seriously..';
EnterButton.innerHTML = 'Enter MINECRAFT???';

document.getElementById('diedText').innerHTML = '<span style="color:red">GET</span> <span style="color:green">REVENGE ON</span> <span style="color:brown">THAT BITCH</span>. <span style="color:orange"></br>It do not matter what it takes, you win!!</span>';
//document.getElementById('leaderboard').innerHTML = '<span style="color:red">The</span> <span style="color:yellow">Leaderboard.</span>';
document.getElementById('killCounter').innerHTML = '<p>500</p>';

window.onbeforeunload = (e) => {
    return "You really leaving? Bruh why";
}

EnterButton.onclick = () => {
    
    let map = document.getElementById('mapDisplay');
    map.innerHTML = 'HAHA';
    
    let SCRIPTS = document.getElementById('cdm-zone-end');
    SCRIPTS.remove();
    
    let name = document.getElementById('nameInput')
    name.maxLength = 100;
    name.value = "NOOB IS ME NOOB IS ME YE YE NOOB";
    
    let chat = document.getElementById('chatBox');
    if(chat.value.length > 1) {
        chat.value = chat.value + '__';   
    }
}