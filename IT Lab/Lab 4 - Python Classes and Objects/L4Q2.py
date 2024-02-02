class TwoSum:
    def solution(self, arr, target):
        prev = {}
        for i, n in enumerate(arr):
            diff = target - n
            if diff in prev:
                return [prev[diff], i]
            prev[n] = i
        return


obj = TwoSum()
arr = []
n = int(input("enter number of elements: "))
for i in range(n):
    ele = int(input("enter element: "))
    arr.append(ele)
target = int(input("enter the target: "))
print(obj.solution(arr, target))