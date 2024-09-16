# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
EXEC = programa

# Lista de arquivos-fonte
SRC = funcionalidades.c dinamic.c

# Regra padrão (default) para compilar e gerar o executável
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Regra para limpar os arquivos gerados pela compilação
clean:
	rm -f $(EXEC) output.txt

# Regra para executar o programa
run: $(EXEC)
	./$(EXEC)