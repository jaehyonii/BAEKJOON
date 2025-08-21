s = input()
s_len = len(s)

if s[0:s_len//2] == s[s_len - s_len//2:][::-1]:
    print(1)
else:
    print(0)