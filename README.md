# Relatório de Resultados



## Introdução
Este relatório apresenta uma análise comparativa do desempenho do algoritmo de **Dijkstra** utilizando duas estruturas de dados diferentes:

- **Heap Binária e Fila de Prioridades Comum** 
- **Heap de Fibonacci**

A avaliação considera o tempo de execução e o uso de memória para diferentes tamanhos de grafos.
Não houveram casos de falha na execução, de modo que todos as instâncias de teste foram contempladas no presente relatório



## Por que Heap Fibonacci?
A escolha da **Heap de Fibonacci** para o algoritmo de Dijkstra pode trazer algumas vantagens e desvantagens em relação à Heap Binária. Seu maior benefício é a operação **decrease-key** em tempo **O(1)**, enquanto na Heap Binária essa operação ocorre em **O(log V)**.  Além disso, a inserção na Heap de Fibonacci também ocorre em **O(1)**, tornando-a útil em situações onde novos nós são adicionados dinamicamente. No entanto, a **extração do mínimo** na Heap de Fibonacci ainda ocorre em **O(log V)** e pode ter um overhead maior devido à necessidade de reorganizar múltiplas árvores. Além disso, sua implementação é significativamente mais complexa e requer mais memória devido ao uso de ponteiros extras e estruturas encadeadas.

Levando esses pontos em consideração, o grupo resolveu implementar a Heap Fibonacci para ganhar familiaridade com essa estrutura e ver como ela iria performar em comparação com a Fila de Prioridades.

## Metodologia
Foram testadas todos os casos de teste do problema oferecidos pelo professor, que doravante serão chamadas:

- **mp1, mp2** → Instâncias muito pequenas
- **p1, p2** → Instâncias pequenas
- **p3, p4** → Instâncias médias
- **m1, m2, m3** → Instâncias  grandes

Todos os casos acima foram executados em ambas as implementações e medidas de tempo e memória foram coletadas, usando as ferramentas `valgrind` e a função `clock` da biblioteca `time.h`
## Entrada e Saída
O programa aceita arquivos de entrada no formato `.txt`, de forma que a primeira linha contenha o nome do vértice fonte e as demais contenham os nomes dos vértices e os pesos de suas arestas, como no exemplo:

```
node_0
node_0, 10, 0, 5, 0
node_1, 0, 1, 2, 0
node_2, 0, 0, 0, 4
node_3, 0, 3, 3, 0
node_4, 7, 0, 6, 0
```
Após a execução, o programa escreverá os resultados no arquivo de saída da seguinte forma, no caso do exemplo anterior:

```
SHORTEST PATH TO node_0: node_0 <- node_0 (Distance: 0.00)
SHORTEST PATH TO node_3: node_3 <- node_0 (Distance: 5.00)
SHORTEST PATH TO node_1: node_1 <- node_3 <- node_0 (Distance: 8.00)
SHORTEST PATH TO node_2: node_2 <- node_3 <- node_0 (Distance: 8.00)
SHORTEST PATH TO node_4: node_4 <- node_2 <- node_3 <- node_0 (Distance: 12.00)
```


## Executando
Para executar o programa, basta compilar o código fonte e fornecer os arquivos de entrada e saída. Por exemplo, suponha que tenha mantido o nome como `casos_teste_v3`,
e queira executar o `caso_teste_muito_pequeno_1` basta compilar a implementação desejada do algoritmo com os comandos:

### Implementação Heap Fibonnaci
```
make fib
./trab1 path/to/input/file path/to/output/file
```
### Implementação Fila de Prioridade
```
make pq
./trab1 path/to/input/file path/to/output/file
```

Caso o arquivo de saída não exista, ele será criado automaticamente

## Resultados

### **Tempo de Execução**

| Instância | Heap Binária (s) | Heap de Fibonacci (s) |
|-----------|-----------------|----------------------|
| mp1       | 0.000132        | 0.000052            |
| mp2       | 0.000112        | 0.000064            |
| p1        | 0.002108        | 0.002127            |
| p2        | 0.002393        | 0.002238            |
| p3        | 0.191006        | 0.221300            |
| p4        | 0.190916        | 0.217498            |
| m1        | 5.197069        | 5.354844            |
| m2        | 5.216550        | 5.371506            |
| m3        | 5.184763        | 5.367246            |

**Observações:**
- Para **instâncias pequenas e médias**, a Heap de Fibonacci foi **ligeiramente mais rápida**.
- Para **instâncias grandes**, a Heap Binária teve **melhor desempenho**.
- Para **instâncias muito grandes**, ambas tiveram **tempos semelhantes**, com uma leve vantagem para a Heap Binária.

### **Uso de Memória**

| Instância | Heap Binária (bytes) | Heap de Fibonacci (bytes) |
|-----------|---------------------|--------------------------|
| mp1       | 1,968               | 7,064                    |
| mp2       | 1,968               | 8,688                    |
| p1        | 321,512             | 342,304                  |
| p2        | 323,688             | 344,608                  |
| p3        | 30,576,648          | 30,871,072               |
| p4        | 30,589,384          | 30,882,776               |
| m1        | 762,220,296         | 763,777,624              |
| m2        | 762,262,344         | 763,828,072              |
| m3        | 762,253,704         | 763,826,224              |

**Observações:**
- A Heap de Fibonacci sempre utilizou **mais memória** do que a Heap Binária, o que era esperado, visto que mantém múltiplas listas encadeadas de árvores.
- Para instâncias pequenas, o overhead da Heap de Fibonacci foi **significativo**.
- Para instâncias médias e grandes, o **uso de memória** da Heap Fibonacci e da Fila de Prioridade foi **semelhante**
- Para instâncias muito grandes, a diferença de consumo de memória foi da ordem de **1 MB a mais** para a Heap de Fibonacci.

## Conclusão
1. **Heap de Fibonacci não trouxe um ganho expressivo no tempo de execução**, mesmo para instâncias grandes.
2. **Heap de Fibonacci usou mais memória em todos os casos**, devido à sua estrutura mais complexa.
3. **Para instâncias pequenas e médias, as diferenças de desempenho foram mínimas**, tornando a Heap Binária mais atrativa devido à sua simplicidade.
4. **Para instâncias muito grandes, a Heap Binária teve leve vantagem em tempo e consumo de memória**, tornando-a a melhor escolha na maioria dos cenários práticos.
   
## Tratamento de E/S:
Nos arquivos de entrada, há algumas entradas com literalmente a string `lixo`. A solução foi: ao encontrar essas entradas,  apenas pular para a próxima, até que uma entrada válida fosse encontrada
## Referências
- Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
- Dijkstra, E. W. (1959). "A Note on Two Problems in Connexion with Graphs." Numerische Mathematik, 1(1), 269-271.
- https://github.com/msambol/dsa/blob/master/data_structures/fibonacci_heap.py
- https://youtube.com/playlist?list=PL9xmBV_5YoZNkwWDXcSiZjMgacw2P0U2j&si=5lT-zEfmAxtOy12L

