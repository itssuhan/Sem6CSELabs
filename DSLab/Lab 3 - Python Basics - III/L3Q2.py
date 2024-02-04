#Find the sum of columns and rows 
#using axis. 

import numpy as np

#Creating Matrix

a = np.array([(20,30),(40,50)])

#Using Axes

print(a)

columns = np.sum(a,axis=0)
print("The Sum of Columns is",columns)

rows = np.sum(a,axis=1)
print("The Sum of rows is",rows)
