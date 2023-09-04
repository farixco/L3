#include <iostream>

int main() {
   int diaIni, bisiesto;
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
	 case 1: limMes = 28 + bisiesto;
	 case 2: limMes = 31;
	 case 3: limMes = 30;
	 case 4: limMes = 31;
	 case 5: limMes = 30;
	 case 6: limMes = 31;
	 case 7: limMes = 31;
	 case 8: limMes = 30;
	 case 9: limMes = 31;
	 case 10: limMes = 30;
	 case 11: limMes = 31;
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
}
