#Compiler targets and libraries
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -g -std=c++98
NAME		=	this_is_brainz

# Directories
SRCS_DIR	=	./
OBJ_DIR		=	${SRCS_DIR}.o

# Colours, symbols and utils
RESET		=		\033[0m
GREEN		=		\033[1;32m
YELLOW		=		\033[0;33m
CYAN		=		\033[1;36m
RED			=		\033[0;31m
ROSE		=		\033[38;5;216m
BOLD		=		\033[1m
OK			=		✓
INFO		=		ⓘ

# Generate log file name with timestamp
LOGFILE = $(shell date +'%Y%m%d_%H%M%S').log

SRC			=	main.cpp \

SRCS		=	$(addprefix ${SRCS_DIR}, ${SRC})
SRC_NR		=	$(words ${SRCS})

OBJS		=	$(patsubst ${SRCS_DIR}%, ${OBJ_DIR}/%, $(SRCS:.cpp=.o))
DEPS		=	$(OBJS:.o=.d)

all:			project_logo ${NAME}

${NAME}:		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "${YELLOW}${BOLD}\nCompilation complete, ${NAME} executable at the root of the directory${RESET}\n"

$(OBJ_DIR)/%.o:	$(SRCS_DIR)%.cpp
				@mkdir -p $(dir $@)
				@printf "Compiling $(notdir $<)"; \
				${CC} ${CFLAGS} -I Account.hpp -c $< -o $@; \
				printf "${GREEN}"; \
				printf " ${OK}\n"; \
				printf "${RESET}"; 

clean:
				@if [ ! -d "${OBJ_DIR}" ]; \
				then \
					echo "${INFO} ${YELLOW}Repo already clean${RESET}"; \
				else \
					echo "${RED}Removing all .o files${RESET}"; \
					rm -r ${OBJ_DIR}; \
				fi
				@echo "Removing logfiles from root"
				@rm -f 2*.log

fclean:			clean
				@echo "Removing executable from root"
				@rm -f ${NAME}

re:				fclean all

project_logo:
				@echo "${RED}   ___     _     _________     _     ____"
				@echo "  /   \   / \   /         \   / \   /    \ "
				@echo " ( ${CYAN}C++${RED} ) ( - ) ( ${CYAN}  CPP01  ${RED} ) ( - ) ( ${CYAN}ex02${RED} )"
				@echo "  \___/   \_/   \_________/   \_/   \____/${RESET}"
				@echo "\n               ${RESET}a 42 project by ${BOLD}Ugo Zanchi${RESET}\n"
.PHONY:			all run clean fclean re project_logo

# Include dependency files
-include $(DEPS)