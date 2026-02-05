// Mathmatecal Functions Used By Main Program


#define SQRT_ITERATIONS 2 // Set for float values, adjust for larger types
#define exp(double val) exp_d(double val)


// General
// Square Root Functions
static float sqrt_f(float val){
  float next = (val >> 1) + 0x1fbb4000; //approximation from bit shift + bias
  for(int i = 0; i < SQRT_ITERATIONS; i++){
    next = (next + (val / next)) / 2;
  }
  return next;
}
static double sqrt_d(double val){
  double next = (val >> 1) + 0x5f3759df; //approximation from bit shift + bias
  for(int i = 0; i < SQRT_ITERATIONS+1; i++){
    next = (next + (val / next)) / 2;
  }
  return next;
}
// Horner Function
static float horner_f(float a, float *vals, int size){
  if(size == 1){
    return a;
  }
  float result = 0;
  for(int i = size - 1; i >= 0; i--){
    result = result * r + vals[i];
  }
  return result;
}
static double horner_d(double a, double *vals, int size){
  if(size == 1){
    return a;
  }
  double result = 0;
  for(int i = size - 1; i >= 0; i--){
    result = result * r + vals[i];
  }
  return result;
}

// Constant Values for ln2
const double invln2 = 0x3ff71547652b82fe;
const double ln2_hi = 0x3fe62e42fee00000;
const double ln2_lo = 0x3dea39ef35793c76;

// magic numbers for e^x approximation
const double exp_C1 = 0x3fc555555555553e;
const double exp_C2 = 0xbf66c16c16bebd93;
const double exp_C3 = 0x3f0656c9d8d17541;
const double exp_C4 = 0xbe97b09645e33f5b;
const double exp_C5 = 0x3e21eed8eff8d898;
const double exp_size = 5;

// e exponent Function

// not accurate enough due to type size
// static float exp_f(float val){
//   // 0 case
//   if(val == 0){
//     return val;
//   }
//   const int k = (int)(val*invln2);
//   float r = val - (k*ln2_hi) - (k*ln2_lo);
//   float coefficents[exp_size] = {exp_C1, exp_C2, exp_C3, exp_C4, exp_C5};
//   float R = horner_d(r*r, coefficents, exp_size);
//   return 1 + 2 * (r / (R - r));
// }


static double exp_f(double val){
  // 0 case
  if(val == 0){
    return val;
  }
  const int k = (int)(val*invln2);
  double r = val - (k*ln2_hi) - (k*ln2_lo);
  double coefficents[exp_size] = {exp_C1, exp_C2, exp_C3, exp_C4, exp_C5};
  double R = horner_d(r*r, coefficents, exp_size);
  return 1 + 2 * (r / (R - r));
}


// Summation (higher order function)
static float summation_f(float *vals, float(*fn)(float val)){

}
static double summation_f(double *vals, double(*fn)(double val)){

}


// Activation Functions

// ReLu Activation Function
float ReLu_f(float val1, float val2){

}
double ReLu_d(double val1, double val2){

}

// sigmoid Activation Function
float sigmoid_f(float val){
  double x = exp(val);
  return (float)(x/(x+1));
}

double sigmoid_d(double val){
  double x = exp(val);
  return (x/(x+1));
}

// Softmax Activation Function
float softmax_f(float val1, float val2){

}
double softmax_d(double val1, double val2){

}



// Loss Functions
