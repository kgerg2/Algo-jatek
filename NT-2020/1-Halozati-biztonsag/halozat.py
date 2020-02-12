from sys import stdin, stdout

def main():
    n, _, k = map(int, stdin.readline().split())
    l = [[] for _ in range(n)]

    be = stdin.readlines()
    for sor in be:
        a, b = map(int, sor.split())
        a -= 1
        b -= 1
        l[a].append(b)
        l[b].append(a)

    rosszak = {i for i, c in enumerate(l) if len(c) < k}
    while rosszak:
        for i, c in enumerate(l):
            if c is not None:
                if len(c) < k:
                    l[i] = None
                else:
                    # l[i] = [x for x in c if x not in rosszak]
                    # l[i] = tuple(filter(lambda x: x not in rosszak, l[i]))
                    l[i] = tuple(x for x in c if x not in rosszak)
        rosszak = {i for i, c in enumerate(l) if c is not None and len(c) < k}

    jok = [str(i+1) for i in range(n) if l[i]]
    stdout.write(str(len(jok)))
    stdout.write("\n")
    stdout.write(" ".join(jok))
    stdout.write("\n")

main()