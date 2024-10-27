# README - Produtor-Consumidor em C

## Descrição

Este projeto implementa o problema clássico do produtor-consumidor utilizando threads em C. O código utiliza mutexes para garantir que o acesso ao buffer compartilhado seja seguro entre as threads produtoras e consumidoras.

## Dependências

- **Sistema Operacional**: O código foi testado em ambientes Linux e Windows. 
- **Compilador C**: Certifique-se de ter um compilador C instalado, como `gcc`.

## Estrutura do Código

1. **Inclusões de Bibliotecas**:
   - O código inclui diferentes bibliotecas dependendo do sistema operacional.
     - Para Linux: `<sys/syscall.h>`
     - Para Windows: `<stdio.h>`, `<sys/types.h>`, `<pthread.h>`, `<unistd.h>`

2. **Definições**:
   - `N`: Tamanho do buffer.
   - `buffer[5]`: Buffer compartilhado para armazenar os dados.
   - `count`: Contador para rastrear o número de itens no buffer.
   - `pthread_mutex_t mt`: Mutex para controlar o acesso ao buffer.

3. **Funções**:
   - `void *produtor()`: Função que simula a produção de itens, adicionando 10 itens ao buffer.
   - `void *consumidor()`: Função que simula o consumo de itens, removendo 10 itens do buffer.

4. **Função `main()`**:
   - Cria duas threads, uma para o produtor e outra para o consumidor.
   - Aguarda a conclusão das duas threads usando `pthread_join`.

## Como Compilar e Executar

### Em um Ambiente Linux

1. Abra um terminal.
2. Navegue até o diretório onde o código está localizado.
3. Compile o código com o seguinte comando:

   ```bash
   gcc -o produtor_consumidor produtor_consumidor.c -lpthread
   ```

4. Execute o programa:

   ```bash
   ./produtor_consumidor
   ```

### Em um Ambiente Windows

1. Abra o terminal (Prompt de Comando ou PowerShell).
2. Navegue até o diretório onde o código está localizado.
3. Compile o código usando um compilador como o `gcc` do MinGW:

   ```bash
   gcc -o produtor_consumidor produtor_consumidor.c -lpthread
   ```

4. Execute o programa:

   ```bash
   produtor_consumidor.exe
   ```

## Considerações Finais

- O código atualmente implementa uma lógica básica de espera ocupada (busy waiting) para verificar se o buffer está cheio ou vazio. Para produção real, considere a implementação de semáforos ou condições de variável para otimizar o desempenho e evitar uso excessivo da CPU.
- Certifique-se de que o número de itens produzidos e consumidos esteja balanceado para evitar deadlocks.
