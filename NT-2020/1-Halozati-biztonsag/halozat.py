from sys import stdin, stdout

def main():
    n, m, k = map(int, stdin.readline().split())
    l = [[False]*n for _ in range(n)]

    for _ in range(m):
        a, b = map(int, stdin.readline().split())
        l[a-1][b-1] = True
        l[b-1][a-1] = True

    ures = [False]*n
    van = True
    while van:
        van = False
        for i, c in enumerate(l):
            if c is not ures and sum(c) < k:
                l[i] = ures
                for j in range(n):
                    l[j][i] = False
                van = True

    jok = [str(i+1) for i in range(n) if l[i] is not ures]
    stdout.write(str(len(jok)))
    stdout.write("\n")
    stdout.write(" ".join(jok))
    stdout.write("\n")

main()