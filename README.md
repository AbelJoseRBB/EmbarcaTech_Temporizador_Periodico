# Temporizador_Periodico
Tarefa do EmbarcaTech destinada a implementar um semáforo com delay de 3 segundos com a utilização da função add_repeating_timer_ms();

# Intruções
Para executar o código em questão, deve-se possuir a extensão Wokwi Simulator instalada no Visual Studio Code. 

Acesse o arquivo diagram.json, com a extensão Wokwi Simulator instalada, para gerar o ambiente de simulação de uma placa RaspBerry Pi Pico W composto de 3 leds (vermelho, verde e amarelo), ligados a 3 resitores com 330Ω.

Ao iniciado, começará imediatamente um loop de um semáforo, iniciando pela cor vermelha, após 3 segundos alternando a cor, primeiramente para amarelo e em seguida para verde. Por fim o loop é repetido até que se interrompa o programa.

# Composição do código
**Temporizador_Periodico.c**
- `inicializar_pinos()`: Prepara os pinos dos botões e do LED para uso.
- `luz_vermelha()`: Ativa o led vermelho. 
- `luz_amarela()`: Ativa o led amarelo. 
- `luz_verde()`: Ativa o led verde.
- `repeating_timer_callback(struct repeating_timer *t)`: Função de callback do temporizador. 
- `main`: Lógica que configura e inicia o programa.

# Desenvolvedor
Abel José Rocha Barros Bezerra
