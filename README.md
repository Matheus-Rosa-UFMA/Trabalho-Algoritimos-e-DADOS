MÁQUINA VIRTUAL BASEADA EM PILHA

Integrantes:
- Millena Gomes Andrade de Menezes Braga
- Jeyce Kelly Cavalcante Costa Nogueira
- Matheus Victor Rocha Rosa
- Jônatas Almeida de Sousa
- Filipe de Araujo Rocha

INSTRUÇÕES DE COMPILAÇÃO E EXECUÇÃO – EXPLICADAS

1. ABRIR O VISUAL STUDIO CODE (VSCode)
Este é o ambiente de desenvolvimento (IDE) que você usará para visualizar, editar, compilar e executar o código da máquina virtual.


2. COMANDO DE COMPILAÇÃO:
gcc main.c interpret.c stack.c -o maquina-pilha

Explicação:
- gcc: É o compilador de C (GNU Compiler Collection).
- main.c interpret.c stack.c: Arquivos-fonte do projeto.
- -o maquina-pilha: Nome do arquivo executável gerado.

Resultado: Um arquivo chamado "maquina-pilha" será criado.

3. COMANDO DE EXECUÇÃO:
./maquina-pilha

Explicação:
- ./ indica que você quer rodar um programa no diretório atual.
- maquina-pilha é o nome do executável.


4. INSTRUÇÕES QUE O CÓDIGO PODE EXCECUTAR 

O código pode realizar operações com: 

soma (add) - Desempilha dois valores da pilha, soma, e empilha o resultado.
subtração (sub) - Desempilha dois valores, subtrai o segundo do primeiro, e empilha o resultado
divisão (div) - Desempilha dois valores, divide o primeiro pelo segundo (divisão inteira), e empilha o  
multiplicação(mul) - Desempilha dois valores, multiplica, e empilha o resultado. 
push  - Adiciona um valor à pilha.
print - Imprime o valor no topo da pilha.


5.  COMO UTILIZAR

Após iniciar a máquina virtual, você pode inserir comandos como:

push 10
push 20
add
print

Saída:
30
