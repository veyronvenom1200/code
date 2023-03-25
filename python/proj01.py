"""proj01.py is a program that enables the user to convert rods (a unit of measurement)
to meters, feet, furlongs, and miles; and, it also enables the user to determine how
long it takes to walk the value (of rods) specified by the user in minutes."""

_Author_ = "Nathan Dohm"
_Version_ = "3.5.2"
_email_ = "dohmnath@msu.edu"

# prompt the user for the number of rods
user_str = input("Input rods: ")
user_float = float(user_str)

# if/else statement is used just for proper grammar
if user_float < 2:
    print("You input", user_float, "rod.")
else:
    print("You input", user_float, "rods.")

# convert rods to meters
rod_float = 5.0292
meter_float = float(user_float * rod_float)
print("Meters: ", meter_float)

# convert meters to feet
foot_float = float(meter_float / .3048)
print("Feet: ", foot_float)

# convert to miles
mile_float = float((1/1609.34)*meter_float)
print("Miles: ", mile_float)

# convert rods to furlongs
furlong_float = float((1/40)*user_float)
print("Furlongs: ", furlong_float)

# determine how long it would take to walk
time_float = float((mile_float/3.1)*60)

# if/else statement is used just for proper grammar
if user_float < 2:
    print("Minutes to walk", user_str, "rod: ", time_float)
else:
    print("Minutes to walk", user_str, "rods: ", time_float)