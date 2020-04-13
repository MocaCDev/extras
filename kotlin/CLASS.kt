class SetupUser (
	val UserName:String="Unknwon"
) {
    fun PrintName(): String {
        return "Username: $UserName"
    }
}

fun main() {
    val NewUser = SetupUser("AIDAN");
    println(NewUser.PrintName())
}
