import random
from ABB import ArvBB

# values = random.sample(range(1, 100), 5)
values = [2, 1, 3]

BST = ArvBB()
for v in values:
  BST.insert(v)

print(BST.isStrictlyBinary())
