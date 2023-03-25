"""
File of function stubs for Projecct 07

@author: enbody
"""
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

def open_file():
    file = input("File name: ")
    while True:
        try:
            fp = open(file, "r")
            return fp
        except:
            file = input("File name: ")


def read_file(fp):
    n = 0
    # Read n and initizlize the network to have n empty lists --
    #    one empty list for each member of the network
    n = fp.readline()
    n = int(n)
    network = []
    for i in range(n):
        network.append([])
    for i in fp:
        i = i.strip()
        i = i.replace(" ", "")
       # print(i)
        if "0" in i:
            print(i)
    # You need to write the code to fill in the network as you read the file
    # Hint: append appropriate values to the appropriate lists.
    # Each iteration of the loop will have two appends -- why?

    return network

"""def num_in_common_between_lists(list1, list2):
    ''' Remember the docstring'''
    pass # this is a placeholder that you will replace with Python code

def init_matrix(n):
    '''Create an nxn matrix, initialize with zeros, and return the matrix.'''
    matrix = []
    for row in range(n):  # for each of the n rows
        matrix.append([])  # create the row and initialize as empty
        for column in range(n):
            matrix[row].append(0)  # append a 0 for each of the n columns
    return matrix

def calc_similarity_scores(network):
    ''' Remember the docstring'''
    pass # this is a placeholder that you will replace with Python code

def recommend(user_id,network,similarity_matrix):
    ''' Remember the docstring'''
    pass # this is a placeholder that you will replace with Python code"""

def main():
    fp = open_file()
    read = read_file(fp)

if __name__ == "__main__":
    main()