var StaticId: Int = 1 // one by default
var NameData = mutableListOf<String?>()
var IdData = mutableListOf<Int?>()

class SetupUser(	
	val UserName: String? = null,
  	val UserId: Int? = null
) {
  constructor(username:String) : this("$username",StaticId++)
  constructor(userid:Int) : this("UNKNOWN$StaticId",userid)
  constructor() : this("UNKNOWN$StaticId",StaticId++)
    
  init {
    if(this.UserName == "UNKNOWN$StaticId") {
      println("Welcome...Default User $UserName")
    } else {
      println("Welcome...$UserName$UserId")
    }
        
    NameData.add(this.UserName)
    IdData.add(this.UserId)
        
    StaticId++
  }
}

fun ParseArray(nameToParse:List<String?>, idToParse:List<Int?>) {
  nameToParse.forEachIndexed{ ind,item -> println("NAME: index $ind -> value $item")}
  idToParse.forEachIndexed{ ind, item -> println("ID: index $ind -> value $item")}
}

// Just practicing vararg arguments
fun ThisIsAmazing(vararg Name: List<String>) {
    Name.forEach{index -> println(index)}
}

fun main() {    
  val User = SetupUser()
  val User2 = SetupUser()
  
  val FirstName = listOf("Aidan","Halie")
  val LastName = listOf("White","Buster")
  
  ThisIsAmazing(FirstName,LastName)

  // We want to parse through the NameData/IdData Lists
  ParseArray(NameData,IdData)
  
  val Something = listOf(true, "yes", listOf("sure","nah","why not"), 1, 2, false)
  
  Something.filterIsInstance<List<String>>().forEach{ item -> item.forEach{itemItem -> println(itemItem)}}
}
