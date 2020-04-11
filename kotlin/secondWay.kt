/* Second way to do what my first program did :) */

var MyName: String? = null

fun main() {
    val NAME = if(MyName != null) MyName else "ARACADERISE(GetStuffDone)"
    
    println(NAME + " is the best 15 year old developer")
}
