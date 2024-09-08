t = int(input())
while t>0:
    x1,y1,x2,y2,x3,y3,x4,y4 = input().split()

    cp = (int(y1) - int(y2)) * (int(x4) - int(x3)) - (int(x2) - int(x1)) * (int(y3) - int(y4))
    val = (int(x2) - int(x1))*(int(x3)*(int(y4)-int(y3)) - int(y3)*(int(x4)-int(x3))) - (int(x4) - int(x3))*(int(x1)*(int(y2)-int(y1)) - int(y1)*(int(x2)-int(x1)))
    if(cp!=0 or cp == val):
        print("YES")
    else:
        print("NO")
    t = t - 1