float myArray[]={336,336,336,336,336,336,336,336,334,334,334,334,334,334,334,334,334,334,334,334,333,334,334,333,333,333,333,333,334,334,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,332,332,333,333,332,333,332,333,332,361,361,361,361,361,361,361,361,361,361,361,361,361,360,360,360,360,360,360,360,360,360,360,360,360,360,359,359,359,359,359,359,358,358,358,358,358,357,357,356,357,357,357,357,357,357,356,356,356,356,356,355,355,355,355,355,355,354,354,354,354,353,353,353,353,352,352,352,352,352,352,351,351,351,351,351,351,351,350,350,350,350,350,350,350,350,350,349,349,349,349,349,349,349,349,349,349,348,348,348,};
float kernel[]={0.05,0.24,0.4,0.24,0.05};
float G[]={336,336,336,336,336,336,336,336,334,334,334,334,334,334,334,334,334,334,334,334,333,334,334,333,333,333,333,333,334,334,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,333,332,332,333,333,332,333,332,333,332,361,361,361,361,361,361,361,361,361,361,361,361,361,360,360,360,360,360,360,360,360,360,360,360,360,360,359,359,359,359,359,359,358,358,358,358,358,357,357,356,357,357,357,357,357,357,356,356,356,356,356,355,355,355,355,355,355,354,354,354,354,353,353,353,353,352,352,352,352,352,352,351,351,351,351,351,351,351,350,350,350,350,350,350,350,350,350,349,349,349,349,349,349,349,349,349,349,348,348,348,};
int N=200, Nk=5;
float den=0,c=0, zj=0;
void setup()
{
Serial.begin(9600);
}

void loop()
{
  den=0;
  for (int i = 0; i < Nk; i++){
    den=den+kernel[i];
  }
  
for (int i = 0; i < N-Nk; i++){
  for (int i2 = 0; i2 < Nk; i2++){
       c=c+kernel[i2]*myArray[i2+i];
  }
   c=c/den;
   Serial.print(c);
   Serial.print(",");
   Serial.println(myArray[i+2]+70);
   c=0;
  }

  SNR();
}

void SNR(){

//Promedio señal original v1
  float sum=0;
  for(int i=0;i<90;i++){
      sum = sum + G[i];
    }
    float promedio=sum/90;
    float v1=((promedio*5)/1023);
    Serial.println(v1);
    Serial.print(",");
    
//Promedio señal Suavizada (v2) metodo de Gauss
   float sum2=0;
  for(int i=0;i<90;i++){
      sum2 = sum2 + G[i+2];
    }
    float promedio2=sum2/90;
    float v2=((promedio2*5)/1023);
    Serial.println(v2);
    Serial.print(",");

//Metrica SNR m=20*log(v2/v1)
    float metrica=20*log(v2/v1);
    Serial.println(metrica);
    Serial.print(",");
    
  }
