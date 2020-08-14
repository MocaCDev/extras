/* 
    HACK TO GATHER INFORMATION FROM USERS GOOGLE SEARCHES TO GATHER UP AN API FOR LATER USE WHEN WITHOUT INTERNET CONNECTION
*/


/* GATHERING ANY TYPE OF ID TO HTML TAGS */
function gather_id(element) {
    let ELEMENT_ID;
    try {
        ELEMENT_ID = document.getElementById(element).id;
    } catch {
           
    }
    
    if(ELEMENT_ID) {
        return ELEMENT_ID;
    } else {
        return null;
    }
}

function grab_check(id,element_id) {
    if(id==element_id) {
        return {'can_use':true,'id':element_id};
    } else {
        return {'can_use':null,'id_invalid':element_id};
    }
}

function grab_use(element_id) {
    return document.getElementById(element_id);
}

/* GETTING THE ID AND WORKING WITH IT */
let ID = grab_check(gather_id('__next'),'__next');
if(ID['can_use'] == true) {
    /* START GATHERING API INFORMATION */
    let usage = grab_use(ID['id']);
    console.log(usage.value);
} else {
    console.log(ID);
}
