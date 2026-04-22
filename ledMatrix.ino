  #include "LedControl.h"

  LedControl lc=LedControl(12,10,11,1); //DIN is pin 12, CS is pin 11, CLK is pin 10, running 5V
 

void printMessage(String message) {//columns ALL VERIFIED
  int timeDelay = 100;//DELAY TIME between columns shifting

  byte space[1]= {B00000000};//adds extra column of space between words
  byte heart[7]={B01110000,B11111000,B11111100,B01111110,B11111100,B11111000,B01110000};//heart icon
  byte plus[8]={B00011000,B00011000,B00011000,B11111111,B11111111,B00011000,B00011000,B00011000};//plus sign
  byte a[6]={B00111110,B01111110,B11001000,B11001000,B01111110,B00111110};
  byte b[6]={B11111110,B11111110,B10010010,B10010010,B11111110,B01101100};
  byte c[7]={B00111000,B01111100,B11000110,B10000010,B10000010,B11000110,B01000100};
  byte d[6]={B11111110,B11111110,B10000010,B10000010,B11111110,B01111100};
  byte e[6]={B11111110,B11111110,B10010010,B10010010,B10010010,B10010010};
  byte f[6]={B11111111,B11111111,B11011000,B11011000,B11011000,B11011000};
  byte g[6]={B01111100,B11111110,B10000010,B10001010,B11001110,B01001100};
  byte h[6]={B11111110,B11111110,B00010000,B00010000,B11111110,B11111110};
  byte LETTERI[4]={B10000010,B11111110,B11111110,B10000010}; //named this way due to conflict with int i in loops
  byte j[6]={B00001100,B00001110,B10000010,B11111110,B11111100,B10000000};
  byte k[6]={B11111110,B11111110,B00010000,B00111000,B11101110,B11000110};
  byte l[6]={B11111110,B11111110,B00000110,B00000110,B00000110,B00000110};
  byte m[7]={B11111110,B11111110,B01100000,B00110000,B01100000,B11111110,B11111110};
  byte n[7]={B11111110,B11111110,B01100000,B00110000,B00011000,B11111110,B11111110};
  byte o[6]={B01111100,B11111110,B10000010,B10000010,B11111110,B01111100};
  byte p[7]={B10000010,B11111110,B11111110,B10010010,B10010000,B11110000,B01100000};
  byte q[6]={B01111000,B11111100,B10000100,B10001110,B11111110,B01111010};
  byte r[6]={B11111110,B11111110,B10011000,B10011100,B11110110,B01100010};
  byte s[6]={B01100100,B11110110,B10010010,B10010010,B11011110,B01001100};
  byte t[6]={B11000000,B11000000,B11111110,B11111110,B11000000,B11000000};
  byte u[6]={B11111110,B11111110,B00000110,B00000110,B11111110,B11111110};
  byte v[6]={B11111000,B11111100,B00000110,B00000110,B11111100,B11111000};
  byte w[7]={B11111110,B11111110,B00001100,B00011000,B00001100,B11111110,B11111110};
  byte x[7]={B11000110,B11101110,B00111000,B00010000,B00111000,B11101110,B11000110};
  byte y[6]={B11100000,B11110000,B00011110,B00011110,B11110000,B11100000};
  byte z[6]={B10000110,B10001110,B10011010,B10110010,B11100010,B11000010};

  //now the code to  make it slide in
  byte buffer[200]; //buffer to hold message
  int bufferLen = 0;
  for(int i = 0; i < 8; i++)//to start screen blank
{
  buffer[bufferLen++] = B00000000; //add column of space between letters and characters
}
  lc.clearDisplay(0);// had to include another clear or the matrix would flash everytime upon upload
  delay(1000);//START DELAY
  for(int i=0; i<message.length();i++)
  {
     char hold = message.charAt(i);//holds current char

  byte* letter;   // pointer to the correct array
  int letterSize; // size of that array

  switch (hold)//sets the current char and sets size command to be used in loops as many letters take different amt of columns
  {   
    case ' '://space
    letter = space; letterSize = sizeof(space);break;
    case'*'://HEART
    letter = heart; letterSize = sizeof(heart); break;
    
    case '+':
      letter = plus; letterSize = sizeof(plus); break;
    
    case 'a':
      letter = a; letterSize = sizeof(a); break;

      case 'b':
      letter = b; letterSize = sizeof(b); break;

      case 'c':
      letter = c; letterSize = sizeof(c); break;

      case 'd':
      letter = d; letterSize = sizeof(d); break;
      
      case 'e':
      letter = e; letterSize = sizeof(e); break;

      case 'f':
      letter = f; letterSize = sizeof(f); break;

      case 'g':
      letter = g; letterSize = sizeof(g); break;

      case 'h':
      letter = h; letterSize = sizeof(h); break;

      case 'i':
      letter = LETTERI; letterSize = sizeof(LETTERI); break;

      case 'j':
      letter = j; letterSize = sizeof(j); break;

      case 'k':
      letter = k; letterSize = sizeof(k); break;
      
      case 'l':
      letter = l; letterSize = sizeof(l); break;

      case 'm':
      letter = m; letterSize = sizeof(m); break;
      
      case 'n':
      letter = n; letterSize = sizeof(n); break;

      case 'o':
      letter = o; letterSize = sizeof(o); break;

      case 'p':
      letter = p; letterSize = sizeof(p); break;

      case 'q':
      letter = q; letterSize = sizeof(q); break;

      case 'r':
      letter = r; letterSize = sizeof(r); break;

      case 's':
      letter = s; letterSize = sizeof(s); break;

      case 't':
      letter = t; letterSize = sizeof(t); break;
      
      case 'u':
      letter = u;letterSize = sizeof(u); break;
      
      case 'v':
      letter = v; letterSize = sizeof(v); break; 

      case 'w':
      letter = w; letterSize = sizeof(w); break;

      case 'x':
      letter = x; letterSize = sizeof(x); break;

      case 'y':
      letter = y; letterSize = sizeof(y); break;

      case 'z':
      letter = z; letterSize = sizeof(z); break;

    default:
      continue; // skip unknown characters
  }
      for(int j=0; j<letterSize; j++)
      {
        buffer[bufferLen++] = letter[j]; //sets columns in the buffer
      }
        buffer[bufferLen++] = B00000000;  
  }
  for (int offset = 0; offset < bufferLen - 8; offset++)//this is what acutually copies the buffer to the dot matrix
{
  for (int col = 0; col < 8; col++)
  {
    lc.setColumn(0, col, buffer[offset + col]);
  }
  delay(timeDelay);
}
for (int col = 0; col < 8; col++)
{
  lc.setColumn(0, col, buffer[bufferLen - 8 + col]);
}
}

void setup() {
  // put your setup code here, to run once:
 lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  String message = "hello world";//MESSAGE HERE ALL LOWERCASE
  printMessage(message);
  delay(500);
  //while(true);//stops after the message has been displayed once if active
}
