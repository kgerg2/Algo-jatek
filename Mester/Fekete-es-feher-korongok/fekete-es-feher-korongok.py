from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(10000)

def main():

    ert = {"": 0}

    def kiszamol(allas):
        j = allas[:-1]
        if j not in ert:
            kiszamol(j)
        b = allas[1:]
        if b not in ert:
            kiszamol(b)
        ert[allas] = allas.count('1') - min(ert[j], ert[b])
        #ert[reversed(allas)] = ert[allas]
    stdin.readline()
    szamok = stdin.readline().strip()[::2]
    kiszamol(szamok)
    stdout.write(str(ert[szamok]))
    #print(ert)

if __name__ == "__main__":
    main()