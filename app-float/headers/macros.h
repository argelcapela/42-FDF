/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: acapela- < acapela-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:39:06 by acapela-          #+#    #+#             */
/*   Updated: 2022/02/23 19:01:07 by acapela-         ###   ########.fr       */
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
# define KEY_MINUS              65453 

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

/*###################################################
#													#
#	 2. colors                           			#
#													#
###################################################*/

# define AC_GREEN1              0x18d26e    
# define WHITE                  0xffffff
# define RED                    0xff0000
# define GREEN                  0x00ff00
# define BLUE                   0x0000ff

/*###################################################
#													#
#	 3. usefull                           			#
#													#
###################################################*/

# define ONE_DEGREE             0.01745329
# define THIRTY_DEGREES         0.52359877
# define FORTY_FIVE_DEGREES     0.01745329

/*###################################################
#													#
#	 4. utils                              			#
#													#
###################################################*/

// return the larger number between 2
#define LARGER(a, b) (a > b ? a : b)

// convert a negative number into positive
#define POSITIVE(a) ((a < 0) ? -a : a)


#endif