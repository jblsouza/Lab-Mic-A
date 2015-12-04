### UFSCar - Universidade Federal de São Carlos
### Turma: Laboratório de Microcontroladores e Aplicações A
### Alunos: João Souza 414298 e Alexandre Rocha 321451


# Projeto Final

# Introdução

Esse projeto visa realizar o controle de um motor de passos através do uso de um sensor de ângulo de rotação(potenciometro) e para realizar o controle da ventoinha foi utilizado um sensor de temperatura.

# Desenvolvimento
## Fisico
### Equipamentos Utilizados
* 1 - Fonte DC 5V
* 1 - Arduino Mega 2560
* 1 - Grove - Temperature Sensor V1.2
* 1 - Grove - Rotary Angle Sensor
* 1 - CI ULN2003
* 1 - Ventoinha 12v 0.06A
* 1 - Base Shield v2
* 1 - Grove - LCD RGB Backlight
* 1 - Astrosyn: Miniangle Stepper

Inicialmente foi utilizado um arduino mega 2560 para realizar o processamento e obtenção dos dados para isso foi necessário acoplar o Base Shield v2 na plataforma primeiro, tanto os dados fornecidos pelos sensores quanto os dados utilizados nos atuadores são fornecidos por portas do arduino. 
### Conexões dos pinos referentes ao Arduino:
* Pino x: Variável ou objeto no Programa; Componente físico conectado
* Pino A0: pinSensorTemp; Grove - Temperature Sensor V1.2
* Pino A1: ROTARY_ANGLE_SENSOR; Grove - Rotary Angle Sensor
* Pino A6: pinCooler; Ventoinha 12v 0.6A
* Pino I2C: I2C Arress; Grove - LCD RGB Backlight
* Pinos 8 a 11: myStepper; CI ULN2003 (IN1 a IN4)
* Pino GND: Fonte DC 5V(Polo Negativo)

### Conexões dos pinos do CI ULN2003:
* Pino 1 a 4: IN1 a IN4
* Pino GND: Fonte DC 5V(negativa)
* Pino 16 a 13: OUT1 a OUT4; Miniangle Stepper COIL4 a COIL1
* Pino COM: Fonte DC 5V(Polo Positivo)

### Conexões dos fios do Miniangle Stepper:
* COIL4 a COIL1: OUT1 a OUT4; ULN2003
* COMMON: Fonte DC 5V(Polo Positivo)

Segue abaixo o esquemático representando o circuito implementado:
![](http://i.imgur.com/yawfk78.png)
http://schematics.com/project/trabalho-final-24477/

## Logico
O programa visa fazer o controle da velocidade da Ventoinha 12v 0.06A através de uma medida de temperatura realizada pelo Temperature Sensor V1.2, quanto maior a temperatura, maior será a potência de giro fornecida para a ventoinha, uma variável é mapeada de um valor de temperatura para o valor de potência a ser fornecido.
O limite de tensão fornecido para a ventoinha foi determinado em 5V, o qual é gerado por um analogWrite(potencia).
Em relação ao controle do motor, foi utilizado o Rotary Angle Sensor, quanto maior o ângulo obtido pelo sensor, mais rapidamente o motor irá girar, para isso foi necessário utilizar uma variável mapeada de um valor de angulação para um valor de RPM, o comportamento do motor se baseia em completar 1/2 revolução e depois alterar para o sentido o oposto e repetir o processo.
O limite de RPM fornecido ao motor foi limitado a 6RPM, isto implica que o motor executa 1/2 volta em 5 segundos no máximo e 30 segundos no mínimo.
O LCD RGB Backlight imprime em sua tela a seguinte mensagem - "Temperature: x" sendo x o valor da temperatura em graus celsius.
### Arquivos
* ProjetoFinalComRotary.ino:Projeto para arduino contendo o código principal para a execução do programa
* rgb_lcd.cpp / rgb_lcd.h: contém as funções e valores relacionados ao dispositivo LCD RGB Backlight
* rotary_angle_sensor.cpp / rotary_angle_sensor.h: contém as funções e valores relacionados ao dispositivo Grove - Rotary Angle Sensor.

Para a execução do programa basta copiar os arquivos deste diretório gitHub numa mesma pasta e abrir o projeto "projetoFinalComRotary.ino".

# Conclusão
É possível realizar um controle preciso de atuadores como o motor de passos e a ventoinha, através do processamento pelo arduino dos dados obtidos pelos sensores de temperatura e rotação, sendo que parte do processo pode ser manipulado mecanicamente com o controle sendo realizado pelo programa.

Segue abaixo o link para download do video mostrando o projeto em funcionamento
https://www.dropbox.com/s/t3sp2hnsswgg2fw/video_ProjetoFinal.mp4?dl=0