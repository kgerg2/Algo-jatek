from sys import stdin, stdout

def main():
    n, m, k = map(int, stdin.readline().split())
    l = [[] for _ in range(n)]

    for _ in range(m):
        a, b = map(int, stdin.readline().split())
        l[a-1].append(b-1)
        l[b-1].append(a-1)

    rosszak = [i for i, c in enumerate(l) if len(c) < k]
    while rosszak:
        for i, c in enumerate(l):
            if c is not None:
                if len(c) < k:
                    l[i] = None
                elif c:
                    l[i] = [x for x in c if x not in rosszak]
        rosszak = [i for i, c in enumerate(l) if c is not None and len(c) < k]

    jok = [str(i+1) for i in range(n) if l[i]]
    stdout.write(str(len(jok)))
    stdout.write("\n")
    stdout.write(" ".join(jok))
    stdout.write("\n")

main()