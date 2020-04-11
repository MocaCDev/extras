/* Bored, and sad, kinda overthinking, so I made a very simple kotlin project :) */
val Emotions = listOf("Sad","Happy","Mad","Angry","Upset")
// null meaning numb
val Numb = mutableMapOf(0 to "numb")
var Numb_: Boolean? = null

fun UpdateEmotion(emotion:Int/*Which index of Emotions*/,reason:String,numb:Boolean) {
    Numb.remove(0) // we don't want this
    if(numb) Numb.put(0,"numb") else Numb.put(0,"Not Numb") // Updating because why not :)
    val Emotion = Emotions[emotion]
    println("I am $Emotion because $reason")
    
    Numb.forEach{ _/*Not used*/, value -> 
    	if(value == "numb") {
            Numb_=true
            println("I am $value")
        } else {
            Numb_=false
           	println("I am $value")
        }
    }
}

fun main() {
    UpdateEmotion(0,"I just am idk why",false)
}
