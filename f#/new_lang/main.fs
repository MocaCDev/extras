open System

let num n = if n >= 10 && n <= 20 then "greater, equal to 10, less, equal to 20" else "idk"

let main() =
  Console.WriteLine(num 10)
 
main()
