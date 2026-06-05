# RP2040 — Controle de Ângulo de Servomotor via Joystick Analógico (PWM)

## Objetivo
Criação de um sistema de controle de hardware interativo para o posicionamento angular de um micro servomotor padrão utilizando o microcontrolador Raspberry Pi Pico W. O projeto foca na leitura de variações analógicas por meio de um joystick integrado à placa BitDogLab e na geração correspondente de sinais de Modulação por Largura de Pulso (PWM) dentro do ambiente de simulação Wokwi.

## Descrição do Funcionamento
O sistema opera através do mapeamento em tempo real entre o periférico de entrada analógica e o atuador de saída mecânica:

* **Leitura do Joystick (Módulo ADC):** O eixo analógico do joystick é monitorado pelo Conversor Analógico-Digital do RP2040, que traduz a variação de tensão física (0V a 3.3V) em dados digitais de 12 bits, variando de 0 a 4095 de forma linear.
* **Controle do Servo (Módulo PWM):** Os dados processados do ADC são convertidos matematicamente para ajustar o *Duty Cycle* (ciclo de trabalho) de um sinal PWM configurado na frequência estrita de 50 Hz (período de 20ms). O sinal é enviado ao servomotor para definir sua posição angular de forma proporcional:
  * **Posição 0°:** Pulso de comando ajustado entre 0.5ms e 1.0ms.
  * **Posição 90°:** Pulso de comando centralizado em 1.5ms.
  * **Posição 180°:** Pulso de comando máximo ajustado entre 2.0ms e 2.5ms.

## Especificações Técnicas
* **Microcontrolador:** Raspberry Pi Pico W (RP2040)
* **Placa de Desenvolvimento:** BitDogLAB
* **Atuador:** Servomotor Micro Servo Padrão (Simulado via Wokwi)
* **Periféricos Utilizados:** Módulo PWM (Controle) e Módulo ADC (Leitura)
* **Linguagem:** C
* **Ambiente:** VS Code + Pico SDK + simulador Wokwi integrado
* **Código Modular:** Estruturado com funções dedicadas de inicialização de hardware, leitura de canais ADC e atualização dos registradores de PWM.

## Como Executar
1. Clone este repositório:

## Organização da Equipe

* **Líder de Projeto:** [JÔNATAS DE SOUSA SOARES DA CRUZ] — Responsável pelo gerenciamento e estruturação do repositório GitHub, revisão dos commits, configuração do ambiente integrado VS Code/Wokwi e desenvolvimento do algoritmo principal de controle de PWM para o servomotor.
* **Desenvolvedor 1:** [NATAN ÉDER VALERIANO] — Responsável pela implementação da rotina de leitura do Conversor Analógico-Digital (ADC) para o joystick, calibração matemática das faixas de pulso síncronas de 50 Hz e testes de validação dos ângulos do motor.


## Demonstração em Vídeo

Conforme os requisitos estabelecidos nas orientações da atividade, foi produzido um vídeo ensaio com duração máxima de 5 minutos. O material audiovisual aborda de forma detalhada a arquitetura do código fonte desenvolvido em C, a validação dos cálculos matemáticos aplicados ao ciclo de trabalho do PWM para atingir a frequência de 50 Hz, e a comprovação prática dos testes de movimentação do servomotor através do joystick.

Assista à apresentação completa e demonstração das funcionalidades através do link abaixo:
▶️ **[Link para a Demonstração em Vídeo](https://canva.link/wivtvbhu1tjjlqn)**

---

## Conclusão

O projeto de controle de hardware foi finalizado com pleno êxito, alcançando a consolidação prática dos objetivos pedagógicos propostos. A integração harmônica entre o periférico de entrada analógica (ADC) e o atuador de saída mecânica (PWM) demonstrou a versatilidade e a robustez do microcontrolador RP2040 quando gerenciado através do Pico SDK. 

Os testes básicos executados em ambiente computacional comprovaram a estabilidade e a precisão do sinal de controle síncrono, garantindo respostas angulares imediatas e lineares no servomotor a partir dos comandos do joystick. Por fim, todo o ciclo de desenvolvimento, arquitetura do software e histórico de versionamento foram devidamente documentados e registrados nesta plataforma de controle.

---

## Licença

Este projeto é protegido e destinado **exclusivamente para fins acadêmicos e pedagógicos**, servindo como ferramenta de avaliação na disciplina **ELET0021 — Microcontroladores e Microprocessadores** (Semestre Letivo 2026.1) do Colegiado Acadêmico de Engenharia Elétrica da Universidade Federal do Vale do São Francisco (UNIVASF), sob a orientação e coordenação do Prof. Dr. Ricardo Menezes Prates.


```bash
   git clone [https://github.com/jonatassoares-sys/Atividade-RP2040-PWM.git](https://github.com/jonatassoares-sys/Atividade-RP2040-PWM.git)
