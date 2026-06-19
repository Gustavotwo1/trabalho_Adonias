#Eddye Robert
class No:
    def __init__(self, valor):
        self.valor = valor
        self.esquerda = None
        self.direita = None

class ArvoreBinaria:
    def __init__(self):
        self.raiz = None

    # Raiz -> Esquerda -> Direita
    def pre_ordem(self, no):
        if no is not None:
            print(no.valor, end=" ")
            self.pre_ordem(no.esquerda)
            self.pre_ordem(no.direita)

    # Esquerda -> Raiz -> Direita
    def em_ordem(self, no):
        if no is not None:
            self.em_ordem(no.esquerda)
            print(no.valor, end=" ")
            self.em_ordem(no.direita)

    # Esquerda -> Direita -> Raiz
    def pos_ordem(self, no):
        if no is not None:
            self.pos_ordem(no.esquerda)
            self.pos_ordem(no.direita)
            print(no.valor, end=" ")

# ==========================================
# ARVORE BINARIA
# ==========================================
arvore = ArvoreBinaria()

# Nível 0 (Raiz)
arvore.raiz = No('A')

# Nível 1
arvore.raiz.esquerda = No('B')
arvore.raiz.direita = No('C')

# Nível 2
arvore.raiz.esquerda.esquerda = No('D')
arvore.raiz.esquerda.direita = No('E')
arvore.raiz.direita.esquerda = No('F')
arvore.raiz.direita.direita = No('G')

# Nível 3
arvore.raiz.esquerda.esquerda.esquerda = No('H')
arvore.raiz.esquerda.esquerda.direita = No('I')
arvore.raiz.esquerda.direita.esquerda = No('J')
arvore.raiz.esquerda.direita.direita = No('K')
arvore.raiz.direita.esquerda.esquerda = No('L')

# ==========================================
# PERCURSOS
# ==========================================
print("Percurso pré-ordem:")
arvore.pre_ordem(arvore.raiz)

print("\n\nPercurso em ordem:")
arvore.em_ordem(arvore.raiz)

print("\n\nPercurso pós-ordem:")
arvore.pos_ordem(arvore.raiz)
print()