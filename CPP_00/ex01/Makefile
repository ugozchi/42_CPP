# Compiler targets and libraries
NAME		=		phonebook
CC			=		c++
CFLAGS		=		-Wall -Werror -Wextra -g -std=c++98

# Directories
SRCS_DIR	=		./sources/
HEAD_DIR	=		./includes/
OBJS_DIR	=		${SRCS_DIR}.o

# Colours, symbols and utils
RESET		=		\033[0m
GREEN		=		\033[1;32m
YELLOW		=		\033[1;33m
CYAN		=		\033[1;36m
RED			=		\033[0;31m
ROSE		=		\033[38;5;216m
BOLD		=		\033[1m
OK			=		✓
INFO		=		ⓘ

# Sources & Objects
SRC			=		Contact.cpp \
					PhoneBook.cpp \
					main.cpp

SRCS		=		$(addprefix ${SRCS_DIR}, ${SRC})
SRC_NR		=		$(words ${SRCS})
OBJS		=		$(patsubst ${SRCS_DIR}%, ${OBJS_DIR}/%, $(SRCS:.cpp=.o))
DEPS		=		$(OBJS:.o=.d)

# Rules
all:				project_logo ${NAME}

${NAME}:			${OBJS}
						@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
						@echo "${YELLOW}\nCompilation complete, ${NAME} executable at the root of the directory${NC}\n"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)%.cpp
						@mkdir -p $(dir $@)
						@printf "Compiling $(notdir $<)"; \
						${CC} ${CFLAGS} -I${HEAD_DIR} -c $< -o $@; \
						printf "${GREEN}"; \
						printf " ${TICK}\n"; \
						printf "${NC}";

clean:
						@if [ ! -d "${OBJ_DIR}" ]; \
						then \
							echo "Repo already clean"; \
						else \
							echo "Removing all .o files"; \
							rm -rf ${OBJ_DIR}; \
						fi

fclean:		
						@echo "Removing executable from root"
						@rm -f ${NAME}

re:					fclean all

project_logo:
				@echo "${RED}   ___     _     _________     _     ____"
				@echo "  /   \   / \   /         \   / \   /    \ "
				@echo " ( ${CYAN}C++${RED} ) ( - ) ( ${CYAN}  CPP00  ${RED} ) ( - ) ( ${CYAN}ex00${RED} )"
				@echo "  \___/   \_/   \_________/   \_/   \____/${RESET}"
				@echo "\n               ${RESET}a 42 project by ${BOLD}Ugo Zanchi${RESET}\n"

.PHONY:				all clean fclean re project_logo

# Include dependency files
-include $(DEPS)