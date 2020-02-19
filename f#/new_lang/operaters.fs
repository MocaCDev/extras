open System

let x = 10
let d = 20

let main() =
  if not (x <> d) && not (x=d && d=x) then printf "no" else printf "yes"

  if not (x = d) && not (x+d=30) then printf "not equal" else printf "equal"

main()
