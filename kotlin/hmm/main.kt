var GetVals = mutableListOf<Boolean?>()
var AddedNames = mutableListOf<String>()
var FoundSymbol: Boolean? = null
val LookFor = '_' // Looking for underscores in the UserName

class Sort (
	vararg val UserName:List<String>
) {
    
    constructor() : this(listOf("RandomUser"))
    
    fun AddName() {
        this.UserName.forEachIndexed{ ind,item ->
        	for(i in 0..item[ind].length) {
                if(item[ind][i]!=LookFor) {
                    // If else statement needed so we don't get an error
                    if(i==item[ind].length-1)break
                    else continue
                }
                else {
                    println("FOUND on index of string $i, index of list: $ind, value: "+item[ind][i])
                    FoundSymbol=true
                    break
                }
            }
        }
        
        this.UserName.forEachIndexed{ ind,item -> AddedNames.add(item[ind])}
    }
    
    fun RETURN_LENGTH() : List<Int> {
        val Length = mutableListOf<Int>()
        
        this.UserName.forEachIndexed{ ind, item -> Length.add(item[ind].length)}
        
        return Length
    }
    fun RETURN_NAMES() : Array<out List<String>> {
        return this.UserName
    }
    
    // This is the init of the function
    init{
        AddName()
        if(FoundSymbol==true) {
            GetVals.add(FoundSymbol)
        } else {
            GetVals.add(FoundSymbol)
        }
    }
    
}

fun main() {
    if(FoundSymbol!=true) {
        val LENGTH:List<Int> = Sort().RETURN_LENGTH()
        val Users: Array<out List<String>> = Sort().RETURN_NAMES()
    } else {
        println("ALREADY DONE")
    }
    
    // Deleting duplicates
    for(i in 0..AddedNames.size) {
        if(i != AddedNames.size) {
        	if(AddedNames[i]==AddedNames[i]) {
            	AddedNames.removeAt(i)
                break
        	}
        }
    }
    
    AddedNames.forEach{ item -> println(item)}
    
}
