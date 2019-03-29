
char command;


int wheel11= 2;
int wheel12=4;
int wheel1pwm=3;


int wheel21=7;
int wheel22=8;
int wheel2pwm=5;

int shaft =11;
int shaftpwm=6;

int right1=A3;
int right2=A0;
int rightpwm=9;

int left1=A1;
int left2=A2;
int leftpwm=10;






void setup(){
pinMode(wheel11,OUTPUT);
pinMode(wheel12,OUTPUT);
pinMode(wheel21,OUTPUT);
pinMode(wheel22,OUTPUT);
pinMode(shaft,OUTPUT);
pinMode(shaftpwm,OUTPUT);
pinMode(leftpwm,OUTPUT);
pinMode(rightpwm,OUTPUT);
pinMode(wheel1pwm,OUTPUT);
pinMode(wheel2pwm,OUTPUT);
pinMode(right1,OUTPUT);
pinMode(right2,OUTPUT);
pinMode(left1,OUTPUT);
pinMode(left2,OUTPUT);



Serial.begin(9600);
}


void forward(){             // To move the wallE forward

    digitalWrite(wheel11,HIGH);  
    digitalWrite(wheel12,LOW);  
    digitalWrite(wheel21,HIGH);  
    digitalWrite(wheel22,LOW);  
    analogWrite(wheel1pwm,250);
    analogWrite(wheel2pwm,250);
  
} 

void back(){            // To move the wallE in reverse direction

    digitalWrite(wheel12,HIGH);  
    digitalWrite(wheel11,LOW);  
    digitalWrite(wheel22,HIGH);  
    digitalWrite(wheel21,LOW);   
     analogWrite(wheel1pwm,250);
    analogWrite(wheel2pwm,250);  
  
}

void right(){           // To move the wallE towards right
    digitalWrite(wheel11,HIGH);  
    digitalWrite(wheel12,LOW);  
    digitalWrite(wheel21,LOW);  
    digitalWrite(wheel22,HIGH);  
     analogWrite(wheel1pwm,250);
    analogWrite(wheel2pwm,150);
}

void left(){          // To move the wallE towards left

    digitalWrite(wheel11,LOW);  
    digitalWrite(wheel12,HIGH);  
    digitalWrite(wheel21,HIGH);  
    digitalWrite(wheel22,LOW);    
     analogWrite(wheel1pwm,150);
    analogWrite(wheel2pwm,250); 
  
}

void stopBOT(){            // To stop  wallE 
   digitalWrite(wheel11,LOW);  
    digitalWrite(wheel12,LOW);  
    digitalWrite(wheel21,LOW);  
    digitalWrite(wheel22,LOW);
     analogWrite(wheel1pwm,0);
    analogWrite(wheel2pwm,0);
}

void down(){
  digitalWrite(shaft,LOW);  
   
  analogWrite(shaftpwm,70);
  
}

void up(){
  digitalWrite(shaft,HIGH);  
  analogWrite(shaftpwm,180);
}
void stophand(){
  digitalWrite(shaft,HIGH);  
  digitalWrite(right1,HIGH);  
  digitalWrite(right2,HIGH);  
  digitalWrite(left1,HIGH);  
  digitalWrite(left2,HIGH);  
  analogWrite(shaftpwm,0);
  analogWrite(rightpwm,0);
  analogWrite(leftpwm,0);
  
}

void rightconverge(){

  digitalWrite(right1,HIGH);  
  digitalWrite(right2,LOW);  
  analogWrite(rightpwm,180);
  
}

void rightdiverge(){

  digitalWrite(right2,HIGH);  
  digitalWrite(right1,LOW);  
  analogWrite(rightpwm,180);
  
}

void leftconverge(){

  digitalWrite(left2,LOW);  
  digitalWrite(left1,HIGH);  
  analogWrite(leftpwm,200);
  
}

void leftdiverge(){

  digitalWrite(left1,LOW);  
  digitalWrite(left2,HIGH);  
  analogWrite(leftpwm,180);
  
}



void diverge(){

digitalWrite(right1,HIGH);  
    digitalWrite(right2,LOW);  
    digitalWrite(left1,LOW);  
    digitalWrite(left2,HIGH);  
     analogWrite(rightpwm,180);
    analogWrite(leftpwm,180);
  
}

void converge(){

digitalWrite(right2,HIGH);  
    digitalWrite(right1,LOW);  
    digitalWrite(left2,LOW);  
    digitalWrite(left1,HIGH);  
     analogWrite(rightpwm,180);
    analogWrite(leftpwm,180);
  
}


void loop(){
  

  while(Serial.available()==0){};

  if (Serial.available()>0){
    command= Serial.read();
    
  }

  switch(command){

    
    case 'S' : {stopBOT();
     
                  break;}
    case 'F' : {forward();
  
                  break;}
    case 'B' : {back();
      
                  break;}            
    case 'R' : {right();
      
                  break;}
    case 'L' : {left();
      
                  break;}
    case 'U' : {up();
      
                  break;}
    case 'D' : {down();
   
                  break;}
    case 'C' : {converge();
  
                  break;} 
   case 'V' : {diverge();
                  break;}
   case 'P': { stophand();
   
               break; }
   case  'W' :{ leftconverge();
               break;
   }
    case  'X' :{leftdiverge();
               break;
   }
    case  'Y' :{rightdiverge();
               break;
   }
    case  'Z' :{rightconverge();
               break;
   }
   
  
  }
  
  }
 
