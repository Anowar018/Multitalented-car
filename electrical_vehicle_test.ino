
#define m11 11    // rear motor
#define m12 12
#define m21 10    // front motor
#define m22 9
#define m31 2    // rear motor
#define m32 3
#define m41 4    // front motor
#define m42 5
//#define e1 7
//#define e2 8
char str[2],i;

void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   //analogWrite(e1,80);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   //analogWrite(e2,80);
   digitalWrite(m31, HIGH);
   digitalWrite(m32, LOW);
   //analogWrite(e1,80);
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW);
   //analogWrite(e2,80);
}

void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   //analogWrite(e1,80);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
   //analogWrite(e2,80); 
   digitalWrite(m31, LOW);
   digitalWrite(m32, HIGH);
   //analogWrite(e1,80);
   digitalWrite(m41, LOW);
   digitalWrite(m42, HIGH);
   //analogWrite(e2,80); 
}

void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   //analogWrite(e1,80);
   delay(100);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
   //analogWrite(e2,80);
   digitalWrite(m31, HIGH);
   digitalWrite(m32, LOW);
   //analogWrite(e1,80);
   delay(100);
   digitalWrite(m41, LOW);
   digitalWrite(m42, HIGH);
   //analogWrite(e2,80);
}

void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   //analogWrite(e1,80);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
   //analogWrite(e2,80);
   digitalWrite(m31, LOW);
   digitalWrite(m32, HIGH);
   //analogWrite(e1,80);
   delay(100);
   digitalWrite(m41, HIGH);
   digitalWrite(m42, LOW);
   //analogWrite(e2,80);
}

void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   digitalWrite(m31, LOW);
   digitalWrite(m32, LOW);
   digitalWrite(m41, LOW);
   digitalWrite(m42, LOW);
}

void wheel1_forward()
{
  digitalWrite(m11,HIGH);
  digitalWrite(m12,LOW);
}
void wheel1_backward()
{
  digitalWrite(m11,LOW);
  digitalWrite(m12,HIGH);
}

void wheel2_forward()
{
  digitalWrite(m21,HIGH);
  digitalWrite(m22,LOW);
}
void wheel2_backward()
{
  digitalWrite(m21,LOW);
  digitalWrite(m22,HIGH);
}

void wheel3_forward()
{
  digitalWrite(m31,HIGH);
  digitalWrite(m32,LOW);
}
void wheel3_backward()
{
  digitalWrite(m31,LOW);
  digitalWrite(m32,HIGH);
}

void wheel4_forward()
{
  digitalWrite(m41,HIGH);
  digitalWrite(m42,LOW);
}
void wheel4_backward()
{
  digitalWrite(m41,LOW);
  digitalWrite(m42,HIGH);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m31, OUTPUT);
  pinMode(m32, OUTPUT);
  pinMode(m41, OUTPUT);
  pinMode(m42, OUTPUT);
  //pinMode(e1, OUTPUT);
  //pinMode(e2, OUTPUT);
}

void loop() 
{
//  motor();
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='F')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }

    else if(str[i-1]=='L')
    {
     Serial.println("Left");
     right();
     i=0;
    }

    else if(str[i-1]=='R')
    {
      Serial.println("Right");
      left();
      i=0;
    }
    
    else if(str[i-1]=='B')
    {
      Serial.println("Backward");
      backward();
      i=0;
    }

    else if(str[i-1]=='S')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}

