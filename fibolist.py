a, b = 0, 1
count=0
lis=[0]
for i in range(0,100):
    while b < 1000:
        print(b)
        lis.append(b)
        #a, b = b, a + b
        c=a+b
        a=b
        b=c  
        
n=int(input("enter the index"))

print(lis[n])
lis.sort(reverse=True)
print(lis)
