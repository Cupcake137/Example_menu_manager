
#ifndef LIB_H
#define LIB_H

typedef struct {
	char name[30];
	int year;
} Sinhvien;

typedef struct {
	float toan;
	float ly;
	float hoa;
} Diemthi;

extern Sinhvien Table_sv[100];
extern Diemthi diem[100];
extern int soSV;
extern int i;

void sua_thong_tin_sv(Sinhvien SV[], Diemthi point[], int n);
void menu_program();

#endif //LIB_H//
