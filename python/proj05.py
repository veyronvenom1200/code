"""proj05.py is a program that takes an inputed encrypted code and outputs the dectryted, readable english text"""

_Author_ = "Nathanm Dohm"
_version_ = "3.5.2"
_email_ = "dohmnath@msu.edu"

# Uncomment the following lines when you run the run_file tests
# so the input shows up in the output file.
#
#import sys
#def input( prompt=None ):
#    if prompt != None:
#        print( prompt, end="" )
#    aaa_str = sys.stdin.readline()
#    aaa_str = aaa_str.rstrip( "\n" )
#    print( aaa_str )
#    return aaa_str
#    
import string  # you might find string.ascii_uppercase to be useful

#decrypts the input text by finding the new character and returning the value to the function output_plaintext()
def get_char(ch,shift):
    alphabet = string.ascii_uppercase
    if ch.isalpha():
        plainTextChar = ord(ch)
        cipherTextChar = ((plainTextChar + int(shift)) % 65) % 26
        ch = alphabet[cipherTextChar]
    else:
        pass

    return ch

#get_shift finds the character that appears the most in string 's' and finds the distance(shift) between that character(maxchar) and the letter "E"
def get_shift(s,ignore):
    s = s + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    count = 0
    maxchar = " "
    for i in s:
        if i in ignore:
            #print("in ignore - ", i)
            continue
        else:
            #print("not in ignore - ", i)
            if i.isalpha():
                char = s.count(i)
                if char > count:
                    count = char
                    maxchar = i

    shift = ord("E") - ord(maxchar)
    return shift, maxchar

#takes get_char and loops it to find the decrytped output of the text
def output_plaintext(s,shift):
    string = " "
    for ch in s:
        new_ch = get_char(ch, shift)
        string += new_ch
    return string

def main():
    s = input("Input cipherText: ")
    s = s.upper()
    ignore = " "
    read = "no"
    while read == "no": #if the output is still unreadable, the main function loops through again, but uses the nth max character
        shift, maxchar = get_shift(s, ignore)
        ignore += maxchar
        print(output_plaintext(s, shift))
        print(ignore)
        read = input("\nIs the plaintext readable as English (yes/no): ")
    if read == "yes":
        quit()


# These two lines allow this program to be imported into other code
# such as our function_test code allowing other functions to be run
# and tested without 'main' running.  However, when this program is
# run alone, 'main' will execute.  
if __name__ == "__main__": 
    main()

#Q1: 5
#Q2: 6
#Q3: 4
#Q4: 4
#Q5: 1
