# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgatnaou <rgatnaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 08:26:52 by rgatnaou          #+#    #+#              #
#    Updated: 2022/02/17 19:52:27 by rgatnaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CLIENT_NAME = client

SERVER_NAME = server

CLIENT_NAME_BONUS = client_bonus

SERVER_NAME_BONUS = server_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

SRC = put_nbr.c atoi.c

OBJ = $(SRC:.c=.o)

all : $(CLIENT_NAME) $(SERVER_NAME)

bonus : $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)
	
$(SERVER_NAME) : $(OBJ) $(SRC) server.c $(HEADER)
	$(CC) $(FLAGS) $(OBJ) server.c -o $@

$(CLIENT_NAME) : $(OBJ) $(SRC) client.c $(HEADER)
	$(CC) $(FLAGS) $(OBJ) client.c -o $@
	
$(SERVER_NAME_BONUS) : $(OBJ) $(SRC) server_bonus.c $(HEADER)
	$(CC) $(FLAGS) $(OBJ) server_bonus.c -o $@

$(CLIENT_NAME_BONUS) : $(OBJ) $(SRC) client_bonus.c $(HEADER)
	$(CC) $(FLAGS) $(OBJ) client_bonus.c -o $@ 

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ)

fclean	:	clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

re		:	fclean all
