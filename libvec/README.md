# libvec
## Documentation
check [here](https://glegendr.github.io/libvec/#/) for more informations
## C vector librairy
### the structure
you can see the 
[structure](https://github.com/glegendr/libvec/blob/e8781f5311d5ff3b81022983099180d24405ac83/inc/vector.h#L19)
here
```
typedef struct	s_vec
{
  void      *private_content;           // vector's content
  int       private_elem_nb;            // current number of element
  int       private_elem_size;          // size of element
  int       private_elem_cap;           // number of element capacity
}               t_vec;
```
### vectors functions
#### [v_append_raw](src/v_append_raw.c)
Copy raw at the end of the vector.

Params:
- vec: the current vector.
- raw: the raw to add at the end of vector.
- nb: the numbers of elems content in the raw.

Return value:

void.
```
void			v_append_raw(t_vec *vec, void *raw, int nb);
```
#### [v_copy](src/v_copy.c)
Copy a vector into a new vector.

Params:
- vec: the current vector.

Return value:

the copy of the current vector `(t_vec)`
```
t_vec			v_copy(t_vec *vec);
```
#### [v_del](src/v_del.c)
Free the vector.

Param:
- vec: the vector to delete.

Return value:

void.
```
void			v_del(t_vec *vec);
```
#### [v_del_all](src/v_del.c)
Free the vector and all vector in.

Param:
- vec: the vector to delete.

Return value:

void.
```
void			v_del_all(t_vec *vec);
```
#### [v_del_last](src/v_del.c)
Del the last Param.
Param:
- vec: the vector to delete.

Return value:

void.
```
void			v_del_last(t_vec *vec);
```
#### [v_get](src/v_get.c)
Get the pointer of element pointed by index.

Params:
- vec: the current vector.
- index: the index.

Return value:

the pointer of the element pointed by index `(void *)`
```
void			*v_get(t_vec *vec, int index);
```
#### [v_get_size](src/v_get_size.c)
Give the size of type.

Param:
- vec: the current vector.

Return value:

the size of the current vector `(int)`
```
int				v_get_size(t_vec *vec);
```
#### [v_new](src/v_new.c)
Create a new vector.

Param:
- elem_size: the size of each element of the vector.

Return value:

the new vector `(t_vec)`
```
t_vec			v_new(int elem_size);
```
#### [v_new_null](src/v_new.c)
Create a new vector but don't malloc it.

Param:
- elem_size: the size of each element of the vector.

Return value:

the new vector `(t_vec)`
```
t_vec			v_new_null(int elem_size);
```
#### [v_pop](src/v_pop.c)
return the last part of the vector and del it from the vector.

Params:
- vec: the current vector.

Return value:

the pointer of the element deleted from the vector `(void *)`
```
void			*v_pop(t_vec *vec);
```
#### [v_print](src/v_print.c)
Print a vector.

Params:
- vec: the current vector.

Return value:

void.
```
void			v_print(t_vec *vec);
```
#### [v_push](src/v_push.c)
Copy a new element at the end of the vector.

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

void.
```
void			v_push(t_vec *vec, void *elem);
```
#### [v_push_int](src/v_push_int.c)
Copy a new element at the end of the vector. -this one is an int-

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

void.
```
void			v_push_int(t_vec *vec, int elem);
```
#### [v_push_first](src/v_push_first.c)
Copy a new element at the start of the vector.

Params:
- vec: the current vector.
- elem: the element to add at the end of vector.

Return value:

void.
```
void			v_push_first(t_vec *vec, void *elem);
```
#### [v_raw](src/v_raw.c)
Give the raw.

Param:
- vec: the current vector.

Return value:

the current data `(void *)`
```
void			*v_raw(t_vec *vec);
```
#### [v_reset](src/v_reset.c)
Reset the current vector.

Param:
- vec: the vector to reset.

Return value:

void.
```
void			v_reset(t_vec *vec);
```
#### [v_reverse_rotate](src/v_reverse_rotate.c)
Rotate the vector by 1 right.

Params:
- vec: the current vector.

Return value:

void.
```
void			v_reverse_rotate(t_vec *vec);
```
#### [v_rotate](src/v_rotate.c)
Rotate the vector by 1 left.

Params:
- vec: the current vector.

Return value:

void.
```
void			v_rotate(t_vec *vec);
```
#### [v_size](src/v_size.c)
Return the element number in the vector.

Param:
- vec: the current vector.

Return value:

the current size `(int)`
```
int				v_size(t_vec *vec);
```
#### [v_sort_size](src/v_sort_size.c)
Sort the current all vector in the current vector by size.

Param:
- vec: the current vector.

Return value:

void.
```
void			v_sort_size(t_vec *vec);
```
#### [v_split](src/v_split.c)
Split a vector into two vector at the index.

Pararms:
- vec: the current vector.
- index: the index where you have to cut.

Return value:

a new vector filled by the first part of the given vector `(t_vec)`
```
t_vec			v_split(t_vec *vec, int index);
```
#### [v_split_raw](src/v_split.c)
Split the vector's data into two data at the index.

Pararms:
- vec: the current vector.
- index: the index where you have to cut.

Return value:

a new data filled by the first part of the given vector `(void *)`
```
void			*v_split_raw(t_vec *vec, int index);
```
#### [v_swap](src/v_swap.c)
Swap 2 params of a vector.

Params:
- vec: the current vector.
- first: the first elem to Swap.
- second: the second elem to Swap.

Return value:

void.
```
void			v_swap(t_vec *vec, size_t first, size_t second);
```
### Utils functions

|Function|Used in|
|-|-|
|ft_memcpy|[ft_realloc](src/ft_realloc.c)  [v_append_raw](src/v_append_raw.c)  [v_copy](src/v_copy.c)  [v_push](src/v_push.c)  [v_push_int](src/v_push_int.c)  [v_push_first](src/v_push_first.c)  [v_reverse_rotate](src/v_reverse_rotate.c)  [v_rotate](src/v_rotate.c)  [v_split](src/v_split.c)  [v_swap](src/v_swap.c)|
|ft_realloc|[v_append_raw](src/v_append_raw.c)  [v_push](src/v_push.c)  [v_push_int](src/v_push_int.c)  [v_push_first](src/v_push_first.c)|
|ft_putchar|[ft_putnbr](src/ft_putnbr.c)  [v_print](src/v_print.c)|
|ft_putnbr|[v_print](src/v_print.c)|

#### [ft_memcpy](src/ft_memcpy.c)
Copy a memory into an other one.

Params:
- dst: the destination (non malloced).
- src: the memory to Copy.
- n: size of the memory src.

Return value:

an other pointer of the destination `(void *)`
```
void			*ft_memcpy(void *dst, const void *src, size_t n);
```
#### [ft_realloc](src/ft_realloc.c)
Copy a memory and malloc to the new size.

Params:
- dst: the memory to Copy.
- mem_size: the size of memory dst.
- new_size: the size you want for your new memory.

Return value:

an other pointer of the destination `(void *)`
```
void			*ft_realloc(void *dst, int mem_size, int new_size);
```
#### [ft_putchar](src/ft_putchar.c)
Print a character.

Params:
- c: the current character.

Return value:

void.
```
void			ft_putchar(char c);
```
#### [ft_putnbr](src/ft_putnbr.c)
Print a number.

Params:
- nb: the current number.

Return value:

void.
```
void			ft_putnbr(int nb);
```
