/* Passing array in as function argument */

fun PARSE(items:Array<Int>, NewList:MutableList<Int>){
    items.forEach{ item -> 
    	if(item%2==0) {
            println("$item%2="+item%2)
            NewList.add(item)
        }
    }
}

fun main() {
    val myArr = arrayOf(1,2,3,4)
    val NewList = mutableListOf(0)
    PARSE(myArr,NewList)
    
    NewList.forEachIndexed { index, value -> if(value != 0)println("$index->$value%2=0")}
}
