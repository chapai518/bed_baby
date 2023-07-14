int regim=1; 
int flag=0; 
#define MOTOR_PIN_PWM 9
 void setup()   
 { 
  pinMode(MOTOR_PIN_PWM,OUTPUT);
  pinMode(13,1);
  // Пины D3 и D11 - 31.4 кГц
  TCCR2B = 0b00000001;  // x1
  TCCR2A = 0b00000001;  // phase correct
  // Пины D9 и D10 - 62.5 кГц
  TCCR1A = 0b00000001;  // 8bit
  TCCR1B = 0b00001001;  // x1 fast pwm
 } 

 void loop() 
 {  
     if(digitalRead(A0)==HIGH&&flag==0){ 
       regim++;   
       flag=1; 
        if(regim>3){ 
          regim=1;
        } 
     } 
      if(digitalRead(A0)==LOW&&flag==1){ 
        flag=0;
     } 
    if(regim==1){
      for (int i = 5; i < 255; i+=25) {
        analogWrite(MOTOR_PIN_PWM, i);
        digitalWrite(13,i);
        delay(5);
        }
      analogWrite(MOTOR_PIN_PWM, 255);
      digitalWrite(13,255);
      delay(130);   
      analogWrite(MOTOR_PIN_PWM,0);
      digitalWrite(13,0);
      delay(450);
    }
    if(regim==2){ 
      for (int i = 5; i < 255; i+=25) {
        analogWrite(MOTOR_PIN_PWM, i);
        digitalWrite(13,i);
        delay(5);
        }
      analogWrite(MOTOR_PIN_PWM, 255);
      digitalWrite(13,255);
      delay(145);         
      analogWrite(MOTOR_PIN_PWM,0);
      digitalWrite(13,0);
      delay(450);
    }
    if(regim==3){
      for (int i = 5; i < 255; i+=25) {
        analogWrite(MOTOR_PIN_PWM, i);
        digitalWrite(13,i);
        delay(5);
        }
      analogWrite(MOTOR_PIN_PWM, 255);
      digitalWrite(13,255);
      delay(160); 
      analogWrite(MOTOR_PIN_PWM,0);
      digitalWrite(13,0);
      delay(450);
    }
 } 
