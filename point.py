t = int(input())
while t>0:
    x,y,a,b,p,q = input().split()

    area = (int(p) - int(a)) * (int(b) - int(y)) - (int(a) - int(x)) * (int(q) - int(b))
    if(area>0):
        print("RIGHT")
    elif(area<0):
        print("LEFT")
    else:
        print("TOUCH")
    t = t - 1



