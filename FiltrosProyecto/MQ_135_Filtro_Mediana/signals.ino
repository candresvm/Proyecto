
//(x)= sin(x[i]*pi*f)
//vin=3 Db -> 0.707
// ECG 
double short_InputSignal_1kHz_15kHz[200]={65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,64,64,64,65,64,64,64,65,65,65,65,65,65,65,65,65,65,65,64,65,65,65,65,65,65,65,64,65,64,64,65,64,64,65,64,64,64,64,65,64,64,65,65,65,65,64,65,65,65,65,64,64,65,64,64,64,64,64,64,64,64,64,65,64,65,64,64,64,64,64,64,64,64,64,64,64,64,78,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,78,78,78,78,78,78,78,78,78,78,78,78,79,78,78,78,78,78,78,78,78,78,77,77,77,77,78,78,79,79,79,79,79,79,78,78,78,78,78,78,78,77,77,77,77,77,77,77,77,77,76,76,76,76,76,75,76,75,75,75,75,75,75,75,75,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,74,};
//filtro pasabajos de 1kHz
/*
 double  Impulse_response[29] = {
  -0.0018225230f, -0.0015879294f, +0.0000000000f, +0.0036977508f, +0.0080754303f, +0.0085302217f, -0.0000000000f, -0.0173976984f,
  -0.0341458607f, -0.0333591565f, +0.0000000000f, +0.0676308395f, +0.1522061835f, +0.2229246956f, +0.2504960933f, +0.2229246956f,
  +0.1522061835f, +0.0676308395f, +0.0000000000f, -0.0333591565f, -0.0341458607f, -0.0173976984f, -0.0000000000f, +0.0085302217f,
  +0.0080754303f, +0.0036977508f, +0.0000000000f, -0.0015879294f, -0.0018225230f
};

*/


 double Impulse_response[21] = {
  -0.020104118828857275,
  -0.058427980043525084,
  -0.061178403647822,
  -0.010939393385339008,
  0.05125096443534968,
  0.03322086767894787,
  -0.05655276971833924,
  -0.08565500737264509,
  0.06337959966054495,
  0.31085440365663597,
  0.4344309124179415,
  0.31085440365663597,
  0.06337959966054495,
  -0.08565500737264509,
  -0.05655276971833924,
  0.03322086767894787,
  0.05125096443534968,
  -0.010939393385339008,
  -0.061178403647822,
  -0.058427980043525084,
  -0.020104118828857275
};