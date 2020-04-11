var Greet: String? = null

fun main() {
    val list_ = mutableListOf("")
    Greet = "AIDAN"
    val GREET = when(Greet) {
        null -> "Hello no name"
        else -> "Hello $Greet"
    }
    list_.add(GREET)
    list_.removeAt(0)
    
    list_.forEach{ index -> println(index) }
}
