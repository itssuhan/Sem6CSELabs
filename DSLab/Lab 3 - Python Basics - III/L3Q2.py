# Operations on Arrays (use numpy wherever required): 
 
# e) Reshape 3X4 array to 2X2X3 array 
# f) Find maximum and minimum element of array, Row wise max and min, column wise max 
# and min and sum of elements. (Use functions max(), min(), sum())


import numpy as np

# a) Creating Array from list with type float

x = [float(i) for i in input().split()]
A = np.array(x)
print(A)

# b) Create array from tuple

y = tuple([float(i) for i in input().split()])
B = np.array(y)
print(B)

# c) Creating a 3X4 array with all zeros 

C = np.zeros((3,4))
print(C)

# d) Create a sequence of integers  from 0 to 20 with steps of 5





