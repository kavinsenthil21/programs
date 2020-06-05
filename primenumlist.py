a=int(input("enter starting"))
b=int(input("enter ending"))

for j in range(a,b):
    flag=1
    for i in range(2,j):
        if j%i==0:
            flag=0  
    if flag==1 and j>1:
        print("{} ".format(j))
        
