from sys import stdin, stdout

def main():
    n, _, k = map(int, stdin.readline().split())
    l = [[] for _ in range(n)]

    be = stdin.read().split()
    prev = 0
    for x in be:
        x = int(x) - 1
        if prev:
            l[prev].append(x)
            l[x].append(prev)
            prev = 0
        else:
            prev = x

    rosszak = {i for i, c in enumerate(l) if c.__len__() < k}
    while rosszak:
        for i, c in enumerate(l):
            if c is not None:
                if c.__len__() < k:
                    l[i] = None
                else:
                    # l[i] = [x for x in c if x not in rosszak]
                    # l[i] = tuple(filter(lambda x: x not in rosszak, l[i]))
                    l[i] = tuple(x for x in c if x not in rosszak)
        rosszak = {i for i, c in enumerate(l) if c is not None and c.__len__() < k}

    jok = [str(i+1) for i in range(n) if l[i]]
    stdout.write(str(len(jok)))
    stdout.write("\n")
    stdout.write(" ".join(jok))
    stdout.write("\n")

main()