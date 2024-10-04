// https://wokwi.com/projects/410302035690579969
// L298N Wokwi custom chip with LEDs-simulating motors
// With potentiometers to control directions
// Also with @Dlloyd's Chip Scopes from https://github.com/Dlloydev/Wokwi-Chip-Scope
// to see the inputs abd outputs of the driver board

// Modified from
// https://wokwi.com/projects/351764383409373773 by Carlos Arino

// Motor A
const byte  ENA = 11;
const byte  IN1 = 10;
const byte  IN2 = 9;

// Motor B
const byte  ENB = 3;
const byte  IN3 = 5;
const byte  IN4 = 6;

int xx = 0, yy = 0; // x&y potentiometers
void setup ()
{
  // Declaramos todos los pines como salidas
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  Serial.begin(115200);
}
//Mover los motores a pleno rendimiento (255), si quieres bajar la velocidad puedes reducir el valor hasta la mínima que son 0 (parados)</pre>
//Para mover los motores en sentido de giro contrario, cambia IN1 a LOW e IN2 a HIGH


void writeA(int a1, int a2) {
  digitalWrite(IN1, a1);
  digitalWrite(IN2, a2);
}
void writeB(int a3, int a4) {
  digitalWrite(IN3, a3);
  digitalWrite(IN4, a4);
}

void loop ()
{
  static int lastXX, lastYY;
  xx = (analogRead(A0)-512) / 8;
  yy = (analogRead(A1) - 512) / 2;

  int speedA = constrain(yy - xx, -255, 255);
  int speedB = constrain(yy + xx, -255, 255);

  //Direccion motor A
  if (speedA >= 0 ) {
    writeA(1, 0);
    analogWrite(ENA, speedA); //Velocidad motor A
  }
  else
  {
    writeA(0, 1);
    analogWrite(ENA, -speedA); //Velocidad motor A
  }
  //Direccion motor B
  if (speedB >= 0 ) {
    writeB(1, 0);
    analogWrite(ENB, speedB); //Velocidad motor A
  }
  else
  {
    writeB(0, 1);
    analogWrite(ENB, -speedB); //Velocidad motor A
  }

  if (false && (xx != lastXX || yy != lastYY)) {
    lastXX = xx;
    lastYY = yy;
    Serial.print(xx);
    Serial.print(",");
    Serial.print(yy);
    Serial.print(" ");
  }
}