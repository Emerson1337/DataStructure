#classe de um no
class Node: 
  def __init__(self, info):
    self.info = info
    self.left = None
    self.right = None 

  #metodo para converter a informacao em string
  def __str__(self):
    return str(self.info)

#arvore binaria de busca
class ArvB:
  def __init__(self, info=None):
    if info:
      node = Node(info)
      self.root = node
    else:
      self.root = None

  def preordem(self, node=None):
    if node is None:
      node = self.root
    print(node)
    if node.left:
      self.preordem(node.left)
    if node.right:
      self.preordem(node.right)

  def emordem(self, node=None):
    if node is None:
      node = self.root
    if node.left:
      self.emordem(node.left)
    print(node)
    if node.right:
      self.emordem(node.right)
  
  def posordem(self, node=None):
    if node is None:
      node = self.root
    if node.left:
      self.posordem(node.left)
    if node.right:
      self.posordem(node.right)
    print(node)

  #retorna o maior valor da arvore binaria
  def maxValue(self, leftHeight, rightHeight):
    if leftHeight > rightHeight:
      return leftHeight
    else:
      return rightHeight

  #retorna a altura da arvore
  def altura_arvore(self, node):
    if node is None:
      return 0  

    leftHeight = self.altura_arvore(node.left)    
    rightHeight = self.altura_arvore(node.right)  

    if(leftHeight > rightHeight):
      return leftHeight + 1
    else:
      return rightHeight + 1


#aqui herdamos os metodos ja criados em uma arvore binaria na arvore de busca binaria
class ArvBB(ArvB):
  #funcao de insercao de elemento
  def insert(self, value):
    parent = None
    aux = self.root
    #percorrendo a arvore para encontrar em qual posicao do no sera inserido o valor
    while(aux):
      parent = aux
      if value < aux.info:
        aux = aux.left
      else:
        aux = aux.right

    #se o parent for nulo, entao a arvore eh vazia
    if parent is None:
      self.root = Node(value)
    #se o valor for maior que o no pai, entao ele sera inserido a direita deste pai
    elif value > parent.info:
      parent.right = Node(value)
    #se o valor for menor que o no pai, entao ele sera inserido a esquerda deste pai
    else:
      parent.left = Node(value)

  #pesquisa uma chave na arvore
  def search(self, value, node=0):
    #se nao foi passado um no(arvore) entao o pegaremos a raiz da arvore que chamou o metodo
    if node == 0:
      node = self.root
    #se chagamos a um no vazio, o valor nao foi encontrado
    if node is None:
      return False
    #se o valor for igual ao no em questao, entao foi encontrado
    if node.info == value:
      return True

    if value < node.info:
      return  self.search(value, node.left)
    else:
      return  self.search(value, node.right)
  
  #captura a menor chave da arvore
  def minValue(self, node=None):
    if node is None:
      node = self.root
    if node.left is None:
      return node.info
    smallestValue = self.minValue(node.left)
    return smallestValue

  #captura a maior chave da arvore
  def maxValue(self, node=None):
    if node is None:
      node = self.root
    if node.right is None:
      return node.info
    biggestValue = self.maxValue(node.right)
    return biggestValue

  #conta todos os nos da arvore
  def contadorNos(self, node=0):
    if node == 0:
      return 0
    if node is None:
      node = self.root
    else:
      countEsq = self.contadorNos(node.left);
      countDir = self.contadorNos(node.right);
      #+1 para somar com a raiz
      return countEsq + countDir + 1

  #soma todos os valores da arvore
  def somatorioValores(self, node=0):
    if node == 0:
      node = self.root
    if node is None:
      return 0
    else:
      leftValue = self.somatorioValores(node.left);
      rightValue = self.somatorioValores(node.right);
      #na chamada recursiva, precisamos identificar o primeiro a ser somado para que a soma nao de sempre 0
      return leftValue + rightValue + node.info

  #conta todos os nos da arvore
  def retornaQtdFolhasAux(self, vetor, node=0):
    if node == 0:
      node = self.root
    if node is None:
      return 0
    else:
      nosEsq = self.retornaQtdFolhasAux(vetor, node.left);
      nosDir = self.retornaQtdFolhasAux(vetor, node.right);
      if node.left is None and node.right is None:
        return vetor.append(node.info)
  
  #conta todos os nos da arvore
  def retornaQtdFolhas(self, node=0):
    if node is None:
      node = self.root
    vetor = []
    self.retornaQtdFolhasAux(vetor, node)
    return len(vetor)

  #retorna os multiplos de 3
  def multiplosTresAux(self, vetor, node=0):
    if node == 0:
      node = self.root
    if node is None:
      return 0
    else:
      self.multiplosTresAux(vetor, node.left);
      self.multiplosTresAux(vetor, node.right);
      if not node.info % 3:
        vetor.append(node.info)

  #funcao que chama uma auxiliar para retornar, em um vetor, os multiplos de 3
  def multiplosTres(self, node=None):
    if node is None:
      node = self.root
    vetor = []
    self.multiplosTresAux(vetor, node)
    return vetor

  #funcao que calcula a media das chaves dos nos
  def calcMedia(self, node=None):
    if node is None:
      node = self.root
    qtdNos = self.contadorNos(node)
    somatorioNos = self.somatorioValores(node)

    return somatorioNos/qtdNos

  #numero de nos que uma binaria completa teria - o que temos dara o numero de nulls
  def numNulls(self, node=None):
    if node is None:
      node = self.root

    #calculando a altura da arvore    
    altArv = self.altura_arvore(node)
    #calculando quantos nos teria se a arvore fosse completamente binaria
    nosCompBinaria = 2**altArv - 1
    #calculando os nos atuais
    qtdNos = self.contadorNos(node)
    #a diferenca significa os nulls
    return nosCompBinaria - qtdNos
  
  def isStrictlyBinary(self, node=0):
    if node == 0:
      node = self.root

    if node.right is None and node.left is None:
      return 1
    if node.right and node.left:
      return self.isStrictlyBinary(node.left) and self.isStrictlyBinary(node.right)
    
    return 0      
