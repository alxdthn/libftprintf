/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 01:55:55 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/27 23:58:16 by nalexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# define CONT (*elem)->content
# define SIZE (*elem)->content_size
# define BUFF_SIZE 7

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
void				*ft_emalloc(size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_puterr(int ret, char *message);
char				**ft_strsplit(char const *s, char c);
void				ft_swap(void *ptr1, void *ptr2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *str2);
char				*ft_strnstr(const char *str, const char *str2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t i);
char				*ft_strcpy(char *dist, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strccount(char *str, char c);
void				*ft_memset(void *str, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memrev(void *data, size_t size);
void				*ft_memdup(void *data, size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
int					ft_satoi(const char *str, size_t *i);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isint(char *nb);
int					ft_toupper(int c);
int					ft_tolower(int c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstclear(void *content, size_t size);
void				ft_lstpushback(t_list **alst, t_list *lst);
size_t				ft_lstcount(t_list *lst);

int					ft_intlen(int n);
size_t				ft_strclen(char const *s, char const c);
size_t				ft_wrdcount(char const *s, char const c);
char				*ft_strcskp(const char *str, char c);
char				*ft_strsskp(const char *str, char *c);
void				*ft_memjoin(void *dst, void *src,
					size_t s_dst, size_t s_src);
ssize_t				ft_read_to_str(int fd, char **str, size_t b_size);
void				ft_arraydel(void ***array);
char				*ft_strrev(char *str);
char				*ft_btoa(__int128_t bits, size_t len, char param);
unsigned long		ft_reverse_bits(unsigned long bits, size_t size);
int					ft_atoi_base(char *nb, int base);
size_t				ft_power(int n, int p);
int					ft_check_file_format(char *file, char *format);

#endif
