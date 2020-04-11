fun parse(infoTOParse: Map<Int, String>) {
    infoTOParse.forEach{ item, value -> println("$item belongs to $value")}
}

fun main() {
    val arr = mutableMapOf(1 to "one", 2 to "two")
    arr.put(3, "three")
    parse(arr)
}
