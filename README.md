# InterfaceSerial

Utilizando o framework MBED, codifique um firmware que implemente um Dimmer PWM,
para ajuste da intensidade de um LED, que seja controlado via interface serial padrão da placa escolhida.
O código deve incrementar a instensidade em 5% cada vez que receber o caractere '+' e decrementar em 5% cada vez que receber o caractere '-'.
O LED deve ser ajustado na intensidade máxima quando o caractere '*' for recebido. Do mesmo modo, O LED deve ser desligado quando '/' for recebido.
A intensidade atual deve ser impressa após cada ajuste realizado. Se qualquer caractere diferente do aguardado for recebido, um mensagem de erro deve ser impressa.

Sugestão: considere criar o projeto com o PlatformIO no VScode e utilize a placa BluePill.
