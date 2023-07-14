#define MOTOR_PIN_PWM 9   //пин к которому подключен транзистор управляющий двигателем
void setup()   
 { 
  pinMode(MOTOR_PIN_PWM,OUTPUT);
  pinMode(13,1);
  //Увеличиваем частоту ШИМ для меньшего нагрева двигателя и транзистора
  // Пины D3 и D11 - 31.4 кГц
  TCCR2B = 0b00000001;  // x1
  TCCR2A = 0b00000001;  // phase correct
  // Пины D9 и D10 - 62.5 кГц
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00001001;  // x1 fast pwm
 } 

void loop() {
  int poten = analogRead(0);    //читаем потенциометр на А0
  poten = map(poten,0,1023,110,200);    //переделываем показания потенциометра в нужный диапазон в мс
  for (int i = 5; i < 255; i+=25) {     //плавный пуск двигателя
        analogWrite(MOTOR_PIN_PWM, i);
        digitalWrite(13,i);
        delay(5);
        }
   analogWrite(MOTOR_PIN_PWM, 255);    //полностью включаем двигатель
   digitalWrite(13,255);              //мигаем диодом
   delay(poten);                     //время работы двигателя задаваемая потенциометром
   analogWrite(MOTOR_PIN_PWM,0);     //выключаем двигатель
   digitalWrite(13,0);               //выключаем светодиод
   delay(poten + 320);               //ждем обратный ход
   }
