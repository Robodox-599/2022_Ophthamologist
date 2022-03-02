// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "PixyBlock.h"
//void PixyBlock();

void PixyBlock::setSig(string a)
{
  stringstream obj(a);
  obj >> sig;
}

int PixyBlock::getSig()
{
  return sig;
}

void PixyBlock::setX(string a)
{
  stringstream obj(a);
  obj >> x;
  x -= 158;
}

double PixyBlock::getX()
{
  return x;
}

void PixyBlock::setY(string a)
{
  stringstream obj(a);
  obj >> y;
  y = 208 - y;
}

double PixyBlock::getY()
{
  return y;
}

void PixyBlock::setW(string a)
{
  stringstream obj(a);
  obj >> w;
}

double PixyBlock::getW()
{
  return w;
}

void PixyBlock::setH(string a)
{
  stringstream obj(a);
  obj >> h;
}

double PixyBlock::getH()
{
  return h;
}

void PixyBlock::setAge(string a)
{
  stringstream obj(a);
  obj >> age;
}

int PixyBlock::getAge()
{
  return age;
}

// double PixyBlock::getTurnValue(double x, double y)
// {
//   double turn = 0.0; 
//   if(x > 0){
//     turn = kT * atan(x / y); 
//   } else if (x < 0){
//     turn = -1 * kT * atan(x / y);
//   }
//   return turn; 
// }

// double PixyBlock::getPower(double w)
// {
//   return (pMax / wMax) * w + pMax; 
// }
