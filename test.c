#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	ft_printf("%c%c%c\n", 'a', '\t', 'b');
	printf("%c%c%c\n", 'a', '\t', 'b');
	ft_printf("%cc%cc%c\n", 'a', '\t', 'b');
	printf("%cc%cc%c\n", 'a', '\t', 'b');
	ft_printf("%cs%cs%c\n", 'c', 'b', 'a');
	printf("%cs%cs%c\n", 'c', 'b', 'a');
	ft_printf("%s%s%s\n", "And ", "some", "joined");
	printf("%s%s%s\n", "And ", "some", "joined");
	ft_printf("%ss%ss%ss\n", "And ", "some other", "joined");
	printf("%ss%ss%ss\n", "And ", "some other", "joined");
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	printf("%pp%p%p\n", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	ft_printf("%d%dd%d\n", 1, 2, -3);
	printf("%d%dd%d\n", 1, 2, -3);
	ft_printf("%i%ii%i\n", 1, 2, -3);
	printf("%i%ii%i\n", 1, 2, -3);
	ft_printf("%u%uu%u\n", 1, 2, -3);
	printf("%u%uu%u\n", 1, 2, -3);
	ft_printf("%x\n", -10);
	printf("%x\n", -10);
	ft_printf("%x\n", -200000);
	printf("%x\n", -200000);
	ft_printf("%x\n", -6000023);
	printf("%x\n", -6000023);
	ft_printf("%x\n", 10000);
	printf("%x\n", 10000);
	ft_printf("%x\n", 100023);
	printf("%x\n", 100023);
	ft_printf("%x\n", 0xabcdef);
	printf("%x\n", 0xabcdef);
	ft_printf("%x\n", 0x7fedcba1);
	printf("%x\n", 0x7fedcba1);
	ft_printf("%x\n", INT_MAX);
	printf("%x\n", INT_MAX);
	ft_printf("%x\n", INT_MIN);
	printf("%x\n", INT_MIN);
	ft_printf("%x\n", INT_MIN);
	printf("%x\n", INT_MIN);
	ft_printf("%x\n", UINT_MAX);
	printf("%x\n", UINT_MAX);
	ft_printf("%x\n", UINT_MAX);
	printf("%x\n", UINT_MAX);
	ft_printf("%x%xx%x\n", 1, 2, -3);
	printf("%x%xx%x\n", 1, 2, -3);
	ft_printf("%x%xx%x\n", 1, 2, -3);
	printf("%x%xx%x\n", 1, 2, -3);
	ft_printf("%X\n", -10);
	printf("%X\n", -10);
	ft_printf("%X\n", -10);
	printf("%X\n", -10);
	ft_printf("%X\n", -200000);
	printf("%X\n", -200000);
	ft_printf("%X\n", -200000);
	printf("%X\n", -200000);
	ft_printf("%X\n", -6000023);
	printf("%X\n", -6000023);
	ft_printf("%X\n", -6000023);
	printf("%X\n", -6000023);
	ft_printf("%X\n", 10000);
	printf("%X\n", 10000);
	ft_printf("%X\n", 100023);
	printf("%X\n", 100023);
	ft_printf("%X\n", 0xabcdef);
	printf("%X\n", 0xabcdef);
	ft_printf("%X\n", 0x7fedcba1);
	printf("%X\n", 0x7fedcba1);
	ft_printf("%X\n", INT_MAX);
	printf("%X\n", INT_MAX);
	ft_printf("%X\n", INT_MIN);
	printf("%X\n", INT_MIN);
	ft_printf("%X\n", INT_MIN);
	printf("%X\n", INT_MIN);
	ft_printf("%X\n", UINT_MAX);
	printf("%X\n", UINT_MAX);
	ft_printf("%X\n", UINT_MAX);
	printf("%X\n", UINT_MAX);
	ft_printf("%X%Xx%X\n", 1, 2, -3);
	printf("%X%Xx%X\n", 1, 2, -3);
	ft_printf("%X%Xx%X\n", 1, 2, -3);
	printf("%X%Xx%X\n", 1, 2, -3);
	ft_printf("h/qUU3\%djW,c%s6!CXm `%%0%s!-}HQ-hR%X>SE9D%d\nYHf\fhv\n", 1975350964, "+8{]R\vX#b/\vzjM\nc\f)(M-EPdPt0O;'Y-Qe[vkL", "_\rth\\cK{:\f/)l_Jbu78Xb&U:mE]1OtjVJzkv6W\n4NIUW-,OS(gn(SHMrSU%)0V", 474024541, -773222926);
	printf("h/qUU3\%djW,c%s6!CXm `%%0%s!-}HQ-hR%X>SE9D%d\nYHf\fhv\n", 1975350964, "+8{]R\vX#b/\vzjM\nc\f)(M-EPdPt0O;'Y-Qe[vkL", "_\rth\\cK{:\f/)l_Jbu78Xb&U:mE]1OtjVJzkv6W\n4NIUW-,OS(gn(SHMrSU%)0V", 474024541, -773222926);
    return 0;
}

	/* char	*s1;
	s1 = "Areté";
	s2 = "Areté";
	s3 = "Areté";
	ft_printf("Test 2: just POINTERS\n");
	ft_printf("Caracteres impresos: %d\n",ft_printf("Test 2: just POINTERS\n"));
	ft_printf("Areté = %p. Areté = %p. Areté = %%.\n\n\n", s1, s2, s3);
	ft_printf("Caracteres impresos: %d\n",ft_printf("Areté = %p. Areté =
			%p. Areté = %%.\n\n\n", s1, s2, s3));
	printf("printf: Areté = %p. Areté = %p. Areté = %p.\n\n\n", s1, s2, s3);
	printf("printf caracteres impresos: %d\n",ft_printf("Areté = %p. Areté =
			%p. Areté = %%.\n\n\n", s1, s2, s3));
	a = 123;
	b = 456;
	c = 0;
	ft_printf("Test 1: just zero.\n");
	ft_printf("Caracteres impresos: %d\n",ft_printf("Test 2: just POINTERS\n"));
	printf("printf caracteres impresos:
		%d\n",ft_printf("Test 2: just POINTERS\n"));
	ft_printf("Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c);
	ft_printf("Caracteres impresos: %d\n",ft_printf("Areté. %x Areté. %x Areté.
			%x\n\n\n", a, b, c));
	printf("printf: Areté. %x Areté. %x Areté. %x\n\n\n", a, b, c);
	printf("printf caracteres impresos: %d\n",ft_printf("Areté. %x Areté.
			%x Areté. %x\n\n\n", a, b, c)); */
	/* 	ft_printf("Test 2: All\n");
		ft_printf("Areté = %X. Areté = %d. Areté = %d.\n\n\n", a, b, c); */
	/* 	long		n;
		n = 0;
		p = &n;
		ft_printf("Test 1: n = 0\n");
		ft_hexa(n, "x");
		ft_printf("\n\n\n");
		ft_printf("Test 2: n = 287\n");
		n = 287;
		ft_hexa(n, "x");
		ft_printf("\n\n\n");
		ft_printf("Test 3: n = 9001\n");
		n = 9001;
		ft_hexa(n, "x");
		ft_printf("\n\n\n");
		ft_printf("Test 4: n = 99\n");
		n = 99;
		ft_hexa(n, "x");
		ft_printf("\n\n\n");
		ft_printf("Test 5: n = long\n");
		ft_hexa((long)p, "x");
			ft_printf("\n\n\n");
		ft_printf("Test 6: n = pointer\n");
		printf("Pointer address: %p Integer address: %ld\n", p, (long)p);
		return(0); */
 /* 	s1 = "Areté";
	s2 = "Areté";
	s3 = "Areté";
	a = -2147483648;
	b = 456;
	c = 0;
	ft_printf("Test 1: just text.\n");
	ft_printf("Areté. Areté. Areté.\n\n\n");
	ft_printf("Test 2: just strings\n");
	ft_printf("Areté = %s. Areté = %s. Areté = %s.\n\n\n", s1, s2, s3);
	ft_printf("Test 3: just integers\n");
	ft_printf("Areté = %d. Areté = %d. Areté = %%.\n\n\n", a, b, c); */
