#include <iostream>

int main() {
   int diaIni, bisiesto = -1;
   std::string intro;
   std::cout << "Ingrese el (número del) día en el que inicia el año. Rango aceptable: 1 a 7." << std::endl;
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
   // inicializando, 12 meses x 6 semanas x 7 días
   for (int i = 0; i < 12; ++i) {
      *(calendario + i) = new int*[6];
      for (int j = 0; j < 6; ++j) {
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
      if (k < 7) {
	 diaIni = k;
      } else {
	 diaIni = 0;
      }
   }
   // print time
   for (int i = 0; i < 12; ++i) {
      switch (i) {
	 case 0: std::cout << "Enero" << std::endl;
	    break;
	 case 1: std::cout << "Febrero" << std::endl;
	    break;
	 case 2: std::cout << "Marzo" << std::endl;
	    break;
	 case 3: std::cout << "Abril" << std::endl;
	    break;
	 case 4: std::cout << "Mayo" << std::endl;
	    break;
	 case 5: std::cout << "Junio" << std::endl;
	    break;
	 case 6: std::cout << "Julio" << std::endl;
	    break;
	 case 7: std::cout << "Agosto" << std::endl;
	    break;
	 case 8: std::cout << "Septiembre" << std::endl;
	    break;
	 case 9: std::cout << "Octubre" << std::endl;
	    break;
	 case 10: std::cout << "Noviembre" << std::endl;
	    break;
	 case 11: std::cout << "Diciembre" << std::endl;
	    break;
      }
      for (int j = 0; j < 6; ++j) {
	 for (int k = 0; k < 7; ++k) {
            if (calendario[i][j][k] >= 10) {
               std::cout << calendario[i][j][k] << " ";
            } else if (calendario[i][j][k] < 10 && calendario[i][j][k] > 0) {
	       std::cout << " " << calendario[i][j][k] << " ";
	    } else {
	       std::cout << "   ";
	    }
         }
	 std::cout << std::endl;
      }
      std::cout << std::endl;
   }
}
