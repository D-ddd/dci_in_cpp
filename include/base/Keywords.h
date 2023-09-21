/*
 * Keywords.h
 *
 *  Created on: 2023年9月20日
 *      Author: dcq
 */

#ifndef HE4A68F26_D74A_4812_A12A_F0BC9E251A57
#define HE4A68F26_D74A_4812_A12A_F0BC9E251A57


#define ABSTRACT(...) virtual __VA_ARGS__ = 0
#define OVERRIDE(...) virtual __VA_ARGS__ override
#define EXTENDS(...) , ##__VA_ARGS__
#define IMPLEMENTS(...) EXTENDS(__VA_ARGS__)


#endif /* HE4A68F26_D74A_4812_A12A_F0BC9E251A57 */
