#include <iostream>

int main() {
   int diaIni, bisiesto = -1;
   std::string intro;
   std::cout << "Ingrese el día en el que inicia el año." << std::endl;
   while (diaIni >= 8 || diaIni <= 0) {
      std::cin >> intro;
      diaIni = std::stoi(intro);
   }
   --diaIni;
   std::cout << "Ahora, escriba 1 si es un año bisiesto y 0 si no lo es." << std::endl;
   while (bisiesto < 0 || bisiesto > 1) {
      std::cin >> intro;
      bisiesto = std::stoi(intro);
   }
   int*** calendario = new int**[12];
   // inicializando, 12 meses x 5 semanas x 7 días
   for (int i = 0; i < 12; ++i) {
      *(calendario + i) = new int*[5];
      for (int j = 0; j < 5; ++j) {
	 *(*(calendario + i) + j) = new int[7];
	 for (int k = 0; k < 7; ++k) {
	    *(*(*(calendario + i) + j) + k) = 0;
	 }
      }
   }
   int dia, limMes;
   for (int i = 0; i < 12; ++i) {
      dia = 1;
      switch (i) {
	 case 0: limMes = 31;
	    break;
	 case 1: limMes = 28 + bisiesto;
	    break;
	 case 2: limMes = 31;
	    break;
	 case 3: limMes = 30;
	    break;
	 case 4: limMes = 31;
	    break;
	 case 5: limMes = 30;
	    break;
	 case 6: limMes = 31;
	    break;
	 case 7: limMes = 31;
	    break;
	 case 8: limMes = 30;
	    break;
	 case 9: limMes = 31;
	    break;
	 case 10: limMes = 30;
	    break;
	 case 11: limMes = 31;
	    break;
	    }
      int j = 0, k = 0, pass = 0;
      while (dia <= limMes) {
	 if (pass == 0) {
	    for (int di = 0; di < diaIni; ++di) {
	       ++k;
	    }
	    pass = 1;
	 }
	 if (k >= 7) {
	    k = 0;
	    ++j;
	 }
	 calendario[i][j][k] = dia;
	 ++dia;
	 ++k;
      }
      diaIni = 7 - k; 
   }
   // print time
   for (int i = 0; i < 12; ++i) {
      for (int j = 0; j < 5; ++j) {
	 for (int k = 0; k < 7; ++k) {
            if (calendario[i][j][k] != 0) {
               std::cout << calendario[i][j][k] << " ";
            } else {
	       std::cout << "   ";
	    }
         }
	 std::cout << std::endl;
      }
      std::cout << std::endl;
   }
}
