find_word = open("dictionary.txt", "r")

def vowels(word):
    vowel_str = "aeiouy"
    vowels_in_word = ""
    for i in word:
        if i in vowel_str:
            vowels_in_word += i

    return vowels_in_word

print("Find words containing a single vowel ('aeiouy'): ")
for word in find_word:
    word = word.lower()
    vowel_str = vowels(word)
    if vowel_str == "aeiou":

        print(word)
