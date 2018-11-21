#include "TMath.h"
#include <iostream>

Double_t simpleFC(Double_t Nobserved, Double_t Nbackground, Double_t CL=0.9)
{
  if (!gROOT->GetClass("TFeldmanCousins")) gSystem->Load("libPhysics");
  TFeldmanCousins f(CL);
  Double_t MaxNobserved = 50;

  if (Nbackground < 0.1)      MaxNobserved = 22;
  else if (Nbackground < 0.5) MaxNobserved = 28;
  else if (Nbackground < 1.)  MaxNobserved = 31;
  else if (Nbackground < 2.)  MaxNobserved = 38;
  else if (Nbackground < 3.)  MaxNobserved = 42;
  else if (Nbackground < 4.)  MaxNobserved = 47;
  else if (Nbackground < 5.)  MaxNobserved = 50; // 28 // 0.95: 6.31029
  else if (Nbackground < 6.)  MaxNobserved = 55;
  else if (Nbackground < 7.)  MaxNobserved = 58;
  else if (Nbackground < 8.)  MaxNobserved = 60;
  else if (Nbackground < 9.)  MaxNobserved = 64; 
  else if (Nbackground < 10.) MaxNobserved = 66; // 39
  else if (Nbackground < 20.) MaxNobserved = 91; // 59  10.7463 (0.95)
  else if (Nbackground < 30.) MaxNobserved = 109; // 76 12.7731 (0.95)  5.87172e-11
  else if (Nbackground < 40.) MaxNobserved = 128; // 92 14.4667 (0.95)  6.05876e-11
  else if (Nbackground < 50.) MaxNobserved = 148; // 107        15.9982 (0.95)  7.64127e-11
  else if (Nbackground <100.) MaxNobserved = 200;  // 148       21.9703 (0.95)  0
  else if (Nbackground <200.) MaxNobserved = 400;  //307        30.3678 (0.95)  7.0203e-11
  else if (Nbackground <400.) MaxNobserved = 800;
  else MaxNobserved = 800;
    
  f.SetMuMax(MaxNobserved);
  f.SetMuMin(0);

  Double_t result = f.CalculateUpperLimit(Nobserved,Nbackground);
  return result;
}

