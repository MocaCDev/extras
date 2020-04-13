var StaticId: Int = 1 // one by default
var NameData = mutableListOf<String?>()
var IdData = mutableListOf<Int?>()

class SetupUser(
	val UserName: String? = null,
  val UserId: Int? = null
) {
  constructor(username:String) : this("$username",StaticId++)
  constructor(userid:Int) : this("UNKNOWN$StaticId",userid)
    
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

fun main() {    
  val User = SetupUser("JOHN")

  // We want to parse through the NameData/IdData Lists
  ParseArray(NameData,IdData)
}
