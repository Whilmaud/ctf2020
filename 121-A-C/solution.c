#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	uint32_t** c;
	c = malloc(11*sizeof(uint32_t*));
	for(int i = 0;i < 11; i++){
		c[i]=malloc(4*sizeof(uint32_t));
	}
	

	//initialisation des c.
	c[0][0] = 0x68636d62;
	c[0][1] = 0x62767278;
	c[0][2] = 0x6f626e65;
	c[0][3] = 0x6e616771;
	c[1][0] = 0x6870666a;
	c[1][1] = 0x7a796f6c;
	c[1][2] = 0x67737477;
	c[1][3] = 0x696c6772;
	c[2][0] = 0x63796a74;
	c[2][1] = 0x76616a72;
	c[2][2] = 0x676a7373;
	c[2][3] = 0x796f6969;
	c[3][0] = 0x786d6965;
	c[3][1] = 0x78756963;
	c[3][2] = 0x79697161;
	c[3][3] = 0x6e6d787a;
	c[4][0] = 0x6777766d;
	c[4][1] = 0x6e747571;
	c[4][2] = 0x656a656b;
	c[4][3] = 0x667a6c75;
	c[5][0] = 0x7a6b6c6a;
	c[5][1] = 0x636c6f69;
	c[5][2] = 0x72747a73;
	c[5][3] = 0x71636d65;
	c[6][0] = 0x6f6c7376;
	c[6][1] = 0x747a7374;
	c[6][2] = 0x71637a63;
	c[6][3] = 0x6e61796d;
	c[7][0] = 0x686e6c74;
	c[7][1] = 0x6266686b;
	c[7][2] = 0x7a6b796c;
	c[7][3] = 0x707a6c66;
	c[8][0] = 0x7476646b;
	c[8][1] = 0x646a7867;
	c[8][2] = 0x75716565;
	c[8][3] = 0x61726c79;
	c[9][0] = 0x75797473;
	c[9][1] = 0x6a756165;
	c[9][2] = 0x706f7474;
	c[9][3] = 0x72627479;
	c[10][0] = 0x6c6e6c69;
	c[10][1] = 0x6d6e7076;
	c[10][2] = 0x7a727375;
	c[10][3] = 0x65766973;
	//pas besoin de c11
/*	c[11][0] = 0x6a787a72;
	c[11][1] = 0x7465756e;
	c[11][2] = 0x73626373;
	c[11][3] = 0x74747368;*/


	//affichage des c
	// for(int i = 0;i < 11;i ++){
	// 	printf("c%d = %x%x%x%x\n",i,c[i][0],c[i][1],c[i][2],c[i][3]);
	// }

	/* rotation des c*/
	uint32_t t1,t2,t3,t4;
	int i = 9;

	/*décalage c10 : 0*/

	/*décalage c9 : 112*/
	// 32 + 32 + 32 + 16 
	t1 = ((c[i][0] & 0x0000ffff) << 16) + ((c[i][1] & 0xffff0000) >> 16);
	t2 = ((c[i][1] & 0x0000ffff) << 16) + ((c[i][2] & 0xffff0000) >> 16);
	t3 = ((c[i][2] & 0x0000ffff) << 16) + ((c[i][3] & 0xffff0000) >> 16);
	t4 = ((c[i][3] & 0x0000ffff) << 16) + ((c[i][0] & 0xffff0000) >> 16);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;
	         
	/*décalage c8 : 125*/
	// 32 + 32 + 32 + 29
	i--;
	int dec= 29;
	uint32_t mask1 = 0x1fffffff;
	uint32_t mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t2 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t3 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t4 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c7 : 126*/
	// 32 + 32 + 32 + 30
	i--;
	dec= 30;
	mask1 = 0x3fffffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t2 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t3 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t4 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c6 : 62*/
	// 32 + 30
	i--;
	dec= 30;
	mask1 = 0x3fffffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t2 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t3 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t4 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c5 : 89*/
	// 32 + 32 + 25
	i--;
	dec= 25;
	mask1 = 0x01ffffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t2 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t3 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t4 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c4 : 16*/
	// 16        
	i--;
	dec= 16;
	mask1 = 0x0000ffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t2 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t3 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t4 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c3 : 108*/
	// 32 + 32 + 32 + 12
	i--;
	dec= 12;
	mask1 = 0x00000fff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t2 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t3 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t4 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c2 : 24*/
	// 24	
	i--;
	dec= 24;
	mask1 = 0x00ffffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t2 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t3 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
	t4 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	c[i][0] = t1;  
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c1 : 51*/
	// 32 + 19
	i--;
	dec= 19;
	mask1 = 0x0007ffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t2 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t3 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t4 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

	/*décalage c0 : 38*/
	// 32 + 6	
	i--;
	dec= 6;
	mask1 = 0x0000003f;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((c[i][2] & mask1) << 32-dec)+ ((c[i][3] & mask2) >> dec);
	t2 = ((c[i][3] & mask1) << 32-dec)+ ((c[i][0] & mask2) >> dec);
	t3 = ((c[i][0] & mask1) << 32-dec)+ ((c[i][1] & mask2) >> dec);
	t4 = ((c[i][1] & mask1) << 32-dec)+ ((c[i][2] & mask2) >> dec);
    c[i][0] = t1;	         
    c[i][1] = t2;	         
    c[i][2] = t3;	         
    c[i][3] = t4;

    //Affichage des c apres rotation.
 //    for(i = 0;i < 11;i ++){
	// 	printf("c%d = %8x%8x%8x%8x\n",i,c[i][0],c[i][1],c[i][2],c[i][3]);
	// }

	uint32_t bigC[4] = {0,0,0,0};

	printf("\n");

    for(i = 0;i < 11;i ++){
		for(int j = 0;j < 4;j ++){
			bigC[j] ^= c[i][j];
		}
	}

	//Affichge c xoré
	//printf("bigC = %8x%8x%8x%8x\n",bigC[0],bigC[1],bigC[2],bigC[3]);

	uint32_t cipher[4] = {0,0,0,0};
	cipher[0] = 0x0fd9e67a;
	cipher[1] = 0x8538d200;
	cipher[2] = 0xa9dab76f;
	cipher[3] = 0xa3abf00a;

	//printf("s = %8x%8x%8x%8x\n",cipher[0],cipher[1],cipher[2],cipher[3]);

	//suppression des c du secret.
	for(int j = 0;j < 4;j ++){
			cipher[j] ^= bigC[j];
	}

	/*décalage s :121*/ // 121 vers la droite == 7 vers la gauche.
	// 32 + 32 + 32 + 25
	dec= 25;
	mask1 = 0x01ffffff;
	mask2 = mask1 ^ 0xffffffff;
	t1 = ((cipher[0] & mask1) << 32-dec)+ ((cipher[1] & mask2) >> dec);
	t2 = ((cipher[1] & mask1) << 32-dec)+ ((cipher[2] & mask2) >> dec);
	t3 = ((cipher[2] & mask1) << 32-dec)+ ((cipher[3] & mask2) >> dec);
	t4 = ((cipher[3] & mask1) << 32-dec)+ ((cipher[0] & mask2) >> dec);
    cipher[0] = t1;	         
    cipher[1] = t2;	         
    cipher[2] = t3;	         
   	cipher[3] = t4;

   	printf("s = %8.8x%8.8x%8.8x%8.8x\n",cipher[0],cipher[1],cipher[2],cipher[3]);

	for(i = 0;i < 11; i++){
		free(c[i]);
	}
	free(c);
	//fclose(f);
	return 0;
}