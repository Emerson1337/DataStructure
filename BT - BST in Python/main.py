import random
from ABB import ArvBB

# values = random.sample(range(1, 100), 5)
values = [40, 20, 10, 30, 60, 50, 70, 35, 5, 11]

BST = ArvBB()
for v in values:
  BST.insert(v)

print(BST.retornaQtdFolhas())
