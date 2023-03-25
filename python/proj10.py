

import cards #This is necessary for the project


BANNER = """
    __        _____ _   _ _   _ _____ ____  _ _ _ 
    \ \      / /_ _| \ | | \ | | ____|  _ \| | | |
     \ \ /\ / / | ||  \| |  \| |  _| | |_) | | | |
      \ V  V /  | || |\  | |\  | |___|  _ <|_|_|_|
       \_/\_/  |___|_| \_|_| \_|_____|_| \_(_|_|_)

"""


RULES = """
     ____        _             _        ____
    | __ )  __ _| | _____ _ __( )___   / ___| __ _ _ __ ___   ___
    |  _ \ / _` | |/ / _ \ '__|// __| | |  _ / _` | '_ ` _ \ / _ \\
    | |_) | (_| |   <  __/ |    \__ \ | |_| | (_| | | | | | |  __/
    |____/ \__,_|_|\_\___|_|    |___/  \____|\__,_|_| |_| |_|\___|

    Cells:       Cells are numbered 1 through 4. They can hold a
                 single card each.

    Foundations: Foundations are numbered 1 through 4. They are
                 built up by rank from Ace to King for each suit.
                 All cards must be in the foundations to win.

    Tableaus:    Tableaus are numbered 1 through 8. They are dealt
                 to at the start of the game from left to right
                 until all cards are dealt. Cards can be moved one
                 at a time from tableaus to cells, foundations, or
                 other tableaus. Tableaus are built down by rank
                 and cards must be of the same suit.

"""


MENU = """

    Game commands:
    
    TC x y    Move card from tableau x to cell y
    TF x y    Move card from tableau x to foundation y
    TT x y    Move card from tableau x to tableau y
    CF x y    Move card from cell x to foundation y
    CT x y    Move card from cell x to tableau y
    R         Restart the game with a re-shuffle
    H         Display this menu of commands
    Q         Quit the game
    
"""
   
     
def valid_fnd_move(src_card, dest_card):
    """
    Add your function header here.
    """
    pass  #Replace this pass statement with your own code
  
      
def valid_tab_move(src_card, dest_card):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code
    
    
def tableau_to_cell(tab, cell):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code
            
            
def tableau_to_foundation(tab, fnd):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code
            
            
def tableau_to_tableau(tab1, tab2):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code


def cell_to_foundation(cell, fnd):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code


def cell_to_tableau(cell, tab):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code
              
              
def is_winner(foundations):
    """
    Add your function header here.
    """    
    pass  #Replace this pass statement with your own code


def setup_game():
    """
    The game setup function. It has 4 cells, 4 foundations, and 8 tableaus. All
    of these are currently empty. This function populates the tableaus from a
    standard card deck. 

    Tableaus: All cards are dealt out from left to right (meaning from tableau
    1 to 8). Thus we will end up with 7 cards in tableaus 1 through 4, and 6
    cards in tableaus 5 through 8 (52/8 = 6 with remainder 4).

    This function will return a tuple: (cells, foundations, tableaus)
    """
    
    #You must use this deck for the entire game.
    #We are using our cards.py file, so use the Deck class from it.
    stock = cards.Deck()
    #The game piles are here, you must use these.
    cells = [[], [], [], []]                    #list of 4 lists
    foundations = [[], [], [], []]              #list of 4 lists
    tableaus = [[], [], [], [], [], [], [], []] #list of 8 lists
    
    """ YOUR SETUP CODE GOES HERE """
    pass  #Replace this pass statement with your own code
    
    return cells, foundations, tableaus


def display_game(cells, foundations, tableaus):
    """
    Add your function header here.
    """
    #Labels for cells and foundations
    print("    =======Cells========  ====Foundations=====")
    print("     --1----2----3----4--  --1----2----3----4--")
    print("    ", end="")

    # to print a card using formatting, convert it to string:
    print(cells)
    print(" ".join(map(str, cells)))
    print("{}".format(str(card)))

    print()
    #Labels for tableaus
    print("    =================Tableaus=================")
    print("    ---1----2----3----4----5----6----7----8---")


#HERE IS THE MAIN BODY OF OUR CODE
print(RULES)
cells, fnds, tabs = setup_game()
display_game(cells, fnds, tabs)
print(MENU)
command = input("prompt :> ").strip().lower()
while command != 'q':
    try:
        
        pass  #Replace this pass statement with your own code
        
    #Any RuntimeError you raise lands here
    except RuntimeError as error_message:
        print("{:s}\nTry again.".format(str(error_message)))
    
    display_game(cells, fnds, tabs)                
    command = input("prompt :> ").strip().lower()


