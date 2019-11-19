# The structure
## Source code {docsify-ignore}
_you can see the implementation 
[here](https://github.com/glegendr/libvec/blob/e8781f5311d5ff3b81022983099180d24405ac83/inc/vector.h#L19)_
``` c
typedef struct	s_vec
{
  void      *private_content;
  int       private_elem_nb;
  int       private_elem_size;
  int       private_elem_cap;
}               t_vec;
```
## Atributes {docsify-ignore}
- private_content:   This is the vector content, here is all you pushed `(void *)`
- private_elem_nb:   This is the number of elements in `(int)`
- private_elem_size: This is the size of the element `(int)`
- private_elem_cap:  This is the number of element that your vector can handle before malloc again `(int)`

_You can see all the functions that works with [here](functions.md)_
