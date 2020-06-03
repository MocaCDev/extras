package main

import (
	f"fmt"
)

func add(a []int, b int) (returned int) {
	defer func (a []int, b int) {
		f.Println("\n\033[1;32mARG A:",a,"ARG B:",b)
		for i := 0; i < len(a); i++ {
			a[i] -= a[i]
		}
		b-=b
		f.Println("\033[1;34mARG A(NOW):",a,"ARG B(NOW):",b,"\033[0;0m")
	}(a,b)

	for i := 0; i < len(a); i++ {	
		returned += a[i] + b
	}

	return
}

func main() {

	ammount := 5
	arr := [5]int{}
	arr2 := [1][1][1][2][2]int{{{{{1,2},{3,4}}}}}
	var sum int
	var CHAR int32 = 0x41

	for i := 0; i < ammount; i++ {
		if !(i%2==0) {
			arr[i] += (i%2)+(i*i)
		} else {
			arr[i]+=(i+1)*(i+1)
		}

		sum += arr[i]
	}

	f.Println(arr,"SOME:",sum)

	for i := 0; i < 1; i++ {
		for x:= 0; x < 1; x++ {
			for a := 0; a < 1; a++ {
				for b := 0; b < 2; b++ {
					for c := 0; c < 2; c++ {
						f.Printf("AT: %d-%d-%d-%d-%d -> %d:%c\n",i,x,a,b,c,arr2[i][x][a][b][c],CHAR)
						CHAR++
					}
				}
			}
		}
	}
	f.Println(arr2[0][0][0][0][1])

	/* SLICES */

	b := make([]int, 5, 10)

	for i := 0; i < cap(b); i++ {
		if i > 0 && i < len(b) {
			b[i] = i*i
		} else {
			b = append(b,(i+1)*(i+1))
		}
	}

	b = append(b, b[0]*b[0],b[1]*b[1],b[2]*b[2])

	f.Println("\nSIMILAR INDEXES:")
	for i, element := range b {
		for j, element2 := range b {
			if j > i && element == element2 {
				f.Println("INDEX:",i,j,"VALUE:",element)
			}
		}
	}

	if cap(b) > len(b) {
		f.Print("\n\033[0;31mERROR: ")
	}

	f.Println(b,"CAPACITY IS",len(b))

	a := add(b[1:4],2)

	f.Println("\nRESULT OF add FUNCTION:",a,"\n\n")
}
