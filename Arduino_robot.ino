

// ---------------------------------------------------------------- //
// Arduino Line Follower
// Using Arduino IDE 2.3.2
// Tested 4/8/2024
// ---------------------------------------------------------------- //

// define variables

//motor pins
int L1 = 9;
int L2 = 8;
int R1 = 7;
int R2 = 6;

//sensorRight = A0 <---sensor numbers
//sensorLeft = A1

void setup() {
  pinMode (L1, OUTPUT); // Motor pins
  pinMode (L2, OUTPUT); //
  pinMode (R1, OUTPUT); //
  pinMode (R2, OUTPUT); //

  pinMode (A0, INPUT) ; // sensor right
  pinMode (A1, INPUT); // sensor left

  Serial.begin (9600) ; // Serial monitor for testing (IGNORE)
 
}

//Movement Functions
void motorStop(int L1, int L2, int R1, int R2)
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
}
void motorForward(int L1, int L2, int R1, int R2)
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}
void motorBackward(int L1, int L2, int R1, int R2)
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}
void motorLeft(int L1, int L2, int R1, int R2) //switched this with motorRight 4/9/2024
{
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(R2, HIGH);
}
void motorRight(int L1, int L2, int R1, int R2)
{
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
}

void loop()
{
  //Input from IR SENSORS
  int S0 = digitalRead(A0);
  int S1 = digitalRead(A1);

  //1 is black and 0 is white
  if (S0 == 1 && S1 == 1)
  {
    motorForward(L1, L2, R1, R2);
  }
  else if (S0 == 0 && S1 == 0)
  {
    motorStop(L1, L2, R1, R2);
  }
  else if (S0 == 1 && S1 == 0)
  {
    motorRight(L1,L2,R1,R2);
  }
  else if (S0 == 0 && S1 == 1)
  {
    motorLeft(L1,L2,R1,R2);
  }
}

