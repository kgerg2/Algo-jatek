honapok = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
napok = [[None]*x for x in honapok]
napok[11][30] = True

def nyer(nap):
    h, n = nap
    if napok[h-1][n-1] is not None:
        return napok[h-1][n-1]
    kovetkezo = [(x, n) for x in range(h+1, 13) if n <= honapok[x-1]]
    kovetkezo += [(h, x) for x in range(n+1, honapok[h-1]+1)]
    napok[h-1][n-1] = not any(map(nyer, kovetkezo))
    return napok[h-1][n-1]

nyer((1, 1))
for hn in napok:
    print(" ".join(map(lambda x: {True: "+", False: "-"}[x], hn)))