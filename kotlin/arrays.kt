var Name: String? = null

fun main() {
    val myArr = mutableListOf(1,2,3,4)
    myArr.add(5)
    val anotherArr = mutableListOf("ARACADERISE","(GetStuffDone)")
    
    anotherArr.forEachIndexed{ index, _ -> Name+=anotherArr[index]}
    println(Name)
    
    // This is one way
    for(ITEM in myArr) {
        println(ITEM)
    }
    
    // This is another way
    myArr.forEach{index -> println(index)}
}
