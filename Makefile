NAME = minitalk

SERVER 	= server
CLIENT  = client

LIBFTPRINTF = ft_printf
LIBFT = libft

SERVER_SRCS = server.c
CLIENT_SRCS = client.c

SERVER_B = server_bonus.c
CLIENT_B = client_bonus.c

SERVER_OBJS	= $(patsubst %.c,%.o,$(SERVER_SRCS))
CLIENT_OBJS = $(patsubst %.c,%.o,$(CLIENT_SRCS))

SERVER_OBJS_B	= $(patsubst %.c,%.o,$(SERVER_B))
CLIENT_OBJS_B = $(patsubst %.c,%.o,$(CLIENT_B))

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

INCLUDES = -I./includes

SERVER_HEADER = includes/server.h
CLIENT_HEADER = includes/client.h
HEADERS = $(SERVER_HEADER) $(CLIENT_HEADER) $(LIBFTPRINTF)/includes/ft_printf.h $(LIBFTPRINTF)/$(LIBFT)/libft.h

all:	$(NAME)

%.o : %.c	$(HEADERS)
	gcc $(CFLAGS) -I includes/ -c $< -o $@

$(NAME):	$(SERVER_OBJS) $(CLIENT_OBJS)
	@make -C $(LIBFTPRINTF)
	@make bonus -C $(LIBFTPRINTF)
	@gcc ft_printf/libftprintf.a $(SERVER_OBJS) -o $(SERVER)
	@gcc ft_printf/libftprintf.a $(CLIENT_OBJS) -o $(CLIENT)

bonus:
	@make SERVER_OBJS="$(SERVER_OBJS_B)" CLIENT_OBJS="$(CLIENT_OBJS_B)" all

clean:
	@make clean -C $(LIBFTPRINTF)
	$(RM) $(SERVER_OBJS) $(SERVER_OBJS_B) $(CLIENT_OBJS) $(CLIENT_OBJS_B)

fclean:	clean
	@make fclean -C $(LIBFTPRINTF)
	$(RM) $(SERVER) $(CLIENT)

re:		fclean all

.PHONY:	all clean fclean re
