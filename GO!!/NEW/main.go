package main

import f"fmt"

// taking 8 bit numbers
func SumOf8(numberone, numbertwo int8) (summed int8) {
	summed = numberone+numbertwo

	return
}

func main() {

	a:=SumOf8(10, 20)

	f.Printf("SUM: %d", a)

	var t complex64 = 10*10*10*10i

	f.Println("\nNUMBER: ",t)
	SayThis()
}
