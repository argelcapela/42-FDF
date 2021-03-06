/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- <acapela-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/03/17 16:56:43 by acapela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*###################################################
#													#
#	 1. keyboard                           			#
#													#
###################################################*/

/* zoom keys */
# define KEY_PLUS               65451 
# define KEY_PLUS2              61
# define KEY_MINUS              65453 
# define KEY_MINUS2             45

/* translation(move) keys */
# define KEY_UP                 65362 
# define KEY_DOWN               65364 
# define KEY_LEFT               65361 
# define KEY_RIGHT              65363 

/* rotation keys */
# define KEY_W                  119 
# define KEY_S                  115 
# define KEY_A                  97 
# define KEY_D                  100 
# define KEY_Q                  113 
# define KEY_E                  101 

/* change projection */
# define KEY_I                  105 

/* change map */
# define KEY_LESS               44 
# define KEY_BIGGER             46 

/* change color randomly */
# define KEY_C                  99

/* exit key */
# define KEY_ESC                65307

/* show/hide hint box */
# define KEY_H                  104 

/* depth */
# define KEY_F                  102 
# define KEY_G                  103 

/* others  */
# define KEY_R                  114
# define KEY_N                  110

/*###################################################
#													#
#	 2. colors                           			#
#													#
###################################################*/

# define AC_GREEN1              0x18d26e    
# define AC_GREEN2              0x3a9e3e    
# define WHITE                  0xffffff
# define RED                    0xff0000
# define GREEN                  0x00ff00
# define BLUE                   0x0000ff
# define BLACK                  0x000000

/*###################################################
#													#
#	 3. usefull                           			#
#													#
###################################################*/

# define ONE_DEGREE             0.01745329
# define THIRTY_DEGREES         0.52359877

#endif