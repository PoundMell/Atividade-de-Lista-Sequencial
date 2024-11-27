# Atividade-de-Lista-Sequencial
Este repositório contém a implementação de uma lista sequencial ordenada em C. As modificações feitas no código original incluem ajustes em funções de inserção, exclusão e busca, além de correções no comportamento de inserção sem duplicação e melhorias em algumas lógicas de busca.

# Mudanças Realizadas
1. Inserção Sem Duplicação (inserirElemListaOrdSemDup):

   - Antes: O código original não impedia a inserção de elementos duplicados, mesmo quando solicitado para não permitir duplicação.
   - Depois: Foi corrigido para garantir que, ao tentar inserir um elemento duplicado, a função inserirElemListaOrdSemDup agora retorna false e não insere o elemento. A busca binária foi adicionada para verificar se o elemento já existe na lista antes de proceder com a inserção.

2. Inserção com Duplicação (inserirElemListaOrd):

   - Antes: O código original inseria elementos de forma ordenada, mas não considerava casos em que os elementos já estavam ordenados ao fazer as inserções.
   - Depois: A lógica de inserção foi ajustada para garantir que os elementos são corretamente deslocados e inseridos na posição certa, mantendo a lista ordenada. A inserção agora lida adequadamente com a ordenação ao inserir um novo elemento.

3. Funções de Busca:

   - Antes: As funções de busca sequencial e binária estavam implementadas, mas algumas lógicas não estavam otimizadas para listas ordenadas.
   - Depois: Foi otimizada a função de busca com sentinela (buscaSentinelaOrdenada), para garantir que a busca seja realizada de forma eficiente em listas ordenadas. A função de busca binária também foi revisada e permanece adequada para buscar elementos de forma eficiente em listas ordenadas.

4. Exclusão de Elementos:

   - Antes: A exclusão de elementos estava implementada, mas de forma simples e sem otimizações específicas para listas ordenadas.
   - Depois: A função de exclusão excluirElemListaOrd foi ajustada para usar busca binária, o que melhora a eficiência ao excluir elementos em listas ordenadas.
5. Correções Gerais:

   - Pequenos ajustes foram feitos para corrigir o comportamento da lista em algumas operações, garantindo que o número de elementos (nroElem) seja atualizado corretamente após inserções e exclusões.
   - A função reinicializarLista foi mantida, mas reforçada para garantir que todos os elementos da lista sejam apagados corretamente.
