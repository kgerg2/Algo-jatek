from subprocess import run, PIPE
import random
import re

for i in range(1000):
    minta = "".join([random.choice("01") for _ in range(15)])
    e1 = run(["cmd", "/c", "echo", minta, "|", "python", "C:\\Users\\kgerg\\Documents\\GitHub\\Algo-jatek\\Mester\\Fekete-es-feher-korongok\\fekete-es-feher-korongok.py"], stdout=PIPE)
    e2 = run(["cmd", "/c", "echo", re.subn("(00)+0", "0", minta)[0], "|", "python", "C:\\Users\\kgerg\\Documents\\GitHub\\Algo-jatek\\Mester\\Fekete-es-feher-korongok\\fekete-es-feher-korongok.py"], stdout=PIPE)
    print("{}. ({}) {} {}".format(i, minta, e1.stdout, e2.stdout))
    if e1.stdout != e2.stdout:
        break

""" test_str = "001101001000100"
for minta in [test_str[i: j] for i in range(len(test_str)) for j in range(i + 1, len(test_str) + 1)]:
    e1 = run(["cmd", "/c", "echo", minta, "|", "python", "C:\\Users\\kgerg\\Documents\\GitHub\\Algo-jatek\\Mester\\Fekete-es-feher-korongok\\fekete-es-feher-korongok.py"], stdout=PIPE)
    e2 = run(["cmd", "/c", "echo", ''.join(re.split("00", minta)), "|", "python", "C:\\Users\\kgerg\\Documents\\GitHub\\Algo-jatek\\Mester\\Fekete-es-feher-korongok\\fekete-es-feher-korongok.py"], stdout=PIPE)
    
    if e1.stdout != e2.stdout:
        print("{}: {} {}".format(minta, e1.stdout, e2.stdout)) """