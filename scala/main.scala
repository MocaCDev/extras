// Learning some Scala, because why not?

object Secondary
{
    private var func_count: Int = 0;

    def succeed(): Int = {
        func_count += 1
        func_count
    }

    def print_(name: String): String = {
        "Hello, " + name
    }

    def loop_array(arr: Array[String]): Int = {
        for(i <- 0 until arr.length)
        {
            println("Index " + (i + 1).toString() + " = " + arr(i))
        }
        this.succeed()
    }

    def succeed_amount: Int = func_count
}

object Main {
    def main(args: Array[String]): Unit = {
        val ar: Array[String] = new Array[String](2);
        ar(0) = "Aidan";
        ar(1) = "Bob";

        Secondary.loop_array(ar);
        println(Secondary.succeed_amount);
    }
}
