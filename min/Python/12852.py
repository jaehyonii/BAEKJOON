n = int(input())

dist = [0]*(n+1)
before = [0]*(n+1)

for i in range(2, n+1):
    dist[i] = dist[i-1]+1
    before[i] = i-1

    if(i%3==0 and dist[i]>dist[i//3]+1):
        dist[i] = dist[i//3]+1
        before[i] = i//3

    if(i%2==0 and dist[i]>dist[i//2]+1):
        dist[i] = dist[i//2]+1
        before[i] = i//2

num = n

print(dist[n])
while(num!=0):
    print(num, end=' ')
    num = before[num]
    
        
