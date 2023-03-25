"""proj08.py is a program that prompts the user for an input file (.csv) and unpacks the data and presents it in a table for the user to read/analyze.
The program then offers to plot the data of user specified x and y coordinates."""

_Author_ = "Nathan Dohm"
_email_ = "dohmnath@msu.edu"
_version_ = "3.5.2"

# uncomment for testing with run_file.py
"""import sys
def input( prompt=None ):
    if prompt != None:
        print(prompt, end="")
    aaa_str = sys.stdin.readline()
    aaa_str = aaa_str.rstrip( "\n" )
    print( aaa_str )
    return aaa_str"""

import pylab

# Here are some constants that are optional to use -- feel free to modify them, if you wish
REGION_LIST = ['Far_West',
 'Great_Lakes',
 'Mideast',
 'New_England',
 'Plains',
 'Rocky_Mountain',
 'Southeast',
 'Southwest',
 'all']
VALUES_LIST = ['Pop', 'GDP', 'PI', 'Sub', 'CE', 'TPI', 'GDPp', 'PIp']
VALUES_NAMES = ['Population(m)','GDP(b)','Income(b)','Subsidies(m)','Compensation(b)','Taxes(b)','GDP per capita','Income per capita']
PROMPT1 = "Specify a region from this list -- far_west,great_lakes,mideast,new_england,plains,rocky_mountain,southeast,southwest,all: "
PROMPT2 = "Specify x and y values, space separated from Pop, GDP, PI, Sub, CE, TPI, GDPp, PIp: "

def open_file():
    '''prompts the user for a csv file. If the file does not exist, the program prompts for another file'''
    fp = input("Input file name: ")
    while True:
        try:
            csv = open(fp,"r")
            return fp, csv
        except IOError:
            print("Error opening file. Please try again.\n")
            fp = input("Input file name: ")

def region(fp):
    '''Prompts the user for a legitimate region of the United States. It also returns the high and low GDP and personal income'''
    state_lst = []
    count = 0
    num_states = 0
    csv = open(fp,"r", encoding="windows-1252")
    n = csv.readline()
    region = input("\n" + PROMPT1)
    region = region.lower()
    if "all" not in region:
        while region not in [x.lower() for x in REGION_LIST]: #if the region does not exist, the program prompts the user for a new region
            print("Error in region name. Please try again.\n")
            region = input(PROMPT1)
            region = region.lower()
        else:
            print("\nData for the " + region.title() + " region:\n")
            for i in csv:
                i = i.replace(",", " ")
                if region.lower() in i.lower():
                    state_lst.append([])
                    for states in i.split():
                        state_lst[num_states].append(states)
                    num_states += 1

    else:
        print("\nData for the " + region.title() + " region:\n")
        for i in csv:
            i = i.replace(",", " ")
            if region.lower() not in i.lower():
                state_lst.append([])
                for states in i.split():
                    state_lst[num_states].append(states)
                num_states += 1


    for j in range(len(state_lst)): #creates the GDP and personal income data and appends it to the lists of each state
        GDP_per_capita = (float(state_lst[count][3]) / float(state_lst[count][2]))*1000
        personal_income = (float(state_lst[count][4]) / float(state_lst[count][2]))*1000
        state_lst[count].append(GDP_per_capita)
        state_lst[count].append(personal_income)
        count += 1

    return state_lst

def region_info(state_lst, lst):
    '''Formats the data, and then prints it in a table.'''
    count = 0

    high_GDP = max([sublist[-2] for sublist in lst])
    for a in lst:
        if high_GDP in a:
            print(a[0], "has the highest GDP per capita at", "${:,.2f}".format(a[-2]))

    low_GDP = min([sublist[-2] for sublist in lst])
    for a in lst:
        if low_GDP in a:
            print(a[0], "has the lowest GDP per capita at", "${:,.2f}".format(a[-2]), "\n")

    high_income = max([sublist[-1] for sublist in lst])
    for a in lst:
        if high_income in a:
            print(a[0], "has the highest income per capita at", "${:,.2f}".format(a[-1]))

    low_income = min([sublist[-1] for sublist in lst])
    for a in lst:
        if low_income in a:
            print(a[0], "has the lowest income per capita at", "${:,.2f}".format(a[-1]), "\n")

    print("State", "{:>25}".format("Population(m)"), "{:>15}".format("GDP(b)"), "{:>15}".format("Income(b)"), "{:>15}".format("Subsidies(m)"), "{:>20}".format("Compensation(b)"), "{:>15}".format("Taxes(b)"), "{:>20}".format("GDP per capita"), "{:>20}".format("Income per capita"))


    for i in range(len(state_lst)):
        print("{:<20}".format(state_lst[count][0]), "{:>10,.2f}".format(float(state_lst[count][2])), "{:>15,.2f}".format(float(state_lst[count][3])), "{:>15,.2f}".format(float(state_lst[count][4])), "{:>15,.2f}".format(float(state_lst[count][5])), "{:>20,.2f}".format(float(state_lst[count][6])), "{:>15,.2f}".format(float(state_lst[count][7])), "{:>20,.2f}".format(state_lst[count][8]), "{:>20,.2f}".format(state_lst[count][9]))
        count += 1



def plot_regression(x,y):
    '''Draws a regression line for values in lists x and y.
       x and y must be the same length.'''
    xarr = pylab.array(x) #numpy array
    yarr = pylab.array(y) #numpy arry
    m,b = pylab.polyfit(xarr,yarr, deg = 1) #creates line, only takes numpy arrays
    #as parameters
    pylab.plot(xarr,m*xarr + b, '-') #plotting the regression line



def plot(lst):   # you need to replace pass with parameters
    '''Plot the values in the parameters.'''
    x_count = 0
    y_count = 0
    x_counter = 2
    y_counter = 2
    name_counter = 0
    x = []
    y = []
    state_names = []

    plot_values = input(PROMPT2)
    plot_values = plot_values.lower().split()
    x_index = [x.lower() for x in VALUES_LIST].index(plot_values[0]) #finds the index value of the first plot_value (x value)
    y_index = [y.lower() for y in VALUES_LIST].index(plot_values[1]) #finds the index value of the second plot_value (y value)

    for a in lst:
        # if the specified x value exists, it finds the index of where the x value is located in the VALUES_LIST and finds all the data at that index
        # in the list of state information for each state in the specified region
        if plot_values[0] in [x_title.lower() for x_title in VALUES_LIST]:
                x.append(float(lst[x_count][x_index + 2]))
                x_count += 1
                x_counter += 1

    for i in lst:
        # if the specified y value exists, it finds the index of where the y value is located in the VALUES_LIST and finds all the data at that index
        # in the list of state information for each state in the specified region
        if plot_values[1] in [y_title.lower() for y_title in VALUES_LIST]:
                y.append(float(lst[y_count][y_index + 2]))
                y_count += 1
                y_counter += 1

    # In the following you need to replace 'pass' with your own arguments
    plot_title = VALUES_NAMES[x_index] + " vs. " + VALUES_NAMES[y_index]
    pylab.title(plot_title)   # plot title

    pylab.xlabel(VALUES_NAMES[x_index])   #label x axis
    pylab.ylabel(VALUES_NAMES[y_index])   #label y axis

    for z in lst:
        state_names.append(lst[name_counter][0])
        name_counter += 1

    pylab.scatter(x,y)
    for i, txt in enumerate(state_names):
        pylab.annotate(txt, (x[i],y[i]))

    plot_regression(x,y)

    # USE ONLY ONE OF THESE TWO
    pylab.show()                # displays the plot
    #pylab.savefig("plot.png")   # saves the plot to file plot.png

def main():
    '''main function'''
    count = 0
    fp, csv = open_file()
    state_lst = region(fp)
    lst = []
    for i in range(len(state_lst)):
        lst.append(state_lst[count])
        count += 1
    region_info(state_lst, lst)
    create_plot = input("\nDo you want to create a plot? ")
    if "yes" in create_plot.lower(): #if user input 'yes', the graph creates a plot
        plot(lst)
    else:
        quit()

main()
