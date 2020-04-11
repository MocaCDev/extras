/* Second way to do what my first program did :) */

var MyName: String? = null

fun main() {
    // Using if
    val NAME = if(MyName != null) MyName else "ARACADERISE(GetStuffDone)"
    
    // Using when
    val NAME_ = when(MyName) {
        null -> "ARACADERISE(GetStuffDone)"
        else -> MyName
    }
    
    print(NAME + " is the best 15 year old developer\n") // print doesn't create new line, \n needed
    print(NAME_ + " is the best 15 year old developer")
}
