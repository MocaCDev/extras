/* FUNCTIONS */

var MyName: String? = null // Will be assigned in SayHi

fun SayHi(usersName:String) {
    MyName=usersName
    
    println("Hello, "+MyName)
}

fun main() {
    SayHi("ARACADERISE(GetStuffDone)")
}
