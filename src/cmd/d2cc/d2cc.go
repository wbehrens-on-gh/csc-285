package main

import (
	"fmt"
	"log"
	"math"
	"strconv"
	"strings"
)

// Helpful array for base 10 to 16 conversion
var hexArr = map[string]string{
	"0000": "0",
	"0001": "1",
	"0010": "2",
	"0011": "3",
	"0100": "4",
	"0101": "5",
	"0110": "6",
	"0111": "7",
	"1000": "8",
	"1001": "9",
	"1010": "A",
	"1011": "B",
	"1100": "C",
	"1101": "D",
	"1110": "E",
	"1111": "F",
}

// Read number input
func getNum(prompt string) (in string) {
	fmt.Print(prompt)
	_, err := fmt.Scanln(&in)
	if err != nil {
		log.Fatal(err)
	}
	return
}

// Entering a string in binary it's backwards from how the algorithm we discussed works
// https://stackoverflow.com/questions/1752414/how-to-reverse-a-string-in-go
func reverse(s string) (result string) {
	for _, v := range s {
		result = string(v) + result
	}
	return
}

func binToDec(in string) (result int) {
	for i, c := range reverse(in) {
		x, _ := strconv.Atoi(string(c)) // Convert character to integer
		result += x * int(math.Pow(2, float64(i)))
	}
	return
}

func binToHex(in string) (result string) {
	// Ensure the input array length is always a multiple of 4 
	//   by padding front of array with 0s.
	app_in := strings.Repeat("0", 4-(len(in)%4)) + in

	// Iterate through 4 bit sections of the number converting them to base 10 then to base 16
	for i := 0; i < len(app_in); i += 4 {
		x := app_in[i : i+4]
		result += hexArr[x]
	}
	return
}

func decToBin(in string) string {
	return ""
}

func printBanner() {
	banner := "\033[H\033[2J" + // Magic sequence to clear screen on Linux
		"## D$'s 2 Cents Converter ##\n" +
		"What would you like to do?\n\n" +
		"1) binary -> decimal\n" +
		"2) binary -> hexadecimal\n" +
		"3) decimal -> binary\n" +
		"4) hexadecimal -> binary\n" +
		"5) end\n" +
		"TODO: sanatize input for spaces"
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
				input := getNum("Enter a whole number in 2, do not include spaces\n>")
				fmt.Println(binToDec(input))
			case 2:
				input := getNum("Enter a whole number in 2, do not include spaces\n>")
				fmt.Println(binToHex(input))
			case 3:
				input := getNum("Enter a whole number in base 10\n>")
				fmt.Println(decToBin(input))
			case 4:
				//input := getNum("Enter a whole number in base 16, do not include spaces\n>")
				//fmt.Println(hexToBin(input))
			case 5:
				continue
			default:
				fmt.Printf("Unknown command: %d\n", cmd)
			}
		}

		// Wait for user input before clearing the screen again
		fmt.Println("Press enter to continue...")
		fmt.Scanln()
	}
}
