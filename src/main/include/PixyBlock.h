// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

class PixyBlock
{

private:
  int sig;
  int x;
  int y;
  int w;
  int h;
  int age;
  // static const double kT = 0.63661977236;
  // static const double pMax = 0.5;
  // static const double wMax = 314; 

public:  
  //PixyBlock();

  void setSig(string a);

  int getSig();

  void setX(string a);

  double getX();

  void setY(string a);

  double getY();

  void setW(string a);

  double getW();

  void setH(string a);

  double getH();

  void setAge(string a);

  int getAge();
};

