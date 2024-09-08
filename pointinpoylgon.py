def area(x,y,a,b,p,q):
    area = (int(p) - int(a)) * (int(b) - int(y)) - (int(a) - int(x)) * (int(q) - int(b))
    return area;

def poly_area(polypnt,x,y):
    total = 0
    side = len(polypnt)

    a,b = polypnt[1][0],polypnt[1][1]
    i = 2
    while(side>=3):
        p,q = polypnt[i]
        total  = total + area(x,y,a,b,p,q)
        a = p
        b = q
        side = side - 1
    return abs(total)


polypnt = [[1,1],[4,2],[3,5],[1,4]]
pnt = [[2,3],[3,1],[1,3]]
# t,m = input().split()
# t = int(t)
# m = int(m)
# i = 0
# while(i<t):
#     polypnt.append(list(input()))
#     i = i + 1
# i = 0
# while(i<m):
#     pnt.append(list(input()))
#     i = i + 1

area = poly_area(polypnt,polypnt[0][0],polypnt[0][1])

    