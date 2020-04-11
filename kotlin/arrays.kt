fun main() {
    val myArr = arrayOf(1,2,3,4)
    
    // This is one way
    for(ITEM in myArr) {
        println(ITEM)
    }
    
    // This is another way
    myArr.forEach{index -> println(index)}
}
