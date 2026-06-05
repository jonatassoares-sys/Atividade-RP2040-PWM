#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

// Definição dos pinos baseados na configuração padrão
#define JOYSTICK_X_PIN 26 // Pino do ADC (Canal 0) conectado ao eixo do Joystick
#define SERVO_PIN 15      // Pino PWM conectado ao sinal do Servomotor

// Função para inicializar e configurar o módulo PWM para o Servomotor
void setup_pwm() {
    // Configura o pino para a função de PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    
    // Obtém o "slice" (canal) de PWM associado ao pino escolhido
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

    // Servomotores padrão operam a uma frequência de 50Hz (período de 20ms).
    // O clock base do RP2040 é de 125MHz.
    // Usando um divisor de 125, o clock do PWM passa a ser de 1MHz (1 tick = 1 microssegundo).
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.0f);
    
    // Define o valor de "wrap" para 20000 ticks, o que equivale a 20.000 microssegundos (20ms)
    pwm_config_set_wrap(&config, 20000); 

    // Inicializa o PWM com as configurações
    pwm_init(slice_num, &config, true);
}

int main() {
    // Inicializa a comunicação padrão (para debug via serial, se necessário)
    stdio_init_all();

    // Configuração do ADC
    adc_init();
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_select_input(0); // Seleciona a entrada do ADC correspondente ao GPIO 26

    // Inicializa o PWM no pino do servo
    setup_pwm();

    while (true) {
        // Realiza a leitura analógica do eixo do joystick (retorna um valor entre 0 e 4095)
        uint16_t adc_value = adc_read();

        // Mapeamento de valores:
        // O pulso PWM para um servo varia normalmente entre 500us (0 graus) e 2500us (180 graus).
        // Precisamos converter a escala do ADC (0 a 4095) para a escala de tempo (500 a 2500).
        // 2500 - 500 = 2000 (amplitude da variação).
        uint32_t pulse_width = 500 + (adc_value * 2000 / 4095);

        // Ajusta o nível do pino PWM, definindo a largura do pulso em microssegundos
        pwm_set_gpio_level(SERVO_PIN, pulse_width);

        // Atraso curto para estabilidade da leitura e do simulador
        sleep_ms(50);
    }
    
    return 0;
}