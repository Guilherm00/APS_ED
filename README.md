📊 Análise Comparativa de Algoritmos de Ordenação em C

Este repositório contém uma implementação em linguagem C projetada para analisar e comparar o desempenho de três algoritmos clássicos de ordenação: Bubble Sort, Selection Sort e Quick Sort.

O objetivo principal é medir o tempo de execução (em milissegundos) de cada algoritmo em diferentes cenários de organização dos dados.

🚀 Funcionalidades

Implementação de Algoritmos:

🫧 Bubble Sort: Algoritmo simples de troca, complexidade $O(n^2)$.

🔍 Selection Sort: Algoritmo de seleção, complexidade $O(n^2)$.

⚡ Quick Sort: Algoritmo "dividir para conquistar", complexidade média $O(n \log n)$.

Cenários de Teste:

📈 Vetor Crescente: Simula o "melhor caso" para algoritmos adaptativos.

📉 Vetor Decrescente: Simula o "pior caso" (inversão total).

🎲 Vetor Aleatório: Simula o "caso médio".

Metodologia de Medição:

Utiliza a biblioteca <time.h> para aferição precisa.

Executa cada teste 10 vezes e calcula a média aritmética para mitigar flutuações do sistema operacional.

Restaura o vetor original antes de cada execução para garantir a integridade dos testes.

🛠️ Como Compilar e Rodar

Pré-requisitos

Você precisará de um compilador C, como o GCC.

Passos

Clone este repositório:

git clone [https://github.com/SEU-USUARIO/NOME-DO-REPO.git](https://github.com/SEU-USUARIO/NOME-DO-REPO.git)


Navegue até a pasta do projeto e compile o código:

gcc OrdenacaoAlgoritmos.c -o ordenacao


Execute o programa:

Windows: ordenacao.exe

Linux/Mac: ./ordenacao

📊 Exemplo de Saída

Ao executar o programa, você verá um relatório semelhante a este:

========================================
Ordenacao QuickSort: 
========================================
Media Vetor Crescente: 0.0040 ms
Media Vetor Decrescente: 0.0050 ms
Media Vetor Aleatorio: 0.0040 ms
-----------------------------------


📝 Estrutura do Código

main(): Função principal que orquestra a execução.

Ger(): Gera os vetores e chama as funções de teste.

run[Algoritmo](): Gerencia as 10 repetições, clonagem de vetores e cálculo da média de tempo.

clonaV(): Função auxiliar para restaurar o vetor de teste ao seu estado original.

💻 Autor

Desenvolvido por [Seu Nome] para a disciplina de Estrutura de Dados.

Este projeto foi desenvolvido para fins acadêmicos e de estudo sobre complexidade de algoritmos.
