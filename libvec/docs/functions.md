# All vectors functions
## v_append_raw
Copy raw at the end of the vector.

Params:
- vec: the current vector.
- raw: the raw to add at the end of vector.
- nb: the numbers of elems content in the raw.

Return value:

`void`
``` c
void			v_append_raw(t_vec *vec, void *raw, int nb);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_append_raw.c)*
## v_copy
Copy a vector into a new vector.

Params:
- vec: the current vector.

Return value:

the copy of the current vector `(t_vec)`
``` c
t_vec			v_copy(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_copy.c)*
## v_del
Free the vector.

Param:
- vec: the vector to delete.

Return value:

`void`
``` c
void			v_del(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_del.c)*

!> If your vector is filled with pointers, the content will not be free
## v_del_all
Free the vector and all sub-vector in.

Param:
- vec: the vector to delete.

Return value:

`void`
``` c
void			v_del_all(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_del.c)*
## v_del_last
Del the last element.
Param:
- vec: the vector to delete.

Return value:

`void`
``` c
void			v_del_last(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_del_last.c)*
## v_get
Get the pointer of element pointed by index.

Params:
- vec: the current vector.
- index: the index.

Return value:

the pointer of the element pointed by index `(void *)`
``` c
void			*v_get(t_vec *vec, int index);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_get.c)*

> If your vector is fulfilled with `int` you have to cast the return like 
```c
int i = *(int *)v_get(&vec, 16);
```
## v_get_size
Give the size of type.

Param:
- vec: the current vector.

Return value:

the size of the current vector `(int)`
``` c
int				v_get_size(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_get_size.c)*
## v_new
Create a new vector.

Param:
- elem_size: the size of each element of the vector.

Return value:

the new vector `(t_vec)`
``` c
t_vec			v_new(int elem_size);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_new.c)*
## v_new_null
Create a new vector but don't malloc it.

Param:
- elem_size: the size of each element of the vector.

Return value:

the new vector `(t_vec)`
``` c
t_vec			v_new_null(int elem_size);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_new.c)*
## v_pop
return the last part of the vector and del it from the vector.

Params:
- vec: the current vector.

Return value:

the pointer of the element deleted from the vector `(void *)`
``` c
void			*v_pop(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_pop.c)*

!> If you use `v_pop` on a vector fulled with pointers, you have to memcpy the return because if you push after, the memory with be crushed.
## v_print
Print a vector.

Params:
- vec: the current vector.

Return value:

`void`
``` c
void			v_print(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_print.c)*

!> Only works with `int`, `char` and `t_vec`
## v_push
Copy a new element at the end of the vector.

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

`void`
``` c
void			v_push(t_vec *vec, void *elem);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_push.c)*
## v_push_int
Copy a new element at the end of the vector. -this one is an int-

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

`void`
``` c
void			v_push_int(t_vec *vec, int elem);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_push_int.c)*
## v_push_first
Copy a new element at the start of the vector.

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

`void`
``` c
void			v_push_first(t_vec *vec, void *elem);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_push_first.c)*
## v_raw
Give the raw.

Param:
- vec: the current vector.

Return value:

the current data `(void *)`
``` c
void			*v_raw(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_raw.c)*
## v_reset
Reset the current vector.

Param:
- vec: the vector to reset.

Return value:

`void`
``` c
void			v_reset(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_reset.c)*
## v_reverse_rotate
Rotate the vector by 1 right.

Params:
- vec: the current vector.

Return value:

`void`
``` c
void			v_reverse_rotate(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_reverse_rotate.c)*
## v_rotate
Rotate the vector by 1 left.

Params:
- vec: the current vector.

Return value:

`void`
``` c
void			v_rotate(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_rotate.c)*
## v_size
Return the number of elements in the vector.

Param:
- vec: the current vector.

Return value:

the current size `(int)`
``` c
int				v_size(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_size.c)*
## v_sort_size
Sort the current all vector in the current vector by size.

Param:
- vec: the current vector.

Return value:

`void`
``` c
void			v_sort_size(t_vec *vec);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_sort_size.c)*
## v_split
Split a vector into two vector at the index.

Pararms:
- vec: the current vector.
- index: the index where you have to cut.

Return value:

a new vector filled by the first part of the given vector `(t_vec)`
``` c
t_vec			v_split(t_vec *vec, int index);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_split.c)*
## v_split_raw
Split the vector's data into two data at the index.

Pararms:
- vec: the current vector.
- index: the index where you have to cut.

Return value:

a new data filled by the first part of the given vector `(void *)`
``` c
void			*v_split_raw(t_vec *vec, int index);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_split.c)*
## v_swap
Swap two elements of a vector.

Params:
- vec: the current vector.
- first: the first elem to Swap.
- second: the second elem to Swap.

Return value:

`void`
``` c
void			v_swap(t_vec *vec, size_t first, size_t second);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/v_swap.c)*
# Utils functions

|Function|Used in|
|-|-|
|ft_memcpy|[ft_realloc](#ft_realloc)  [v_append_raw](#v_append_raw)  [v_copy](#v_copy)  [v_push](#v_push)  [v_push_int](#v_push_int)  [v_push_first](#v_push_first)  [v_reverse_rotate](#v_reverse_rotate)  [v_rotate](#v_rotate)  [v_split](#v_split)  [v_swap](#v_swap)|
|ft_realloc|[v_append_raw](#v_append_raw)  [v_push](#v_push)  [v_push_int](#v_push_int)  [v_push_first](#v_push_first)|
|ft_putchar|[ft_putnbr](#ft_putnbr)  [v_print](#v_print)|
|ft_putnbr|[v_print](#v_print)|

## ft_memcpy
Copy a memory into an other one.

Params:
- dst: the destination (non malloced).
- src: the memory to Copy.
- n: size of the memory src.

Return value:

an other pointer of the destination `(void *)`
``` c
void			*ft_memcpy(void *dst, const void *src, size_t n);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/ft_memcpy.c)*
## ft_realloc
Copy a memory and malloc to the new size.

Params:
- dst: the memory to Copy.
- mem_size: the size of memory dst.
- new_size: the size you want for your new memory.

Return value:

an other pointer of the destination `(void *)`
``` c
void			*ft_realloc(void *dst, int mem_size, int new_size);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/ft_realloc.c)*
## ft_putchar
Print a character.

Params:
- c: the current character.

Return value:

`void`
``` c
void			ft_putchar(char c);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/ft_putchar.c)*
## ft_putnbr
Print a number.

Params:
- nb: the current number.

Return value:

`void`
``` c
void			ft_putnbr(int nb);
```
*see implementation [here](https://github.com/glegendr/libvec/blob/master/src/ft_putnbr.c)*
