#include "ft_printf.h"

int	main(void)
{
	printf("\nft_printf return value: %d", ft_printf(" %d ", -1));
	printf("\n");
	printf("\nprintf return value: %d", printf(" %d ", -1));
}