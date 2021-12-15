a=[]
n=int(input("enter number of columns and rows:\n"))
for i in range(n):
    b=[]
    for j in range(n):
        j=int(input("enter number in["+str(i)+"]["+str(j)+"]:"))
        b.append(j)
    a.append(b)
print("matrix :\n")
for i in range(n):
    for j in range(n):
        print(a[i][j],end=" ")
    print()
temp=0
for i in range(n):
    min=a[i][0]  #from first element  #for min element of rows 
    c=0  #initialising for column
    for j in range(n):
        if a[i][j]<min:
            min=a[i][j]
            c=j #location of column is stored in j
    max=a[0][c]
    for k in range(n):
        if a[k][c]>max:  #jis row ka min nikala hai usi ka column me max find
            max=a[k][c]
    if min==max:
        print("saddle point of matrix is ",min)  #row ka min==col ka max then it is saddle print
        
        temp=1 
if temp==0:
    print("no saddle point found")