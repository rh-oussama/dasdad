all:
	gcc -no-pie -g -g3 srcs/*.c srcs/parse/*.c srcs/execution/*.c ./lib/libft/libft.a -I./includes/ -lreadline -o minishell