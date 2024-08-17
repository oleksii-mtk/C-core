/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maywong <maywong@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:23:26 by maywong           #+#    #+#             */
/*   Updated: 2024/08/17 21:30:28 by omatyko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LINE 1000
#define MAX_LEN 255

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	//ft_putchar('\n');
}

int	is_space(int c)
{
	if (c == 10)
		return (0);
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

void	ft_get_key_value_(char *buf)
{
	int     n;
        int     col_n;
        int     sp_n;
	int	end_n;
	int	i;
	char	*key;
	char 	*value;
	int is_key;

//	printf("\n%s\n", buf);
	i = 0;
	is_key = 0;

	n = 0;

	while (buf[i] != '\0')
	{
		if (is_space(buf[i]))
			i++;
		else
		{
			if (is_key == 0)
				is_key = 1;
			if (buf[i] != ':')
			{
				if (is_key == 2)
					value[n] = buf[i];
				if (is_key == 1)
					key[n] = buf[i];
				
				n++;

			}
			if (buf[i] == ':')
			{
				is_key = 2;
				n = 0;
				key[n] = '\0';
			}
			if (buf[i] == '\n')
			{
				value[n] = '\0';
				printf(" %s", key);
				printf(" %s", value);
				n = 0;
				is_key = 0;
				return ;
			}
			i++;
		}
	
	}

/*
	n = 0;
	while (buf[n] && (buf[n] == ':' || buf[n] == 32))
	{
		if (buf[n] == ':')
			col_n = n - 1;
		else if (buf[n] == 32)
			sp_n = n + 1;
		n++;
	}
	if (buf[n] == '\0')
		end_n = n - 1;
		*/
}

void print_array(char *arr)
{
	while (*arr != '\0')
	{
		write(1, arr, 1);
		arr++;
	}
}

void clear_array(char *arr)
{
        while (*arr != '\0')
        {
                *arr = '\0';
                arr++;
        }
}


int    ft_get_key_value(char *buf)
{
        int     n;
        int     col_n;
        int     sp_n;
        int     end_n;
        int     i;
        char    *key;
	char    *value;
        int is_key;


        i = 0;
	while (buf[i] != '\n')
		i++;
	key = (char*)malloc(i*sizeof(char));
	value = (char*)malloc(i*sizeof(char));
	if (key == NULL || value == NULL)
	{
		return (1);
	}

	i = 0;
        is_key = 0;

//	clear_array(key);
//	clear_array(value);
        n = 0;
        while (buf[i] != '\n')
        {
              if (is_space(buf[i]) == 0)
                {
                        if (is_key == 0)
                                is_key = 1;
			
                        if (buf[i] != ':' )
                        {
            
                                if (is_key == 2)
			               value[n] = buf[i];
			        if (is_key == 1)
			                key[n] = buf[i];
			           n++;
                        }
                        if (buf[i] == ':')
                        {
                                is_key = 2;
                                
				key[n] = '\0';
				n = 0;
                        }
                 
                }
              
                i++;
        }

	value[n] = '\0';
	
        printf("\n %s", key);
       printf("\n %s", value);

	free(key);
	free(value);
	return (0);
}


/*
void	ft_set_key(char *buf, int col_n)
{
	int	n = 0;
	//char	key[];
	
	ft_putstr("Key : ");
	while (n <= col_n || is_space(buf[n] == 0))
	{
		ft_putchar(buf[n]);
		//key = buf[n];	
		n++;
	}
	ft_putchar('\n');
}

void	ft_set_value(char *buf, int sp_n)
{
	int	n = 0;
	//char	value[];

	ft_putstr("Value : ");
	while (buf[n])
	{
		ft_putchar(buf[n]);
		//value = buf[n];
		n++;
	}
	ft_putchar('\n');
}*/

int     ft_read_file()
{
	//char	line[MAX_LINE][MAX_LEN];
	char    buffer[255];
	char	*key;
	char	*value;
	FILE	*f = fopen("numbers.dict", "r");

	if (f == NULL)
	{
		ft_putstr("ERROR open file");
		return (1);
        }
	else
	{
		while (fgets(buffer, MAX_LEN, f) != NULL)
		{
			//key = strtok(line, ":");
			//value = strtok(NULL, "\n");
			//printf("Key %s : Value %s\n", key, value);
		//	printf("\nOUR BUFFER %s\n", buffer);
			//ft_putstr(buffer);
			ft_get_key_value(buffer);
        	}
	}
        fclose(f);
        return (0);
}

int	main()
{
	//ft_read_file("numbers.dict");
	ft_read_file();
}
