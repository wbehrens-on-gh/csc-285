package main

import (
	"fmt"
	"log"
)

func printBanner() {
	fmt.Print("\033[H\033[2J") // clears the screen
	fmt.Println("## D$'s 2 Cents Converter ##")
	fmt.Println("What would you like to do?\n")
	fmt.Println("1) binary -> decimal")	
	fmt.Println("2) binary -> hexadecimal")	
	fmt.Println("3) decimal -> binary")	
	fmt.Println("4) hexadecimal -> binary")	
	fmt.Println("5) end")	
}

func main() {
	var cmd int
	printBanner()
	fmt.Print(">")
	_, err := fmt.Scanln(&cmd)
	
	if err != nil {
		log.Fatal(err)
	}

	for cmd != 5 {
		fmt.Scanln(&cmd)
	}
	

	//ary := ["binary", "decimal", "hexadecimal"] 
	//fmt.Printf("Enter a number in %s) ", )
}
