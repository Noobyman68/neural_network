// Mathmatecal Functions Used By Main Program


#define SQRT_ITERATIONS 2 // Set for float values, adjust for larger types


// General
// Square Root Functions
static float sqrt_f(float val){
  float next = (val >> 1) + 0x1fbb4000;
  for(int i = 0; i < SQRT_ITERATIONS; i++){
    next = (next + (val / next)) / 2;
  }
  return next;
}
static double sqrt_d(double val){
  double next = (val >> 1) + 0x5f3759df;
  for(int i = 0; i < SQRT_ITERATIONS+1; i++){
    next = (next + (val / next)) / 2;
  }
  return next;
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

// Softmax Activation Function
float softmax_f(float val1, float val2){

}
double softmax_d(double val1, double val2){

}



// Loss Functions
