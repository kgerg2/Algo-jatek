from sys import stdin, stdout

n, k, m, c = map(int, stdin.readline().split())
l = list(map(int, stdin.readline().split()))
if n > 10 or k > 20000 or m > 10 or c > 10000:
    raise ValueError

ik = []
db = 0
elo = None
for i in l:
    ik = [x-i+elo for x in ik if x > i-elo]
    elo = i
    if len(ik) < n:
        ik.append(m)
        db += 1

print(db)