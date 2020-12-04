/*


 Autor: Luiz Guilherme M S Ito
 Projeto: PWM Duplo com alta precisão
 utilizando a ferramenta do MicroC


*/


#define butt1 RB1_bit
#define butt2 RB2_bit
#define butt3 RB3_bit
#define butt4 RB4_bit


unsigned short duty1, duty2;

void main()
{
     CMCON = 0x07;              //Desabilitar os comparadores do PIC
     TRISB = 0xFF;              //Todo PORTB será entrada
     TRISC = 0x00;              //Todo PORTC como saída
     PORTB = 0xFF;              //PORTB inicia em high
     PORTC = 0x00;              //PORTC inicia em low

     PWM1_Init(20000);                         // Escolha da Frequência do PWM1 em Hz (20kHz)
     PWM2_Init(20000);                        // Escolha da Frequência do PWM2 em Hz (20kHz)

     duty1 = 127;
     duty2 = 127;

     PWM1_Start();
     PWM2_Start();

     PWM1_Set_Duty(duty1);
     PWM2_Set_Duty(duty2);

     while(1)
     {
         if(!butt1)
         {
            delay_ms(40);
            duty1++;
            PWM1_Set_Duty(duty1);
         }

         if(!butt2)
         {
            delay_ms(40);
            duty1--;
            PWM1_Set_Duty(duty1);
         }

         if(!butt3)
         {
            delay_ms(40);
            duty2++;
            PWM2_Set_Duty(duty2);
         }

         if(!butt4)
         {
            delay_ms(40);
            duty2--;
            PWM2_Set_Duty(duty2);
         }


     } //end while

}