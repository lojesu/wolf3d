/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glegendr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:26:53 by glegendr          #+#    #+#             */
/*   Updated: 2019/11/19 16:18:33 by glegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stddef.h>
# include <stdlib.h>
# define NB_ELEM_INI 32

typedef struct	s_vec
{
	void			*private_content;
	int				private_elem_nb;
	int				private_elem_size;
	int				private_elem_cap;
}				t_vec;

/*
** vector functions
*/

/*
** Copy raw at the end of the vector.
**
** Params:
**    vec: the current vector.
**    raw: the raw to add at the end of vector.
**    nb: the numbers of elems content in the raw.
*/
void			v_append_raw(t_vec *vec, void *raw, int nb);

/*
** Copy a vector into a new vector.
**
** Params:
**    vec: the current vector.
*/
t_vec			v_copy(t_vec *vec);

/*
** Free the vector.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del(t_vec *vec);

/*
** Free the vector and all vector in.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del_all(t_vec *vec);

/*
** Del the last Param.
**
** Param:
**    vec: the vector to delete.
*/
void			v_del_last(t_vec *vec);

/*
** Get the pointer of element pointed by index.
**
** Params:
**    vec: the current vector.
**    index: the index.
*/
void			*v_get(t_vec *vec, int index);

/*
** Give the size of type.
**
** Param:
**   vec: the current vector.
*/
int				v_get_size(t_vec *vec);

/*
** Create a new vector.
**
** Param:
**    elem_size: the size of each element of the vector.
*/
t_vec			v_new(int elem_size);

/*
** Create a new vector but don't malloc it.
**
** Param:
**    elem_size: the size of each element of the vector.
*/
t_vec			v_new_null(int elem_size);

/*
** return the last part of the vector and del it from the vector.
**
** Params:
**    vec: the current vector.
*/
void			*v_pop(t_vec *vec);

/*
** Print a vector.
**
** Params:
**    vec: the current vector.
*/
void			v_print(t_vec *vec);

/*
** Copy a new element at the end of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push(t_vec *vec, void *elem);
void			v_push_int(t_vec *vec, int elem);

/*
** Copy a new element at the start of the vector.
**
** Params:
**    vec: the current vector.
**    elem: the element to add at the end of vector.
*/
void			v_push_first(t_vec *vec, void *elem);

/*
** Give the raw.
**
** Param:
**    vec: the current vector.
*/
void			*v_raw(t_vec *vec);

/*
** Reset the current vector.
**
** Param:
**    vec: the vector to reset.
*/
void			v_reset(t_vec *vec);

/*
** Rotate a vector by 1.
**
** Params:
**    vec: the current vector.
*/
void			v_reverse_rotate(t_vec *vec);
void			v_rotate(t_vec *vec);

/*
** Return the element number in the vector.
**
** Param:
**    vec: the current vector.
*/
int				v_size(t_vec *vec);

/*
** Sort the current all vector in the current vector by size.
**
** Param:
**    vec: the current vector.
*/
void			v_sort_size(t_vec *vec);

/*
** Split a vector into two vector at the inex.
**
** Pararms:
**     vec: the current vector.
**     index: the index where you have to cut.
*/
t_vec			v_split(t_vec *vec, int index);
void			*v_split_raw(t_vec *vec, int index);

/*
** Swap 2 params of vec.
**
** Params:
**    vec: the current vector.
**    first: the first elem to Swap.
**    second: the second elem to Swap.
*/
void			v_swap(t_vec *vec, size_t first, size_t second);

/*
** Utils functions
*/

/*
** Copy a memory into an other one.
**
** Params:
**    dst: the destination (non malloced).
**    src: the memory to Copy.
**    n: size of the memory src.
*/
void			*v_memcpy(void *dst, const void *src, size_t n);

/*
** Copy a memory and malloc to the new size.
**
** Params:
**    dst: the memory to Copy.
**    mem_size: the size of memory dst.
**    new_size: the size you want for your new memory (new_size >= mem_size).
*/
void			*v_realloc(void *dst, int mem_size, int new_size);

/*
** Print a number / character.
**
** Params:
**    nb: the current number.
**    c: the current character.
*/
void			v_putnbr(int nb);
void			v_putchar(char c);

#endif
