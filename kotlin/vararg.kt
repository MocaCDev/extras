fun AddY(vararg strings: String): Array<String> {
    val NEW = Array<String>(5){""}
    strings.forEachIndexed{ index, val_ -> 
        //println(index)
        NEW.drop(0)
        NEW[index]=val_+'y'
    }
    
    return NEW
}


fun main() {
    var newArr: Array<String> = AddY(*arrayOf("a","b"))
    
    newArr.forEach{ ind -> println(ind)}
}
