nyerok = {}

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
                if nyerok[ujlista]:
                    nyerok[lista] = False
                    return
    nyerok[lista] = True

def bemenetre_megold(be):
    lista = [0]
    for uj in be:
        if uj == "0":
            lista[-1] += 1
        else:
            lista.append(0)
    lista = {x for x in set(lista) if lista.count(x) % 2 == 1}
    lista.discard(0)
    lista = tuple(sorted(lista))
    if lista not in nyerok:
        kiszamol(lista)
    return "NEM" if nyerok[lista] else "IGEN"

bemenetek = []
kimenetek = []

with open(".\\Korongfordito\\tesztadatok\\in.2") as be:
    hossz = int(be.readline())
    for i in range(hossz):
        bemenetek.append(be.readline().split())
        bemenetek[-1].pop(0)
        kimenetek.append(bemenetre_megold(bemenetek[-1]))

with open(".\\Korongfordito\\tesztadatok\\out.2", "w") as ki:
    for i, eredm in enumerate(kimenetek):
        if eredm == "NEM":
            ki.write("NEM\n")
        else:
            ki.write("IGEN ")
            for j in range(len(bemenetek[i])):
                if bemenetek[i][j] == "1":
                    continue
                ujsor = bemenetek[i][:]
                ujsor[j] = "1"
                if bemenetre_megold(ujsor) == "NEM":
                    ki.write(f"{j+1} 1\n")
                    break
                ujsor[j+1] = "1"
                if bemenetre_megold(ujsor) == "NEM":
                    ki.write(f"{j+1} 2\n")
                    break
