# Data structure assignments

Algumas aplicações de estruturas de dados utilizadas nas disciplinas de algoritmo e estrutura de dados I/II

### Uma breve descrição de cada estrutura:

* **Pilha:** todas as inserções, remoções e geralmente todos os acessos são realizados em uma única extremidade, denominada topo;

* **Fila:**  todas as remoções e, em geral, os acessos são realizados em uma ponta (frente), e todas as inserções são feitas em outra ponta (traseira);

* **Listas:** uma lista linear é uma estrutura de dados na qual elementos de um mesmo tipo de dados são organizados logicamente de forma sequencial:

  * **Lista encadeada:** as listas são unidirecionais, ou seja, começam de um ponto, do início, e vai até o fim;
  
  * **Lista circular duplamente encadeada:** cada célula contém o endereço da célula anterior e o endereço da célula seguinte.


* **Grafo:** um conjunto de nós que possuem dados e estão conectados a outros nós:
  * **Matriz de adjacência :** uma matriz 2D de tamanho V x V onde V é o número de vértices em um gráfico;
  
  
* **Árvore:** é uma estrutura de dados que organiza seus elementos de forma hierárquica, onde existe um elemento que fica no topo, chamado de raiz e existem os elementos subordinados a ele, que são chamados de nós filhos. Cada nó filho pode conter zero, um ou mais de um nós filhos. Os nós filhos que não contém outros nós filhos são chamados de nós folha;

### Algoritmos de ordenação:
Basicamente, um algoritmo de ordenação coloca um array em ordem, isto é, ordena o vetor

* **Bubble sort:** esse algoritmo realiza comparações de pares, ou seja, repete esse processo até que todo o vetor seja ordenado. Então, funciona bem para arrays pequenos, mas tem uma complexidade muito alta, ou seja, muito custo computacional;
  * **Complexidade:** O(n²);

* **Insertion sort:** os elementos do array são comparados uns com os outros sequencialmente e, em seguida, organizados simultaneamente em alguma ordem particular;
  * **Complexidade:** O(n²);

* **Mergesort:**  divide o array em grupos e ordena recursivamente cada um deles, por fim realiza o merge e dá origem a um único array final (ordenado);
  * **Complexidade:** O(n log n);

* **Quicksort:** assim como o MERGESORT, o quicksort é um algoritmo de divisão e conquista. Ele seleciona um elemento como pivô e particiona o array fornecido ao redor do pivô selecionado;
  * **Complexidade:** O(n²);

* **Heapsort:** é um algoritmo de ordenação que se resume em comparação, com base na estrutura de dados Binary Heap. É semelhante ao SELECTIONSORT, onde primeiro encontramos o elemento mínimo e o colocamos no início. Repetimos o mesmo processo para os elementos restantes;
  * **Complexidade:** O(n log n);

* **Árvore binária de busca:** árvore binária baseada em nós, onde todos os nós da subárvore esquerda possuem um valor numérico inferior ao nó raiz e todos os nós da subárvore direita possuem um valor superior ao nó raiz;
  * **Complexidade:** O(n);

* **Árvore AVL:** uma árvore de busca binária de autobalanceada, em que a diferença entre as alturas das subárvores esquerda e direita não pode ser mais de um para todos os nós;
  * **Complexidade:** O(n);

* **Árvore rubro-negra:** um tipo de árvore binária de busca (autobalanceada), de modo que cada nó tem um bit extra, e esse bit é frequentemente interpretado como a cor (vermelho ou preto). Essas cores são usadas para garantir que a árvore permaneça equilibrada durante as inserções e exclusões;
  * **Complexidade:** O(log n);

* **Hash table:** também conhecida como tabela de dispersão ou tabela de espalhamento, é uma estrutura de dados especial, que associa chaves e valores. Seu objetivo é a partir de uma chave simples, fazer uma busca rápida e obter o valor desejado. A Tabela Hash leva em conta o valor absoluto de cada chave, interpretado como um valor numérico e através da aplicação de uma função
conveniente, a chave é transformada em um endereço de uma tabela;
  * **Complexidade:** O(n);


