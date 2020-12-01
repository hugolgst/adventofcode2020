package main

import (
	"fmt"
	"io/ioutil"
	"strconv"
	"strings"
)

func main() {
	partOneResult, partTwoResult := false, false

	// Read the entry bites
	data, err := ioutil.ReadFile("./day1/entry.txt")
	if err != nil {
		panic(err)
	}

	// Split all the elements by line
	entries := strings.Split(string(data), "\n")

	for _, entry := range entries {
		// Convert the string to an integer
		intEntry, _ := strconv.Atoi(entry)

		for _, entry2 := range entries {
			// Convert the string to an integer
			intEntry2, _ := strconv.Atoi(entry2)

			if intEntry+intEntry2 == 2020 && !partOneResult {
				fmt.Printf("Part 1 solution: %d\n", intEntry*intEntry2)
				partOneResult = true
				continue
			}

			partTwo(
				entries,
				intEntry,
				intEntry2,
				&partTwoResult,
			)
		}
	}
}

func partTwo(entries []string, entry1, entry2 int, gotResult *bool) {
	for _, entry3 := range entries {
		// Convert the string to an integer
		intEntry3, _ := strconv.Atoi(entry3)
		product := entry1 * entry2 * intEntry3
		sum := entry1 + entry2 + intEntry3

		if sum != 2020 || product == 0 || *gotResult {
			continue
		}

		fmt.Printf("Part 2 solution: %d\n", product)
		*gotResult = true
	}
}
