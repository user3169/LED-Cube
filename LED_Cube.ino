//pins controlling transistors' bases
//for layers 1 to 3 starting from the bottom 
int tlayer1 = 11;
int tlayer2 = 12;
int tlayer3 = 13;

//all pins 2- 10 to HIGH
void DPinsHigh()
{
  for(int i = 2; i<11; i++)
  {
    digitalWrite(i, HIGH);
  }
}

//all pins 2- 10 to LOW
void DPinsLow()
{
  for(int i = 2; i<11; i++)
  {
    digitalWrite(i, LOW);
  }
}

//all diods blink
void Blink()
{
  TPinsHigh();
  DPinsHigh();
  delay(800);
  DPinsLow();
  TPinsLow();
  delay(800);
}

//all pins 11 - 13 controlling transistors' bases to HIGH
void TPinsHigh()
{
  for(int i = 0; i<3; i++)
  {
    digitalWrite(tlayer1 + i, HIGH);
  }
}

//all pins 11 - 13 controlling transistors' bases to LOW
void TPinsLow()
{
  for(int i = 0; i<3; i++)
  {
    digitalWrite(tlayer1 + i, LOW);
  }
}

//layers going up
void layersUp()
{
  DPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(tlayer1 + i, HIGH);
    delay(800);
    digitalWrite(tlayer1 + i, LOW);
  }
  DPinsLow();
}

//layers going down
void layersDown()
{
  DPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(tlayer3 - i, HIGH);
    delay(800);
    digitalWrite(tlayer3 - i, LOW);
  }
  DPinsLow();
}

//light going from left to right
void LeftToRight()
{
  TPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(10 - 3 * i, HIGH);
    digitalWrite(9 - 3 * i, HIGH);
    digitalWrite(8 - 3 * i, HIGH);
    delay(800);
    digitalWrite(10 - 3 * i, LOW);
    digitalWrite(9 - 3 * i, LOW);
    digitalWrite(8 - 3 * i, LOW);
  }
  TPinsLow();
}

//light going from right to left
void RightToLeft()
{
  TPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(3 * i + 2, HIGH);
    digitalWrite(3 * i + 3, HIGH);
    digitalWrite(3 * i + 4, HIGH);
    delay(800);
    digitalWrite(3 * i + 2, LOW);
    digitalWrite(3 * i + 3, LOW);
    digitalWrite(3 * i + 4, LOW);
  }
  TPinsLow();
}

//light going from front to back
void FrontToBack()
{
  TPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(4 - i, HIGH);
    digitalWrite(7 - i, HIGH);
    digitalWrite(10 - i, HIGH);
    delay(800);
    digitalWrite(4 - i, LOW);
    digitalWrite(7 - i, LOW);
    digitalWrite(10 - i, LOW);
  }
  TPinsLow();
}

//light going from back to front
void BackToFront()
{
  TPinsHigh();
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(2 + i, HIGH);
    digitalWrite(5 + i, HIGH);
    digitalWrite(8 + i, HIGH);
    delay(800);
    digitalWrite(2 + i, LOW);
    digitalWrite(5 + i, LOW);
    digitalWrite(8 + i, LOW);
  }
  TPinsLow();
}

//from bottom right to top left
void BrToTl()
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(tlayer1 + i, HIGH);
    digitalWrite(10 - 3 * i, HIGH);
    digitalWrite(9 - 3 * i, HIGH);
    digitalWrite(8 - 3 * i, HIGH);
    delay(800);
    digitalWrite(tlayer1 + i, LOW);
    digitalWrite(10 - 3 * i, LOW);
    digitalWrite(9 - 3 * i, LOW);
    digitalWrite(8 - 3 * i, LOW);
  }
}

//light spins arround the middle column
void Spin()
{
  digitalWrite(6, HIGH);
  TPinsHigh();
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(10 - i, HIGH);
    digitalWrite(2 + i, HIGH);
    delay(800);
    digitalWrite(10 - i, LOW);
    digitalWrite(2 + i, LOW);
  }
  digitalWrite(6, LOW);
  TPinsLow();
}

//columns light up one by one
void ColByCol()
{
  TPinsHigh();
  for(int i = 2; i < 11; i++)
  {
    digitalWrite(12 - i, HIGH);
    delay(800);
  }
  TPinsHigh();
  DPinsLow();
}

//light extends in th form of cube
void CubeExtend()
{
  digitalWrite(tlayer1, HIGH);
  digitalWrite(10, HIGH);
  delay(800);
  digitalWrite(tlayer2, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(800);
  digitalWrite(tlayer3, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  delay(800);
  DPinsLow();
  TPinsLow();
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(tlayer1, OUTPUT);
  pinMode(tlayer2, OUTPUT);
  pinMode(tlayer3, OUTPUT);
}

void loop()
{
    ColByCol(); 
    Blink();
    layersUp(); 
    layersDown(); 
    LeftToRight();
    RightToLeft(); 
    FrontToBack(); 
    BackToFront(); 
    BrToTl(); 
    Spin(); 
    CubeExtend();
}
