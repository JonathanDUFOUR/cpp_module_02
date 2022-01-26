# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 00:12:40 by jodufour          #+#    #+#              #
#    Updated: 2022/01/26 00:29:30 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CXX				=	c++ -c
LINK			=	c++
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	ex02.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	./
OBJ_DIR			=	objs/

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					Fixed.cpp	\
					main.cpp

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.cpp=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CPPFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS		+=	-std=c++98
CPPFLAGS		+=	-MMD -MP

LDFLAGS			=	

ifeq (${DEBUG}, 1)
	CPPFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	@${MKDIR} ${@D}
	${CXX} ${CPPFLAGS} $< ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

re: clean all

fre: fclean all

.PHONY:	all clean fclean re fre
