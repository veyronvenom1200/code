"""lab01 is a program that is used to determine the roots of a quadratic
equation by plugging them into the quadratic formula"""

_Author_ = "Nathan Dohm"
_Version_= "3.5.2"
_email_= "dohmnath@msu.edu"

import math

A = float( input( "\nEnter the coefficient A: " ) )

B = float( input( "\nEnter the coefficient B: " ) )

C = float( input( "\nEnter the coefficient C: " ) )

print( "\nThe coefficients of the equation:\n" )
print( "  Coefficient A = ", A )
print( "  Coefficient B = ", B )
print( "  Coefficient C = ", C )


# **** Replace the following with the calculations of the roots ****

root1 = (-B+(math.sqrt((B**2)-(4*A*C))))/(2*A)
root2 = (-B-(math.sqrt((B**2)-(4*A*C))))/(2*A)


print( "\nThe roots of the equation:\n" )
print( "  Root #1 = ", root1 )
print( "  Root #2 = ", root2 )