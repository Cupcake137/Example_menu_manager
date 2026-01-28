#include <stdio.h>
#include <string.h>
#include "lib.h"

Sinhvien Table_sv[100];
Diemthi diem[100];
int soSV;
int i;
int msv;
int diemTB;
int choice;

void sua_thong_tin_sv(Sinhvien SV[], Diemthi point[], int n) {
	int msv;
	
	printf("Nhap so thu tu (STT) sv can sua: ");
    scanf("%d", &msv);
	
	if (msv > n || msv <= 0) {
		printf("Sinh vien ko ton tai!\n");
		//return 1;
	}
	else {
		int index = msv - 1;
		
		printf("--- Sua thong tin cho sv[%d]---\n", msv);
		
		printf("Ten cu: %s. Ten moi can sua cua sv[%d]: ", SV[index].name, msv);
		fflush(stdin);
		gets(SV[index].name);
		
		printf("Tuoi cu: %d. Tuoi moi can sua cua sv[%d]: ", SV[index].year, msv);
		scanf("%d", &SV[index].year);
		
		printf("Ten cua sv[%d] da sua thanh: %s\n", msv, SV[index].name);
		
		printf("Tuoi cua sv[%d] da sua thanh: %d\n", msv, SV[index].year);
		
		printf("Diem toan cu: %.2f. Diem toan moi can sua cua sv[%d]: ", point[index].toan, msv);
		scanf("%f", &point[index].toan);
		
		printf("Diem ly cu: %2.f. Diem ly moi can sua cua sv[%d]: ", point[index].ly, msv);
		scanf("%f", &point[index].ly);
		
		printf("Diem hoa cu: %.2f. Diem hoa moi can sua cua sv[%d]: ", point[index].hoa, msv);
		scanf("%f", &point[index].hoa);
		
		printf("Diem toan cua sv[%d] da sua thanh: %.2f\n", msv, point[index].toan);
		
		printf("Diem ly cua sv[%d] da sua thanh: %.2f\n", msv, point[index].ly);
		
		printf("Diem hoa cua sv[%d] da sua thanh: %.2f\n", msv, point[index].hoa);
	}
	//return 0;
}

/*
void sua_diem(Diemthi point[], Sinhvien SV[], int n) {
	int msv;
	int index = msv - 1;
	
	printf("Nhap so thu tu (STT) sv can sua diem: ");
    scanf("%d", &msv);
    
    if (msv > n || msv <= 0) {
		printf("Sinh vien ko ton tai!\n");
		//return 1;
	}
	else {
		printf("Diem toan cu: %d. Diem toan moi can sua cua sv[%d]: ", SV[index].year, msv);
		scanf("%f", &point[index].toan);
		
		printf("Diem ly cu: %d. Diem ly moi can sua cua sv[%d]: ", SV[index].year, msv);
		scanf("%f", &point[index].ly);
		
		printf("Diem hoa cu: %d. Diem hoa moi can sua cua sv[%d]: ", SV[index].year, msv);
		scanf("%f", &point[index].hoa);
		
		printf("Diem toan cua sv[%d] da sua thanh: %.2f\n", msv, point[index].toan);
		
		printf("Diem ly cua sv[%d] da sua thanh: %.2f\n", msv, point[index].ly);
		
		printf("Diem hoa cua sv[%d] da sua thanh: %.2f\n", msv, point[index].hoa);
	}
}
*/

void menu_program(int choice) {
	do {
        system("cls"); 
        
        printf("================ MENU QUAN LY SINH VIEN ================\n");
        printf("| 1. Nhap danh sach sinh vien va diem                  |\n");
        printf("| 2. Hien thi danh sach                                |\n");
        printf("| 3. Tinh diem Trung Binh                              |\n");
        printf("| 4. Sua thong tin sinh vien                           |\n");
        printf("| 5. Sap xep diem thi sinh vien tang dan               |\n");
        printf("| 6. Xep loai hoc luc sinh vien                        |\n");
        printf("| 0. Thoat chuong trinh                                |\n");
        printf("========================================================\n");
        printf("Moi ban chon chuc nang (0-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- BAN CHON CHUC NANG NHAP LIEU ---\n");
                
                printf("Nhap so sv: ");
				scanf("%d", &soSV);
				
				printf("--- Nhap thong tin cua sv: ---\n");
				for(i = 0; i < soSV; i++){
					printf("Nhap Ten cua sv[%d]: ", i+1);
					fflush(stdin);
					gets(Table_sv[i].name);
					
					printf("Nhap Tuoi cua sv[%d]: ", i+1);
					scanf("%d", &Table_sv[i].year);
					
					printf("Nhap diem toan cua sv[%d]: ", i+1);
					scanf("%f", &diem[i].toan);
					
					printf("Nhap diem ly cua sv[%d]: ", i+1);
					scanf("%f", &diem[i].ly);
					
					printf("Nhap diem hoa cua sv[%d]: ", i+1);
					scanf("%f", &diem[i].hoa);
				}
                break;
            
            case 2:
                printf("\n--- DANH SACH SINH VIEN ---\n");
                
				for(i = 0; i < soSV; i++){
					printf("Ten cua sv[%d]: %s\n", i+1, Table_sv[i].name);
					
					printf("Tuoi cua sv[%d]: %d\n", i+1, Table_sv[i].year);
					
					if (diem[i].toan < 0 || diem[i].toan > 10 || 
			    		diem[i].hoa  < 0 || diem[i].hoa  > 10 || 
			    		diem[i].ly   < 0 || diem[i].ly   > 10) {
						printf("So diem khong hop le, vui long nhap lai !!!\n");
						
						while (1) {
							printf("----------------\n");
							printf("Nhap diem sai cu phap, vui long nhap lai: \n");
							
							printf("Nhap lai diem toan cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].toan);
						
							printf("Nhap lai diem ly cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].ly);
							
							printf("Nhap lai diem hoa cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].hoa);
							
							if (diem[i].toan >= 0 && diem[i].toan <= 10 && 
							    diem[i].ly   >= 0 && diem[i].ly   <= 10 && 
							    diem[i].hoa  >= 0 && diem[i].hoa  <= 10) {
				    			break;
							}
						}
					} 
					else {
						printf("Diem toan cua sv[%d]: %.2f\n", i+1, diem[i].toan);
						
						printf("Diem ly cua sv[%d]: %.2f\n", i+1, diem[i].ly);
						
						printf("Diem hoa cua sv[%d]: %.2f\n", i+1, diem[i].hoa);
						
						printf("----------------\n");
					}
				}
                break;

            case 3:
                printf("\n--- TINH DIEM TRUNG BINH ---\n");
                for (i = 0; i < soSV; i++){
                	if (diem[i].toan < 0 || diem[i].toan > 10 || 
			    		diem[i].hoa  < 0 || diem[i].hoa  > 10 || 
			    		diem[i].ly   < 0 || diem[i].ly   > 10) {
						printf("So diem khong hop le, vui long nhap lai !!!\n");
						
						while (1) {
							printf("----------------\n");
							printf("Nhap diem sai cu phap, vui long nhap lai: \n");
							
							printf("Nhap lai diem toan cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].toan);
						
							printf("Nhap lai diem ly cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].ly);
							
							printf("Nhap lai diem hoa cua sv[%d] (0 < diem <10): ", i+1);
							scanf("%f", &diem[i].hoa);
							
							if (diem[i].toan >= 0 && diem[i].toan <= 10 && 
							    diem[i].ly   >= 0 && diem[i].ly   <= 10 && 
							    diem[i].hoa  >= 0 && diem[i].hoa  <= 10) {
				    			break;
							}
						}
					}
                	printf("----------------\n");
                	
	                printf("Diem toan cua sv[%d]: %.2f\n", i+1, diem[i].toan);
							
					printf("Diem ly cua sv[%d]: %.2f\n", i+1, diem[i].ly);
							
					printf("Diem hoa cua sv[%d]: %.2f\n", i+1, diem[i].hoa);
	                
	                diemTB = (diem[i].toan + diem[i].hoa + diem[i].ly) / 3; 
	                
					printf("Diem TB 3 mon toan, ly, hoa cua sv[%d]: %.2f\n", i+1, diemTB);
				}
                break;

            case 4:
                printf("\n--- SUA THONG TIN ---\n");
                
                sua_thong_tin_sv(Table_sv, diem, soSV);
                //sua_diem(diem, Table_sv, soSV);
                break;
			
			case 5:
				printf("\n--- THU TU DIEM ---\n");
				break;
				
			case 6:
				printf("\n--- XEP LOAI ---\n");
				break;
				
            case 0:
                printf("Dang thoat chuong trinh...\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon lai.\n");
        }

        if (choice != 0) {
            printf("\nBam phim bat ky de quay lai Menu...");
            fflush(stdin); 
            getchar();
        }
    } while (choice != 0);
}
