n, m, k = map(int, input().split())
l = [set() for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    l[a-1].add(b-1)
    l[b-1].add(a-1)

rosszak = {i for i, c in enumerate(l) if len(c) < k}
while rosszak:
    for i, c in enumerate(l):
        if i in rosszak:
            l[i] = None
        if c:
            c -= rosszak
    rosszak = {i for i, c in enumerate(l) if c is not None and len(c) < k}

jok = [str(i+1) for i in range(n) if l[i]]
print(len(jok))
print(" ".join(jok))