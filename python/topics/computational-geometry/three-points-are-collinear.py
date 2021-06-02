# Slope based solution to check if three
# points are collinear.

# function to check if
# point collinear or not
def collinear(x1, y1, x2, y2, x3, y3):
	
	if ((y3 - y2)*(x2 - x1) == (y2 - y1)*(x3 - x2)):
		print ("Yes")
	else:
		print ("No")

# Driver Code
x1, x2, x3, y1, y2, y3 = 1, 1, 0, 1, 6, 9
collinear(x1, y1, x2, y2, x3, y3);


