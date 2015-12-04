### UFSCar - Universidade Federal de S�o Carlos
### Turma: Laborat�rio de Microcontroladores e Aplica��es A
### Alunos: Jo�o Souza 414298 e Alexandre Rocha 321451


# Projeto Final

# Introdu��o

Esse projeto visa realizar o controle de um motor de passos atrav�s do uso de um sensor de �ngulo de rota��o(potenciometro) e para realizar o controle da ventoinha foi utilizado um sensor de temperatura.

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

Inicialmente foi utilizado um arduino mega 2560 para realizar o processamento e obten��o dos dados para isso foi necess�rio acoplar o Base Shield v2 na plataforma primeiro, tanto os dados fornecidos pelos sensores quanto os dados utilizados nos atuadores s�o fornecidos por portas do arduino. 
### Conex�es dos pinos referentes ao Arduino:
* Pino x: Vari�vel ou objeto no Programa; Componente f�sico conectado
* Pino A0: pinSensorTemp; Grove - Temperature Sensor V1.2
* Pino A1: ROTARY_ANGLE_SENSOR; Grove - Rotary Angle Sensor
* Pino A6: pinCooler; Ventoinha 12v 0.6A
* Pino I2C: I2C Arress; Grove - LCD RGB Backlight
* Pinos 8 a 11: myStepper; CI ULN2003 (IN1 a IN4)
* Pino GND: Fonte DC 5V(Polo Negativo)

### Conex�es dos pinos do CI ULN2003:
* Pino 1 a 4: IN1 a IN4
* Pino GND: Fonte DC 5V(negativa)
* Pino 16 a 13: OUT1 a OUT4; Miniangle Stepper COIL4 a COIL1
* Pino COM: Fonte DC 5V(Polo Positivo)

### Conex�es dos fios do Miniangle Stepper:
* COIL4 a COIL1: OUT1 a OUT4; ULN2003
* COMMON: Fonte DC 5V(Polo Positivo)

Segue abaixo o esquem�tico representando o circuito implementado:
![](http://i.imgur.com/yawfk78.png)
http://schematics.com/project/trabalho-final-24477/

## Logico
O programa visa fazer o controle da velocidade da Ventoinha 12v 0.06A atrav�s de uma medida de temperatura realizada pelo Temperature Sensor V1.2, quanto maior a temperatura, maior ser� a pot�ncia de giro fornecida para a ventoinha, uma vari�vel � mapeada de um valor de temperatura para o valor de pot�ncia a ser fornecido.
O limite de tens�o fornecido para a ventoinha foi determinado em 5V, o qual � gerado por um analogWrite(potencia).
Em rela��o ao controle do motor, foi utilizado o Rotary Angle Sensor, quanto maior o �ngulo obtido pelo sensor, mais rapidamente o motor ir� girar, para isso foi necess�rio utilizar uma vari�vel mapeada de um valor de angula��o para um valor de RPM, o comportamento do motor se baseia em completar 1/2 revolu��o e depois alterar para o sentido o oposto e repetir o processo.
O limite de RPM fornecido ao motor foi limitado a 6RPM, isto implica que o motor executa 1/2 volta em 5 segundos no m�ximo e 30 segundos no m�nimo.
O LCD RGB Backlight imprime em sua tela a seguinte mensagem - "Temperature: x" sendo x o valor da temperatura em graus celsius.
### Arquivos
* ProjetoFinalComRotary.ino:Projeto para arduino contendo o c�digo principal para a execu��o do programa
* rgb_lcd.cpp / rgb_lcd.h: cont�m as fun��es e valores relacionados ao dispositivo LCD RGB Backlight
* rotary_angle_sensor.cpp / rotary_angle_sensor.h: cont�m as fun��es e valores relacionados ao dispositivo Grove - Rotary Angle Sensor.

Para a execu��o do programa basta copiar os arquivos deste diret�rio gitHub numa mesma pasta e abrir o projeto "projetoFinalComRotary.ino".

# Conclus�o
� poss�vel realizar um controle preciso de atuadores como o motor de passos e a ventoinha, atrav�s do processamento pelo arduino dos dados obtidos pelos sensores de temperatura e rota��o, sendo que parte do processo pode ser manipulado mecanicamente com o controle sendo realizado pelo programa.

Segue abaixo o link para download do video mostrando o projeto em funcionamento
https://www.dropbox.com/s/t3sp2hnsswgg2fw/video_ProjetoFinal.mp4?dl=0