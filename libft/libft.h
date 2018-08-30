/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmayika <kmayika@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:18:41 by kmayika           #+#    #+#             */
/*   Updated: 2018/08/28 13:35:30 by kmayika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>

# define BUFF_SIZE 9999
# define MAX_FD 1024

int		ft_isdigit(int c);
int		ft_isascii(int c);
char	*ft_strdup(const char *s1);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strequ(char const *s1, char const *s2);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putendl(char const *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr(int n);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strnew(size_t size);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	**ft_strsplit(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		get_next_line(int const fd, char **line);

#endif
