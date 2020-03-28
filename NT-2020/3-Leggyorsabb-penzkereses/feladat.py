n, p = map(int, input().split())
l = list(map(int, input().split()))

i = j = 0
s = 0
m = float("inf")
while i < n:
    while i < n and s < p:
        s += l[i]
        i += 1
    while s >= p:
        s -= l[j]
        j += 1
    m = min(i-j, m)

print(m+1)