#include <stdio.h>

#define ADRCHAMPS(v) \
	printf("   .e = %ld\n", (long)&v.e); \
	printf("   .r = %ld\n", (long)&v.r); \
	printf("   .t = %ld\n", (long)&v.t); \
	printf("   .s = %ld\n", (long)&v.s); \
	printf("   .c = %ld\n", (long)&v.c); \


struct idiote {
	int e;
	double r;
	int t[10];
	char *s;
	char c;
};

int main (int argc, char *argv[]) {
	struct idiote v1, v2;

	printf("sizeof(struct idiote) = %lu octets\n",sizeof(struct idiote));
	printf("somme de la taille des champs = %lu octets\n\n",sizeof v1.e + sizeof v1.r + sizeof v1.t + sizeof v1.s + sizeof v1.c);
	printf("&v1   = %ld\n", (long)&v1);
	ADRCHAMPS(v1);
	printf("\n&v2   = %ld\n", (long)&v2);
	ADRCHAMPS(v2);
	printf("\n&v1-&v2 = %ld\n", (long)&v1 - (long)&v2);
	return 0;
}
