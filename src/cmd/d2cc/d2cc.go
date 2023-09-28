package main

import (
	"fmt"
	"log"
)

func binToDec() {

}

func printBanner() {
	banner := "\033[H\033[2J" + // Magic sequence to clear screen on Linux
		"## D$'s 2 Cents Converter ##\n" +
		"What would you like to do?\n\n" +
		"1) binary -> decimal\n" +
		"2) binary -> hexadecimal\n" +
		"3) decimal -> binary\n" +
		"4) hexadecimal -> binary\n" +
		"5) end\n"
	fmt.Println("%s", banner)
}

func main() {
	for cmd := 0; cmd != 5; {
		printBanner()
		fmt.Print(">")
		_, err := fmt.Scanln(&cmd) 
		if err != nil {
			log.Fatal(err)
		} else {
			switch cmd {
			case 1:
				binToDec()
			case 2:
				//binToHex()
			case 3:
				//decToBin()	
			case 4:
				//hexToBin()	
			case 5:
				continue;
			default:
				fmt.Printf("Unknown command: %d\n", cmd)
			}
		}	
		
		// Wait for user input before clearing the screen again
		fmt.Println("Press enter to continue...")
		fmt.Scanln()
	}
}
