#include <stdio.h>
#include "pico/stdlib.h"

#define red_pin 11
#define yellow_pin 12
#define green_pin 13

int cont = 0;

//  Função que inicializa os pinos 
void incicializar_pinos(){
    gpio_init(red_pin);
    gpio_set_dir(red_pin, GPIO_OUT);

    gpio_init(yellow_pin);
    gpio_set_dir(yellow_pin, GPIO_OUT);

    gpio_init(green_pin);
    gpio_set_dir(green_pin, GPIO_OUT);
}

// Função que liga a luz vermelha 
void luz_vermelha(){
    gpio_put(red_pin, 1);
    gpio_put(yellow_pin, 0);
    gpio_put(green_pin, 0);
}

// Função que liga a luz amarela 
void luz_amarela(){
    gpio_put(red_pin, 0);
    gpio_put(green_pin, 0);
    gpio_put(yellow_pin, 1);
}

// Função que liga a luz verde
void luz_verde(){
    gpio_put(red_pin, 0);
    gpio_put(green_pin, 1);
    gpio_put(yellow_pin, 0);
}

// Função de callback do temporizador 
bool repeating_timer_callback(struct repeating_timer *t){
    switch(cont){
        case 0: 
            luz_vermelha();
            break;
        case 1:
            luz_amarela();
            break;
        case 2:
            luz_verde();
            break;
    }
    
    cont++; // Avança para para a próxima cor 

    if(cont > 2){
        cont = 0;
    }
    return true; // Retorna true para continuar o temporizador 
}   

int main()
{
    stdio_init_all();
    incicializar_pinos();

    // Declara a variável do temporizador
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    // Chama o callback manualmente para iniciar imediatamente
    repeating_timer_callback(NULL);

    while (true) {
        
        printf("Tempo decorrido: 1 segundo\n");
        sleep_ms(1000); // Espera 1 segundo
        
    }
}
