/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:01 by asultanb          #+#    #+#             */
/*   Updated: 2019/12/05 17:35:08 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
//	float n = 6;

	printf("o: %.12f\n", 19.123456789);
	ft_printf("m: %.12f\n", 19.123456789);

	//printf("%i\n", ft_printf("%+5.f", 19.99)); 
	//printf("%i\n", printf("%+5.f", 19.99)); 

    /* Misc. */

	/*
	ft_printf("m:%d\n", 34);
	printf("o:%d\n", 34);

    printf("\noctal : %-5o done", 23);
    ft_printf("\noctal : %-5o done", 23);
    printf("\noctal : %-5u done", 23);
    ft_printf("\noctal : %-5u done", 23);
    printf("\noctal : %-5.8x done", 23);
    ft_printf("\noctal : %-5.8x done", 23);
    printf("\nunsigned integer : %lu done", 4294967295);
    ft_printf("\nunsigned integer : %lu done", 4294967295);
    printf("\nhex lower : %x done", 225);
    ft_printf("\nhex lower : %x done", 225);
    printf("\nhex upper : %X done", 225);
    ft_printf("\nhex upper : %X done", 225);
	*/
    
    /* percent */

	/*
	printf("%%\n");
	ft_printf("%%\n");
    ft_printf("\nWith width, align and precision: : %% done");
    ft_printf("\nWith width, align and precision: : %10% done");
    ft_printf("\nWith width, align and precision: : %-10% done");
    ft_printf("\nWith multiple specifiers : %% %% %% done");

    printf("\nWith width, align and precision: : %% done");
    printf("\nWith width, align and precision: : %10% done");
    printf("\nWith width, align and precision: : %-10% done");
    printf("\nWith multiple specifiers : %% %% %% done");
	*/

	/*
    // flag '0' is ignored when flag '-' is present
    printf("\nsigned integer : %+020d done", 225);
    printf("\nsigned integer : %025.20d done", 1);
    printf("\nsigned integer : %05d done", 1);
    printf("\nsigned integer : %0+5d done", 1);
    printf("\nsigned integer : %-25.20d done", 225);
    printf("\nsigned integer : %.20d done", 1);
    printf("\nsigned integer : %+5d done", 42);
    printf("\nsigned integer : %0+5d done", 42);
    printf("\nsigned integer : %-d done", -42);
*/
    /*
    ft_printf("\noctal : %#o done", 2);
    ft_printf("\noctal : %#.5o done", 2);
    ft_printf("\noctal : %#0.5o done", 2);
    ft_printf("\noctal : %#.7o done", 2);
    ft_printf("\noctal : %#0.7o done", 2);
	*/
	/*
    printf("\noctal : %#o done", 2);
    printf("\noctal : %#.5o done", 2);
    printf("\noctal : %#0.5o done", 2);
    printf("\noctal : %#.7o done", 2);
    printf("\noctal : %#0.7o done", 2);
*/
	/*
	ft_printf("\nupper hex : %0-8.3X", 8375);
    ft_printf("hello, %s.", NULL);
    ft_printf("%-5c end\n", '\x00');
    ft_printf("%5c end\n", '\x00');
    ft_printf("%f\n", 3.14);
    ft_printf("%lf\n", 3.14);
    ft_printf("%b\n", 255a);
    ft_printf("%08b\n", 127);
    ft_printf("%.8b\n", 127);
    ft_printf("%-8b\n", 1);
    ft_printf("%8b\n", 1);
    ft_printf("%lld", (int64_t)9223372036854775808); //too large to be represented in signed integer type
	*/
	/*
    printf("\nupper hex : %08.3X", 8375);
    char *str = ft_strdup("\x00");
    printf("%s\n", str);
    printf("%-5c end\n", '\x00');
    printf("%5c end\n", '\x00');
    printf("%0c", '\x00'); // undefined behavior
    printf("%lld", -9223372036854775808); //too large to be represented in signed integer type
*/


   /* signed integer */

	/*
    ft_printf("m:%.0d\n", 0);
    printf("o:%.0d\n", 0);

    ft_printf("\nWith basic specifier length l applied : %ld done", (long int)-2147483647);
    ft_printf("\nWith basic specifier length h applied : %hd done", (short int)-32767);
    ft_printf("\nWith basic specifier length ll applied : %lld done", (long long int)9223372036854775807);
    ft_printf("\nWith basic specifier length hh applied : %hhd done", (signed char)-127);
	*/

	/*
    printf("\nWith basic specifier : %d done", 42);
    printf("\nWith basic specifier length l applied : %ld done", (long int)-2147483647);
    printf("\nWith basic specifier length h applied : %hd done", (short int)-32767);
    printf("\nWith basic specifier length ll applied : %lld done", (long long int)9223372036854775807);
    printf("\nWith basic specifier length hh applied : %hhd done", (signed char)-127);
	*/


    /*
    ft_printf("\nWith basic specifier and precision : %d done", 42);
    ft_printf("\nWith basic specifier and precision : %.10d done", 42);
	*/
	/*
    printf("\nWith basic specifier and precision : %d done", 42);
    printf("\nWith basic specifier and precision : %.10d done", 42);
*/

    /*
    ft_printf("\nWith basic specifier and precision : %+d done", 42);
    ft_printf("\nWith basic specifier and precision : %+d done", -42);
    ft_printf("\nWith basic specifier and precision : % d done", 42);
	*/
	/*
    printf("\nWith basic specifier and precision : %+d done", 42);
    printf("\nWith basic specifier and precision : %+d done", -42);
    printf("\nWith basic specifier and precision : % d done", 42);
*/
	/*
    ft_printf("\nWith basic specifier, width, plus : %+5d done", 42);
    ft_printf("\nWith basic specifier, width, plus : %+5d done", -42);
    ft_printf("\nWith basic specifier, width, space : % d done", 42);
    ft_printf("\nWith basic specifier, width, space : %+.10d done", 42);
    ft_printf("\nWith basic specifier, width, space : %+5.8d done", 42);
    ft_printf("\nWith basic specifier, width, space : % 5.8d done", 42);
    ft_printf("\nWith basic specifier, width, space : %05d done", 42);
	*/

	/*
    printf("\nWith basic specifier, width, plus : %+5d done", 42);
    printf("\nWith basic specifier, width, plus : %+5d done", -42);
    printf("\nWith basic specifier, width, space : % d done", 42);
    printf("\nWith basic specifier, width, space : %+.10d done", 42);
    printf("\nWith basic specifier, width, space : %+5.8d done", 42);
    printf("\nWith basic specifier, width, space : % 5.8d done", 42);
    printf("\nWith basic specifier, width, space : %05d done", 42);
*/



    /* address */
/*
    int nb = 2;

	//ft_printf("%9.2p\n", &nb);
	printf("%.0p\n", 0);
	ft_printf("%.0p\n", 0);
//	ft_printf("%020.15p\n", &nb);
	//ft_printf("%-17p\n", &nb);
	//printf("%-.15p\n", &nb);
    printf("With width, align and precision: : %25p done\n", &nb);
    ft_printf("With width, align and precision: : %25p done\n", &nb);
    printf("%i\n", printf("%p\n", &nb));
    printf("%i\n", ft_printf("%p\n", &nb));

    printf("With width, align and precision: : %-25p done\n", &nb);
    printf("With width, align and precision: : %025p done\n", &nb);
    printf("With width, align and precision: : %p done\n", &nb);
    printf("With width, align and precision: : %015.17p done\n", &nb);
    ft_printf("\nWith width, align and precision: : %-5p done", &nb);
    ft_printf("\nWith width, align and precision: : %25p done", &nb);
    ft_printf("\nWith width, align and precision: : %-25p done", &nb);
	*/
 
/* string specifier tests */

	/*
	static char *s_hidden = "hi low\0don't print me lol\0";

	printf("%+ 3s\n", s_hidden);
	ft_printf("%+ 3s\n", s_hidden);
	ft_printf("%32s\n", NULL);
	printf("%32s\n", NULL);
	ft_printf("%.0s\n", "hello");
	printf("%.0s\n", "hello");
	ft_printf("%.s\n", "hello");
	printf("%.s\n", "hello");
    ft_printf("With width and align : %-10s done\n", "abcdef");
    printf("With width and align : %-10s done\n", "abcdef");
    ft_printf("With width, align and precision: : %-10.3s done\n", "abcdef");
    printf("With width, align and precision: : %-10.3s done\n", "abcdef");
    ft_printf("With width and precision: : %10.3s done\n", "abcdef");
    printf("With width and precision: : %10.3s done\n", "abcdef");
    ft_printf("With width and align : %-10s done\n", "abcdef");
    printf("With width and align : %-10s done\n", "abcdef");
    ft_printf("With width : %10s done\n", "abcdef");
    printf("With width : %10s done\n", "abcdef");
    printf("With width : %-5s %-5s %-5s done\n", "one", "two", "three");
    ft_printf("With width : %-5s %-5s %-5s done\n", "one", "two", "three");
    printf("With precision : %.3s done\n", "abcdef");
    ft_printf("With precision : %.3s done\n", "abcdef");
	*/

    /* char */

	/*
    ft_printf("With width, align and precision: : %c done\n", '$');
    printf("With width, align and precision: : %c done\n", '$');
    ft_printf("With width, align and precision: : %-10c done\n", '$');
    printf("With width, align and precision: : %-10c done\n", '$');
    ft_printf("With width, align and precision: : %10c done\n", '$');
    printf("With width, align and precision: : %10c done\n", '$');
    ft_printf("With width, align and precision: : %-5c done\n", '$');
    printf("With width, align and precision: : %-5c done\n", '$');
	*/
	return (0);
}
