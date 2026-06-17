# 🌄 Cenário Animado em OpenGL (C)

Projeto desenvolvido para a disciplina de Computação Gráfica, utilizando OpenGL (GLUT)em linguagem C.

O sistema simula um cenário 2D interativo com mudança de estado entre dia e noite, além de animações de personagens e elementos do ambiente.

## 🎯 Objetivo

Construir um cenário gráfico interativo com:

- Casa detalhada 🏠  
- Jardim com flores 🌷  
- Árvores 🌳  
- Duas pessoas animadas 🚶‍♂️🚶‍♀️  
- Alternância entre dia e noite 🌞🌙  
- Movimentação de nuvens e fumaça ☁️  
- Estrelas piscando ⭐  

## 🧠 Conceitos aplicados

- Primitivas gráficas do OpenGL (GL_LINES, GL_POLYGON, GL_POINTS)
- Transformações 2D
- Animação contínua com `glutIdleFunc`
- Interação via teclado
- Controle de estado (dia/noite)
- Funções modulares

## 🕹️ Controles

| Tecla | Função |
|------|--------|
|   T | Alterna entre dia e noite |
|   M | Ativa/desativa caminhada dos personagens |
|   R | Reinicia o cenário |

## 🚶 Funcionalidades
  
### 🌞 Dia
- Céu azul
- Sol com raios
- Nuvens em movimento
- Pessoas caminhando no jardim

### 🌙 Noite
- Céu escuro
- Lua crescente
- Estrelas piscando
- Janelas iluminadas

## 🏠 Elementos do cenário

### Casa
- Estrutura principal
- Telhado triangular
- Porta com maçaneta
- Janelas com divisórias
- Chaminé com fumaça

### Ambiente
- Jardim com flores coloridas
- Cerca branca
- Árvores com maçãs

## 🚶 Personagens

Os personagens foram desenvolvidos com:
- Cabeça (círculo)
- Cabelo
- Olhos
- Tronco (roupas diferentes)
- Braços e pernas articulados
- Animação de caminhada com seno (`sin()`)
