# Define os arquivos a serem excluídos para cada regra
EXCLUDE_FIB = codigo/pqDij.c codigo/PQ.c
EXCLUDE_PQ = codigo/fibDij.c codigo/fibHeap.c codigo/nodeFH.c

# Lista todos os arquivos .c dentro da pasta "codigo"
SRCS = $(wildcard codigo/*.c)

# Filtra os arquivos para cada regra
SRCS_FIB = $(filter-out $(EXCLUDE_FIB), $(SRCS))
SRCS_PQ = $(filter-out $(EXCLUDE_PQ), $(SRCS))

FLAGS = -Wall -Wextra

# Nome do executável
TARGET = trab1

# Regra para compilar "fib"
fib:
	@gcc $(FLAGS) $(SRCS_FIB) -lm -o $(TARGET)

# Regra para compilar "pq"
pq:
	@gcc $(FLAGS) $(SRCS_PQ) -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)
