def convert(lst):
    return (lst[0].split())
 
# Driver code
str = input("Enter the text : ")

lst = []
lst.append(str)
#lst =  ["hello am Kavin Senthil"]
i=-1
l=[]
a= convert(lst)

#print(a)
#print(len(a))


for word in range(0,len(a)-1):
    i=0
    j=i+1
    if  a[word][i].isupper() and a[word+1][0].isupper() :
        print(a[word],a[word+1])
        #print(a[word+1])
        #print("{}{}".format(a[word],a[word+1])
