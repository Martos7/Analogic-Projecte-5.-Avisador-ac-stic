/**********************************************************************************
**                                                                               **
**                                  Projecte 5. Avisador acústic                 **
**                                                                               **
**                                 Programa 1+2                                  **
**                                                                               **
**********************************************************************************/
//Raúl Martos

const int speaker = 9;        // speaker pin 9 
const int ldr0 = A0;         //  LDR 0 pin A0 
const int ldr1 = A1;         //  LDR 1 pin A1 
const int ldr2 = A2;         //  LDR 2 pin A2 

int valorLdr0;                 // guardar valor del ldr  0
int valorLdr1;                 // guardar valor del ldr  0
int valorLdr2;                 // guardar valor del ldr  0
int freq;                    // freqüència del speaker


void setup()
{
  pinMode(speaker, OUTPUT);     // speaker SALIDA
  pinMode(ldr0, INPUT);         // LDR 0 ENTRADA
  pinMode(ldr1, INPUT);         // LDR 1 ENTRADA
  pinMode(ldr2, INPUT);         // LDR 2 ENTRADA
}


void loop()
{
  valorLdr0 = analogRead(ldr0);   // llegir valor ldr 0 
  valorLdr1 = analogRead(ldr1);   // llegir valor ldr 1
  valorLdr2 = analogRead(ldr2);   // llegir valor ldr 2 
  
  freq = min(valorLdr0, valorLdr1);  // veure quin ldr té objecte més aprop
  freq = min(valorLdr2, freq);
  freq = map(freq, 0, 1023, 2000, 0);   // mapejar valor de 0-1023 a 2000-10
  
  tone(speaker, freq, 100);   // so de durada 300ms
  delay(100+100);            // esperar so i silenci
}

// Aquest programa el que fa és depenent si al LDR li toca llum o no fa sons de diferent frequencia
// VIDEO penjat a electroaulda
