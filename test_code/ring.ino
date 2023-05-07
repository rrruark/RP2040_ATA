/*
  Ring


*/
#define RM  22
#define PD  27
#define SHK 26
#define FR  21
#define LED 1


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RM, OUTPUT);
  pinMode(PD, OUTPUT);
  pinMode(SHK, INPUT);
  pinMode(FR, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(PD, LOW);
  digitalWrite(LED, HIGH);
  digitalWrite(RM, LOW);
  digitalWrite(FR, LOW);
  
}

// the loop function runs over and over again forever
void loop() 
{
  if(digitalRead(SHK))
  {
    digitalWrite(LED, digitalRead(SHK));
    delay(10);
  }
  else
  {
    digitalWrite(LED, digitalRead(SHK));
    ring();
  }
}

void ring()
{
  while(!digitalRead(SHK))
  {
    digitalWrite(RM,1);
    for(int i=0;i<20;i++)
    {
      digitalWrite(FR,1);
      delay(25);
      digitalWrite(FR,0);
      delay(25);
    }
    digitalWrite(RM,0);
    delay(2000);
  }
}
