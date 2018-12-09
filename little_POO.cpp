#include <bits/stdc++.h>

using namespace std;

class Car {
    private:
      int currentSpeed;
      string model;
      float power;
      int maxSpeed;
    public:
      Car(string m, float p, int max){
        setModel(m);
        setPower(p);
        setMaxSpeed(max);
        setCurrentSpeed(0);
      }
      void setModel(string m){
        this->model = m;
      }
      void setPower(float p){
        this->power = p;
      }
      void setMaxSpeed(int max){
        this->maxSpeed = max;
      }
      void setCurrentSpeed(int s){
        this->currentSpeed = s;
      }
      string getModel(){
        return this->model;
      }
      float getPower(){
        return this->power;
      }
      int getMaxSpeed(){
        return this->maxSpeed;
      }
      int getCurrentSpeed(){
        return this->currentSpeed;
      }
      void printIt(){
        cout << "Model: " << getModel() << "\n";
        cout << "Power: " << getPower() << "\n";
        cout << "Max Speed: " << getMaxSpeed() << "\n";
        cout << "Current Speed: " << getCurrentSpeed() << "\n";
      }
      
      void speedUp(){
        setCurrentSpeed(getCurrentSpeed()+1);
        cout << "Acelerando... Velocidade atual do " << getModel()<< ": " << getCurrentSpeed() << "\n";
      }
      void brake() {
        setCurrentSpeed(getCurrentSpeed()-1);
        cout << "Freando... Velocidade atual do " << getModel()<< ": " << getCurrentSpeed() << "\n";
      }
};

int main() {
  Car camaro("Camaro", 4.2, 350);
  Car onix("Onix", 6.2, 150);
  Car ferrari("Ferrari", 6.2, 350);
  vector <Car> cars;
  cars.push_back (camaro);
  cars.push_back(ferrari);
  cars.push_back(onix);
  
  for (int i=0; i<10; i++)
    camaro.speedUp();
  for (int i=0; i<10; i++)
    camaro.brake();
  for (int i=0; i<cars.size(); i++){
    cout << "\n";
    cars[i].printIt();
  }
  return 0;
}
