# ft_malloc

| Branch    | Build status    |
| :-------- | :-------------: |
| master    | [![Build Status](https://travis-ci.org/tnicolas42/ft_malloc.svg?branch=master)](https://travis-ci.org/tnicolas42/ft_malloc) |
| develop   | [![Build Status](https://travis-ci.org/tnicolas42/ft_malloc.svg?branch=develop)](https://travis-ci.org/tnicolas42/ft_malloc) |

## Fonctions

### malloc
```c
void  *malloc(size_t size);
```
Voir `man malloc`
### calloc
```c
void  *calloc(size_t count, size_t size);
```
Voir `man calloc`
### realloc
```c
void  *realloc(void *ptr, size_t size);
```
Voir `man realloc`
### free
```c
void  free(void *ptr);
```
Voir `man free`
### is_allocated
```c
int is_allocated(void *ptr);
```
Prend en argument un pointeur et retourne SUCCESS (0) si le pointeur a été alloué avec `malloc` retourne ERROR (1) sinon.
### get_alloc_size
```c
size_t  get_alloc_size(void *ptr);
```
Prend en argument un pointeur vers une zone allouée avec `malloc` et renvoie sa taille.
### print_alloc_mem
```c
void  print_alloc_mem(void *ptr, size_t size);
```
Affiche le contenu d'une zone memoire (si size == 0 : affiche tout le contenu de la zone allouée).
### free_all
```c
void  free_all(void);
```
Free tout les elements allouées avec `malloc`
### show_alloc_mem
```c
void  show_alloc_mem(void);
```
Affiche les differentes zones allouées avec leurs tailles
