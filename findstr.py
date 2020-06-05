finding string

string = raw_input()
substring = raw_input()
answer = 0
start = 0
length = len(string)
index = string.find(substring, start, length)
while index<>-1:
    answer = answer+1
    start = index+1
    index = string.find(substring, start, length)
print (answer)

