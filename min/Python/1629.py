import sys
a, b, c = map(int, sys.stdin.readline().split())

ans = 1

while(b):
    if(b%2!=0):
        ans = ans * a % c
    a = a * a % c
    b = b//2

print(ans)
