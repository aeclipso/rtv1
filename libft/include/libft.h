/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:32:52 by aeclipso          #+#    #+#             */
/*   Updated: 2020/10/24 13:49:10 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define MAX_SIZE_T 18446744073709551615ULL
# define BUFF_SIZE 1
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ft_printf.h"
# include "big_int.h"

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
/*
**	ft_is
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
/*
**	ft_lst
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_beforelast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
/*
**	ft_mem
*/
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
/*
**	ft_put
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*
**	ft_str
*/
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strreverse(char *s);
char				*ft_strtolower(char *s);
char				*ft_strtoupper(char *s);
char				*ft_strjoinoneletter(char const *s1, char const *s2);
int					ft_strchrn(const char *s, int c);
char				*ft_strjoin_free1(char **s1, char *s2);
char				*ft_strjoin_free2(char *s1, char **s2);
int					ft_strchrnor(char *s, int c1, int c2);
size_t				ft_strlen_prot(const char *s);
char				*ft_strdup_prot(const char *s);
/*
**	ft_to
*/
int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
char				*ft_itoa_base(unsigned long long a, unsigned int base);
char				*ft_itoa(int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_tozero2(size_t *i, size_t *j);
void				ft_tozero3(size_t *i, size_t *j, size_t *k);
void				ft_tozero4(size_t *i, size_t *j, size_t *k, size_t *l);
void				ft_tozero2_int(int *i, int *j);
void				ft_tozero3_int(int *i, int *j, int *k);
void				ft_tozero4_int(int *i, int *j, int *k, int *l);
/*
**	ft_gnl
*/
int					get_next_line(const	int	fd, char **line);
/*
**	other
*/
void				ft_copyword(char **word, char const *s, char c);
size_t				ft_countw(char const *s, char c);
size_t				ft_lengthcounter(char const *s, char c);
int					ft_longover(const char *str, int sign);
unsigned	int		ft_power(int nb, int n);
int					ft_whatismyint(int n);
int					ft_abs(int a);

#endif
