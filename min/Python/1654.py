k, n = input().split()
k = int(k)
n = int(n)
arr = []
max = 0

for i in range(k):
    num = int(input())
    arr.append(num)
    if(num > max):
        max = num
    
left = 1
right = max
ans = 0

while(left<=right):
    mid = (left+right)//2
    sum = 0
    for i in range(k):
        sum += arr[i]//mid
    if(sum >= n):
        ans = mid
        left = mid+1
    else:
        right = mid-1

print(ans)
