/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_draw_pixel_in_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:26 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

/*--------------------------------------------------
   
   Big endian:      0x ff 11 22 33
   (more significant byte left)

   Little endian:   0x 33 22 11 ff
   (more significant byte right/final)

   How to put a color?

   solution 1:
   
    	(int *)(pixel) = color_int;

   solution 2:
	
		pixel[0] = (color) & 0xFF;
		pixel[1] = (color >> 8) & 0xFF;
		pixel[2] = (color >> 16) & 0xFF;
		pixel[3] = (color >> 24);

	explanation:

	a) (color) & 0xFF: always [return the last
	bit of an hexa number.] Getting the last bit
	we can create step by step our number in
	big endian or little endian order.

	 -0xFF - 0000 0000 0000 0000 1111 1111 - in bits
	
	 -&    - make a logical bit per bit

	 ->>   - drag the bits to the right.

	0x11 & 0xFF:
	0xFF   - 0000 0000 0000 0000 1111 1111
	0x11   - 0000 0000 0000 0000 0001 0001
	result - 0000 0000 0000 0000 0001 0001

	b) if the color is 
	
	hexa -  0x ff 11 22 33
	int  -  4279312947
	bits -  1111 1111 0001 0001 0010 0010 0011 0011

	pixel[0] = (color) & 0xFF; 
	 - get 33.
	 - 0x ff 11 22 33

	pixel[1] = (color >> 8) & 0xFF;
	 - 1 byte  = 8 bits
	 - drag 8 bits right, 22 became the last
	   number. 0x 00 ff 11 22
	 - get the number 22.

	pixel[2] = (color >> 16) & 0xFF;
	 - 2 bytes = 16 bits
	 - drag 16 to the right, 11 become the last
	   number. 0x 00 00 ff 11
	 - get the number 11.

	pixel[3] = (color >> 24);
	 - 3 bytes = 24 bits
     - drag 24 to the right, ff become the last
	   number. 0x 00 00 00 ff
	 - get the number ff.

	 the number is: 
	 ff 11 22 33

	 but little endian system order is: 
	 33 22 11 ff 

---------------------------------------------------*/

void	draw_pixel_in_image(t_fdf **fdf, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= (*fdf)->window_width
		|| y < 0 || y >= (*fdf)->window_height)
		return ;
	pixel = (*fdf)->img->buffer + x * (4) + y * (*fdf)->img->size_line;
	pixel[0] = (color) & 0xFF;
	pixel[1] = (color >> 8) & 0xFF;
	pixel[2] = (color >> 16) & 0xFF;
	pixel[3] = (color >> 24);
}
