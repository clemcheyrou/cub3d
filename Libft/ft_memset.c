/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:09:48 by ccheyrou          #+#    #+#             */
/*   Updated: 2022/05/15 02:13:58 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = c;
	return (s);
}

/*int	main() 
{
    char array[6] = "salut";
    char array_test[6] = "salut";
    int c = '4';
    size_t size = 2*sizeof(char);

    printf("\n\n");
    
    ft_memset(array, c, size);
    memset(array_test, c, size);

    printf( "-Tableau memset : %s \n", array );
    printf( "-Tableau ft_memset : %s \n\n", array_test );
    printf( "\n" );

    char array1[6] = "salut";
    char array_test1[6] = "salut";
    int c1 = '.';
    size_t size1 = 4*sizeof(char);

    printf("\n\n");
    
    ft_memset(array1, c1, size1);
    memset(array_test1, c1, size1);

    printf( "-Tableau memset : %s \n", array1 );
    printf( "-Tableau ft_memset : %s\n\n", array_test1 );

    int array2[] = {1,2,3};
    int array_test2[] = {1,2,3};
    int c2 = '4';
    size_t size2 = 3*sizeof(char);
    int i = 0;

    printf("(2)\033[4mTableau initial:\033[0m");
    while (i < 3)
	    printf("%d", array2[i++]); 
    printf("\n\n");
    
    ft_memset(array2, c2, size2);
    memset(array_test2, c2, size2);

    printf( "-Tableau memset \n");
    while (i < 3)
	    printf("%d", array2[i++]);
    printf( "-Tableau ft_memset ");
    while (i < 3)
	    printf("%d", array_test2[i++]);  printf( "\n" );  
    
    return 0;
}
*/
