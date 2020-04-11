/* FUNCTIONS */

var UserName: String? = null // Will be assigned in SayHi
var UserAge: Int? = null

fun SayHi(usersName:String, usersAge:Int) {
    UserName=usersName
    UserAge=usersAge
    
    println("Hello, "+UserName+".\nI see you're "+UserAge+" years old!")
}

fun main() {
    SayHi("ARACADERISE(GetStuffDone)",15)
}
