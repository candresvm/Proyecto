/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *        FICA-CITEL
 *     SISTEMAS EMBEBIDOS
 *     CHRISTIAN VILLEGAS
 *  Knn con 40 datos de prueba
 */
#include "datos.h"
#include "prueba.h"

int respuesta;
int knn (int k, int etiquetas, int tam_col, int col_fil); // definir la func

int sensor_mq135 = 0;
int sensor_mq7 = 0;
int cont=0;
int x=0;
int y=21;
int i=0;
int aux=0;
int comparar= matriz_prueba[aux][2];
int z;

void setup() {
Serial.begin(9600);
Serial.println("#  MQ135  MQ7  Tipo de Aire");

}

void loop() {
  respuesta=knn(3,2,3,160);
  if(cont<41){
    switch(respuesta){
      case 1:
        Serial.println(String(cont)+String("   ")+String(sensor_mq135)+String("   ")+String(sensor_mq7)+String("    ")+String("Aire Contaminado"));
        delay(500);
        
      break;
      case 2:
        Serial.println(String(cont)+String("   ")+String(sensor_mq135)+String("   ")+String(sensor_mq7)+String("    ")+String("Aire Limpio"));
        delay(500);
      break;
    }
    if(respuesta==comparar){
      y++;
    }
    if(cont==40){
      z=(y/40)*100;
      Serial.println(String("En 40 pruebas tenemos una eficiencia del : ")+String(z)+String("%"));
      cont++;
    }
  }
}

int knn (int k, int etiquetas, int tam_col, int tam_fil){
int col;
int fil=0;
int i=0;
int j;
float aux;
float aux_etiqueta;
float potencia;
float raiz;
int label;
String salida="";
sensor_mq135= matriz_prueba[cont][0];
sensor_mq7= matriz_prueba[cont][1];


float datos_prueba [3]={sensor_mq135,sensor_mq7,2.0};
 float matriz_k [3][k];
 for(;i<k;i++){
  matriz_k[0][i]=i+1.00;
  matriz_k[1][i]=0;
  matriz_k[2][i]=2500.0+i;
  }
  i=0;
  float matriz_eti[2][etiquetas];
  for(;i<etiquetas;i++){
      matriz_eti[0][i]=i+1.0;
      matriz_eti[1][i]=0.0;
    }

   for(;fil<tam_fil;fil++){
      for(col=0;col<tam_col-1;col++){
          potencia=potencia+pow(matriz[fil][col]-datos_prueba[col],2);
        }
        raiz=sqrt(potencia);
        potencia=0;
        if(raiz<matriz_k[2][k-1]){
          matriz_k[2][k-1]=raiz;
          matriz_k[1][k-1]=matriz[fil][tam_col-1]; 
          for(i=0;i<k;i++){
             for(j=i+1;j<k;j++){
               if(matriz_k[2][i]>matriz_k[2][j]){
                 // distancia
                  aux=matriz_k[2][i];
                  matriz_k[2][i]=matriz_k[2][j];
                  matriz_k[2][j]=aux;
                  //etiqueta
                  aux_etiqueta=matriz_k[1][i];
                  matriz_k[1][i]=matriz_k[1][j];
                  matriz_k[1][j]=aux_etiqueta;
                }
              }
            }
        }
    }
    for(i=0;i<etiquetas;i++){
      for(j=0;j<k;j++){
          if(matriz_eti[0][i]==matriz_k[1][j]){
            matriz_eti[1][i]++;
          }
        }
      }
    for(i=0;i<etiquetas-1;i++){
       if(matriz_eti[1][i]<matriz_eti[1][i+1])
        label=(int)matriz_eti[0][i+1];
        else 
        label=(int)matriz_eti[0][i];
      }  
      cont++;
 return label;
};
