import pandas as pd
import numpy as np

studentData = {'Name':['ABC','DEF','GHI'],'Height': [40,30,20],'Qualification':['BTech','BTech','BTech']}
studentDataFrame = pd.DataFrame(studentData)
print(studentDataFrame)

#Create a list to be converted into new column and add it to the exsisting dataFrame

addressList = ['1st Street NYC','2nd Street NYC','3rd Street NYC']
studentDataFrame['Address']= addressList
print(studentDataFrame)
