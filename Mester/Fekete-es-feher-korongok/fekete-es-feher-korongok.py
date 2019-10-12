from sys import stdin, stdout, setrecursionlimit
import re
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
    szamok = re.subn("(00)+0", "0", stdin.readline().strip()[::2])[0]
    print(len(szamok))
    #szamok = stdin.readline().strip()
    #print(szamok)
    kiszamol(szamok)
    stdout.write(str(ert[szamok]))
    #print(ert)

main()