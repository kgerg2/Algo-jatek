import random

for i in range(1, 6):
    with open(".\\Korongfordito\\tesztadatok\\in.%d" % i, "w") as ki:
        ki.write("5\n")
        for _ in range(5):
            hossz = random.randint(1, 5)
            ki.write("%d " % hossz + " ".join([random.choice(["0", "1"]) for _ in range(hossz)]) + "\n")

for i in range(6, 11):
    with open(".\\Korongfordito\\tesztadatok\\in.%d" % i, "w") as ki:
        ki.write("10\n")
        for _ in range(10):
            hossz = random.randint(6, 10)
            ki.write("%d " % hossz + " ".join([random.choice(["0", "1"]) for _ in range(hossz)]) + "\n")

for i in range(11, 21):
    with open(".\\Korongfordito\\tesztadatok\\in.%d" % i, "w") as ki:
        ki.write("100\n")
        for _ in range(100):
            hossz = random.randint(50, 100)
            ki.write("%d " % hossz + " ".join([random.choice(["0", "1"]) for _ in range(hossz)]) + "\n")
