import pandas as pd
import numpy as np

studentData = {'Name':['ABC','DEF','GHI'],'Height': [40,30,20],'Qualification':['BTech','BTech','BTech']}
studentDataFrame = pd.DataFrame(studentData)

#using dataframeName.insert to insert a column

AgeList = [20,23,19]
#DataFrame.insert(index where the column should be,name of column,data)
studentDataFrame.insert(1,'Age',AgeList)
print(studentDataFrame)
