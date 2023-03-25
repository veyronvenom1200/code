L = [1,2,3,4,5,6,7,8,9]
i = 0
s = ''
while i < len(L):
    if i%2:
        i += 1
        continue
    elif i>8:
        break
    s += str(L[i])
    i += 2
else:
    print("else executed")  # Line 1

print(s)  # Line 2
