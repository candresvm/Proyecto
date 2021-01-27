
import processing.serial.*;
int fil1;
int i=0;
int altura=0;
Serial port;
int dato;
int dato1;
int n=0;
int dato3=0;
PImage img;
PImage img2;
PImage img3;

void setup () {
  size(1000,830);
  background(255);
  port= new Serial(this,"COM10",9600);
  img = loadImage("limpio.jpg");
  img2 = loadImage("descarga.jpg");
  img3 = loadImage("fondo.jpg");
  port.bufferUntil('\n');
}

void draw() {
  fill(255);
  strokeWeight(3);
  rect(5,5,985,820);
  img3.resize(984,819);
  image(img3, 6, 6);
  fill(0);
  rect(370,0,270,90);
  fill(#1F025F);
  rect(50,200,900,585);
  textSize(25);
  fill(255);
  text("SISTEMAS EMBEBIDOS",375,30);
  text("PROYECTO FINAL",400,60);
  fill(255);
  strokeWeight(3);
  rect(100,400,175,100);
  fill(255);
  strokeWeight(3);
  rect(325,400,175,100);
  fill(255);
  strokeWeight(3);
  rect(600,400,275,100);
  textSize(25);
  fill(255);
  text("SENSOR MQ 135",90,380);
  textSize(25);
  fill(255);
  text("SENSOR MQ 7",330,380);
  textSize(25);
  fill(255);
  text("TIPO DE AIRE",610,380);
  textSize(25);
  fill(0);
  text(dato,130,450);
  text(dato1,350,450);
  if(dato3==2){
    text("Aire limpio",620,450);
    img.resize(450,200);
    image(img, 250, 550);
  }else if(dato3==1){
    text("Aire contaminado",620,450);
    img2.resize(450,200);
    image(img2, 250, 550);
  }
}

void serialEvent(Serial port){
    dato=port.read();
    if(dato<70){
      dato1=dato*(333/65);
      dato3=2;
    }else
    {
      dato1=dato*(356/79);
      dato3=1;
    }
}
