package main

import (
	"fmt"
	"unicode"
)

func numberOfSpecialChars(word string) int {

	const ALPHABET_SIZE = 26
	var lowerCaseAtLeastOnce = make([]int, ALPHABET_SIZE)
	var upperCaseAtLeastOnce = make([]int, ALPHABET_SIZE)

	for _, letter := range word {
		if unicode.IsLower(letter) {
			lowerCaseAtLeastOnce[letter-'a'] = 1
		} else {
			upperCaseAtLeastOnce[letter-'A'] = 1
		}
	}

	var numberOfSpecialChars = 0
	for i := 0; i < ALPHABET_SIZE; i++ {
		numberOfSpecialChars += lowerCaseAtLeastOnce[i] & upperCaseAtLeastOnce[i]
	}

	return numberOfSpecialChars
}