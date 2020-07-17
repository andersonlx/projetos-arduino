# Conectando o ESP8266 com o Arduino

Enviando Comandos AT
Com o monitor aberto e configurado corretamente, envie o comando AT. 
O módulo ESP8266 deve retornar um OK.

Após receber OK como resposta, utilize o comando AT+CWMODE=1 para configurar o módulo para o modo "estação".

Após a configuração do módulo, é possível enviar o comando AT+CWLAP para que o módulo retorne todas as redes Wi-Fi em seu alcance.

Após observar as redes Wi-Fi em alcance do módulo ESP8266, envie o comando AT+CWJAP="sua-rede-wi-fi","senha-da-sua-rede-wi-fi" para que o módulo se conecte à sua rede Wi-Fi. Assim como todos os comandos AT, a resposta por parte do módulo é um OK.

Agora que o módulo está conectado à sua rede Wi-Fi, é possível obter o endereço de IP do módulo com o comando AT+CIFSR.

Com estes comandos é possível testar a funcionalidade do módulo ESP8266, assim como alguns de seus recursos.

* Configure o monitor para a opção "Ambos NL & RC" ("Both NL & RC") e altere a velocidade de comunicação para 9600 bps.
