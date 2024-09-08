def area(x,y,a,b,p,q):
    area = (int(p) - int(a)) * (int(b) - int(y)) - (int(a) - int(x)) * (int(q) - int(b))
    return area;
total = 0
side = int(input())
x,y = input().split()
a,b = input().split()
while (side>=3):
    p,q = input().split()
    total = total + area(x,y,a,b,p,q)
    a = p
    b = q
    side = side - 1

print(abs(total))