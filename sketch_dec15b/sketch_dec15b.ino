#include <SPI.h> 
#include <MFRC522.h>
#include <EEPROM.h>
#include <Servo.h>

#define RST_PIN 9//Rfid rst pini
#define SS_PIN 53//Rfid ss pini
MFRC522 mfrc522(SS_PIN, RST_PIN);


String lastRfid = "";
String kart[5];

int aracSayisi=0;


int a = 24;
int b = 25;
int c = 27;
int d = 28;//7 segment display için pin numaraları
int e = 29;
int f = 23;
int g = 26;
char  incomingByte;


Servo girisServosu;
Servo cikisServosu;

MFRC522::MIFARE_Key key;

int trigPin1 = 12;
int echoPin1 = 11;  
int trigPin2 = 7; 
int echoPin2 = 6;  

long sure;
long uzaklik;



void setup()
{
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);//7segemnt display pinleri çıkış olarak ayarlandı
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
pinMode(trigPin1, OUTPUT); /* trig pini çıkış olarak ayarlandı */
pinMode(echoPin1,INPUT); /* echo pini giriş olarak ayarlandı */
pinMode(trigPin2, OUTPUT); /* trig pini çıkış olarak ayarlandı */
pinMode(echoPin2,INPUT); /* echo pini giriş olarak ayarlandı */

girisServosu.attach(8);
cikisServosu.attach(10);
  
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
readEEPROM();//Epromda kayıtlı veriler okunur.
girisServosu.write(89);
cikisServosu.write(260);

}


void loop()
{
  RakamYaz(aracSayisi);
   girisKontrol();
   cikisKontrol();
   arabaKontrol();
   
  
}
void arabaKontrol(){
  if(analogRead(0)<700){
    Serial.println("araba1var");
    
    }else{
       Serial.println("araba1yok");
      }
      delay(120);
       if(analogRead(1)<700){
    Serial.println("araba2var");
    
    }else{
       Serial.println("araba2yok");
       
      }
       delay(120);
      if(analogRead(2)<700){
    Serial.println("araba3var");
   
    }else{
       Serial.println("araba3yok");
       
      }
 delay(120);
       if(analogRead(3)<700){
    Serial.println("araba4var");
    
    }else{
       Serial.println("araba4yok");
       
      }
       delay(120);
       if(analogRead(4)<700){
    Serial.println("araba5var");
    
    }else{
       Serial.println("araba5yok");
       
      }
       delay(120);
       if(analogRead(5)<700){
    Serial.println("araba6var");
    
    }else{
       Serial.println("araba6yok");
       
      }
       delay(120);
       if(analogRead(6)<700){
    Serial.println("araba7var");
    
    }else{
       Serial.println("araba7yok");
       
      }
 delay(120);
  
   
  
  }


void cikisKontrol(){
  delay(200);
  if(aracSayisi>0 && cikisSensor()<=4 ){

 cikisServosu.write(100);
 Serial.println("cikisac");
 delay(2000);
 arabaKontrol();
do{
    delay(1000);
    arabaKontrol();
  }while(cikisSensor()<=4);
delay(500);
cikisServosu.write(260);
Serial.println("cikiskapat");
delay(200);
aracSayisi--;
   
  
  }}
  
//rfid kart okumuşsa girişi acar aracın gecmesini bekler.
void girisKontrol(){
  delay(200);
  if(RFID()==false && aracSayisi<7){

 girisServosu.write(180);
 Serial.println("girisac");
 delay(2000);
 arabaKontrol();
do{
    delay(1000);
    arabaKontrol();
    
  }while(girisSensor()<=5);
delay(1000);
girisServosu.write(90);
Serial.println("giriskapat");
lastRfid="";
delay(200);
aracSayisi++;
   }else if(aracSayisi==7){
    digitalWrite(2,LOW);
    digitalWrite(3,HIGH);
    
    }else if(aracSayisi<7){
      digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
      }
  }





//rfid kartı okur kart tanımlıysa false dondurur.
bool RFID(){
   String rfid = "";
    if ( mfrc522.PICC_IsNewCardPresent()){
  if ( mfrc522.PICC_ReadCardSerial())
   {
    
      for (byte i = 0; i < mfrc522.uid.size; i++){
  
        rfid += mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ";
        rfid += String(mfrc522.uid.uidByte[i], HEX);
    }
    
  //string'in boyutunu ayarla ve tamamını büyük harfe çevir
  rfid.trim();
  rfid.toUpperCase();

  if (rfid != lastRfid){
    
  lastRfid = rfid;
 
for(int i=0;i<5;i++){
 
  if (rfid == kart[i])
  {
    
    return false;
}

 }}}}}
 



//7 segment display de araç sayısını gostermek için kullanılır.

void RakamYaz(int rakam)
{
   switch(rakam)
   {
   case 0 :
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,LOW);
   break;
   case 1:
   digitalWrite(a, LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   break;
   case 2:
   digitalWrite(a, HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,LOW);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   break;
   case 3:
   digitalWrite(a, HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,HIGH);
   break;
   case 4:
   digitalWrite(a, LOW);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   break;
   case 5:
   digitalWrite(a, HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   break;
   case 6:
   digitalWrite(a, HIGH);
   digitalWrite(b,LOW);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   break;
   case 7:
   digitalWrite(a, HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,LOW);
   digitalWrite(e,LOW);
   digitalWrite(f,LOW);
   digitalWrite(g,LOW);
   break;
   case 8:
   digitalWrite(a, HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,HIGH);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   break;
   case 9:
   digitalWrite(a,HIGH);
   digitalWrite(b,HIGH);
   digitalWrite(c,HIGH);
   digitalWrite(d,HIGH);
   digitalWrite(e,LOW);
   digitalWrite(f,HIGH);
   digitalWrite(g,HIGH);
   break;
   }
}

  


//giristeki sensorun degerini dondurur.
int girisSensor(){
    digitalWrite(trigPin1, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin1, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */   
 
  return uzaklik;
      

 }
 int cikisSensor(){
    digitalWrite(trigPin2, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin2, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */   
 
  return uzaklik;
      

 }








//program başında bir kere calışır eprom okur.

void readEEPROM()
{
  //EEPROM'dan ilk kartın UID'sini oku (ilk 4 byte)
  int i=0;
  int sayac=0;

  while(sayac<=5){

  for (int j = 0 ; j < 4 ; j++)
  {
  
    kart[sayac] += EEPROM.read(i) < 0x10 ? " 0" : " ";
    kart[sayac] += String(EEPROM.read(i), HEX);
  i++;
  }
  sayac++;
  }
  //EEPROM'dan ikinci kartın UID'sini oku
  
  //Okunan stringleri düzenle
  for(int i=0;i<sayac;i++){
  kart[i].trim();
  kart[i].toUpperCase();
 
  }
  
}
void test(){
Serial.println("----------Test---------");
Serial.print("1.Araba=");
Serial.println(analogRead(0));
Serial.print("2.Araba=");
Serial.println(analogRead(1));
Serial.print("3.Araba=");
Serial.println(analogRead(2));
Serial.print("4.Araba=");
Serial.println(analogRead(3));
Serial.print("5.Araba=");
Serial.println(analogRead(4));
Serial.print("6.Araba=");
Serial.println(analogRead(5));
Serial.print("7.Araba=");
Serial.println(analogRead(6));
Serial.println("-----------");
Serial.print("girisSensor=");
Serial.println(girisSensor());
Serial.print("cikisSensor=");
Serial.println(cikisSensor());
delay(3000);









}


