var Name: String? = null

fun main() {
    val myArr = mutableListOf(1,2,3,4)
    myArr.add(5)
    val anotherArr = mutableListOf("ARACADERISE","(GetStuffDone)")
    
    // MAPS
    val MAP = mutableMapOf(1 to "fail", 0 to "success")
    
    anotherArr.forEachIndexed{ index, _ -> Name+=anotherArr[index]}
    println(Name)
    MAP.forEach{ token, value -> println("$token = $value")}
    
    // This is one way
    for(ITEM in myArr) {
        println(ITEM)
    }
    
    // This is another way
    myArr.forEach{index -> println(index)}
}
