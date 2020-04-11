var MyName: String? = null

fun main() {
    MyName = "AIDAN"
    when(MyName) {
        null -> println("IS NULL")
        "AIDAN" -> println("IS AIDAN")
        else -> println(MyName)
    }
}
