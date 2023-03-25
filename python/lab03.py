original = input(str("Enter a word: "))
word = original.lower()
first = word[0]
consonants = "bcdfghjklmnpqrstvwxyz"

def vowel(original):
    return original + "way"

def consonant(original):
    while original[0] not in "aeiou":
        original = original[1:] + original[0:1]
    return original + "ay"

def main_function():
    if len(original) > 0 and original.isalpha():
        if first in "aeiou":
            print(vowel(original))
        else:
            print(consonant(original))

main_function()
