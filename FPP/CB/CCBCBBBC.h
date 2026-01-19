#pragma once
#include <iostream>

static int __cb_counter = 0;

#define C ++__cb_counter
#define B do { std::cout << char(__cb_counter); __cb_counter = 0; } while(0)
