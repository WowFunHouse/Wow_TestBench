#include <stdio.h>

void main(void)
{
	unsigned char 
		ptn[][8]={{0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01},
			{0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80},
			{0x81, 0x81, 0x42, 0x42, 0x24, 0x24, 0x18, 0x18},
			{0x18, 0x18, 0x24, 0x24, 0x42, 0x42, 0x81, 0x81}};

	unsigned char *i, m, o, q, x, y, z;
	unsigned char a[5]={100,101,102,103,104};
	unsigned char p, n;

	for (p = 0; p< 3; p++)
	{
		for (n=0; n< 8; n++)
		{
			printf("ptn[%d][%d]=0x%x\n", p, n, ptn[p][n]);
		}
	}

	x=77;
	y=88;
	z=99;
	m=123;
	o=233;
	q=145;
	i=&y;
	i=&z;
	i=&m;
	i=&o;
	i=&q;
	i+=m;
	printf("&x=%d a=%d &p=%d &n=%d\n", &x, a, &p, &n);
	for (n=0; n<= 10; n++)
	{
		printf("a[%d]=%d\n", n, a[n]);
		printf("a=%d *(a+%d)=%d\n", a, n, *(a+n));
	}
	
	for (n=0; n<40; n++)
	{
		printf("a[%d]=0x%x\n", n, a[n]);
	}
}
