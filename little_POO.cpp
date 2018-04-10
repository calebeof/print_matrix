#include <bits/stdc++.h>

using namespace std;

class Car {
  int currentSpeed = 0;
  public: 
    string model;
    float power;
    int maxSpeed;
  
  void printIt(){
    cout << "Model: " << model << "\n";
    cout << "Power: " << power << "\n";
    cout << "Max Speed: " << maxSpeed << "\n";
    cout << "Current Speed: " << currentSpeed << "\n";
  }
  
  void speedUp(){
    cout << "Acelerando... Velocidade atual: " << currentSpeed++ << "\n";
  }
  void brake() {
    cout << "Freando... Velocidade atual: " << currentSpeed-- << "\n";
  }
};

int main() {
  Car camaro;
  Car onix;
  Car ferrari;
  
  camaro.model = "Camaro";
  camaro.power = 4.2;
  camaro.maxSpeed = 350;
  onix.model = "Onix";
  onix.power = 6.2;
  onix.maxSpeed = 150;
  ferrari.model = "Ferrari";
  ferrari.power = 6.2; 
  ferrari.maxSpeed = 350;
  
  vector <Car> cars;
  cars.push_back (camaro);
  cars.push_back(ferrari);
  cars.push_back(onix);
  
  for (int i=0; i<10; i++){
    camaro.speedUp();
  }
  for (int i=0; i<10; i++){
    camaro.brake();
  }
  for (int i=0; i<3; i++){
    cout << "\n";
    cars[i].printIt();
  }
  return 0;
}
