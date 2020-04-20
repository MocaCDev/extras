package main

import f"fmt"

func TakeIn(numberone, numbertwo int) int {
    return numberone*numbertwo/numberone
}

// LET = Less Than, Equal To
func L_E_T(numberToCheck ,lessThanEqualTo int) bool {
    if(numberToCheck<=lessThanEqualTo) {
        return true
    } else {
        return false
    }
}

func main() {
    var s int
    f.Scanf("%d",&s)
    
    b:=TakeIn(s,20)
    LET:=L_E_T(b,20)
    
    if(LET==true) {
        f.Println("TRUE")
    } else {
        f.Println("FALSE")
    }
}
