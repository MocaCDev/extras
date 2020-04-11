var MyName: String? = null

fun main() {
    MyName = "ARACADERISE"
    if(MyName == "ARACADERISE") {
        MyName+="(GetStuffDone)"
    }
    when(MyName) {
        null -> println("IS NULL")
        "ARACADERISE(GetStuffDone)" -> println(MyName+" is the best 15 year old developer!")
        else -> println(MyName)
    }
}
