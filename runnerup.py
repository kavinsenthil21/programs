runner up finder

if __name__ == '__main__':
    n = int(input())
  
    numb = input()
    lis = list(map(int, numb.split()))
    lis2=[]
    lis.sort(reverse=True)
    c=n-2
    for i in range(1,n):
        if lis[i]!=lis[0]:
            a = i
            break
    print(lis[a]) 
