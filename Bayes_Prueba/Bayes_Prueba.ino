/*
 * UNIVERSIDAD TECNICA DEL NORTE 
 *        FICA-CITEL
 *     SISTEMAS EMBEBIDOS
 *     CHRISTIAN VILLEGAS
 *  Bayes con 40 datos de prueba
 */
#include <ListLib.h>
#include "datos.h"
#include "prueba.h"

// crear una nueva lista (vector dinamico)
List <int> list;

int sensor_mq135 = 0;
int sensor_mq7 = 1;
int cont=0;
int resultado=0;

void bayesiano(int etiquetas, int columnas, int filas, float r);
void setup() {
  Serial.begin(9600);
  Serial.println("#  MQ135  MQ7     Tipo de Aire");
}

void loop() {
  if(cont<40){
    bayesiano(2,3,160,0.2);
    switch(resultado){
    case 1:
      Serial.println(String(cont)+String("   ")+String(sensor_mq135)+String("   ")+String(sensor_mq7)+String("    ")+String("Aire Contaminado"));
      delay(500);
    break;
    case 2:
      Serial.println(String(cont)+String("   ")+String(sensor_mq135)+String("   ")+String(sensor_mq7)+String("    ")+String("Aire Limpio"));
      delay(500);
    break;
    }
  }
}

void bayesiano(int etiquetas, int columnas, int filas, float r){
 int i=0;
 int j=0;
 int k=0;
 int t=0;
 float p_x=0.0; // probabilidad marginal
 float distancia=0.0; 
 float sumatoria=0.0;
 float normalizador=0.0;
 float dist_mayor=0.0001;
  // resultado de etiqueta
 float aux=0; // auxiliar de cambio de variable
 sensor_mq135= matriz_prueba[cont][0];
 sensor_mq7= matriz_prueba[cont][1];
   
   float datos_prueba [3]={sensor_mq135,sensor_mq7};
   float prob [4][etiquetas];
   //encerar matriz y asignar etiquetas a la fila 0
    for(i=0;i<4;i++){
       for(j=0;j<etiquetas;j++){ 
          prob[i][j]=0;   
          if(i==0) 
          prob[i][j]=j+1;
        }
      }
    for(i=0;i<etiquetas;i++){              
        for(j=0;j<filas;j++){               
          if(matriz[j][columnas-1]==i+1)   
            prob[1][i]++;                  
          }
      }


    //encontrar la distancia mayor 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2); 
        }
        distancia=sqrt(sumatoria); 
        sumatoria=0;
        if(distancia>dist_mayor)
          dist_mayor=distancia;
      }
      distancia=0; 
    for(i=0;i<filas;i++){
       for(j=0;j<columnas-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2);
       }
        distancia=sqrt(sumatoria);
        sumatoria=0;
        normalizador=distancia/dist_mayor; 
        if(normalizador<r)
            list.Add(i); 
    }
    for(i=0;i<list.Count();i++){                         
      for(j=0;j<etiquetas;j++){                          
          if(matriz[list[i]][columnas-1]==prob[0][j])    
            prob[2][j]++;     
        }
      }
      p_x=float(list.Count())/float(filas); 
   for(k=0;k<etiquetas;k++){ 
      prob[3][k]=((prob[1][k]/filas)*(prob[2][k]/prob[1][k]))/p_x;
    }
      for(k=0;k<etiquetas;k++){
         if(prob[3][k]>aux){
           resultado=int(prob[0][k]);
           aux=prob[3][k];
          }   
        }
    cont++;
    for(int m=0;m<160;m++){
        list.Remove(m);
    }
 }
