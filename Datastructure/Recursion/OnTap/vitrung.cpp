#include <stdio.h>
int So_Vitrung(int vitrung, int sogio){
	if(sogio==0) return vitrung;
	else return So_Vitrung(vitrung,sogio-1)*2;
}
int main(){
	int vitrung, sogio;
	printf("Nhap so vi trung: ");
	scanf("%d", &vitrung);
	printf("Nhap so gio: ");
	scanf("%d", &sogio);
	printf("So vi trung sau %d gio: %d", sogio, So_Vitrung(vitrung,sogio));
}
