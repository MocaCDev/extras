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
                    println(item[ind][i])
                    
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
        
        if(FoundSymbol!=true) {
            this.UserName.forEachIndexed{ ind, item -> AddedNames.add(item[ind])}
        }
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
        val SymbolCatcher = Sort()
    } else {
        println("ALREADY DONE")
    }
    
    AddedNames.forEach{ item -> println(item)}
    
}
