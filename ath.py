athletesort

x=list(map(int,input().split()))
n=x[0]
m=x[1]
y=[]
for i in range(n):
	y.append(list(map(int,input().split())))
k=int(input())
import operator
def pr(l):
	for i in range(len(l)):
		string=''
		for j in range(len(l[i])):
			string+=str(l[i][j])+' '
		print(string)

print(list(sorted(y,key=operator.itemgetter(k))))

