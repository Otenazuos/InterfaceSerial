#include <mbed.h>

// O código deve incrementar a instensidade em 5% cada vez que receber o caractere '+'
// decrementar em 5% cada vez que receber o caractere '-'
// O LED deve ser ajustado na intensidade máxima quando o caractere '*' for recebido
// O LED deve ser desligado quando '/' for recebido
// A intensidade atual deve ser impressa após cada ajuste realizado
// Se qualquer caractere diferente do aguardado for recebido, uma mensagem de erro deve ser impressa

PwmOut _led(LED1);

volatile char c = '\0'; // Inicia com caractere nulo
Serial pc(USBTX, USBRX, 9600);
float IntensLed;

void CharReceived(){
  c = pc.getc();
}

int main() {
  pc.attach(&CharReceived);

  while(1) {

    if (c != '\0'){

      switch(c){

        case '+':
        if (IntensLed >= 1.0f)
          IntensLed = 1.0f;
        else
          IntensLed += 0.05;
        break;

        case '-':
        if (IntensLed <= 0.0f)
          IntensLed = 0.0f;
        else
          IntensLed -= 0.05;
        break;

        case '*':
        IntensLed = 1.0f;
        break;

        case '/':
        IntensLed = 0.0f;
        break;

        default:
        pc.printf("Erro, caractere inválido!\n");
        break;
      }
_led.write (IntensLed);
pc.printf("Intendidade LED: %f \n", IntensLed);

wait_ms(100);

    }  
  }
}