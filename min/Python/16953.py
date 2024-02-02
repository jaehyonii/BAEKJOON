import sys
a, b = map(int, sys.stdin.readline().split())

cnt = 0

while(b > a):
    if(b % 10 == 1):
        b -= 1
        b //= 10
        cnt +=1
    elif(b % 2 == 0):
        b //= 2
        cnt +=1
    else:
        break

if(b==a):
    cnt +=1
    print(cnt)
else:
    print(-1)
