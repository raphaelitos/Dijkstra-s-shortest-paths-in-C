# Defina os arquivos a serem excluídos para cada regra
EXCLUDE_FIB = pqDij.c
EXCLUDE_PQ = fibDij.c 

# Lista todos os arquivos .c no diretório atual
SRCS = $(wildcard *.c)

# Filtra os arquivos para cada regra
SRCS_FIB = $(filter-out $(EXCLUDE_FIB), $(SRCS))
SRCS_PQ = $(filter-out $(EXCLUDE_PQ), $(SRCS))

# Nomes dos executáveis
TARGET = trab1

# Regra para compilar "fib"
fib:
	gcc $(SRCS_FIB) -lm -o $(TARGET)

# Regra para compilar "pq"
pq:
	gcc $(SRCS_PQ) -lm -o $(TARGET)

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET)