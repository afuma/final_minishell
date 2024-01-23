from itertools import product

# elements = ["cmd", "r1", "r2", "r3", "r4", "p", "a", "e", "2e", "sq", "dq", "2sq", "2dq"]

# Générer toutes les combinaisons possibles
combinations = [list(combo) for combo in product(elements, repeat=len(elements))]

# Supprimer les combinaisons dont le premier élément est 'a'
combinations = [combo for combo in combinations if combo[0] != 'a']

# Afficher les combinaisons
i = 0
for combo in combinations:
    if i > 50:
        break
    print(combo)
    i += 1


