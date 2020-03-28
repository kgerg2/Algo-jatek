n, p = map(int, input().split())
l = list(map(int, input().split()))

for i in range(1, n+1):
    if max(sum(l[j:j+i]) for j in range(n-i)) >= p:
        print(i)
        exit()