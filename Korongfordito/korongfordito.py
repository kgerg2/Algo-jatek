# hossz = 10
# korongok = [True]*hossz
# hosszok = [True, False, False] + [None]*(hossz-2)
import time
from pprint import pprint
import random

def sor_kozeprol(max):
    """
    Megadja a természetes számokat úgy, hogy középről kezdi és alternálva folytatja.
    Az elemek a [0, max) intervalumban vannak.
    """
    szorzo = 1
    for i in range(1, max+1):
        yield max//2 + i//2*szorzo
        szorzo *= -1


nyerok = {}

def kozeprol_kiszamol(lista):
    for h in lista:
        for j in sor_kozeprol(h):
            for vagh in [1, 2]:
                if j == h-1 and vagh == 2:
                    continue
                ujlista = set(lista)
                ujlista.discard(h)
                if j == 0 or j == h-1:
                    ujlista ^= {h-vagh}
                elif h > vagh:
                    ujlista ^= {j}
                    ujlista ^= {h-vagh-j}
                ujlista.discard(0)
                ujlista = tuple(sorted(ujlista))
                if ujlista not in nyerok:
                    kozeprol_kiszamol(ujlista)

                # print(ujlista, nyerok[ujlista])

                if nyerok[ujlista]:
                    nyerok[lista] = False
                    return
    nyerok[lista] = True

def kiszamol(lista):
    for h in lista:
        for j in range(h):
            for vagh in [1, 2]:
                if j == h-1 and vagh == 2:
                    continue
                ujlista = set(lista)
                ujlista.discard(h)
                if j == 0 or j == h-1:
                    ujlista ^= {h-vagh}
                elif h > vagh:
                    ujlista ^= {j}
                    ujlista ^= {h-vagh-j}
                ujlista.discard(0)
                ujlista = tuple(sorted(ujlista))
                if ujlista not in nyerok:
                    kiszamol(ujlista)

                # print(ujlista, nyerok[ujlista])

                if nyerok[ujlista]:
                    nyerok[lista] = False
                    return
    nyerok[lista] = True


def eltarolva_kiszamol(lista):
    for i, h in enumerate(lista):
        for j in range(h):
            for vagh in [1, 2]:
                if j == h-1 and vagh == 2:
                    continue
                ujlista = list(lista)
                ujlista.pop(i)
                if j == 0 or j == h-1:
                    ujlista.append(h-vagh)
                elif h > vagh:
                    ujlista.append(j)
                    ujlista.append(h-vagh-j)
                ujlista = [x for x in sorted(ujlista) if x != 0]
                if tuple(ujlista) not in nyerok:
                    eltarolva_kiszamol(tuple(ujlista))
                # print(ujlista, nyerok[tuple(ujlista)])

                if nyerok[tuple(ujlista)]:
                    nyerok[lista] = False
                    return
    nyerok[lista] = True

def lassan_kiszamol(lista):
    for i, h in enumerate(lista):
        for j in range(h):
            for vagh in [1, 2]:
                if j == h-1 and vagh == 2:
                    continue
                ujlista = lista[:]
                ujlista.pop(i)
                if j == 0 or j == h-1:
                    ujlista.append(h-vagh)
                elif h > vagh:
                    ujlista.append(j)
                    ujlista.append(h-vagh-j)
                nyero = lassan_kiszamol(ujlista)
                # print(ujlista, nyero)
                
                if nyero:
                    return False
    return True

# elolrol_kiszamol((2, 2))
# pprint(nyerok)
# pprint(dict(filter(lambda x: x[1], nyerok.items())))

def tesztel(t1, t2):
    global nyerok
    o1 = o2 = 0
    for h in range(100):
        print(h)
        tesztadatok = [1, h] + [random.randint(1, h) for _ in range(random.randint(h//4, h//2))]
        tesztadatok.sort()
        tesztadatok = [tesztadatok[i+1]-tesztadatok[i] for i in range(len(tesztadatok)-1) if tesztadatok[i+1] != tesztadatok[i]]
        tesztadatok = tuple(sorted(set(tesztadatok)))
        nyerok = {}
        kezd = time.time()
        t1(tesztadatok)
        o1 += time.time()-kezd
        print(time.time()-kezd, end=", ")
        n1 = dict(nyerok)
        nyerok = {}
        kezd = time.time()
        t2(tesztadatok)
        o2 += time.time()-kezd
        print(time.time()-kezd)
        print(f"Összesen: {o1}, {o2}")
        n2 = nyerok
        kozosek = n1.keys() & n2.keys()
        jo = all([n1[k] == n2[k] for k in kozosek])
        # print(jo, n1, n2)
        if not jo:
            return False
    return True

print(tesztel(kiszamol, elolrol_kiszamol))
# kiszamol((4, 1))
# print(nyerok)