class SetupUser (
	UserName:String="Unknown"
) {
    val UserName = UserName
    init {
        println("USER CREATED\nUSERNAME -> $UserName")
    }
}

fun main() {
    val NewUser = SetupUser("AIDAN");
}
