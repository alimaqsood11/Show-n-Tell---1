array = [10,5,6,7,1,12,13,15,21]


#This is an inefficient code. it uses both for loops and performs extra unwanted steps.
def bubblesort():
    for x in range (len(array)):
        for y in range (len(array) -1):
            if array[y] > array [y+1]:
                temp = array[y]
                array[y] = array[y+1]
                array[y+1] = temp

"""
#This is a more efficient code. Outer loop is conditional with flag looping and inner loop is for loop.
def bubblesort():
    noswaps = False
    boundary = len(array) -1
    while noswaps == False:
        noswaps = True
        for y in range (boundary):
            if array[y] > array[y+1]:
                temp = array[y]
                array[y] = array[y+1]
                array[y+1] = temp
                noswaps = False
        boundary = boundary - 1
"""
print(array)
bubblesort()
print(array)




