import random

with open(".\\Korongfordito\\tesztadatok\\in.1", "w") as ki:
    ki.write("5\n")
    for _ in range(5):
        hossz = random.randint(5, 20)
        ki.write(f"{hossz} " + " ".join([random.choice(["0", "1"]) for _ in range(hossz)]) + "\n")

with open(".\\Korongfordito\\tesztadatok\\in.2", "w") as ki:
    ki.write("100\n")
    for _ in range(100):
        hossz = random.randint(50, 100)
        ki.write(f"{hossz} " + " ".join([random.choice(["0", "1"]) for _ in range(hossz)]) + "\n")