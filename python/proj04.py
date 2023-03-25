"""proj04.py is a hangman program. The purpose of the program is to prompt the first player to input a word,
and the second player is supposed to guess it. The second player only has 6 tries, otherwise they lose"""

_Author_ = "Nathan Dohm"

_version_ = "3.5.2"

_email_ = "dohmnath@msu.edu"


right = ""
attempts = 6
tries = 0
guess = ""

print("Hangman: guess letters until you can guess the word or phrase. \nIn this game you get six tries.")

right_str = input("\nEnter a word or phrase: ")

if right_str.isalpha():
    pass
else:
    print("Error: only letters are allowed as input.")
    right_str = input("\nEnter a word or phrase: ")

phrase = print("Phrase: ", right_str)

#displays the proper amount of unknown spaces
right = right * len(right_str)

#if there are spaces in the original phrase, then the current will display spaces
for c in right_str:
    if c != " ":
        right += "-"
    else:
        right += " "

print("current: " + right)
print("0 guesses so far out of 6")

#runs through the code until the player has guessed six times
while tries < 6:
    guessed = input("\nGuess a letter or whole word/phrase: ")

#ends program if guessed phrase is correct
    if guessed.lower() == right_str.lower():
        print("Current: " + right_str)
        print("You won.")
        quit()

#ends program is guessed phrase is incorrect
    if (guessed.lower() != right_str.lower()) and (len(guessed) > 1):
        print("Wrong guess of whole word or phrase.")
        print("You lost.")
        print("The word/phrase was: ", right_str)
        quit()

    guessed = guessed.lower()
    guessed_upper = guessed.upper()

#checks to see if the player has already used a word, and then displays it, and also adds 1 to the guesses made until
#six guesses have been made or the game has been won/lost
    if guessed.isalpha():
        if guessed in guess:
            print("Letter has already been used")
        else:
            guess += guessed
        tries += 1

    if guessed not in right_str and guessed.isalpha():
        print("Letter not in phrase.")

#indexes the word and slices it according to where the letter is at and prints the result
    if guessed.isalpha():
        for i in range(0, len(right_str)):
            if right_str[i] in guessed:
                right = right[:i] + guessed + right[i + 1:]
            if right_str[i] in guessed_upper:
                right = right[:i] + guessed_upper + right[i + 1:]

        print("Current: ", right)
        print(tries, " guesses so far out of 6: " + guess)

    else:
        print("Only letters and spaces are allowed as input.")
        print(tries, " guesses so far out of 6: " + guess)

    if right == right_str:
        print("You won.")
        quit()

else:
    print("You lost.")
    print("The word/phrase was: ", right_str)

#Questions
#Q1:5
#Q2:6
#Q3:4
#Q4:5
#Q5:1