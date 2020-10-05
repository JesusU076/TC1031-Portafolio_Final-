#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct dato{
  int key;
  string linea;
  string ip;
  string ip2;
  string ip3;
  string ip4;
  string ip5;
  long ipp;
}; 


int burbuja(vector<dato> &vec){
  bool interruptor = true;
  dato tmp;
  int cont = 0;
  for (int i=0; i<vec.size()-1 && interruptor; i++) {
    interruptor = false; // no se han hecho intercambios
    for (int j=0; j<vec.size()-1-i; j++) {
      cont++; //contador
      if (vec[j+1].ipp < vec[j].ipp) {
        tmp = vec[j];
        vec[j] = vec[j+1];
        vec[j+1] = tmp;
        interruptor = true;
      }
    }
  }
  return cont;
}
void ahoraSi(dato &v){
  while(v.ip.length() < 3) v.ip = '0' + v.ip;
  while(v.ip2.length() < 2) v.ip2 = '0' + v.ip2;
  while(v.ip3.length() < 3) v.ip3 = '0' + v.ip3;
  while(v.ip4.length() < 2) v.ip4 = '0' + v.ip4;; 
  v.ipp = stoi(v.ip + v.ip2 + v.ip3);
  v.ipp = v.ipp*1000000 + stoi(v.ip4 + v.ip5);
}

int main() {
  fstream fin;
  dato registro;
  vector<dato> orden;
int p=0;
  fin.open("bitacora.txt",ios::in);
  while(!fin.eof()){
    getline(fin,registro.linea);
    orden.push_back(registro);
  }
  fin.close();

  string ss;
  for(int i = 0; i<orden.size(); i++){ 
    stringstream s(orden[i].linea);
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,orden[i].ip, '.');//3
    getline(s,orden[i].ip2,'.');//2
    getline(s,orden[i].ip3,'.');//3
    getline(s,orden[i].ip4,':');//2
    getline(s,orden[i].ip5,' ');//4
    ahoraSi(orden[i]);
  }

  burbuja(orden);

  for(int i = 0; i<orden.size(); i++){
    cout << i << " " << orden[i].linea << endl;
  }

}
