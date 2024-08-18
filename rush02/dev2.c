/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omatyko <omatyko@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:23:37 by omatyko           #+#    #+#             */
/*   Updated: 2024/08/18 13:01:48 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
void my_strcpy(char *dest, const char *src) {
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}
int my_strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
int my_sizearr(char **s1, int size) {
    int count = 0;
    int i = 0;
    while (i < size)
    {
        if (s1[i] != NULL && s1[i][0] != '\0')
        {
            count++;
            }
             i++;
    }
    return count;
}
int get_index(char **keys, char *key)
{
    int     i = 0;
    while (i < my_sizearr(keys, MAX_SIZE)) {
        if (strcmp(keys[i], key) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}
void set(char **keys, char **values,char *key,char *value)
{
    int index = get_index(keys,key);
    int newindex;
    if (index == -1) {
        newindex = my_sizearr(keys, MAX_SIZE);
        my_strcpy(values[newindex], value);
        my_strcpy(keys[newindex], key);
    }
    else {
        my_strcpy(values[index], value);
        my_strcpy(keys[index], key);
    }
}
void printMap(char **keys, char **values)
{
    for (int i = 0; i < my_sizearr(keys, MAX_SIZE); i++) {
        printf("%s: %s\n", keys[i], values[i]);
    }
}
void fill_from_file(char **keys, char **values)
{
set(keys, values, "0", "zero");
set(keys, values, "1", "one");
set(keys, values, "2", "two");
set(keys, values, "3", "three");
set(keys, values, "4", "four");
set(keys, values, "5", "five");
set(keys, values, "6", "six");
set(keys, values, "7", "seven");
set(keys, values, "8", "eight");
set(keys, values, "9", "nine");
set(keys, values, "10", "ten");
set(keys, values, "11", "eleven");
set(keys, values, "12", "twelve");
set(keys, values, "13", "thirteen");
set(keys, values, "14", "fourteen");
set(keys, values, "15", "fifteen");
set(keys, values, "16", "sixteen");
set(keys, values, "17", "seventeen");
set(keys, values, "18", "eighteen");
set(keys, values, "19", "nineteen");
set(keys, values, "20", "twenty");
set(keys, values, "30", "thirty");
set(keys, values, "40", "forty");
set(keys, values, "50", "fifty");
set(keys, values, "60", "sixty");
set(keys, values, "70", "seventy");
set(keys, values, "80", "eighty");
set(keys, values, "90", "ninety");
set(keys, values, "100", "hundred");
set(keys, values, "1000", "thousand");
set(keys, values, "1000000", "million");
set(keys, values, "1000000000", "billion");
set(keys, values, "1000000000000", "trillion");
set(keys, values, "1000000000000000", "quadrillion");
set(keys, values, "1000000000000000000", "quintillion");
set(keys, values, "1000000000000000000000", "sextillion");
set(keys, values, "1000000000000000000000000", "septillion");
set(keys, values, "1000000000000000000000000000", "octillion");
set(keys, values, "1000000000000000000000000000000", "nonillion");
set(keys, values, "1000000000000000000000000000000000", "decillion");
set(keys, values, "1000000000000000000000000000000000000", "undecillion");
}

void inv_array(char *arrchar)
{
    char a_char[38];
    int count;
    int i;
     i = 0;
     count = 0;
    while(arrchar[count] != '\0'){
        a_char[count] = arrchar[count];
    count++;
    }
    while (i < count)
    {
        arrchar[i] = a_char[count - i - 1];
        i++;
    }
    arrchar[i] = '\0';
    
}
void clr_array(char *arrchar)
{
    int count;
    count = 0;
    while(arrchar[count] != '\0'){
        arrchar[count] = '\0';
    count++;
    }
}
    
int     ft_digit(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    i++;
    return i;
}
int    ft_itoa(unsigned long long nb,char *f)
{
        int             i;
         i = 0;
         clr_array(f);
                if (nb < 0)
                    return 1;
                while (nb >= 10)
                {
                        f[i] = '0' + nb % 10;
                        nb = nb / 10;
                        i++;
                }
                
                f[i] = '0' + nb;
		f[i+1]= '\0';
                inv_array(f);
                return (0);
}
void    print_value(char **values, int index)
{
    int i;
    i = 0;
    if (index != -1)
    {
    while (values[index][i] != '\0')
    {
       // printf("%s\n",values[index]);
        write(1, &values[index][i], 1);
        i++;
    }
    }
}
void    print_space(void)
{
    
        write(1, " ", 1);

}
 void ft_tostr(unsigned long long input,char **keys,char **values)
{
    char str_key[38];
    //printf("INPUT = %d\n", input);
	printf("We are in \n");
    ft_itoa(input, str_key);
    if (ft_digit(str_key) == 1)
    {
        print_value(values, get_index(keys,str_key));
    }
    if (ft_digit(str_key) == 2 && input < 20)
    {
        print_value(values, get_index(keys,str_key));
    }
    if (ft_digit(str_key) == 2 && input > 19 && input < 100 && input % 10 == 0)
    {
        print_value(values, get_index(keys,str_key));
    }
        if (ft_digit(str_key) == 2 && input > 19 && input < 100 && input % 10 != 0)
    {
       ft_itoa((input / 10) * 10, str_key);
       print_value(values, get_index(keys,str_key));
       print_space();
       ft_itoa(input % 10, str_key);
       print_value(values, get_index(keys,str_key));
    }
    if (ft_digit(str_key) == 3 )
    {
       ft_itoa((input / 100) , str_key);
       print_value(values, get_index(keys,str_key));
       print_space();
       print_value(values, get_index(keys,"100"));
       print_space();
       //printf("\n%d\n", );
       if (input % 100 != 0)
       ft_tostr(input % 100, keys, values);
        
    }
    if (ft_digit(str_key) == 4 )
    {
       ft_itoa((input / 1000) , str_key);
       print_value(values, get_index(keys,str_key));
       print_space();
       print_value(values, get_index(keys,"1000"));
       print_space();
      // printf("\n%d\n", input % 1000);
       if (input % 1000 != 0)
       ft_tostr(input % 1000, keys, values);
        
    }
    if (ft_digit(str_key) == 5 || ft_digit(str_key) == 6 )
    {
        //printf("5 = %d\n",input / 1000 );
        ft_tostr(input / 1000, keys, values);
       //ft_itoa((input / 1000) , str_key);
       //print_value(values, get_index(keys,str_key));
       print_space();
       print_value(values, get_index(keys,"1000"));
       print_space();
       //printf("\n%d\n", );
       if (input % 1000 != 0)
       ft_tostr(input % 1000, keys, values);
        
    }
        if (ft_digit(str_key) == 7 || ft_digit(str_key) == 8 || ft_digit(str_key) == 9 )
    {
        //printf("5 = %d\n",input / 1000 );
        ft_tostr(input / 1000000, keys, values); //print one
        print_space();
        print_value(values, get_index(keys,"1000000")); //print million
        print_space();
       if (input % 1000000 != 0)
       ft_tostr(input % 1000000, keys, values);
        
    }
    if (ft_digit(str_key) >= 10 && ft_digit(str_key) <= 12)
    {
        printf("TEST \n");
        ft_tostr(input / 1000000000, keys, values);
        print_space();
        print_value(values, get_index(keys, "1000000000"));
        if (input % 1000000000 != 0)
        {
            print_space();
            ft_tostr(input % 1000000000, keys, values);
        }
    }
    if (ft_digit(str_key) >= 13 && ft_digit(str_key) <= 15)
    {
        ft_tostr(input / 1000000000000, keys, values);
        print_space();
        print_value(values, get_index(keys, "1000000000000"));
        if (input % 1000000000000 != 0)
        {
            print_space();
            ft_tostr(input % 1000000000000, keys, values);
        }
    }
	if (ft_digit(str_key) >= 16 && ft_digit(str_key) <= 18)
    {
	printf("TEST TEST 18 /n");
        ft_tostr(input / 1000000000000000, keys, values);
        print_space();
        print_value(values, get_index(keys, "1000000000000000"));
        if (input % 1000000000000000 != 0)
        {
            print_space();
            ft_tostr(input % 1000000000000000, keys, values);
        }
    }
	if (ft_digit(str_key) >= 19 && ft_digit(str_key) <= 21)
    {
	printf("TEST TEST 21 /n");
        ft_tostr(input / 1000000000000000000, keys, values);
        print_space();
        print_value(values, get_index(keys, "1000000000000000000"));
        if (input % 1000000000000000000 != 0)
        {
            print_space();
            ft_tostr(input % 1000000000000000000, keys, values);
        }
    }
    

}


int main(int argc, char **argv) 
{
    //char str_key[33];
    unsigned long long input;
    //char    *ptr;
	/*if(argc == 2)
		input = atoi(argv[1]);
	else
	return (0);
*/
    input = 5000000000000000;
    char **keys = malloc(MAX_SIZE * sizeof(char *));
    char **values = malloc(MAX_SIZE * sizeof(char *));
    if (keys == NULL || values == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
     for (int i = 0; i < MAX_SIZE; i++) {
        keys[i] = malloc(52 * sizeof(char));
        values[i] = malloc(50 * sizeof(char));
        if (keys[i] == NULL || values[i] == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
    }
    
    /********************************************************/
    fill_from_file(keys, values);

    ft_tostr(input, keys, values);

    /*********************************************************/
    for (int i = 0; i < MAX_SIZE; i++) {
        free(keys[i]);
        free(values[i]);
    }
    free(keys);
    free(values);
    return (0);
}
