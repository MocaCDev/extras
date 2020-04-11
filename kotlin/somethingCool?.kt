/* Passing array in as function argument */

fun PARSE(items:Array<Int>, RemainderOfZero:MutableList<Int>){
    items.forEach{ item -> 
    	if(item%2==0) {
            println("$item%2="+item%2)
            RemainderOfZero.add(item) // Appending items that have remainder of zero
        }
    }
}

fun main() {
    val myArr = arrayOf(1,2,3,4)
    var RemainderOfZero = mutableListOf(0)
    PARSE(myArr,RemainderOfZero)
    RemainderOfZero.remove(0)
    
    RemainderOfZero.forEachIndexed { index, value -> println("Index $index->$value")}
}
