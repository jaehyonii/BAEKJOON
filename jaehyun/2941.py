croatia_alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

s = input()
answer = 0

s_len = len(s)
idx = 0
while idx < s_len:
    for prefix in croatia_alpha:
        if s[idx:].startswith(prefix):
            idx += len(prefix) - 1
            continue
            
    answer += 1
    idx+=1
    
print(answer)