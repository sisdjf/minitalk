# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sizitout <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 21:16:05 by sizitout          #+#    #+#              #
#    Updated: 2024/03/17 01:45:10 by sizitout         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS			=  client.c \

SERVER_SRCS			=  server.c \
							   
								

CLIENT_NAME			= client
SERVER_NAME			= server

SERVER_OBJS 		= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)
CC					= cc -g3 -Wall -Wextra -Werror

INCLUDES			= -I. -I/usr/include -Ilibft


LIBFT = libft/libft.a

all:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):		$(SERVER_OBJS) $(LIBFT)
					$(CC) -o $(SERVER_NAME) $(SERVER_SRCS) $(CFLAGS) $(LIBFT)

$(CLIENT_NAME):		$(CLIENT_OBJS) $(LIBFT)
					$(CC) -o $(CLIENT_NAME) $(CLIENT_SRCS) $(CFLAGS) $(LIBFT)

$(LIBFT): 
		make -C libft

clean: 
		rm -rf ${SERVER_OBJS}
		rm -rf ${CLIENT_OBJS}
		make -C libft clean

fclean: 		clean
		rm -rf ${CLIENT_NAME}
		rm -rf ${SERVER_NAME}
		make -C libft fclean

re:                     fclean all

.PHONY:         all clean fclean re