open System

let num n = if n > 10 && n < 20 then "greater than 10, less than 20" else "idk"

let main() =
  Console.WriteLine(num 10)
 
main()
