n, m = input().split()

n = int(n)
m = int(m)

dna = []
for i in range(n):
	dna.append(input())

res = ""
hd = 0

for i in range(m):
	A = T = G = C = 0
	for j in range(n):
		if(dna[j][i] == 'A'):
			A += 1
		elif(dna[j][i] == 'T'):
			T += 1
		elif(dna[j][i] == 'G'):
			G += 1
		elif(dna[j][i] == 'C'):
			C += 1
	d = A
	ch = 'A'
	if(d < C):
		d = C
		ch='C'
	if(d < G):
		d = G
		ch = 'G'
	if(d < T):
		d= T
		ch ='T'

	res += ch
	hd += n - d

print(res + '\n' + str(hd))