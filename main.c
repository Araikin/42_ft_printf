/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:14:01 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/21 18:14:58 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
//	int a = 5;

//	printf("char c: %c\n", 'a');
//	printf("char C: %C\n", 'b');

	ft_printf("expected:\tc - x\noutput:\t\tc - %c\n", 'x');

	/*
	printf("orig - string:\t\t%s\n", "hello");
	printf("orig - char:\t\t%55c\n", 'x');
	*/
//	printf("orig - pointer:\t\t%p\n", &a);
	
//	ft_printf("decimal: %d\n", 42);
	//printf("integer: %i\n", 4242);

	//ft_printf("mine - string: %s\n", "hello");
	//ft_printf("mine - char: %c\n", 'x');
		
/* string specifier tests */

	/*
    ft_printf("\nWith width : %-5s %-5s %-5s done", "one", "two", "three");
    ft_printf("\nWith precision : %.3s done", "abcdef");
    ft_printf("\nWith width : %10s done", "abcdef");
    ft_printf("\nWith width and align : %-10s done", "abcdef");
    ft_printf("\nWith width and precision: : %10.3s done", "abcdef");
    ft_printf("\nWith width, align and precision: : %-10.3s done", "abcdef");
    ft_printf("\nWith width and align : %-10s done", "abcdef");
	*/

	/*
    printf("\nWith width : %s %s %s done", "one", "two", "three");
    printf("\nWith precision : %.3s done", "abcdef");
    printf("\nWith width : %10s done", "abcdef");
    printf("\nWith width and precision: : %10.3s done", "abcdef");
    printf("\nWith width, align and precision: : %-10.3s done", "abcdef");

	*/
    /* char */

    /*
    ft_printf("\nWith width, align and precision: : %-5c done", '$');
    ft_printf("\nWith width, align and precision: : %10c done", '$');
    ft_printf("\nWith width, align and precision: : %-10c done", '$');
	*/
	/*
    printf("\nWith width, align and precision: : %c done", '$');
    printf("\nWith width, align and precision: : %10c done", '$');
    printf("\nWith width, align and precision: : %-10c done", '$');
	*/

    /* address */

//    int nb = 2;
	/*
    ft_printf("\nWith width, align and precision: : %-5p done", &nb);
    ft_printf("\nWith width, align and precision: : %25p done", &nb);
    ft_printf("\nWith width, align and precision: : %-25p done", &nb);
	*/
	/*
    printf("\nWith width, align and precision: : %p done", &nb);
    printf("\nWith width, align and precision: : %25p done", &nb);
    printf("\nWith width, align and precision: : %-25p done", &nb);
*/
    /* signed integer */

    /*
    ft_printf("\nWith basic specifier : %-5d done", 42);
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

    /* percent */

    /*
    ft_printf("\nWith width, align and precision: : %% done");
    ft_printf("\nWith width, align and precision: : %10% done");
    ft_printf("\nWith width, align and precision: : %-10% done");
    ft_printf("\nWith multiple specifiers : %% %% %% done");
	*/
	/*
    printf("\nWith width, align and precision: : %% done");
    printf("\nWith width, align and precision: : %10% done");
    printf("\nWith width, align and precision: : %-10% done");
    printf("\nWith multiple specifiers : %% %% %% done");
    char *n = NULL;
    printf("\nWith multiple specifiers : %p done", &n);
*/

    /* Misc. */

	/*
    printf("\noctal : %-5o done", 23);
    printf("\noctal : %-5u done", 23);
    printf("\noctal : %-5.8x done", 23);
    printf("\noctal : %-5.8X done", 23);
    printf("\nunsigned integer : %lu done", 4294967295);
    printf("\nhex lower : %x done", 225);
    printf("\nhex upper : %X done", 225);
    

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
	return (0);
}
